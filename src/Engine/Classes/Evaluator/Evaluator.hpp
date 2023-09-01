#ifndef ENGINE_EVALUATOR_HPP
#define ENGINE_EVALUATOR_HPP

#include "./../MemoryBoard/EngineBoard.hpp"

class Engine {
   public:
    Board* board;

    Engine(Board* b) : board(b) {}

    int evaluateBoard() { return board->evaluate(); }

    int minimax(int depth, bool isMaximizing, int alpha, int beta);

    Move findBestMove(int depth);
};

#endif  // ENGINE_EVALUATOR_HPP