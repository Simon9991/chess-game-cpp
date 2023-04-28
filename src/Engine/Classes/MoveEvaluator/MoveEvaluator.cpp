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

    // Possible change: values can be inside a .ini file which can be changed by the user or by the engine itself (machine learning)
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
    return 0;
}

// Evaluates king safety (not implemented in this basic example)
int MoveEvaluator::king_safety() const {
    // A more sophisticated evaluation would consider factors like king shelter, king exposure, etc.
    // For this basic example, we'll return 0 (no evaluation)
    return 0;
}
