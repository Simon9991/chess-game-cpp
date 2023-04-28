#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <memory>

#include "./../../include/main.hpp"

class Search {
   public:
    // Constructor
    Search(const Board& board, const MoveEvaluator& move_evaluator, int search_depth);

    // Finds the best move for the current position
    Move find_best_move(bool is_white_turn);

    void print_best_move(bool is_white_turn);

   private:
    // Minimax search algorithm with alpha-beta pruning
    int minimax(int depth, bool is_white_turn, int alpha, int beta);

    // Reference to the board object
    const Board& board;

    // Reference to the move evaluator object
    const MoveEvaluator& move_evaluator;

    // Search depth
    int search_depth;
};

#endif  // SEARCH_HPP
