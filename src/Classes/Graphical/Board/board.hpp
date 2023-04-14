// Class Board, a chess board is made of 64 squares
#ifndef BOARD_HPP
#define BOARD_HPP

#include "./../../../include/main.hpp"

class Square;

class Board {
   public:
    // TODO: Loading board from a text or FEN file
    Board(std::string fen = nullptr);
    // Destructor
    ~Board();
    // Initialize the board without a FEN file
    void initBoard();
    // Initialize the board with a FEN file
    void initBoard(std::string fen);
    // Draw the board
    void draw(sf::RenderWindow &window);
    // Get the square at the given position
    Square *getSquare(int x, int y);
    // Set the square at the given position
    void setSquare(int x, int y, Square square);
    // Get the memory board
    PieceType **getMemoryBoard();
    // Set the memory board
    void setMemoryBoard(PieceType **memoryBoard);
    // Get the piece at the given position
    PieceType getPiece(int x, int y);
    // Set the piece at the given position
    void setPiece(int x, int y, PieceType piece);

   private:
    // Array of squares
    Square *squares[BOARD_SIZE][BOARD_SIZE];
    // Memory board
    PieceType **memoryBoard;
};

#endif /* !BOARD_HPP */
