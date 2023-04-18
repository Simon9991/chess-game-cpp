#ifndef MOUSE_INPUT_HPP
#define MOUSE_INPUT_HPP

#include "./../../../include/main.hpp"

class Board;
class Piece;

class MouseInput {
   public:
    // Constructor
    MouseInput();
    // Destructor
    ~MouseInput();
    // Get the position of the mouse
    sf::Vector2i getPosition(sf::RenderWindow &window);
    // Get the relative position of the mouse click
    sf::Vector2i getRelativePositionClick();
    // Get the position of the mouse click
    sf::Vector2f getPositionClick();
    // Get if the mouse is clicked
    bool isClicked(sf::RenderWindow &window);
    // Check if we clicked on a piece in the board
    Piece *isClickedOnPiece(sf::RenderWindow &window, Board *board);

   private:
    // Position of the mouse
    sf::Vector2i position;
    // Position of the mouse click
    sf::Vector2i positionClick;
    // If the mouse is clicked
    bool clicked;
    // Visual board
    Board *board;
};

#endif /* !MOUSE_INPUT_HPP */
