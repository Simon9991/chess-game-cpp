#ifndef MOVEGENERATOR_HPP
#define MOVEGENERATOR_HPP

#include "./../../include/main.hpp"

#include <vector>

class MoveGenerator {
public:
    // Generates all legal moves for the specified color in the given board position
    static std::vector<Move> generateLegalMoves(const EngineMemoryBoard& board, PieceColor color);

private:
    // Generates legal moves for pawns
    static void generatePawnMoves(const EngineMemoryBoard& board, int sourceSquare, std::vector<Move>& moves, PieceColor color);

    // Generates legal moves for knights
    static void generateKnightMoves(const EngineMemoryBoard& board, int sourceSquare, std::vector<Move>& moves);

    // Generates legal moves for bishops
    static void generateBishopMoves(const EngineMemoryBoard& board, int sourceSquare, std::vector<Move>& moves);

    // Generates legal moves for rooks
    static void generateRookMoves(const EngineMemoryBoard& board, int sourceSquare, std::vector<Move>& moves);

    // Generates legal moves for queens
    static void generateQueenMoves(const EngineMemoryBoard& board, int sourceSquare, std::vector<Move>& moves);

    // Generates legal moves for kings
    static void generateKingMoves(const EngineMemoryBoard& board, int sourceSquare, std::vector<Move>& moves);
};

#endif
