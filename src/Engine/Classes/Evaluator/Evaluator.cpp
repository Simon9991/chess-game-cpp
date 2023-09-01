#include "Evaluator.hpp"

int Engine::minimax(int depth, bool isMaximizing, int alpha, int beta) {
    if (depth == 0) {
        return board.evaluate();
    }

    // Generate all legal moves for the current position
    std::vector<Move> moves = board.generateLegalMoves();

    if (isMaximizing) {
        int maxEval = INT_MIN;
        for (Move move : moves) {
            board.makeMove(move);
            int eval = minimax(board, depth - 1, false, alpha, beta);
            board.undoMove(move);
            maxEval = std::max(maxEval, eval);
            alpha = std::max(alpha, eval);
            if (beta <= alpha) {
                break;  // Alpha-beta pruning
            }
        }
        return maxEval;
    } else {
        int minEval = INT_MAX;
        for (Move move : moves) {
            Move madeMove = board.makeMove(move);
            int eval = minimax(board, depth - 1, true, alpha, beta);
            board.undoMove(madeMove);
            minEval = std::min(minEval, eval);
            beta = std::min(beta, eval);
            if (beta <= alpha) {
                break;  // Alpha-beta pruning
            }
        }
        return minEval;
    }
}

Move Engine::findBestMove(int depth) {
    int bestValue = INT_MIN;
    Move bestMove;
    std::vector<Move> moves = board.generateLegalMoves();

    for (Move move : moves) {
        board.makeMove(move);
        int moveValue = minimax(board, depth - 1, false, INT_MIN, INT_MAX);
        board.undoMove(move);
        if (moveValue > bestValue) {
            bestValue = moveValue;
            bestMove = move;
        }
    }

    return bestMove;
}
