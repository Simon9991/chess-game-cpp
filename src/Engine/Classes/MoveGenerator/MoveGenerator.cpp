#include "MoveGenerator.hpp"

std::vector<Move> MoveGenerator::generate_moves(bool is_white_turn) const {
    std::vector<Move> moves;

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            Piece piece = board.get_piece(row, col);
            if (piece != Piece::EMPTY && is_white_turn == is_white_piece(piece)) {
                std::vector<Move> piece_moves = generate_moves_for_piece(piece, row, col);
                moves.insert(moves.end(), piece_moves.begin(), piece_moves.end());
            }
        }
    }

    // Note: This implementation does not handle filtering moves that would put the
    // player's own king in check. Illegal moves needs to be filtered.

    return moves;
}

std::vector<Move> MoveGenerator::generate_moves_for_piece(Piece piece, int row, int col) const {
    Piece gotPiece = board.get_piece(row, col);
    std::vector<Move> moves;
    std::vector<Move> legal_moves;

    switch (gotPiece) {
        case Piece::WHITE_PAWN:
        case Piece::BLACK_PAWN:
            moves = generate_pawn_moves(row, col);
            break;
        case Piece::WHITE_KNIGHT:
        case Piece::BLACK_KNIGHT:
            moves = generate_knight_moves(row, col);
            break;
        case Piece::WHITE_BISHOP:
        case Piece::BLACK_BISHOP:
            moves = generate_bishop_moves(row, col);
            break;
        case Piece::WHITE_ROOK:
        case Piece::BLACK_ROOK:
            moves = generate_rook_moves(row, col);
            break;
        case Piece::WHITE_QUEEN:
        case Piece::BLACK_QUEEN:
            moves = generate_queen_moves(row, col);
            break;
        case Piece::WHITE_KING:
        case Piece::BLACK_KING:
            moves = generate_king_moves(row, col);
            break;
        default:
            // No moves for an empty square or an unrecognized piece
            break;
    }

    // Filter out moves that would put the king in check
    for (const Move& move : moves) {
        if (!is_king_in_check_after_move(move)) {
            legal_moves.push_back(move);
        }
    }

    return moves;
}

bool MoveGenerator::is_move_legal(const Move& move) const {
    return false;
}

std::vector<Move> MoveGenerator::generate_pawn_moves(int row, int col) const {
    std::vector<Move> moves;
    Piece pawn = board.get_piece(row, col);

    if (pawn == Piece::WHITE_PAWN) {
        // Single move forward
        if (row > 0 && board.get_piece(row - 1, col) == Piece::EMPTY) {
            moves.emplace_back(row, col, row - 1, col);

            // Double move forward from the starting position
            if (row == 6 && board.get_piece(row - 2, col) == Piece::EMPTY) {
                moves.emplace_back(row, col, row - 2, col);
            }
        }

        // Capture moves
        if (row > 0 && col > 0 && is_black_piece(board.get_piece(row - 1, col - 1))) {
            moves.emplace_back(row, col, row - 1, col - 1);
        }
        if (row > 0 && col < 7 && is_black_piece(board.get_piece(row - 1, col + 1))) {
            moves.emplace_back(row, col, row - 1, col + 1);
        }
    } else if (pawn == Piece::BLACK_PAWN) {
        // Single move forward
        if (row < 7 && board.get_piece(row + 1, col) == Piece::EMPTY) {
            moves.emplace_back(row, col, row + 1, col);

            // Double move forward from the starting position
            if (row == 1 && board.get_piece(row + 2, col) == Piece::EMPTY) {
                moves.emplace_back(row, col, row + 2, col);
            }
        }

        // Capture moves
        if (row < 7 && col > 0 && is_white_piece(board.get_piece(row + 1, col - 1))) {
            moves.emplace_back(row, col, row + 1, col - 1);
        }
        if (row < 7 && col < 7 && is_white_piece(board.get_piece(row + 1, col + 1))) {
            moves.emplace_back(row, col, row + 1, col + 1);
        }
    }

    // TODO: Add en passant moves and promotion moves

    return moves;
}
std::vector<Move> MoveGenerator::generate_rook_moves(int row, int col) const {
    std::vector<Move> moves;
    Piece rook = board.get_piece(row, col);
    bool is_rook_white = is_white_piece(rook);

    // Move up
    for (int r = row - 1; r >= 0; --r) {
        Piece piece = board.get_piece(r, col);
        if (piece == Piece::EMPTY) {
            moves.emplace_back(row, col, r, col);
        } else {
            if (is_rook_white != is_white_piece(piece)) {
                moves.emplace_back(row, col, r, col);
            }
            break;
        }
    }

    // Move down
    for (int r = row + 1; r <= 7; ++r) {
        Piece piece = board.get_piece(r, col);
        if (piece == Piece::EMPTY) {
            moves.emplace_back(row, col, r, col);
        } else {
            if (is_rook_white != is_white_piece(piece)) {
                moves.emplace_back(row, col, r, col);
            }
            break;
        }
    }

    // Move left
    for (int c = col - 1; c >= 0; --c) {
        Piece piece = board.get_piece(row, c);
        if (piece == Piece::EMPTY) {
            moves.emplace_back(row, col, row, c);
        } else {
            if (is_rook_white != is_white_piece(piece)) {
                moves.emplace_back(row, col, row, c);
            }
            break;
        }
    }

    // Move right
    for (int c = col + 1; c <= 7; ++c) {
        Piece piece = board.get_piece(row, c);
        if (piece == Piece::EMPTY) {
            moves.emplace_back(row, col, row, c);
        } else {
            if (is_rook_white != is_white_piece(piece)) {
                moves.emplace_back(row, col, row, c);
            }
            break;
        }
    }

    return moves;
}

