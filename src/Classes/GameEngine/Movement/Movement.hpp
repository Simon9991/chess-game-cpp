// Class which take a class Piece and defines it's movement based on the Piece type (Pawn, Rook, Knight, Bishop, Queen,
// King) Path: src/Classes/GameEngine/Movement/Movement.cpp

#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

#include <SFML/Graphics.hpp>

#include "./../../../include/main.hpp"

class Piece;

class Movement {
   public:
    Movement(PieceType **memoryBoard);
    ~Movement();
    // Get the possible moves of the piece
    std::vector<sf::Vector2f> getPossibleMoves(Piece *piece);

   private:
    PieceType **memoryBoard;
};

#endif /* !MOVEMENT_HPP */
