#include "memoryBoard.hpp"

Board::Board(std::string fen) {
    int j = 0;
    int k = 0;

    // Setting the double vector to EMPTY
    while (j < BOARD_SIZE) {
        this->board.push_back(std::vector<Piece>());
        while (k < BOARD_SIZE) {
            this->board.at(j).push_back(Piece::EMPTY);
            k++;
        }
        k = 0;
        j++;
    }

    initBoard(fen);
}

void Board::initBoard(std::string fen) {
    // Initializes the board with the given FEN string
    // fen is the FEN string
    size_t i = 0;
    int j = 0;
    int k = 0;

    while (i < fen.length()) {
        if (fen[i] == '/') {
            j++;
            k = 0;
        } else if (fen[i] == ' ') {
            break;
        } else if (fen[i] >= '1' && fen[i] <= '8') {
            k += fen[i] - '0';
        } else {
            if (fen[i] == 'p') {
                this->board[j][k] = Piece::BLACK_PAWN;
            } else if (fen[i] == 'P') {
                this->board[j][k] = Piece::WHITE_PAWN;
            } else if (fen[i] == 'n') {
                this->board[j][k] = Piece::BLACK_KNIGHT;
            } else if (fen[i] == 'N') {
                this->board[j][k] = Piece::WHITE_KNIGHT;
            } else if (fen[i] == 'b') {
                this->board[j][k] = Piece::BLACK_BISHOP;
            } else if (fen[i] == 'B') {
                this->board[j][k] = Piece::WHITE_BISHOP;
            } else if (fen[i] == 'r') {
                this->board[j][k] = Piece::BLACK_ROOK;
            } else if (fen[i] == 'R') {
                this->board[j][k] = Piece::WHITE_ROOK;
            } else if (fen[i] == 'q') {
                this->board[j][k] = Piece::BLACK_QUEEN;
            } else if (fen[i] == 'Q') {
                this->board[j][k] = Piece::WHITE_QUEEN;
            } else if (fen[i] == 'k') {
                this->board[j][k] = Piece::BLACK_KING;
            } else if (fen[i] == 'K') {
                this->board[j][k] = Piece::WHITE_KING;
            }
            k++;
        }
        i++;
    }

    this->playerTurn = (fen.find("w") != std::string::npos) ? PieceColor::WHITE_PIECE : PieceColor::BLACK_PIECE;
}

void Board::execute_move(const Move& move) {
    int start_row = move.get_start_row();
    int start_col = move.get_start_col();
    int end_row = move.get_end_row();
    int end_col = move.get_end_col();

    Piece piece_to_move = get_piece(start_row, start_col);

    // Move the piece to the destination square
    set_piece(end_row, end_col, piece_to_move);

    // Clear the starting square
    set_piece(start_row, start_col, Piece::EMPTY);

    // Handle pawn promotion (assumes promotion to queen)
    if (piece_to_move == Piece::WHITE_PAWN && end_row == 0) {
        set_piece(end_row, end_col, Piece::WHITE_QUEEN);
    } else if (piece_to_move == Piece::BLACK_PAWN && end_row == 7) {
        set_piece(end_row, end_col, Piece::BLACK_QUEEN);
    }

    // Note: This implementation does not handle castling, en passant, or other
    // special chess rules.
}

bool Board::is_king_in_check(bool is_white_turn, const MoveGenerator& move_gen) const {
    // Find the position of the king
    int king_row = -1;
    int king_col = -1;
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            Piece piece = get_piece(row, col);
            if ((piece == Piece::WHITE_KING && is_white_turn) || (piece == Piece::BLACK_KING && !is_white_turn)) {
                king_row = row;
                king_col = col;
                break;
            }
        }
        if (king_row != -1) {
            break;
        }
    }

    // Check if any opposing piece attacks the king's position
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            Piece piece = get_piece(row, col);
            if (piece != Piece::EMPTY && is_white_turn != is_white_piece(piece)) {
                // Generate moves for the current piece using the passed move generator
                std::vector<Move> moves = move_gen.generate_moves_for_piece(row, col);

                // Check if any move attacks the king's position
                for (const Move& move : moves) {
                    if (move.get_end_row() == king_row && move.get_end_col() == king_col) {
                        return true;  // King is in check
                    }
                }
            }
        }
    }

    return false;  // King is not in check
}
