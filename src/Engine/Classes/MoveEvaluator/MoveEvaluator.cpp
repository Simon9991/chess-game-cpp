#include "MoveEvaluator.hpp"

// Constructor
MoveEvaluator::MoveEvaluator(const Board& board) : board(board) {}

// Evaluates the current position and returns a score
int MoveEvaluator::evaluate_position() const {
    // Combine scores from different evaluation functions
    int score = 0;
    score += material_balance();
    score += piece_activity();
    score += pawn_structure();
    score += king_safety();
    score += king_tropism();

    // Add scores from additional evaluation functions here, if any

    return score;
}

// Evaluates the material balance on the board
int MoveEvaluator::material_balance() const {
    // Assign material values to pieces
    // Values can be changed to improve the evaluation function
    // https://en.wikipedia.org/wiki/Chess_piece_relative_value
    // https://www.chessprogramming.org/Simplified_Evaluation_Function
    // Possible improvement: add a bonus for having a bishop pair (especially in the endgame)
    // Possible improvement: add a bonus for having a rook on an open file
    // Possible improvement: add a bonus for having a rook on the 7th rank
    // Possible improvement: add a bonus for having a queen on an open file
    // Possible improvement: add a bonus for having a queen on the 7th rank

    // Possible change: values can be inside a .ini file which can be changed by the user or by the engine itself
    // (machine learning)
    const int pawn_value = 100;
    const int knight_value = 300;
    const int bishop_value = 300;
    const int rook_value = 500;
    const int queen_value = 900;

    int white_material = 0;
    int black_material = 0;

    // Iterate through the board and sum up material values
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            Piece piece = board.get_piece(row, col);

            // Add or subtract material value based on the piece's color and type
            if (piece != Piece::EMPTY) {
                int value = 0;
                switch (piece) {
                    case Piece::WHITE_PAWN:
                    case Piece::BLACK_PAWN:
                        value = pawn_value;
                        break;
                    case Piece::WHITE_KNIGHT:
                    case Piece::BLACK_KNIGHT:
                        value = knight_value;
                        break;
                    case Piece::WHITE_BISHOP:
                    case Piece::BLACK_BISHOP:
                        value = bishop_value;
                        break;
                    case Piece::WHITE_ROOK:
                    case Piece::BLACK_ROOK:
                        value = rook_value;
                        break;
                    case Piece::WHITE_QUEEN:
                    case Piece::BLACK_QUEEN:
                        value = queen_value;
                        break;
                    default:
                        break;
                }

                if (is_white_piece(piece)) {
                    white_material += value;
                } else {
                    black_material -= value;
                }
            }
        }
    }

    return white_material + black_material;
}

// Evaluates piece activity (a very basic example)
int MoveEvaluator::piece_activity() const {
    // For this basic example, we'll just count the number of legal moves for each side.
    // A more sophisticated evaluation would consider factors like piece mobility, piece placement, etc.
    MoveGenerator move_gen(board);
    std::vector<Move> white_moves = move_gen.generate_moves(true);
    std::vector<Move> black_moves = move_gen.generate_moves(false);

    return static_cast<int>(white_moves.size() - black_moves.size());
}

