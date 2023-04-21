// Class which take a class Piece and defines it's movement based on the Piece type (Pawn, Rook, Knight, Bishop, Queen,
// King) Path: src/Classes/GameEngine/Movement/Movement.cpp

#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

#include <SFML/Graphics.hpp>

#include "./../../../include/main.hpp"

class Piece;
class Board;

class Movement {
   public:
    Movement(PieceType **memoryBoard, Board *board);
    ~Movement();
    // Get the possible moves of the piece
    std::vector<sf::Vector2f> getPossibleMoves(Piece *piece);
    // Moves the piece to the given relative position (memory position)
    void movePiece(Piece *piece, sf::Vector2i relativePosition);
    // Updates the memory board
    void updateMemoryBoard(PieceType **memoryBoard);
    // Get piece at relative position
    Piece *getPieceAtPosition(int x, int y);

   private:
    PieceType **memoryBoard;
    Board *board;
};

#endif /* !MOVEMENT_HPP */
