// Class Board, a chess board is made of 64 squares
#ifndef BOARD_HPP
#define BOARD_HPP

#include <SFML/Graphics.hpp>

#include "./../Square/square.hpp"

class Board {
   public:
    // Constructor
    Board();
    // Destructor
    ~Board();
    // Draw the board
    void draw(sf::RenderWindow &window);
    // Get the square at the given position
    Square *getSquare(int x, int y);
    // Set the square at the given position
    void setSquare(int x, int y, Square square);

   private:
    // Array of squares
    Square *squares[8][8];
};

#endif /* !BOARD_HPP */