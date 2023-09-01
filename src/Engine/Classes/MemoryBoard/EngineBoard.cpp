#include "EngineBoard.hpp"

void Board::parseFEN(const std::string &fen) {
    std::unordered_map<char, int> pieceMap = {
        {'P', 0}, {'N', 1}, {'B', 2}, {'R', 3}, {'Q', 4},  {'K', 5},
        {'p', 6}, {'n', 7}, {'b', 8}, {'r', 9}, {'q', 10}, {'k', 11},
    };

    int rank = 7;
    int file = 0;
    int i = 0;

    // Clear all bitboards
    for (int j = 0; j < 12; j++) {
        pieces[j] = 0;
    }

    // Parse pieces
    while (fen[i] != ' ') {
        if (fen[i] == '/') {
            rank--;
            file = 0;
        } else if (isdigit(fen[i])) {
            file += fen[i] - '0';
        } else {
            pieces[pieceMap[fen[i]]] |= (1ULL << (rank * 8 + file));
            file++;
        }
        i++;
    }

    i++;  // Skip space

    // Parse active color
    // (You can use this information if needed)

    i += 2;  // Skip space

    // Parse castling rights
    while (fen[i] != ' ') {
        switch (fen[i]) {
            case 'K':
                castlingRights[0] = true;
                break;
            case 'Q':
                castlingRights[1] = true;
                break;
            case 'k':
                castlingRights[2] = true;
                break;
            case 'q':
                castlingRights[3] = true;
                break;
        }
        i++;
    }

    i++;  // Skip space

    // Parse en passant square
    if (fen[i] != '-') {
        file = fen[i] - 'a';
        rank = fen[i + 1] - '1';
        enPassant = (1ULL << (rank * 8 + file));
    }
}

void Board::print_board() const {
    for (int rank = 7; rank >= 0; rank--) {
        for (int file = 0; file < 8; file++) {
            char pieceChar = '.';
            for (int i = 0; i < 12; i++) {
                if (pieces[i] & (1ULL << (rank * 8 + file))) {
                    pieceChar = "PNBRQKpnbrqk"[i];
                    break;
                }
            }
            std::cout << pieceChar << ' ';
        }
        std::cout << '\n';
    }
    std::cout << "Castling rights: K=" << castlingRights[0] << " Q=" << castlingRights[1] << " k=" << castlingRights[2]
              << " q=" << castlingRights[3] << '\n';
    std::cout << "En passant square: ";
    if (enPassant) {
        for (int i = 0; i < 64; i++) {
            if (enPassant & (1ULL << i)) {
                std::cout << char('a' + (i % 8)) << char('1' + (i / 8)) << '\n';
                break;
            }
        }
    } else {
        std::cout << "None\n";
    }

    sideToMove = (fen.find("w") != std::string::npos) ? TURN::WHITE : TURN::BLACK;
}

int Board::evaluate() {
    int score = 0;
    int pieceValues[12] = {100, 300, 300, 500, 900, 10000, -100, -300, -300, -500, -900, -10000};

    for (int i = 0; i < 12; i++) {
        score += __builtin_popcountll(pieces[i]) * pieceValues[i];
    }

    score += activityScore();

    return score;
}

int Board::legalMovesForPawn(int position, bool isWhite) {
    int rank = position / 8;
    // int file = position % 8;
    int moves = 0;

    if (isWhite && rank < 7 && !(pieces[6] & (1ULL << (position + 8)))) {
        moves++;
    } else if (!isWhite && rank > 0 && !(pieces[0] & (1ULL << (position - 8)))) {
        moves++;
    }

    return moves;
}

int Board::legalMovesForKnight(int position) {
    static const int knightMoves[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};

    int rank = position / 8;
    int file = position % 8;
    int moves = 0;

    for (int i = 0; i < 8; i++) {
        int newRank = rank + knightMoves[i][0];
        int newFile = file + knightMoves[i][1];
        if (newRank >= 0 && newRank < 8 && newFile >= 0 && newFile < 8) {
            moves++;
        }
    }

    return moves;
}

