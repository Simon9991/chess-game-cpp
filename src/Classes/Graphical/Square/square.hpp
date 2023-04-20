// SFML class which represents a 2D square
#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "./../../../include/main.hpp"

class Piece;

class Square {
   public:
    // Constructor
    Square(int x, int y, int size, sf::Color color, Piece *piece);
    // Destructor
    ~Square();
    // Draw the square
    void draw(sf::RenderWindow &window);
    // Get the position of the square
    sf::Vector2f getPosition();
    // Get the relative position of the square
    sf::Vector2i getRelativePosition();
    // Get the size of the square
    int getSize();
    // Get the color of the square
    sf::Color getColor();
    // Set the position of the square
    void setPosition(sf::Vector2f position);
    // Set the size of the square
    void setSize(int size);
    // Set the color of the square
    void setColor(sf::Color color);
    // Returns the piece on the square
    Piece *getPiece();
    // Set the piece on the square
    void setPiece(Piece *piece);
    // Get if it is possible to move to this square
    bool isPossibleMove();
    // Set if it is possible to move to this square
    void setPossibleMove(bool possibleMove);

   private:
    // Position of the square
    sf::Vector2f position;
    // Size of the square
    int size;
    // Color of the square
    sf::Color color;
    // SFML shape of the square
    sf::RectangleShape shape;
    // Piece on the square
    Piece *piece;
    // Is possible to move to this square
    bool possibleMove;
};

#endif /* !SQUARE_HPP */