// Evaluates pawn structure (not implemented in this basic example)
int MoveEvaluator::pawn_structure() const {
    // A more sophisticated evaluation would consider factors like pawn chains, doubled pawns, etc.
    // For this basic example, we'll return 0 (no evaluation)

    // Checking if there are doubled pawns
    int white_doubled_pawns = 0;
    int black_doubled_pawns = 0;

    for (int col = 0; col < BOARD_SIZE; ++col) {
        int white_pawns_in_col = 0;
        int black_pawns_in_col = 0;

        for (int row = 0; row < BOARD_SIZE; ++row) {
            Piece piece = board.get_piece(row, col);

            if (piece == Piece::WHITE_PAWN) {
                ++white_pawns_in_col;
            } else if (piece == Piece::BLACK_PAWN) {
                ++black_pawns_in_col;
            }
        }

        if (white_pawns_in_col > 1) {
            white_doubled_pawns += white_pawns_in_col;
        }

        if (black_pawns_in_col > 1) {
            black_doubled_pawns += black_pawns_in_col;
        }
    }

    // Checking if there are isolated pawns
    int white_isolated_pawns = 0;
    int black_isolated_pawns = 0;

    for (int col = 0; col < BOARD_SIZE; ++col) {
        int white_pawns_in_col = 0;
        int black_pawns_in_col = 0;

        for (int row = 0; row < BOARD_SIZE; ++row) {
            Piece piece = board.get_piece(row, col);

            if (piece == Piece::WHITE_PAWN) {
                ++white_pawns_in_col;
            } else if (piece == Piece::BLACK_PAWN) {
                ++black_pawns_in_col;
            }
        }

        if (white_pawns_in_col > 1) {
            bool is_isolated = true;

            // Checking the right column
            if (col + 1 < BOARD_SIZE) {
                for (int row = 0; row < BOARD_SIZE; ++row) {
                    Piece piece = board.get_piece(row, col + 1);

                    if (piece == Piece::WHITE_PAWN) {
                        is_isolated = false;
                    }
                }
            }

            // Checking the left column
            if (col - 1 >= 0) {
                for (int row = 0; row < BOARD_SIZE; ++row) {
                    Piece piece = board.get_piece(row, col - 1);

                    if (piece == Piece::WHITE_PAWN) {
                        is_isolated = false;
                    }
                }
            }

            if (is_isolated) {
                ++white_isolated_pawns;
            }
        }

        if (black_pawns_in_col > 1) {
            bool is_isolated = true;

            // Checking the right column
            if (col + 1 < BOARD_SIZE) {
                for (int row = 0; row < BOARD_SIZE; ++row) {
                    Piece piece = board.get_piece(row, col + 1);

                    if (piece == Piece::BLACK_PAWN) {
                        is_isolated = false;
                    }
                }
            }

            // Checking the left column
            if (col - 1 >= 0) {
                for (int row = 0; row < BOARD_SIZE; ++row) {
                    Piece piece = board.get_piece(row, col - 1);

                    if (piece == Piece::BLACK_PAWN) {
                        is_isolated = false;
                    }
                }
            }

            if (is_isolated) {
                ++black_isolated_pawns;
            }
        }
    }

    // Checking if pawn is passed
    int white_passed_pawns = 0;
    int black_passed_pawns = 0;

    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            Piece piece = board.get_piece(row, col);

            if (piece == Piece::WHITE_PAWN || piece == Piece::BLACK_PAWN) {
                bool is_passed = true;

                for (int other_row = row - 1; other_row >= 0; --other_row) {
                    for (int other_col = std::max(col - 1, 0); other_col <= std::min(col + 1, BOARD_SIZE - 1); ++other_col) {
                        Piece other_piece = board.get_piece(other_row, other_col);

                        if (piece == Piece::WHITE_PAWN && other_piece == Piece::BLACK_PAWN) {
                            is_passed = false;
                            break;
                        } else if (piece == Piece::BLACK_PAWN && other_piece == Piece::WHITE_PAWN) {
                            is_passed = false;
                            break;
                        }
                    }

                    if (!is_passed) {
                        break;
                    }
                }

                if (is_passed) {
                    if (piece == Piece::WHITE_PAWN) {
                        ++white_passed_pawns;
                    } else {
                        ++black_passed_pawns;
                    }
                }
            }
        }
    }

    // Checking pawn chains
    int white_chains = 0;
    int black_chains = 0;

    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            Piece piece = board.get_piece(row, col);

            if (piece == Piece::WHITE_PAWN) {
                if ((col - 1 >= 0 && board.get_piece(row - 1, col - 1) == Piece::WHITE_PAWN) ||
                    (col + 1 < BOARD_SIZE && board.get_piece(row - 1, col + 1) == Piece::WHITE_PAWN)) {
                    ++white_chains;
                }
            } else if (piece == Piece::BLACK_PAWN) {
                if ((col - 1 >= 0 && board.get_piece(row + 1, col - 1) == Piece::BLACK_PAWN) ||
                    (col + 1 < BOARD_SIZE && board.get_piece(row + 1, col + 1) == Piece::BLACK_PAWN)) {
                    ++black_chains;
                }
            }
        }
    }

    // Computing the score
    int white_score = 0;
    int black_score = 0;

    white_score -= white_doubled_pawns * 10;
    black_score -= black_doubled_pawns * 10;

    white_score -= white_isolated_pawns * 10;
    black_score -= black_isolated_pawns * 10;

    white_score += white_passed_pawns * 20;
    black_score += black_passed_pawns * 20;

    white_score += white_chains * 5;
    black_score += black_chains * 5;

    return white_score + black_score;
}

// Evaluates king safety (not implemented in this basic example)
int MoveEvaluator::king_safety() const {
    // Define king safety score matrix for opening/middlegame
    constexpr int king_safety_matrix[BOARD_SIZE][BOARD_SIZE] = {
        {5, 5, 4, 3, 3, 3, 5, 5},
        {4, 3, 3, 3, 3, 3, 3, 4},
        {2, 2, 2, 2, 2, 2, 2, 2},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {2, 2, 2, 2, 2, 2, 2, 2},
        {4, 3, 3, 3, 3, 3, 3, 4},
        {5, 5, 4, 3, 3, 3, 5, 5},
    };

    // Find the kings' positions
    int white_king_row = 0;
    int white_king_col = 0;
    int black_king_row = 0;
    int black_king_col = 0;

    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            Piece piece = board.get_piece(row, col);

            if (piece == Piece::WHITE_KING) {
                white_king_row = row;
                white_king_col = col;
            } else if (piece == Piece::BLACK_KING) {
                black_king_row = row;
                black_king_col = col;
            }
        }
    }

    // Calculate the king safety scores based on the matrix
    int white_score = king_safety_matrix[white_king_row][white_king_col];
    int black_score = king_safety_matrix[black_king_row][black_king_col];

    return white_score - black_score;
}

int MoveEvaluator::king_tropism() const {
    int white_king_row = -1;
    int white_king_col = -1;
    int black_king_row = -1;
    int black_king_col = -1;

    // Locate kings
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            Piece piece = board.get_piece(row, col);
            if (piece == Piece::WHITE_KING) {
                white_king_row = row;
                white_king_col = col;
            } else if (piece == Piece::BLACK_KING) {
                black_king_row = row;
                black_king_col = col;
            }
        }
    }

    int white_tropism = 0;
    int black_tropism = 0;

    // Calculate tropism
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            Piece piece = board.get_piece(row, col);
            if (piece != Piece::EMPTY && piece != Piece::WHITE_KING && piece != Piece::BLACK_KING) {
                int distance_to_white_king = std::abs(row - white_king_row) + std::abs(col - white_king_col);
                int distance_to_black_king = std::abs(row - black_king_row) + std::abs(col - black_king_col);

                if (is_white_piece(piece)) {
                    white_tropism += 10 * (BOARD_SIZE - distance_to_black_king);
                } else {
                    black_tropism += 10 * (BOARD_SIZE - distance_to_white_king);
                }
            }
        }
    }

    return white_tropism - black_tropism;
}