int Board::legalMovesForBishop(int position) {
    static const int bishopMoves[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    int rank = position / 8;
    int file = position % 8;
    int moves = 0;

    for (int i = 0; i < 4; i++) {
        int newRank = rank + bishopMoves[i][0];
        int newFile = file + bishopMoves[i][1];
        while (newRank >= 0 && newRank < 8 && newFile >= 0 && newFile < 8) {
            if (pieces[6] & (1ULL << (newRank * 8 + newFile)) || pieces[0] & (1ULL << (newRank * 8 + newFile))) {
                // Stop if there's a piece in the way
                break;
            }
            moves++;
            newRank += bishopMoves[i][0];
            newFile += bishopMoves[i][1];
        }
    }

    return moves;
}

int Board::legalMovesForRook(int position) {
    static const int rookMoves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int rank = position / 8;
    int file = position % 8;
    int moves = 0;

    for (int i = 0; i < 4; i++) {
        int newRank = rank + rookMoves[i][0];
        int newFile = file + rookMoves[i][1];
        while (newRank >= 0 && newRank < 8 && newFile >= 0 && newFile < 8) {
            if (pieces[6] & (1ULL << (newRank * 8 + newFile)) || pieces[0] & (1ULL << (newRank * 8 + newFile))) {
                // Stop if there's a piece in the way
                break;
            }
            moves++;
            newRank += rookMoves[i][0];
            newFile += rookMoves[i][1];
        }
    }

    return moves;
}

int Board::legalMovesForQueen(int position) {
    // Queens can move like both bishops and rooks
    return legalMovesForBishop(position) + legalMovesForRook(position);
}

int Board::activityScore() {
    int score = 0;

    for (int position = 0; position < 64; position++) {
        if (pieces[0] & (1ULL << position)) {
            score += legalMovesForPawn(position, true);
        } else if (pieces[1] & (1ULL << position)) {
            score += legalMovesForKnight(position);
        } else if (pieces[6] & (1ULL << position)) {
            score -= legalMovesForPawn(position, false);
        } else if (pieces[7] & (1ULL << position)) {
            score -= legalMovesForKnight(position);
        } else if (pieces[2] & (1ULL << position)) {
            score += legalMovesForBishop(position);
        } else if (pieces[8] & (1ULL << position)) {
            score -= legalMovesForBishop(position);
        } else if (pieces[3] & (1ULL << position)) {
            score += legalMovesForRook(position);
        } else if (pieces[9] & (1ULL << position)) {
            score -= legalMovesForRook(position);
        } else if (pieces[4] & (1ULL << position)) {
            score += legalMovesForQueen(position);
        } else if (pieces[10] & (1ULL << position)) {
            score -= legalMovesForQueen(position);
        }
    }

    return score;
}

int Board::getPieceAt(int square) {
    for (int i = 0; i < 12; i++) {
        if (pieces[i] & (1ULL << square)) {
            return i;
        }
    }
    return -1;
}

Move Board::makeMove(Move move) {
    int piece = getPieceAt(move.startSquare);

    // Update bitboards
    uint64_t startBit = 1ULL << move.startSquare;
    uint64_t endBit = 1ULL << move.endSquare;
    pieces[piece] &= ~startBit;  // Remove piece from start square
    pieces[piece] |= endBit;     // Place piece on end square

    // Check if a piece was captured and update its bitboard
    int capturedPiece = getPieceAt(move.endSquare);
    if (capturedPiece != -1) {
        pieces[capturedPiece] &= ~endBit;
        move.capturedPiece = capturedPiece;
    }

    // Handle special moves
    // if (move.isCastling) {
    //     // Determine if it's kingside or queenside castling
    //     if (move.endSquare > move.startSquare) {
    //         // Kingside castling
    //         pieces[ROOK] &= ~(1ULL << (move.startSquare + 3));  // Remove rook from original square
    //         pieces[ROOK] |= (1ULL << (move.startSquare + 1));   // Place rook next to the king
    //     } else {
    //         // Queenside castling
    //         pieces[ROOK] &= ~(1ULL << (move.startSquare - 4));  // Remove rook from original square
    //         pieces[ROOK] |= (1ULL << (move.startSquare - 1));   // Place rook next to the king
    //     }
    // } else if (move.isEnPassant) {
    //     // Determine the square of the pawn being captured
    //     int enPassantSquare = (move.startSquare % 8 == move.endSquare % 8) ? move.endSquare - 8 : move.endSquare + 8;
    //     pieces[PAWN] &= ~(1ULL << enPassantSquare);  // Remove the pawn
    // } else if (move.promotionPiece != '\0') {
    //     // Remove the pawn from the end square
    //     pieces[PAWN] &= ~endBit;
    //     // Place the promoted piece on the end square
    //     int promotedPiece = charToPiece(move.promotionPiece);
    //     pieces[promotedPiece] |= endBit;
    // }

    // Update other board state
    // This would include toggling the side to move, updating castling rights, setting the en passant square, etc.
    // For example:
    sideToMove = (sideToMove == TURN::WHITE) ? TURN::BLACK : TURN::WHITE;
    // updateCastlingRights(move);
    // setEnPassantSquare(move);

    return move;
}

void Board::undoMove(Move move) {
    int piece = getPieceAt(move.endSquare);

    // Update bitboards
    uint64_t startBit = 1ULL << move.startSquare;
    uint64_t endBit = 1ULL << move.endSquare;
    pieces[piece] &= ~endBit;   // Remove piece from end square
    pieces[piece] |= startBit;  // Place piece back on start square

    // If a piece was captured, put it back
    // Note: You might need to store the captured piece in the Move struct to know which piece was captured.
    if (move.capturedPiece != -1) {
        pieces[move.capturedPiece] |= endBit;
    }

    // // Handle special moves
    // if (move.isCastling) {
    //     // Determine if it's kingside or queenside castling
    //     if (move.endSquare > move.startSquare) {
    //         // Kingside castling
    //         pieces[ROOK] |= (1ULL << (move.startSquare + 3));  // Place rook back to its original square
    //         pieces[ROOK] &= ~(1ULL << (move.startSquare + 1)); // Remove rook from its castled position
    //     } else {
    //         // Queenside castling
    //         pieces[ROOK] |= (1ULL << (move.startSquare - 4));  // Place rook back to its original square
    //         pieces[ROOK] &= ~(1ULL << (move.startSquare - 1)); // Remove rook from its castled position
    //     }
    // } else if (move.isEnPassant) {
    //     // Determine the square of the pawn that was captured en passant
    //     int enPassantSquare = (move.startSquare % 8 == move.endSquare % 8) ? move.endSquare - 8 : move.endSquare + 8;
    //     pieces[PAWN] |= (1ULL << enPassantSquare);  // Place the pawn back
    // } else if (move.promotionPiece != '\0') {
    //     // Demote the piece back to a pawn
    //     pieces[piece] &= ~endBit;  // Remove the promoted piece
    //     pieces[PAWN] |= endBit;    // Place the pawn back on the end square
    // }

    // Revert other board state
    // This would include toggling the side to move, updating castling rights, setting the en passant square, etc.
    sideToMove = (sideToMove == TURN::WHITE) ? TURN::BLACK : TURN::WHITE;
    // You might need to store the previous state (like castling rights, en passant square, etc.) to revert them here.
}

std::vector<Move> Board::generateLegalMoves() {
    std::vector<Move> moves;

    // For each piece on the board
    for (int square = 0; square < 64; square++) {
        int piece = getPieceAt(square);
        if (piece != EMPTY) {
            // Generate moves based on the piece type
            if (piece == PAWN) {
                // Add pawn moves (including captures, promotions, and en passant)
                legalMovesForPawn()
            } else if (piece == KNIGHT) {
                // Add knight moves
            } else if (piece == BISHOP) {
                // Add bishop moves
            } else if (piece == ROOK) {
                // Add rook moves
            } else if (piece == QUEEN) {
                // Add queen moves
            } else if (piece == KING) {
                // Add king moves (including castling)
            }
        }
    }

    return moves;
}