std::vector<Move> MoveGenerator::generate_knight_moves(int row, int col) const {
    std::vector<Move> moves;
    Piece knight = board.get_piece(row, col);
    bool is_knight_white = is_white_piece(knight);

    // Possible knight moves relative to the current position
    const std::vector<std::pair<int, int>> knight_moves = {
        {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

    for (const auto& move : knight_moves) {
        int new_row = row + move.first;
        int new_col = col + move.second;

        if (is_move_in_bounds(new_row, new_col)) {
            Piece piece = board.get_piece(new_row, new_col);
            if (piece == Piece::EMPTY || is_knight_white != is_white_piece(piece)) {
                moves.emplace_back(row, col, new_row, new_col);
            }
        }
    }

    return moves;
}

std::vector<Move> MoveGenerator::generate_bishop_moves(int row, int col) const {
    std::vector<Move> moves;
    Piece bishop = board.get_piece(row, col);
    bool is_bishop_white = is_white_piece(bishop);

    // Move up and left
    for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; --r, --c) {
        Piece piece = board.get_piece(r, c);
        if (piece == Piece::EMPTY) {
            moves.emplace_back(row, col, r, c);
        } else {
            if (is_bishop_white != is_white_piece(piece)) {
                moves.emplace_back(row, col, r, c);
            }
            break;
        }
    }

    // Move up and right
    for (int r = row - 1, c = col + 1; r >= 0 && c <= 7; --r, ++c) {
        Piece piece = board.get_piece(r, c);
        if (piece == Piece::EMPTY) {
            moves.emplace_back(row, col, r, c);
        } else {
            if (is_bishop_white != is_white_piece(piece)) {
                moves.emplace_back(row, col, r, c);
            }
            break;
        }
    }

    // Move down and left
    for (int r = row + 1, c = col - 1; r <= 7 && c >= 0; ++r, --c) {
        Piece piece = board.get_piece(r, c);
        if (piece == Piece::EMPTY) {
            moves.emplace_back(row, col, r, c);
        } else {
            if (is_bishop_white != is_white_piece(piece)) {
                moves.emplace_back(row, col, r, c);
            }
            break;
        }
    }

    // Move down and right
    for (int r = row + 1, c = col + 1; r <= 7 && c <= 7; ++r, ++c) {
        Piece piece = board.get_piece(r, c);
        if (piece == Piece::EMPTY) {
            moves.emplace_back(row, col, r, c);
        } else {
            if (is_bishop_white != is_white_piece(piece)) {
                moves.emplace_back(row, col, r, c);
            }
            break;
        }
    }

    return moves;
}

std::vector<Move> MoveGenerator::generate_queen_moves(int row, int col) const {
    std::vector<Move> moves;

    // Generate rook-like moves
    std::vector<Move> rook_moves = generate_rook_moves(row, col);
    moves.insert(moves.end(), rook_moves.begin(), rook_moves.end());

    // Generate bishop-like moves
    std::vector<Move> bishop_moves = generate_bishop_moves(row, col);
    moves.insert(moves.end(), bishop_moves.begin(), bishop_moves.end());

    return moves;
}

std::vector<Move> MoveGenerator::generate_king_moves(int row, int col) const {
    std::vector<Move> moves;
    Piece king = board.get_piece(row, col);
    bool is_king_white = is_white_piece(king);

    // Possible king moves relative to the current position
    const std::vector<std::pair<int, int>> king_moves = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    for (const auto& move : king_moves) {
        int new_row = row + move.first;
        int new_col = col + move.second;

        if (is_move_in_bounds(new_row, new_col)) {
            Piece piece = board.get_piece(new_row, new_col);
            if (piece == Piece::EMPTY || is_king_white != is_white_piece(piece)) {
                moves.emplace_back(row, col, new_row, new_col);
            }
        }
    }

    // TODO: This implementation does not handle castling. It needs to be added.
    // TODO: additional logic to handle castling if required.

    return moves;
}

// Helper methods for move validation

bool MoveGenerator::is_move_in_bounds(int row, int col) const {
    return row >= 0 && row <= 7 && col >= 0 && col <= 7;
}

bool MoveGenerator::is_move_blocked(const Move& move) const {
    return false;
}

bool MoveGenerator::is_move_capturing_own_piece(const Move& move) const {
    return false;
}

bool MoveGenerator::is_king_in_check_after_move(const Move& move) const {
    // Create a temporary copy of the board
    Board temp_board = board;

    // Execute the move on the temporary board
    // temp_board.execute_move(move);

    // Check if the player's king is in check on the temporary board
    bool is_white_turn = is_white_piece(board.get_piece(move.get_start_row(), move.get_start_col()));
    // return temp_board.is_king_in_check(is_white_turn);

    return false;  // Placeholder return
}

bool MoveGenerator::is_white_piece(Piece piece) const {
    return piece >= Piece::WHITE_PAWN && piece <= Piece::WHITE_KING;
}

bool MoveGenerator::is_black_piece(Piece piece) const {
    return piece >= Piece::BLACK_PAWN && piece <= Piece::BLACK_KING;
}
