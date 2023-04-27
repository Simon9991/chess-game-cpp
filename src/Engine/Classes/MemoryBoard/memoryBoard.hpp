// Class Board, a chess board is made of 64 squares
#ifndef ENGINE_MEMORYBOARD_HPP
#define ENGINE_MEMORYBOARD_HPP

#include "./../../../include/main.hpp"

class EngineMemoryBoard
{
    public:
        EngineMemoryBoard(std::string fen);
        ~EngineMemoryBoard();
    private:
        PieceType **memoryBoard;
        PieceColor playerTurn;
        void initBoard(std::string fen);
};

#endif /* !ENGINE_MEMORYBOARD_HPP */
