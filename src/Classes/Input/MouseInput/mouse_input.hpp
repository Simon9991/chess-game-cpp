#ifndef MOUSE_INPUT_HPP
#define MOUSE_INPUT_HPP

#include "./../../../include/main.hpp"

class Board;

class MouseInput {
   public:
    // Constructor
    MouseInput();
    // Destructor
    ~MouseInput();
    // Get the position of the mouse
    sf::Vector2i getPosition(sf::RenderWindow &window);
    // // Get the position of the mouse
    // sf::Vector2f getPositionF(sf::RenderWindow &window);
    // // Get the position of the mouse
    // sf::Vector2f getPositionF(sf::RenderWindow &window, sf::View &view);
    // // Get the position of the mouse
    // sf::Vector2i getPosition(sf::RenderWindow &window, sf::View &view);
    // // Get the position of the mouse
    // sf::Vector2f getPositionF(sf::RenderWindow &window, sf::View &view, sf::Vector2f offset);
    // // Get the position of the mouse
    // sf::Vector2i getPosition(sf::RenderWindow &window, sf::View &view, sf::Vector2f offset);
    // // Get the position of the mouse
    // sf::Vector2f getPositionF(sf::RenderWindow &window, sf::View &view, sf::Vector2f offset, sf::Vector2f scale);
    // // Get the position of the mouse
    // sf::Vector2i getPosition(sf::RenderWindow &window, sf::View &view, sf::Vector2f offset, sf::Vector2f scale);
    // // Get the position of the mouse
    // sf::Vector2f getPositionF(sf::RenderWindow &window, sf::View &view, sf::Vector2f offset, sf::Vector2f scale,
    // sf::Vector2f origin);
    // // Get the position of the mouse
    // sf::Vector2i getPosition(sf::RenderWindow &window, sf::View &view, sf::Vector2f offset, sf::Vector2f scale,
    // sf::Vector2f origin);
    // // Get the position of the mouse
    // sf::Vector2f getPositionF(sf::RenderWindow &window, sf::View &view, sf::Vector2f offset, sf::Vector2f scale,
    // sf::Vector2f origin, sf::Vector2f size);
    // // Get the position of the mouse
    // sf::Vector2i getPosition(sf::RenderWindow &window, sf::View &view, sf::Vector2f offset, sf::Vector2f scale,
    // sf::Vector2f origin, sf::Vector2f size);
    // // Get the position of the mouse
    // sf::Vector2f getPositionF(sf::RenderWindow &window, sf::View &view, sf::Vector2f offset, sf::Vector2f scale,
    // sf::Vector2f origin, sf::Vector2f size, sf::Vector2f scaleOrigin); Get the position of the mouse click
    sf::Vector2i getPositionClick(sf::RenderWindow &window);
    // Get if the mouse is clicked
    bool isClicked(sf::RenderWindow &window);

    // Check if we clicked on a piece in the board
    bool isClickedOnPiece(sf::RenderWindow &window, Board *board);

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
