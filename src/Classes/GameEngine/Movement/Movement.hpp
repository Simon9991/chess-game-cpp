// Class which take a class Piece and defines it's movement based on the Piece type (Pawn, Rook, Knight, Bishop, Queen,
// King) Path: src/Classes/GameEngine/Movement/Movement.cpp

#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

#include <SFML/Graphics.hpp>

#include "./../../../include/main.hpp"

class Movement {
   public:
    Movement(Piece *piece, PieceType **memoryBoard);
    ~Movement();
    // Get the possible moves of the piece
    std::vector<sf::Vector2f> getPossibleMoves();
    // Get the possible moves of the piece
    std::vector<sf::Vector2f> getPossibleMoves(sf::Vector2f position);
    // Get the possible moves of the piece
    std::vector<sf::Vector2f> getPossibleMoves(int x, int y);
    // Get the possible moves of the piece
    std::vector<sf::Vector2f> getPossibleMoves(int x, int y, sf::Vector2f position);
    // // Get the possible moves of the piece
    // std::vector<sf::Vector2f> getPossibleMoves(int x, int y, int x2, int y2);
    // // Get the possible moves of the piece
    // std::vector<sf::Vector2f> getPossibleMoves(int x, int y, int x2, int y2, sf::Vector2f position);
    // // Get the possible moves of the piece
    // std::vector<sf::Vector2f> getPossibleMoves(int x, int y, int x2, int y2, int x3, int y3);
    // // Get the possible moves of the piece
    // std::vector<sf::Vector2f> getPossibleMoves(int x, int y, int x2, int y2, int x3, int y3, sf::Vector2f position);
    // // Get the possible moves of the piece
    // std::vector<sf::Vector2f> getPossibleMoves(int x, int y, int x2, int y2, int x3, int y3, int x4, int y4);
    // // Get the possible moves of the piece
    // std::vector<sf::Vector2f> getPossibleMoves(int x, int y, int x2, int y2, int x3, int y3, int x4, int y4,
    // sf::Vector2f position);
    // // Get the possible moves of the piece
    // std::vector<sf::Vector2f> getPossibleMoves(int x, int y, int x2, int y2, int x3, int y3, int x4, int y4, int x5,
    // int y5);
    // // Get the possible moves of the piece
    // std::vector<sf::Vector2f> getPossibleMoves(int x, int y, int x2, int y2, int x3, int y3, int x4, int y4, int x5,
    // int y5, sf::Vector2f position);
    // // Get the possible moves of the piece
    // std::vector<sf::Vector2f> getPossibleMoves(int x, int y, int x2, int y2, int x3, int y3, int x4, int y4, int x5,
    // int y5, int x6, int y6);

   private:
    Piece *piece;
    std::vector<sf::Vector2f> possibleMoves;
    PieceType **memoryBoard;
};

#endif /* !MOVEMENT_HPP */