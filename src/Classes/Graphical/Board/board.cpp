#include "board.hpp"

#include "./../../../include/main.hpp"
#include "./../Square/square.hpp"

Board::Board() {
    // Creates the board
    int i = 0;
    int j = 0;

    while (i < BOARD_SIZE) {
        j = 0;

        while (j < BOARD_SIZE) {
            if ((i + j) % 2 == 0) {
                this->squares[i][j] = new Square(i * SQUARE_SIZE, j * SQUARE_SIZE, SQUARE_SIZE, sf::Color::Black);
            } else {
                this->squares[i][j] = new Square(i * SQUARE_SIZE, j * SQUARE_SIZE, SQUARE_SIZE, sf::Color::White);
            }
            j++;
        }
        i++;
    }
}

Board::~Board() {}

void Board::draw(sf::RenderWindow& window) {
    // Iterates through the squares array to draw each square
    int i = 0;
    int j = 0;

    while (i < BOARD_SIZE) {
        j = 0;

        while (j < BOARD_SIZE) {
            this->squares[i][j]->draw(window);
            j++;
        }
        i++;
    }
}

Square* Board::getSquare(int x, int y) {
    // Iterates through the squares array to find the square at the given position
    // x and y are the coordinates of the square
    // Returns the square at the given position
    int i = 0;
    int j = 0;

    while (i < BOARD_SIZE) {
        j = 0;

        while (j < BOARD_SIZE) {
            if (this->squares[i][j]->getPosition().x == x && this->squares[i][j]->getPosition().y == y) {
                return this->squares[i][j];
            }
            j++;
        }
    }

    return nullptr;
}

void Board::setSquare(int x, int y, Square square) {
    // Iterates through the squares array to find the square at the given position
    // x and y are the coordinates of the square
    // Sets the square at the given position
    int i = 0;
    int j = 0;

    while (i < BOARD_SIZE) {
        j = 0;

        while (j < BOARD_SIZE) {
            if (this->squares[i][j]->getPosition().x == x && this->squares[i][j]->getPosition().y == y) {
                this->squares[i][j] = &square;
            }
            j++;
        }
    }
}
