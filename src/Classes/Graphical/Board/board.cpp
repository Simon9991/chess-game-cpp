#include "board.hpp"

#include "./../../../include/main.hpp"

Board::Board(std::string fen) {
    int i = 0;
    int j = 0;

    this->memoryBoard = new PieceType *[BOARD_SIZE];
    while (i < BOARD_SIZE) {
        this->memoryBoard[i] = new PieceType[BOARD_SIZE];
        j = 0;

        while (j < BOARD_SIZE) {
            this->memoryBoard[i][j] = EMPTY;
            j++;
        }
        i++;
    }

    this->playerTurn = PieceColor::WHITE_PIECE;  // Can be changed later to be more flexible

    this->initBoard(fen);
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

void Board::initBoard(std::string fen) {
    // Initializes the board with the given FEN string
    // fen is the FEN string
    size_t i = 0;
    int j = 0;
    int k = 0;

    // Setting up the memeryBoard fist
    // TODO: Change to a switch case
    // TODO: Add FEN validation
    while (i < fen.length()) {
        if (fen[i] == '/') {
            j++;
            k = 0;
        } else if (fen[i] == ' ') {
            break;
        } else if (fen[i] >= '1' && fen[i] <= '8') {
            k += fen[i] - '0';
        } else {
            if (fen[i] == 'p') {
                this->memoryBoard[j][k] = PieceType::BLACK_PAWN;
            } else if (fen[i] == 'P') {
                this->memoryBoard[j][k] = PieceType::WHITE_PAWN;
            } else if (fen[i] == 'n') {
                this->memoryBoard[j][k] = PieceType::BLACK_KNIGHT;
            } else if (fen[i] == 'N') {
                this->memoryBoard[j][k] = PieceType::WHITE_KNIGHT;
            } else if (fen[i] == 'b') {
                this->memoryBoard[j][k] = PieceType::BLACK_BISHOP;
            } else if (fen[i] == 'B') {
                this->memoryBoard[j][k] = PieceType::WHITE_BISHOP;
            } else if (fen[i] == 'r') {
                this->memoryBoard[j][k] = PieceType::BLACK_ROOK;
            } else if (fen[i] == 'R') {
                this->memoryBoard[j][k] = PieceType::WHITE_ROOK;
            } else if (fen[i] == 'q') {
                this->memoryBoard[j][k] = PieceType::BLACK_QUEEN;
            } else if (fen[i] == 'Q') {
                this->memoryBoard[j][k] = PieceType::WHITE_QUEEN;
            } else if (fen[i] == 'k') {
                this->memoryBoard[j][k] = PieceType::BLACK_KING;
            } else if (fen[i] == 'K') {
                this->memoryBoard[j][k] = PieceType::WHITE_KING;
            }
            k++;
        }
        i++;
    }

    // Printing the memory board
    if (DEBUG) {
        std::cout << "Memory board:" << std::endl;
        i = 0;
        while (i < BOARD_SIZE) {
            j = 0;
            while (j < BOARD_SIZE) {
                std::cout << this->memoryBoard[i][j] << " ";
                j++;
            }
            std::cout << std::endl;
            i++;
        }
    }

    // Based on the memory board, we set the board
    i = 0;
    while (i < BOARD_SIZE) {
        j = 0;
        while (j < BOARD_SIZE) {
            bool isWhite = false;
            isWhite = (i + j) % 2 == 0 ? true : false;
            if (this->memoryBoard[i][j] != PieceType::EMPTY) {
                if (this->memoryBoard[i][j] == PieceType::BLACK_PAWN) {
                    Piece *blackPawn = new Piece(sf::Vector2f(j * SQUARE_SIZE, i * SQUARE_SIZE), PieceType::BLACK_PAWN,
                                                 BLACK, PIECE_SIZE, PieceColor::BLACK_PIECE, j, i);
                    this->squares[i][j] = new Square(j * SQUARE_SIZE, i * SQUARE_SIZE, SQUARE_SIZE,
                                                     isWhite == true ? LIGHT_GRAY : DARK_GRAY, blackPawn);
                } else if (this->memoryBoard[i][j] == PieceType::WHITE_PAWN) {
                    Piece *whitePawn = new Piece(sf::Vector2f(j * SQUARE_SIZE, i * SQUARE_SIZE), PieceType::WHITE_PAWN,
                                                 WHITE, PIECE_SIZE, PieceColor::WHITE_PIECE, j, i);
                    this->squares[i][j] = new Square(j * SQUARE_SIZE, i * SQUARE_SIZE, SQUARE_SIZE,
                                                     isWhite == true ? LIGHT_GRAY : DARK_GRAY, whitePawn);
                } else if (this->memoryBoard[i][j] == PieceType::BLACK_KNIGHT) {
                    Piece *blackKnight =
                        new Piece(sf::Vector2f(j * SQUARE_SIZE, i * SQUARE_SIZE), PieceType::BLACK_KNIGHT, BLACK,
                                  PIECE_SIZE, PieceColor::BLACK_PIECE, j, i);
                    this->squares[i][j] = new Square(j * SQUARE_SIZE, i * SQUARE_SIZE, SQUARE_SIZE,
                                                     isWhite == true ? LIGHT_GRAY : DARK_GRAY, blackKnight);
                } else if (this->memoryBoard[i][j] == PieceType::WHITE_KNIGHT) {
                    Piece *whiteKnight =
                        new Piece(sf::Vector2f(j * SQUARE_SIZE, i * SQUARE_SIZE), PieceType::WHITE_KNIGHT, WHITE,
                                  PIECE_SIZE, PieceColor::WHITE_PIECE, j, i);
                    this->squares[i][j] = new Square(j * SQUARE_SIZE, i * SQUARE_SIZE, SQUARE_SIZE,
                                                     isWhite == true ? LIGHT_GRAY : DARK_GRAY, whiteKnight);
                } else if (this->memoryBoard[i][j] == PieceType::BLACK_BISHOP) {
                    Piece *blackBishop =
                        new Piece(sf::Vector2f(j * SQUARE_SIZE, i * SQUARE_SIZE), PieceType::BLACK_BISHOP, BLACK,
                                  PIECE_SIZE, PieceColor::BLACK_PIECE, j, i);
                    this->squares[i][j] = new Square(j * SQUARE_SIZE, i * SQUARE_SIZE, SQUARE_SIZE,
                                                     isWhite == true ? LIGHT_GRAY : DARK_GRAY, blackBishop);
                } else if (this->memoryBoard[i][j] == PieceType::WHITE_BISHOP) {
                    Piece *whiteBishop =
                        new Piece(sf::Vector2f(j * SQUARE_SIZE, i * SQUARE_SIZE), PieceType::WHITE_BISHOP, WHITE,
                                  PIECE_SIZE, PieceColor::WHITE_PIECE, j, i);
                    this->squares[i][j] = new Square(j * SQUARE_SIZE, i * SQUARE_SIZE, SQUARE_SIZE,
                                                     isWhite == true ? LIGHT_GRAY : DARK_GRAY, whiteBishop);
                } else if (this->memoryBoard[i][j] == PieceType::BLACK_ROOK) {
                    Piece *blackRook = new Piece(sf::Vector2f(j * SQUARE_SIZE, i * SQUARE_SIZE), PieceType::BLACK_ROOK,
                                                 BLACK, PIECE_SIZE, PieceColor::BLACK_PIECE, j, i);
                    this->squares[i][j] = new Square(j * SQUARE_SIZE, i * SQUARE_SIZE, SQUARE_SIZE,
                                                     isWhite == true ? LIGHT_GRAY : DARK_GRAY, blackRook);
                } else if (this->memoryBoard[i][j] == PieceType::WHITE_ROOK) {
                    Piece *whiteRook = new Piece(sf::Vector2f(j * SQUARE_SIZE, i * SQUARE_SIZE), PieceType::WHITE_ROOK,
                                                 WHITE, PIECE_SIZE, PieceColor::WHITE_PIECE, j, i);
                    this->squares[i][j] = new Square(j * SQUARE_SIZE, i * SQUARE_SIZE, SQUARE_SIZE,
                                                     isWhite == true ? LIGHT_GRAY : DARK_GRAY, whiteRook);
                } else if (this->memoryBoard[i][j] == PieceType::BLACK_QUEEN) {
                    Piece *blackQueen =
                        new Piece(sf::Vector2f(j * SQUARE_SIZE, i * SQUARE_SIZE), PieceType::BLACK_QUEEN, BLACK,
                                  PIECE_SIZE, PieceColor::BLACK_PIECE, j, i);
                    this->squares[i][j] = new Square(j * SQUARE_SIZE, i * SQUARE_SIZE, SQUARE_SIZE,
                                                     isWhite == true ? LIGHT_GRAY : DARK_GRAY, blackQueen);
                } else if (this->memoryBoard[i][j] == PieceType::WHITE_QUEEN) {
                    Piece *whiteQueen =
                        new Piece(sf::Vector2f(j * SQUARE_SIZE, i * SQUARE_SIZE), PieceType::WHITE_QUEEN, WHITE,
                                  PIECE_SIZE, PieceColor::WHITE_PIECE, j, i);
                    this->squares[i][j] = new Square(j * SQUARE_SIZE, i * SQUARE_SIZE, SQUARE_SIZE,
                                                     isWhite == true ? LIGHT_GRAY : DARK_GRAY, whiteQueen);
                } else if (this->memoryBoard[i][j] == PieceType::BLACK_KING) {
                    Piece *blackKing = new Piece(sf::Vector2f(j * SQUARE_SIZE, i * SQUARE_SIZE), PieceType::BLACK_KING,
                                                 BLACK, PIECE_SIZE, PieceColor::BLACK_PIECE, j, i);
                    this->squares[i][j] = new Square(j * SQUARE_SIZE, i * SQUARE_SIZE, SQUARE_SIZE,
                                                     isWhite == true ? LIGHT_GRAY : DARK_GRAY, blackKing);
                } else if (this->memoryBoard[i][j] == PieceType::WHITE_KING) {
                    Piece *whiteKing = new Piece(sf::Vector2f(j * SQUARE_SIZE, i * SQUARE_SIZE), PieceType::WHITE_KING,
                                                 WHITE, PIECE_SIZE, PieceColor::WHITE_PIECE, j, i);
                    this->squares[i][j] = new Square(j * SQUARE_SIZE, i * SQUARE_SIZE, SQUARE_SIZE,
                                                     isWhite == true ? LIGHT_GRAY : DARK_GRAY, whiteKing);
                }
            } else {
                this->squares[i][j] = new Square(j * SQUARE_SIZE, i * SQUARE_SIZE, SQUARE_SIZE,
                                                 isWhite == true ? LIGHT_GRAY : DARK_GRAY, nullptr);
            }
            j++;
        }
        i++;
    }

    // TODO: Implement the rest of the FEN string

    // // Sets the board's turn
    // if (fen[i] == 'w')
    // {
    //     this->turn = PieceColor::WHITE_PIECE;
    // }
    // else
    // {
    //     this->turn = PieceColor::BLACK_PIECE;
    // }

    // // Sets the board's castling rights
    // i += 2;

    // while (fen[i] != ' ')
    // {
    //     if (fen[i] == 'K')
    //     {
    //         this->whiteKingSideCastling = true;
    //     }
    //     else if (fen[i] == 'Q')
    //     {
    //         this->whiteQueenSideCastling = true;
    //     }
    //     else if (fen[i] == 'k')
    //     {
    //         this->blackKingSideCastling = true;
    //     }
    //     else if (fen[i] == 'q')
    //     {
    //         this->blackQueenSideCastling = true;
    //     }

    //     i++;
    // }

    // // Sets the board's en passant square
    // i += 2;

    // if (fen[i] != '-')
    // {
    //     int x = fen[i] - 'a';
    //     int y = fen[i + 1] - '1';

    //     this->enPassantSquare = this->squares[y][x];
    // }

    // // Sets the board's halfmove clock
    // i += 3;

    // while (fen[i] != ' ')
    // {
    //     this->halfmoveClock = this->halfmoveClock * 10 + (fen[i] - '0');
    //     i++;
    // }
}

void Board::draw(sf::RenderWindow &window) {
    // Iterates through the squares array to draw each square
    int i = 0;
    int j = 0;

    while (i < BOARD_SIZE) {
        j = 0;

        while (j < BOARD_SIZE) {
            this->squares[i][j]->draw(window);
            if (this->squares[i][j]->getPiece() != nullptr) this->squares[i][j]->getPiece()->draw(window);
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

        i++;
    }

    return nullptr;
}

Square *Board::getRelativeSquare(sf::Vector2i position) {
    return this->squares[position.y][position.x];
}

void Board::resetPossibleMoves() {
    // Iterates through the squares array to reset the possible moves of each square
    int i = 0;
    int j = 0;

    while (i < BOARD_SIZE) {
        j = 0;

        while (j < BOARD_SIZE) {
            this->squares[i][j]->setPossibleMove(false);
            j++;
        }
        i++;
    }
}

void Board::printMemoryBoard() {
    // Prints the memory board
    int i = 0;
    int j = 0;

    while (i < BOARD_SIZE) {
        j = 0;

        while (j < BOARD_SIZE) {
            std::cout << this->memoryBoard[i][j] << " ";
            j++;
        }
        std::cout << std::endl;
        i++;
    }
}

void Board::updateSquares() {
    // Iterates through the squares array to update each square
    int i = 0;
    int j = 0;

    while (i < BOARD_SIZE) {
        j = 0;

        while (j < BOARD_SIZE) {
            // this->squares[i][j]->update(this->memoryBoard[i][j]);
            j++;
        }
        i++;
    }
}

PieceColor Board::getPlayerTurn() { return this->playerTurn; }

void Board::setPlayerTurn(PieceColor playerTurn) { this->playerTurn = playerTurn; }

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

PieceType ***Board::getMemoryBoardPointer() { return &this->memoryBoard; }

void Board::setMemoryBoard(PieceType **memoryBoard) { this->memoryBoard = memoryBoard; }

PieceType Board::getPieceType(int x, int y) { return this->memoryBoard[x][y]; }

void Board::setPiece(int x, int y, PieceType piece) {
    this->memoryBoard[x][y] = piece;
    // TODO: Set the piece on the board (?)
    // this->squares[x][y]->setPiece(piece);
}

Piece *Board::getPiece(int x, int y) {
    // We get the y and x coordinate of the piece in the memory board
    // Then we get the square at the given position
    // Then we get the piece at the given square
    // TODO: Check if the piece is EMPTY in the memory board (?)
    return this->squares[x][y]->getPiece();
}

void Board::movePiece(Piece *piece, sf::Vector2f position) {
    /*
    "Smoothly move the piece to the given relative position"
    */

    // Checking if the piece is a king and it is trying to castle
    if (piece->getType() == PieceType::WHITE_KING && piece->getIsFirstMove() && position.x > piece->getPosition().x) {
        // Checking if the white king is trying to castle to the king side
        Piece *rook = this->getPiece(7, 7);

        if (rook->getPieceType() != PieceType::WHITE_ROOK || !rook->getIsFirstMove())
            return;

        // Moving the rook to the left of the king
        this->movePiece(rook, sf::Vector2f(5 * SQUARE_SIZE, 7 * SQUARE_SIZE));

        // Moving the king to the right of the rook
        piece->setIsFirstMove(false);
        this->movePiece(piece, sf::Vector2f(position.x, position.y));
        return;

    }  // Checking if castling queen side
    else if (piece->getType() == PieceType::WHITE_KING && piece->getIsFirstMove() && position.x < piece->getPosition().x) {
        // Checking if the white king is trying to castle to the queen side
        Piece *rook = this->getPiece(7, 0);

        if (rook->getPieceType() != PieceType::WHITE_ROOK || !rook->getIsFirstMove())
            return;

        // Moving the rook to the right of the king
        this->movePiece(rook, sf::Vector2f(3 * SQUARE_SIZE, 7 * SQUARE_SIZE));

        // Moving the king to the left of the rook
        piece->setIsFirstMove(false);
        this->movePiece(piece, sf::Vector2f(position.x, position.y));
        return;
    } else if (piece->getType() == PieceType::BLACK_KING && piece->getIsFirstMove() && position.x > piece->getPosition().x) {
        // Checking if the black king is trying to castle to the king side
        Piece *rook = this->getPiece(0, 7);

        if (rook->getPieceType() != PieceType::BLACK_ROOK || !rook->getIsFirstMove())
            return;

        // Moving the rook to the left of the king
        this->movePiece(rook, sf::Vector2f(5 * SQUARE_SIZE, 0));

        // Moving the king to the right of the rook
        piece->setIsFirstMove(false);
        this->movePiece(piece, sf::Vector2f(position.x, position.y));
        return;
    } else if (piece->getType() == PieceType::BLACK_KING && piece->getIsFirstMove() && position.x < piece->getPosition().x) {
        // Checking if the black king is trying to castle to the queen side
        Piece *rook = this->getPiece(0, 0);

        if (rook->getPieceType() != PieceType::BLACK_ROOK || !rook->getIsFirstMove())
            return;

        // Moving the rook to the right of the king
        this->movePiece(rook, sf::Vector2f(3 * SQUARE_SIZE, 0));

        // Moving the king to the left of the rook
        piece->setIsFirstMove(false);
        this->movePiece(piece, sf::Vector2f(position.x, position.y));
        return;
    }

    // Move the piece to the given position
    // this->printMemoryBoard();
    this->memoryBoard[piece->getMemoryPosition().y][piece->getMemoryPosition().x] = PieceType::EMPTY;
    sf::Vector2i relativePosition = sf::Vector2i(position.x / SQUARE_SIZE / 100, position.y / SQUARE_SIZE / 100);
    this->memoryBoard[relativePosition.y][relativePosition.x] = piece->getType();

    // Retrieves the square at the given position
    Square *square = this->getRelativeSquare(relativePosition);
    Square *oldSquare = this->getRelativeSquare(piece->getMemoryPosition());
    oldSquare->setPiece(nullptr);
    square->setPiece(piece);

    sf::Vector2f memoryPosition = sf::Vector2f(position.y, position.x);

    piece->setPosition(position, relativePosition.x, relativePosition.y);
    piece->setIsFirstMove(false);
    piece->setCanCastleKingSide(false);
    piece->setCanCastleKingSide(false);
    // this->printMemoryBoard();

    // TODO: Check if the move puts the opponent's king in check
    // TODO: Check if the move puts the player's king in check (in movement.cpp)
}
