// Class Board, a chess board is made of 64 squares
#ifndef BOARD_HPP
#define BOARD_HPP

#include "./../../../include/main.hpp"

class Square;
class Piece;

class Board {
   public:
    // Loading board from a FEN file
    Board(std::string fen);
    // Destructor
    ~Board();
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
    // Get the memory board pointer
    PieceType ***getMemoryBoardPointer();
    // Set the memory board
    void setMemoryBoard(PieceType **memoryBoard);
    // Get the piece type at the given position from the memory board
    PieceType getPieceType(int x, int y);
    // Set the piece at the given position
    void setPiece(int x, int y, PieceType piece);
    // Get the piece at the given position from the memory board
    Piece *getPiece(int x, int y);
    // Moving a piece from a position to another in the memory board
    void movePiece(Piece *piece, sf::Vector2f position);
    // Get the relative square
    Square *getRelativeSquare(sf::Vector2i position);
    // Resets the possible moves
    void resetPossibleMoves();
    // Prints the memory board
    void printMemoryBoard();
    // Sets the squares Piece pointer to their new values based on the memory board
    void updateSquares();

   private:
    // Array of squares
    Square *squares[BOARD_SIZE][BOARD_SIZE];
    // Memory board
    PieceType **memoryBoard;
};

#endif /* !BOARD_HPP */
