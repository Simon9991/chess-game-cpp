// Class Board, a chess board is made of 64 squares
#ifndef ENGINE_MEMORYBOARD_HPP
#define ENGINE_MEMORYBOARD_HPP

#include "./../../include/main.hpp"

class EngineMemoryBoard {
   public:
    // Loading board from a FEN file
    EngineMemoryBoard(std::string fen);
    // Destructor
    ~EngineMemoryBoard();
    // Get the memory board
    void printMemoryBoard() const;
    // TODO: Add: update the position, and retrieve information about the position, such as piece locations and legality of moves
    // Update the board position
    void updatePosition(PieceType **position);
    // Check if a move is legal
    bool isLegalMove(int sourceSquare, int destinationSquare) const;

   private:
    PieceType** memoryBoard;
    PieceColor playerTurn;
    // Initialize the board with a FEN file
    void initBoard(std::string fen);
    // Checks if a square is within the board bounds
    bool isWithinBounds(int square) const;

};

#endif /* !ENGINE_MEMORYBOARD_HPP */
