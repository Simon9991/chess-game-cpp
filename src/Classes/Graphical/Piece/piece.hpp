#ifndef PIECE_HPP
#define PIECE_HPP

#include <SFML/Graphics.hpp>

#include "./../../../include/main.hpp"

class Piece {
   public:
    Piece(sf::Vector2f position, Pieces type, sf::Color color, int size);
    ~Piece();
    // Get the position of the piece
    sf::Vector2f getPosition();
    // Get the x position of the piece
    int getX();
    // Get the y position of the piece
    int getY();
    // Get the type of the piece
    Pieces getType();
    // Get the color of the piece
    sf::Color getColor();
    // Set the position of the piece
    void setPosition(sf::Vector2f position);
    // Draw the piece
    void draw(sf::RenderWindow &window);

   private:
    sf::Vector2f position;
    int x;
    int y;
    Pieces type;
    sf::Color color;
    sf::CircleShape shape;
    int size;
    // To add later: movement, etc.
};

#endif /* !PIECE_HPP */