#include "board.hpp"

#include "./../../../include/main.hpp"

Board::Board() {
    // Creates the board
    int i = 0;
    int j = 0;

    while (i < BOARD_SIZE) {
        j = 0;

        while (j < BOARD_SIZE) {
            if ((i + j) % 2 == 0) {
                if (i < 2) {
                    Piece *blackPawn = new Piece(sf::Vector2f(j * SQUARE_SIZE, i * SQUARE_SIZE), PieceType::PAWN, BLACK,
                                                 SQUARE_SIZE, PieceColor::BLACK_PIECE, j, i);
                    this->squares[i][j] =
                        new Square(j * SQUARE_SIZE, i * SQUARE_SIZE, SQUARE_SIZE, DARK_GRAY, blackPawn);
                } else if (i > 5) {
                    Piece *whitePawn = new Piece(sf::Vector2f(j * SQUARE_SIZE, i * SQUARE_SIZE), PieceType::PAWN, WHITE,
                                                 SQUARE_SIZE, PieceColor::WHITE_PIECE, j, i);
                    this->squares[i][j] =
                        new Square(j * SQUARE_SIZE, i * SQUARE_SIZE, SQUARE_SIZE, DARK_GRAY, whitePawn);
                } else {
                    Piece *emptyPiece = new Piece(sf::Vector2f(j * SQUARE_SIZE, i * SQUARE_SIZE), j, i);
                    this->squares[i][j] =
                        new Square(j * SQUARE_SIZE, i * SQUARE_SIZE, SQUARE_SIZE, DARK_GRAY, emptyPiece);
                }
            } else {
                if (i < 2) {
                    Piece *blackPawn = new Piece(sf::Vector2f(j * SQUARE_SIZE, i * SQUARE_SIZE), PieceType::PAWN, BLACK,
                                                 SQUARE_SIZE, PieceColor::BLACK_PIECE, j, i);
                    this->squares[i][j] =
                        new Square(j * SQUARE_SIZE, i * SQUARE_SIZE, SQUARE_SIZE, LIGHT_GRAY, blackPawn);
                } else if (i > 5) {
                    Piece *whitePawn = new Piece(sf::Vector2f(j * SQUARE_SIZE, i * SQUARE_SIZE), PieceType::PAWN, WHITE,
                                                 SQUARE_SIZE, PieceColor::WHITE_PIECE, j, i);
                    this->squares[i][j] =
                        new Square(j * SQUARE_SIZE, i * SQUARE_SIZE, SQUARE_SIZE, LIGHT_GRAY, whitePawn);
                } else {
                    Piece *emptyPiece = new Piece(sf::Vector2f(j * SQUARE_SIZE, i * SQUARE_SIZE), j, i);
                    this->squares[i][j] =
                        new Square(j * SQUARE_SIZE, i * SQUARE_SIZE, SQUARE_SIZE, LIGHT_GRAY, emptyPiece);
                }
            }
            j++;
        }
        i++;
    }

    // Creates the memory board
    this->memoryBoard = new PieceType *[BOARD_SIZE];

    i = 0;
    while (i < BOARD_SIZE) {
        this->memoryBoard[i] = new PieceType[BOARD_SIZE];
        i++;
    }

    // Sets the memory board
    i = 0;

    while (i < BOARD_SIZE) {
        j = 0;

        while (j < BOARD_SIZE) {
            this->memoryBoard[i][j] = PieceType::EMPTY;
            j++;
        }
        i++;
    }
}

Board::~Board() {
    // Deletes the board
    int i = 0;
    int j = 0;

    while (i < BOARD_SIZE) {
        j = 0;

        while (j < BOARD_SIZE) {
            delete this->squares[i][j];
            j++;
        }
        i++;
    }

    // Deletes the memory board
    i = 0;

    while (i < BOARD_SIZE) {
        delete[] this->memoryBoard[i];
        i++;
    }

    delete[] this->memoryBoard;
}

void Board::draw(sf::RenderWindow &window) {
    // Iterates through the squares array to draw each square
    int i = 0;
    int j = 0;

    while (i < BOARD_SIZE) {
        j = 0;

        while (j < BOARD_SIZE) {
            this->squares[i][j]->draw(window);
            this->squares[i][j]->getPiece()->draw(window);
            j++;
        }
        i++;
    }
}

Square *Board::getSquare(int x, int y) {
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

PieceType **Board::getMemoryBoard() { return this->memoryBoard; }

void Board::setMemoryBoard(PieceType **memoryBoard) { this->memoryBoard = memoryBoard; }

PieceType Board::getPiece(int x, int y) { return this->memoryBoard[x][y]; }

void Board::setPiece(int x, int y, PieceType piece) {
    this->memoryBoard[x][y] = piece;
    // TODO: Set the piece on the board (?)
    // this->squares[x][y]->setPiece(piece);
}
