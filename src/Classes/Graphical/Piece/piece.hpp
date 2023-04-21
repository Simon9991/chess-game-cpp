#ifndef PIECE_HPP
#define PIECE_HPP

#include "./../../../include/main.hpp"

class Image;

class Piece {
   public:
    // Empty Piece
    Piece(sf::Vector2f position, int x, int y);
    Piece(sf::Vector2f position, PieceType type, sf::Color color, int size, PieceColor pieceColor, int x, int y);
    ~Piece();
    // Get the position of the piece
    sf::Vector2f getPosition();
    // Get the position of the piece in the memory board
    sf::Vector2i getMemoryPosition();
    // Get the x position of the piece
    int getX();
    // Get the y position of the piece
    int getY();
    // Get the type of the piece
    PieceType getType();
    // Get the color of the piece
    sf::Color getColor();
    // Set the position of the piece
    void setPosition(sf::Vector2f position, int x, int y);
    // Draw the piece
    void draw(sf::RenderWindow &window);
    // Get the piece color
    PieceColor getPieceColor();
    // Getting the PieceType
    PieceType getPieceType();
    // Getting the Image
    Image *getImage();
    // Get the opposite color
    PieceColor getOppositeColor();
    // Get if it is the first move
    bool getIsFirstMove();
    // Set if it is the first move
    void setIsFirstMove(bool isFirstMove);

   private:
    sf::Vector2f position;
    int x;
    int y;
    PieceType type;
    sf::Color color;
    sf::CircleShape shape;
    int size;
    PieceColor pieceColor;
    // To add later: movement, Sprite etc.
    Image *image;
    bool isFirstMove;
};

#endif /* !PIECE_HPP */
