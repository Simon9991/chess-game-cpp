#include "Search.hpp"

#include <limits>

Search::Search(const Board& board, const MoveEvaluator& move_evaluator, int search_depth)
    : board(board), move_evaluator(move_evaluator), search_depth(search_depth) {}

Move Search::find_best_move(bool is_white_turn) {
    int best_score = is_white_turn ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();
    Move best_move;
    MoveGenerator move_gen(board);

    // Generate all legal moves for the current position
    std::vector<Move> legal_moves = move_gen.generate_moves(is_white_turn);

    // Iterate through legal moves and evaluate them
    for (const Move& move : legal_moves) {
        Board temp_board = board;
        temp_board.execute_move(move);

        // Call minimax search algorithm
        int score =
            minimax(search_depth - 1, !is_white_turn, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

        // Update best move and best score
        if (is_white_turn && score > best_score) {
            best_score = score;
            best_move = move;
        } else if (!is_white_turn && score < best_score) {
            best_score = score;
            best_move = move;
        }
    }

    return best_move;
}

void Search::print_best_move(bool is_white_turn) {
    Move best_move = this->find_best_move(is_white_turn);

    // Convert move coordinates to chess notation
    char start_col = 'a' + best_move.get_start_col();
    int start_row = 8 - best_move.get_start_row();
    char end_col = 'a' + best_move.get_end_col();
    int end_row = 8 - best_move.get_end_row();

    std::cout << "Best move: " << start_col << start_row << " -> " << end_col << end_row << std::endl;
}

int Search::minimax(int depth, bool is_white_turn, int alpha, int beta) {
    if (depth == 0) {
        return move_evaluator.evaluate_position();
    }

    MoveGenerator move_gen(board);

    std::vector<Move> legal_moves = move_gen.generate_moves(is_white_turn);

    if (is_white_turn) {
        int best_score = std::numeric_limits<int>::min();
        for (const Move& move : legal_moves) {
            Board temp_board = board;
            temp_board.execute_move(move);
            int score = minimax(depth - 1, !is_white_turn, alpha, beta);

            std::cout << "Score for move: ";
            move.print_move();
            std::cout << " is: " << score << std::endl;

            best_score = std::max(best_score, score);
            alpha = std::max(alpha, best_score);
            if (beta <= alpha) {
                break;  // Alpha-beta pruning
            }
        }
        return best_score;
    } else {
        int best_score = std::numeric_limits<int>::max();
        for (const Move& move : legal_moves) {
            Board temp_board = board;
            temp_board.execute_move(move);
            int score = minimax(depth - 1, !is_white_turn, alpha, beta);
            best_score = std::min(best_score, score);
            beta = std::min(beta, best_score);
            if (beta <= alpha) {
                break;  // Alpha-beta pruning
            }
        }
        return best_score;
    }
}
