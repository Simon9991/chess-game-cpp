#include "movement.hpp"

#include "./../../../include/main.hpp"

Movement::Movement(PieceType** memoryBoard, Board* board) {
    this->memoryBoard = memoryBoard;
    this->board = board;
}

Movement::~Movement() {}

std::vector<sf::Vector2f> Movement::getPossibleMoves(Piece* piece) {
    // TODO: Implement checking if the king is in check
    // To implement this, we need to check if the king is in check before the move, and after the move
    // Maybe in another function as if the king is in check, other piece can block the check and if they cannot then
    // they cannot move
    // TODO: Implement castling

    std::vector<sf::Vector2f> possibleMoves;

    switch (piece->getType()) {
        case PieceType::WHITE_PAWN: {
            // Checking if can move forward
            sf::Vector2i memoryPosition = piece->getMemoryPosition();

            // Checking if can move forward
            // y and x are reversed
            if (memoryPosition.y - 1 >= 0) {
                if (memoryBoard[memoryPosition.y - 1][memoryPosition.x] == PieceType::EMPTY) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x, piece->getPosition().y - SQUARE_SIZE));
                    // Checking if can move forward twice
                    if (piece->getIsFirstMove() &&
                        memoryBoard[memoryPosition.y - 2][memoryPosition.x] == PieceType::EMPTY) {
                        possibleMoves.push_back(
                            sf::Vector2f(piece->getPosition().x, piece->getPosition().y - SQUARE_SIZE * 2));
                    }
                }
                if (memoryBoard[memoryPosition.y - 1][memoryPosition.x - 1] == PieceType::BLACK_PAWN ||
                    memoryBoard[memoryPosition.y - 1][memoryPosition.x - 1] == PieceType::BLACK_ROOK ||
                    memoryBoard[memoryPosition.y - 1][memoryPosition.x - 1] == PieceType::BLACK_KNIGHT ||
                    memoryBoard[memoryPosition.y - 1][memoryPosition.x - 1] == PieceType::BLACK_BISHOP ||
                    memoryBoard[memoryPosition.y - 1][memoryPosition.x - 1] == PieceType::BLACK_QUEEN) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x - SQUARE_SIZE, piece->getPosition().y - SQUARE_SIZE));
                }
                if (memoryBoard[memoryPosition.y - 1][memoryPosition.x + 1] == PieceType::BLACK_PAWN ||
                    memoryBoard[memoryPosition.y - 1][memoryPosition.x + 1] == PieceType::BLACK_ROOK ||
                    memoryBoard[memoryPosition.y - 1][memoryPosition.x + 1] == PieceType::BLACK_KNIGHT ||
                    memoryBoard[memoryPosition.y - 1][memoryPosition.x + 1] == PieceType::BLACK_BISHOP ||
                    memoryBoard[memoryPosition.y - 1][memoryPosition.x + 1] == PieceType::BLACK_QUEEN) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x + SQUARE_SIZE, piece->getPosition().y - SQUARE_SIZE));
                }
            }

            return possibleMoves;
            break;
        }
        case PieceType::WHITE_KNIGHT: {
            // Checking if can move forward
            sf::Vector2i memoryPosition = piece->getMemoryPosition();

            // Checking if can move forward
            // y and x are reversed
            if (memoryPosition.y - 2 >= 0) {
                if (memoryPosition.x - 1 >= 0) {
                    if (memoryBoard[memoryPosition.y - 2][memoryPosition.x - 1] == PieceType::EMPTY ||
                        memoryBoard[memoryPosition.y - 2][memoryPosition.x - 1] == PieceType::BLACK_PAWN ||
                        memoryBoard[memoryPosition.y - 2][memoryPosition.x - 1] == PieceType::BLACK_ROOK ||
                        memoryBoard[memoryPosition.y - 2][memoryPosition.x - 1] == PieceType::BLACK_KNIGHT ||
                        memoryBoard[memoryPosition.y - 2][memoryPosition.x - 1] == PieceType::BLACK_BISHOP ||
                        memoryBoard[memoryPosition.y - 2][memoryPosition.x - 1] == PieceType::BLACK_QUEEN) {
                        possibleMoves.push_back(sf::Vector2f(piece->getPosition().x - SQUARE_SIZE,
                                                             piece->getPosition().y - SQUARE_SIZE * 2));
                    }
                }
                if (memoryPosition.x + 1 < BOARD_SIZE) {
                    if (memoryBoard[memoryPosition.y - 2][memoryPosition.x + 1] == PieceType::EMPTY ||
                        memoryBoard[memoryPosition.y - 2][memoryPosition.x + 1] == PieceType::BLACK_PAWN ||
                        memoryBoard[memoryPosition.y - 2][memoryPosition.x + 1] == PieceType::BLACK_ROOK ||
                        memoryBoard[memoryPosition.y - 2][memoryPosition.x + 1] == PieceType::BLACK_KNIGHT ||
                        memoryBoard[memoryPosition.y - 2][memoryPosition.x + 1] == PieceType::BLACK_BISHOP ||
                        memoryBoard[memoryPosition.y - 2][memoryPosition.x + 1] == PieceType::BLACK_QUEEN) {
                        possibleMoves.push_back(sf::Vector2f(piece->getPosition().x + SQUARE_SIZE,
                                                             piece->getPosition().y - SQUARE_SIZE * 2));
                    }
                }
            }
            if (memoryPosition.y + 2 < BOARD_SIZE) {
                if (memoryPosition.x - 1 >= 0) {
                    if (memoryBoard[memoryPosition.y + 2][memoryPosition.x - 1] == PieceType::EMPTY ||
                        memoryBoard[memoryPosition.y + 2][memoryPosition.x - 1] == PieceType::BLACK_PAWN ||
                        memoryBoard[memoryPosition.y + 2][memoryPosition.x - 1] == PieceType::BLACK_ROOK ||
                        memoryBoard[memoryPosition.y + 2][memoryPosition.x - 1] == PieceType::BLACK_KNIGHT ||
                        memoryBoard[memoryPosition.y + 2][memoryPosition.x - 1] == PieceType::BLACK_BISHOP ||
                        memoryBoard[memoryPosition.y + 2][memoryPosition.x - 1] == PieceType::BLACK_QUEEN) {
                        possibleMoves.push_back(sf::Vector2f(piece->getPosition().x - SQUARE_SIZE,
                                                             piece->getPosition().y + SQUARE_SIZE * 2));
                    }
                }
                if (memoryPosition.x + 1 < BOARD_SIZE) {
                    if (memoryBoard[memoryPosition.y + 2][memoryPosition.x + 1] == PieceType::EMPTY ||
                        memoryBoard[memoryPosition.y + 2][memoryPosition.x + 1] == PieceType::BLACK_PAWN ||
                        memoryBoard[memoryPosition.y + 2][memoryPosition.x + 1] == PieceType::BLACK_ROOK ||
                        memoryBoard[memoryPosition.y + 2][memoryPosition.x + 1] == PieceType::BLACK_KNIGHT ||
                        memoryBoard[memoryPosition.y + 2][memoryPosition.x + 1] == PieceType::BLACK_BISHOP ||
                        memoryBoard[memoryPosition.y + 2][memoryPosition.x + 1] == PieceType::BLACK_QUEEN) {
                        possibleMoves.push_back(sf::Vector2f(piece->getPosition().x + SQUARE_SIZE,
                                                             piece->getPosition().y + SQUARE_SIZE * 2));
                    }
                }
            }
            if (memoryPosition.x - 2 >= 0) {
                if (memoryPosition.y - 1 >= 0) {
                    if (memoryBoard[memoryPosition.y - 1][memoryPosition.x - 2] == PieceType::EMPTY ||
                        memoryBoard[memoryPosition.y - 1][memoryPosition.x - 2] == PieceType::BLACK_PAWN ||
                        memoryBoard[memoryPosition.y - 1][memoryPosition.x - 2] == PieceType::BLACK_ROOK ||
                        memoryBoard[memoryPosition.y - 1][memoryPosition.x - 2] == PieceType::BLACK_KNIGHT ||
                        memoryBoard[memoryPosition.y - 1][memoryPosition.x - 2] == PieceType::BLACK_BISHOP ||
                        memoryBoard[memoryPosition.y - 1][memoryPosition.x - 2] == PieceType::BLACK_QUEEN) {
                        possibleMoves.push_back(sf::Vector2f(piece->getPosition().x - SQUARE_SIZE * 2,
                                                             piece->getPosition().y - SQUARE_SIZE));
                    }
                }
                if (memoryPosition.y + 1 < BOARD_SIZE) {
                    if (memoryBoard[memoryPosition.y + 1][memoryPosition.x - 2] == PieceType::EMPTY ||
                        memoryBoard[memoryPosition.y + 1][memoryPosition.x - 2] == PieceType::BLACK_PAWN ||
                        memoryBoard[memoryPosition.y + 1][memoryPosition.x - 2] == PieceType::BLACK_ROOK ||
                        memoryBoard[memoryPosition.y + 1][memoryPosition.x - 2] == PieceType::BLACK_KNIGHT ||
                        memoryBoard[memoryPosition.y + 1][memoryPosition.x - 2] == PieceType::BLACK_BISHOP ||
                        memoryBoard[memoryPosition.y + 1][memoryPosition.x - 2] == PieceType::BLACK_QUEEN) {
                        possibleMoves.push_back(sf::Vector2f(piece->getPosition().x - SQUARE_SIZE * 2,
                                                             piece->getPosition().y + SQUARE_SIZE));
                    }
                }
            }
            if (memoryPosition.x + 2 < BOARD_SIZE) {
                if (memoryPosition.y - 1 >= 0) {
                    if (memoryBoard[memoryPosition.y - 1][memoryPosition.x + 2] == PieceType::EMPTY ||
                        memoryBoard[memoryPosition.y - 1][memoryPosition.x + 2] == PieceType::BLACK_PAWN ||
                        memoryBoard[memoryPosition.y - 1][memoryPosition.x + 2] == PieceType::BLACK_ROOK ||
                        memoryBoard[memoryPosition.y - 1][memoryPosition.x + 2] == PieceType::BLACK_KNIGHT ||
                        memoryBoard[memoryPosition.y - 1][memoryPosition.x + 2] == PieceType::BLACK_BISHOP ||
                        memoryBoard[memoryPosition.y - 1][memoryPosition.x + 2] == PieceType::BLACK_QUEEN) {
                        possibleMoves.push_back(sf::Vector2f(piece->getPosition().x + SQUARE_SIZE * 2,
                                                             piece->getPosition().y - SQUARE_SIZE));
                    }
                }
                if (memoryPosition.y + 1 < BOARD_SIZE) {
                    if (memoryBoard[memoryPosition.y + 1][memoryPosition.x + 2] == PieceType::EMPTY ||
                        memoryBoard[memoryPosition.y + 1][memoryPosition.x + 2] == PieceType::BLACK_PAWN ||
                        memoryBoard[memoryPosition.y + 1][memoryPosition.x + 2] == PieceType::BLACK_ROOK ||
                        memoryBoard[memoryPosition.y + 1][memoryPosition.x + 2] == PieceType::BLACK_KNIGHT ||
                        memoryBoard[memoryPosition.y + 1][memoryPosition.x + 2] == PieceType::BLACK_BISHOP ||
                        memoryBoard[memoryPosition.y + 1][memoryPosition.x + 2] == PieceType::BLACK_QUEEN) {
                        possibleMoves.push_back(sf::Vector2f(piece->getPosition().x + SQUARE_SIZE * 2,
                                                             piece->getPosition().y + SQUARE_SIZE));
                    }
                }
            }

            return possibleMoves;
            break;
        }

        case PieceType::BLACK_KNIGHT: {
            // Checking if can move forward
            sf::Vector2i memoryPosition = piece->getMemoryPosition();

            // Checking if can move forward
            // y and x are reversed
            if (memoryPosition.y - 2 >= 0) {
                if (memoryPosition.x - 1 >= 0) {
                    if (memoryBoard[memoryPosition.y - 2][memoryPosition.x - 1] == PieceType::EMPTY ||
                        memoryBoard[memoryPosition.y - 2][memoryPosition.x - 1] == PieceType::WHITE_PAWN ||
                        memoryBoard[memoryPosition.y - 2][memoryPosition.x - 1] == PieceType::WHITE_ROOK ||
                        memoryBoard[memoryPosition.y - 2][memoryPosition.x - 1] == PieceType::WHITE_KNIGHT ||
                        memoryBoard[memoryPosition.y - 2][memoryPosition.x - 1] == PieceType::WHITE_BISHOP ||
                        memoryBoard[memoryPosition.y - 2][memoryPosition.x - 1] == PieceType::WHITE_QUEEN) {
                        possibleMoves.push_back(sf::Vector2f(piece->getPosition().x - SQUARE_SIZE,
                                                             piece->getPosition().y - SQUARE_SIZE * 2));
                    }
                }
                if (memoryPosition.x + 1 < BOARD_SIZE) {
                    if (memoryBoard[memoryPosition.y - 2][memoryPosition.x + 1] == PieceType::EMPTY ||
                        memoryBoard[memoryPosition.y - 2][memoryPosition.x + 1] == PieceType::WHITE_PAWN ||
                        memoryBoard[memoryPosition.y - 2][memoryPosition.x + 1] == PieceType::WHITE_ROOK ||
                        memoryBoard[memoryPosition.y - 2][memoryPosition.x + 1] == PieceType::WHITE_KNIGHT ||
                        memoryBoard[memoryPosition.y - 2][memoryPosition.x + 1] == PieceType::WHITE_BISHOP ||
                        memoryBoard[memoryPosition.y - 2][memoryPosition.x + 1] == PieceType::WHITE_QUEEN) {
                        possibleMoves.push_back(sf::Vector2f(piece->getPosition().x + SQUARE_SIZE,
                                                             piece->getPosition().y - SQUARE_SIZE * 2));
                    }
                }
            }
            if (memoryPosition.y + 2 < BOARD_SIZE) {
                if (memoryPosition.x - 1 >= 0) {
                    if (memoryBoard[memoryPosition.y + 2][memoryPosition.x - 1] == PieceType::EMPTY ||
                        memoryBoard[memoryPosition.y + 2][memoryPosition.x - 1] == PieceType::WHITE_PAWN ||
                        memoryBoard[memoryPosition.y + 2][memoryPosition.x - 1] == PieceType::WHITE_ROOK ||
                        memoryBoard[memoryPosition.y + 2][memoryPosition.x - 1] == PieceType::WHITE_KNIGHT ||
                        memoryBoard[memoryPosition.y + 2][memoryPosition.x - 1] == PieceType::WHITE_BISHOP ||
                        memoryBoard[memoryPosition.y + 2][memoryPosition.x - 1] == PieceType::WHITE_QUEEN) {
                        possibleMoves.push_back(sf::Vector2f(piece->getPosition().x - SQUARE_SIZE,
                                                             piece->getPosition().y + SQUARE_SIZE * 2));
                    }
                }
                if (memoryPosition.x + 1 < BOARD_SIZE) {
                    if (memoryBoard[memoryPosition.y + 2][memoryPosition.x + 1] == PieceType::EMPTY ||
                        memoryBoard[memoryPosition.y + 2][memoryPosition.x + 1] == PieceType::WHITE_PAWN ||
                        memoryBoard[memoryPosition.y + 2][memoryPosition.x + 1] == PieceType::WHITE_ROOK ||
                        memoryBoard[memoryPosition.y + 2][memoryPosition.x + 1] == PieceType::WHITE_KNIGHT ||
                        memoryBoard[memoryPosition.y + 2][memoryPosition.x + 1] == PieceType::WHITE_BISHOP ||
                        memoryBoard[memoryPosition.y + 2][memoryPosition.x + 1] == PieceType::WHITE_QUEEN) {
                        possibleMoves.push_back(sf::Vector2f(piece->getPosition().x + SQUARE_SIZE,
                                                             piece->getPosition().y + SQUARE_SIZE * 2));
                    }
                }
            }
            if (memoryPosition.x - 2 >= 0) {
                if (memoryPosition.y - 1 >= 0) {
                    if (memoryBoard[memoryPosition.y - 1][memoryPosition.x - 2] == PieceType::EMPTY ||
                        memoryBoard[memoryPosition.y - 1][memoryPosition.x - 2] == PieceType::WHITE_PAWN ||
                        memoryBoard[memoryPosition.y - 1][memoryPosition.x - 2] == PieceType::WHITE_ROOK ||
                        memoryBoard[memoryPosition.y - 1][memoryPosition.x - 2] == PieceType::WHITE_KNIGHT ||
                        memoryBoard[memoryPosition.y - 1][memoryPosition.x - 2] == PieceType::WHITE_BISHOP ||
                        memoryBoard[memoryPosition.y - 1][memoryPosition.x - 2] == PieceType::WHITE_QUEEN) {
                        possibleMoves.push_back(sf::Vector2f(piece->getPosition().x - SQUARE_SIZE * 2,
                                                             piece->getPosition().y - SQUARE_SIZE));
                    }
                }
                if (memoryPosition.y + 1 < BOARD_SIZE) {
                    if (memoryBoard[memoryPosition.y + 1][memoryPosition.x - 2] == PieceType::EMPTY ||
                        memoryBoard[memoryPosition.y + 1][memoryPosition.x - 2] == PieceType::WHITE_PAWN ||
                        memoryBoard[memoryPosition.y + 1][memoryPosition.x - 2] == PieceType::WHITE_ROOK ||
                        memoryBoard[memoryPosition.y + 1][memoryPosition.x - 2] == PieceType::WHITE_KNIGHT ||
                        memoryBoard[memoryPosition.y + 1][memoryPosition.x - 2] == PieceType::WHITE_BISHOP ||
                        memoryBoard[memoryPosition.y + 1][memoryPosition.x - 2] == PieceType::WHITE_QUEEN) {
                        possibleMoves.push_back(sf::Vector2f(piece->getPosition().x - SQUARE_SIZE * 2,
                                                             piece->getPosition().y + SQUARE_SIZE));
                    }
                }
            }
            if (memoryPosition.x + 2 < BOARD_SIZE) {
                if (memoryPosition.y - 1 >= 0) {
                    if (memoryBoard[memoryPosition.y - 1][memoryPosition.x + 2] == PieceType::EMPTY ||
                        memoryBoard[memoryPosition.y - 1][memoryPosition.x + 2] == PieceType::WHITE_PAWN ||
                        memoryBoard[memoryPosition.y - 1][memoryPosition.x + 2] == PieceType::WHITE_ROOK ||
                        memoryBoard[memoryPosition.y - 1][memoryPosition.x + 2] == PieceType::WHITE_KNIGHT ||
                        memoryBoard[memoryPosition.y - 1][memoryPosition.x + 2] == PieceType::WHITE_BISHOP ||
                        memoryBoard[memoryPosition.y - 1][memoryPosition.x + 2] == PieceType::WHITE_QUEEN) {
                        possibleMoves.push_back(sf::Vector2f(piece->getPosition().x + SQUARE_SIZE * 2,
                                                             piece->getPosition().y - SQUARE_SIZE));
                    }
                }
                if (memoryPosition.y + 1 < BOARD_SIZE) {
                    if (memoryBoard[memoryPosition.y + 1][memoryPosition.x + 2] == PieceType::EMPTY ||
                        memoryBoard[memoryPosition.y + 1][memoryPosition.x + 2] == PieceType::WHITE_PAWN ||
                        memoryBoard[memoryPosition.y + 1][memoryPosition.x + 2] == PieceType::WHITE_ROOK ||
                        memoryBoard[memoryPosition.y + 1][memoryPosition.x + 2] == PieceType::WHITE_KNIGHT ||
                        memoryBoard[memoryPosition.y + 1][memoryPosition.x + 2] == PieceType::WHITE_BISHOP ||
                        memoryBoard[memoryPosition.y + 1][memoryPosition.x + 2] == PieceType::WHITE_QUEEN) {
                        possibleMoves.push_back(sf::Vector2f(piece->getPosition().x + SQUARE_SIZE * 2,
                                                             piece->getPosition().y + SQUARE_SIZE));
                    }
                }
            }

            return possibleMoves;
            break;
        }

        case PieceType::BLACK_ROOK: {
            // Checking if can move forward
            sf::Vector2i memoryPosition = piece->getMemoryPosition();

            // Checking if can move forward
            // y and x are reversed
            for (int i = memoryPosition.y + 1; i < BOARD_SIZE; i++) {
                if (memoryBoard[i][memoryPosition.x] == PieceType::EMPTY) {
                    possibleMoves.push_back(sf::Vector2f(
                        piece->getPosition().x, piece->getPosition().y + SQUARE_SIZE * (i - memoryPosition.y)));
                } else if (memoryBoard[i][memoryPosition.x] == PieceType::WHITE_PAWN ||
                           memoryBoard[i][memoryPosition.x] == PieceType::WHITE_ROOK ||
                           memoryBoard[i][memoryPosition.x] == PieceType::WHITE_KNIGHT ||
                           memoryBoard[i][memoryPosition.x] == PieceType::WHITE_BISHOP ||
                           memoryBoard[i][memoryPosition.x] == PieceType::WHITE_QUEEN) {
                    possibleMoves.push_back(sf::Vector2f(
                        piece->getPosition().x, piece->getPosition().y + SQUARE_SIZE * (i - memoryPosition.y)));
                    break;
                } else {
                    break;
                }
            }

            // Checking if can move backward
            for (int i = memoryPosition.y - 1; i >= 0; i--) {
                if (memoryBoard[i][memoryPosition.x] == PieceType::EMPTY) {
                    possibleMoves.push_back(sf::Vector2f(
                        piece->getPosition().x, piece->getPosition().y - SQUARE_SIZE * (memoryPosition.y - i)));
                } else if (memoryBoard[i][memoryPosition.x] == PieceType::WHITE_PAWN ||
                           memoryBoard[i][memoryPosition.x] == PieceType::WHITE_ROOK ||
                           memoryBoard[i][memoryPosition.x] == PieceType::WHITE_KNIGHT ||
                           memoryBoard[i][memoryPosition.x] == PieceType::WHITE_BISHOP ||
                           memoryBoard[i][memoryPosition.x] == PieceType::WHITE_QUEEN) {
                    possibleMoves.push_back(sf::Vector2f(
                        piece->getPosition().x, piece->getPosition().y - SQUARE_SIZE * (memoryPosition.y - i)));
                    break;
                } else {
                    break;
                }
            }

            // Checking if can move right
            for (int i = memoryPosition.x + 1; i < BOARD_SIZE; i++) {
                if (memoryBoard[memoryPosition.y][i] == PieceType::EMPTY) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x + SQUARE_SIZE * (i - memoryPosition.x),
                                                         piece->getPosition().y));
                } else if (memoryBoard[memoryPosition.y][i] == PieceType::WHITE_PAWN ||
                           memoryBoard[memoryPosition.y][i] == PieceType::WHITE_ROOK ||
                           memoryBoard[memoryPosition.y][i] == PieceType::WHITE_KNIGHT ||
                           memoryBoard[memoryPosition.y][i] == PieceType::WHITE_BISHOP ||
                           memoryBoard[memoryPosition.y][i] == PieceType::WHITE_QUEEN) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x + SQUARE_SIZE * (i - memoryPosition.x),
                                                         piece->getPosition().y));
                    break;
                } else {
                    break;
                }
            }

            // Checking if can move left
            for (int i = memoryPosition.x - 1; i >= 0; i--) {
                if (memoryBoard[memoryPosition.y][i] == PieceType::EMPTY) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x - SQUARE_SIZE * (memoryPosition.x - i),
                                                         piece->getPosition().y));
                } else if (memoryBoard[memoryPosition.y][i] == PieceType::WHITE_PAWN ||
                           memoryBoard[memoryPosition.y][i] == PieceType::WHITE_ROOK ||
                           memoryBoard[memoryPosition.y][i] == PieceType::WHITE_KNIGHT ||
                           memoryBoard[memoryPosition.y][i] == PieceType::WHITE_BISHOP ||
                           memoryBoard[memoryPosition.y][i] == PieceType::WHITE_QUEEN) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x - SQUARE_SIZE * (memoryPosition.x - i),
                                                         piece->getPosition().y));
                    break;
                } else {
                    break;
                }
            }

            return possibleMoves;
            break;
        }

        case PieceType::WHITE_ROOK: {
            // Checking if can move forward
            sf::Vector2i memoryPosition = piece->getMemoryPosition();

            // Checking if can move forward
            // y and x are reversed
            for (int i = memoryPosition.y + 1; i < BOARD_SIZE; i++) {
                if (memoryBoard[i][memoryPosition.x] == PieceType::EMPTY) {
                    possibleMoves.push_back(sf::Vector2f(
                        piece->getPosition().x, piece->getPosition().y + SQUARE_SIZE * (i - memoryPosition.y)));
                } else if (memoryBoard[i][memoryPosition.x] == PieceType::BLACK_PAWN ||
                           memoryBoard[i][memoryPosition.x] == PieceType::BLACK_ROOK ||
                           memoryBoard[i][memoryPosition.x] == PieceType::BLACK_KNIGHT ||
                           memoryBoard[i][memoryPosition.x] == PieceType::BLACK_BISHOP ||
                           memoryBoard[i][memoryPosition.x] == PieceType::BLACK_QUEEN) {
                    possibleMoves.push_back(sf::Vector2f(
                        piece->getPosition().x, piece->getPosition().y + SQUARE_SIZE * (i - memoryPosition.y)));
                    break;
                } else {
                    break;
                }
            }

            // Checking if can move backward
            for (int i = memoryPosition.y - 1; i >= 0; i--) {
                if (memoryBoard[i][memoryPosition.x] == PieceType::EMPTY) {
                    possibleMoves.push_back(sf::Vector2f(
                        piece->getPosition().x, piece->getPosition().y - SQUARE_SIZE * (memoryPosition.y - i)));
                } else if (memoryBoard[i][memoryPosition.x] == PieceType::BLACK_PAWN ||
                           memoryBoard[i][memoryPosition.x] == PieceType::BLACK_ROOK ||
                           memoryBoard[i][memoryPosition.x] == PieceType::BLACK_KNIGHT ||
                           memoryBoard[i][memoryPosition.x] == PieceType::BLACK_BISHOP ||
                           memoryBoard[i][memoryPosition.x] == PieceType::BLACK_QUEEN) {
                    possibleMoves.push_back(sf::Vector2f(
                        piece->getPosition().x, piece->getPosition().y - SQUARE_SIZE * (memoryPosition.y - i)));
                    break;
                } else {
                    break;
                }
            }

            // Checking if can move right
            for (int i = memoryPosition.x + 1; i < BOARD_SIZE; i++) {
                if (memoryBoard[memoryPosition.y][i] == PieceType::EMPTY) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x + SQUARE_SIZE * (i - memoryPosition.x),
                                                         piece->getPosition().y));
                } else if (memoryBoard[memoryPosition.y][i] == PieceType::BLACK_PAWN ||
                           memoryBoard[memoryPosition.y][i] == PieceType::BLACK_ROOK ||
                           memoryBoard[memoryPosition.y][i] == PieceType::BLACK_KNIGHT ||
                           memoryBoard[memoryPosition.y][i] == PieceType::BLACK_BISHOP ||
                           memoryBoard[memoryPosition.y][i] == PieceType::BLACK_QUEEN) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x + SQUARE_SIZE * (i - memoryPosition.x),
                                                         piece->getPosition().y));
                    break;
                } else {
                    break;
                }
            }

            // Checking if can move left
            for (int i = memoryPosition.x - 1; i >= 0; i--) {
                if (memoryBoard[memoryPosition.y][i] == PieceType::EMPTY) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x - SQUARE_SIZE * (memoryPosition.x - i),
                                                         piece->getPosition().y));
                } else if (memoryBoard[memoryPosition.y][i] == PieceType::BLACK_PAWN ||
                           memoryBoard[memoryPosition.y][i] == PieceType::BLACK_ROOK ||
                           memoryBoard[memoryPosition.y][i] == PieceType::BLACK_KNIGHT ||
                           memoryBoard[memoryPosition.y][i] == PieceType::BLACK_BISHOP ||
                           memoryBoard[memoryPosition.y][i] == PieceType::BLACK_QUEEN) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x - SQUARE_SIZE * (memoryPosition.x - i),
                                                         piece->getPosition().y));
                    break;
                } else {
                    break;
                }
            }

            return possibleMoves;
            break;
        }

        case PieceType::BLACK_BISHOP: {
            // Checking if can move forward
            sf::Vector2i memoryPosition = piece->getMemoryPosition();

            // Checking if can move forward
            // y and x are reversed
            for (int i = memoryPosition.y + 1, j = memoryPosition.x + 1; i < BOARD_SIZE && j < BOARD_SIZE; i++, j++) {
                if (memoryBoard[i][j] == PieceType::EMPTY) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x + SQUARE_SIZE * (j - memoryPosition.x),
                                     piece->getPosition().y + SQUARE_SIZE * (i - memoryPosition.y)));
                } else if (memoryBoard[i][j] == PieceType::WHITE_PAWN || memoryBoard[i][j] == PieceType::WHITE_ROOK ||
                           memoryBoard[i][j] == PieceType::WHITE_KNIGHT ||
                           memoryBoard[i][j] == PieceType::WHITE_BISHOP ||
                           memoryBoard[i][j] == PieceType::WHITE_QUEEN) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x + SQUARE_SIZE * (j - memoryPosition.x),
                                     piece->getPosition().y + SQUARE_SIZE * (i - memoryPosition.y)));
                    break;
                } else {
                    break;
                }
            }

            // Checking if can move backward
            for (int i = memoryPosition.y - 1, j = memoryPosition.x - 1; i >= 0 && j >= 0; i--, j--) {
                if (memoryBoard[i][j] == PieceType::EMPTY) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x - SQUARE_SIZE * (memoryPosition.x - j),
                                     piece->getPosition().y - SQUARE_SIZE * (memoryPosition.y - i)));
                } else if (memoryBoard[i][j] == PieceType::WHITE_PAWN || memoryBoard[i][j] == PieceType::WHITE_ROOK ||
                           memoryBoard[i][j] == PieceType::WHITE_KNIGHT ||
                           memoryBoard[i][j] == PieceType::WHITE_BISHOP ||
                           memoryBoard[i][j] == PieceType::WHITE_QUEEN) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x - SQUARE_SIZE * (memoryPosition.x - j),
                                     piece->getPosition().y - SQUARE_SIZE * (memoryPosition.y - i)));
                    break;
                } else {
                    break;
                }
            }

            // Checking if can move right
            for (int i = memoryPosition.y + 1, j = memoryPosition.x - 1; i < BOARD_SIZE && j >= 0; i++, j--) {
                if (memoryBoard[i][j] == PieceType::EMPTY) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x - SQUARE_SIZE * (memoryPosition.x - j),
                                     piece->getPosition().y + SQUARE_SIZE * (i - memoryPosition.y)));
                } else if (memoryBoard[i][j] == PieceType::WHITE_PAWN || memoryBoard[i][j] == PieceType::WHITE_ROOK ||
                           memoryBoard[i][j] == PieceType::WHITE_KNIGHT ||
                           memoryBoard[i][j] == PieceType::WHITE_BISHOP ||
                           memoryBoard[i][j] == PieceType::WHITE_QUEEN) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x - SQUARE_SIZE * (memoryPosition.x - j),
                                     piece->getPosition().y + SQUARE_SIZE * (i - memoryPosition.y)));
                    break;
                } else {
                    break;
                }
            }

            // Checking if can move left
            for (int i = memoryPosition.y - 1, j = memoryPosition.x + 1; i >= 0 && j < BOARD_SIZE; i--, j++) {
                if (memoryBoard[i][j] == PieceType::EMPTY) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x + SQUARE_SIZE * (j - memoryPosition.x),
                                     piece->getPosition().y - SQUARE_SIZE * (memoryPosition.y - i)));
                } else if (memoryBoard[i][j] == PieceType::WHITE_PAWN || memoryBoard[i][j] == PieceType::WHITE_ROOK ||
                           memoryBoard[i][j] == PieceType::WHITE_KNIGHT ||
                           memoryBoard[i][j] == PieceType::WHITE_BISHOP ||
                           memoryBoard[i][j] == PieceType::WHITE_QUEEN) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x + SQUARE_SIZE * (j - memoryPosition.x),
                                     piece->getPosition().y - SQUARE_SIZE * (memoryPosition.y - i)));
                    break;
                } else {
                    break;
                }
            }

            return possibleMoves;
            break;
        }

        case PieceType::WHITE_BISHOP: {
            // Checking if can move forward
            sf::Vector2i memoryPosition = piece->getMemoryPosition();

            // Checking if can move forward
            // y and x are reversed
            for (int i = memoryPosition.y + 1, j = memoryPosition.x + 1; i < BOARD_SIZE && j < BOARD_SIZE; i++, j++) {
                if (memoryBoard[i][j] == PieceType::EMPTY) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x + SQUARE_SIZE * (j - memoryPosition.x),
                                     piece->getPosition().y + SQUARE_SIZE * (i - memoryPosition.y)));
                } else if (memoryBoard[i][j] == PieceType::BLACK_PAWN || memoryBoard[i][j] == PieceType::BLACK_ROOK ||
                           memoryBoard[i][j] == PieceType::BLACK_KNIGHT ||
                           memoryBoard[i][j] == PieceType::BLACK_BISHOP ||
                           memoryBoard[i][j] == PieceType::BLACK_QUEEN) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x + SQUARE_SIZE * (j - memoryPosition.x),
                                     piece->getPosition().y + SQUARE_SIZE * (i - memoryPosition.y)));
                    break;
                } else {
                    break;
                }
            }

            // Checking if can move backward
            for (int i = memoryPosition.y - 1, j = memoryPosition.x - 1; i >= 0 && j >= 0; i--, j--) {
                if (memoryBoard[i][j] == PieceType::EMPTY) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x - SQUARE_SIZE * (memoryPosition.x - j),
                                     piece->getPosition().y - SQUARE_SIZE * (memoryPosition.y - i)));
                } else if (memoryBoard[i][j] == PieceType::BLACK_PAWN || memoryBoard[i][j] == PieceType::BLACK_ROOK ||
                           memoryBoard[i][j] == PieceType::BLACK_KNIGHT ||
                           memoryBoard[i][j] == PieceType::BLACK_BISHOP ||
                           memoryBoard[i][j] == PieceType::BLACK_QUEEN) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x - SQUARE_SIZE * (memoryPosition.x - j),
                                     piece->getPosition().y - SQUARE_SIZE * (memoryPosition.y - i)));
                    break;
                } else {
                    break;
                }
            }

            // Checking if can move right
            for (int i = memoryPosition.y + 1, j = memoryPosition.x - 1; i < BOARD_SIZE && j >= 0; i++, j--) {
                if (memoryBoard[i][j] == PieceType::EMPTY) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x - SQUARE_SIZE * (memoryPosition.x - j),
                                     piece->getPosition().y + SQUARE_SIZE * (i - memoryPosition.y)));
                } else if (memoryBoard[i][j] == PieceType::BLACK_PAWN || memoryBoard[i][j] == PieceType::BLACK_ROOK ||
                           memoryBoard[i][j] == PieceType::BLACK_KNIGHT ||
                           memoryBoard[i][j] == PieceType::BLACK_BISHOP ||
                           memoryBoard[i][j] == PieceType::BLACK_QUEEN) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x - SQUARE_SIZE * (memoryPosition.x - j),
                                     piece->getPosition().y + SQUARE_SIZE * (i - memoryPosition.y)));
                    break;
                } else {
                    break;
                }
            }

            // Checking if can move left
            for (int i = memoryPosition.y - 1, j = memoryPosition.x + 1; i >= 0 && j < BOARD_SIZE; i--, j++) {
                if (memoryBoard[i][j] == PieceType::EMPTY) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x + SQUARE_SIZE * (j - memoryPosition.x),
                                     piece->getPosition().y - SQUARE_SIZE * (memoryPosition.y - i)));
                } else if (memoryBoard[i][j] == PieceType::BLACK_PAWN || memoryBoard[i][j] == PieceType::BLACK_ROOK ||
                           memoryBoard[i][j] == PieceType::BLACK_KNIGHT ||
                           memoryBoard[i][j] == PieceType::BLACK_BISHOP ||
                           memoryBoard[i][j] == PieceType::BLACK_QUEEN) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x + SQUARE_SIZE * (j - memoryPosition.x),
                                     piece->getPosition().y - SQUARE_SIZE * (memoryPosition.y - i)));
                    break;
                } else {
                    break;
                }
            }

            return possibleMoves;
            break;
        }

        case PieceType::WHITE_QUEEN: {
            // Checking if can move forward
            sf::Vector2i memoryPosition = piece->getMemoryPosition();

            // Checking if can move forward
            // y and x are reversed
            for (int i = memoryPosition.y + 1; i < BOARD_SIZE; i++) {
                if (memoryBoard[i][memoryPosition.x] == PieceType::EMPTY) {
                    possibleMoves.push_back(sf::Vector2f(
                        piece->getPosition().x, piece->getPosition().y + SQUARE_SIZE * (i - memoryPosition.y)));
                } else if (memoryBoard[i][memoryPosition.x] == PieceType::BLACK_PAWN ||
                           memoryBoard[i][memoryPosition.x] == PieceType::BLACK_ROOK ||
                           memoryBoard[i][memoryPosition.x] == PieceType::BLACK_KNIGHT ||
                           memoryBoard[i][memoryPosition.x] == PieceType::BLACK_BISHOP ||
                           memoryBoard[i][memoryPosition.x] == PieceType::BLACK_QUEEN) {
                    possibleMoves.push_back(sf::Vector2f(
                        piece->getPosition().x, piece->getPosition().y + SQUARE_SIZE * (i - memoryPosition.y)));
                    break;
                } else {
                    break;
                }
            }

            // Checking if can move backward
            for (int i = memoryPosition.y - 1; i >= 0; i--) {
                if (memoryBoard[i][memoryPosition.x] == PieceType::EMPTY) {
                    possibleMoves.push_back(sf::Vector2f(
                        piece->getPosition().x, piece->getPosition().y - SQUARE_SIZE * (memoryPosition.y - i)));
                } else if (memoryBoard[i][memoryPosition.x] == PieceType::BLACK_PAWN ||
                           memoryBoard[i][memoryPosition.x] == PieceType::BLACK_ROOK ||
                           memoryBoard[i][memoryPosition.x] == PieceType::BLACK_KNIGHT ||
                           memoryBoard[i][memoryPosition.x] == PieceType::BLACK_BISHOP ||
                           memoryBoard[i][memoryPosition.x] == PieceType::BLACK_QUEEN) {
                    possibleMoves.push_back(sf::Vector2f(
                        piece->getPosition().x, piece->getPosition().y - SQUARE_SIZE * (memoryPosition.y - i)));
                    break;
                } else {
                    break;
                }
            }

            // Checking if can move right
            for (int i = memoryPosition.x + 1; i < BOARD_SIZE; i++) {
                if (memoryBoard[memoryPosition.y][i] == PieceType::EMPTY) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x + SQUARE_SIZE * (i - memoryPosition.x),
                                                         piece->getPosition().y));
                } else if (memoryBoard[memoryPosition.y][i] == PieceType::BLACK_PAWN ||
                           memoryBoard[memoryPosition.y][i] == PieceType::BLACK_ROOK ||
                           memoryBoard[memoryPosition.y][i] == PieceType::BLACK_KNIGHT ||
                           memoryBoard[memoryPosition.y][i] == PieceType::BLACK_BISHOP ||
                           memoryBoard[memoryPosition.y][i] == PieceType::BLACK_QUEEN) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x + SQUARE_SIZE * (i - memoryPosition.x),
                                                         piece->getPosition().y));
                    break;
                } else {
                    break;
                }
            }

            // Checking if can move left
            for (int i = memoryPosition.x - 1; i >= 0; i--) {
                if (memoryBoard[memoryPosition.y][i] == PieceType::EMPTY) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x - SQUARE_SIZE * (memoryPosition.x - i),
                                                         piece->getPosition().y));
                } else if (memoryBoard[memoryPosition.y][i] == PieceType::BLACK_PAWN ||
                           memoryBoard[memoryPosition.y][i] == PieceType::BLACK_ROOK ||
                           memoryBoard[memoryPosition.y][i] == PieceType::BLACK_KNIGHT ||
                           memoryBoard[memoryPosition.y][i] == PieceType::BLACK_BISHOP ||
                           memoryBoard[memoryPosition.y][i] == PieceType::BLACK_QUEEN) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x - SQUARE_SIZE * (memoryPosition.x - i),
                                                         piece->getPosition().y));
                    break;
                } else {
                    break;
                }
            }

            // Checking if can move forward
            // y and x are reversed
            for (int i = memoryPosition.y + 1, j = memoryPosition.x + 1; i < BOARD_SIZE && j < BOARD_SIZE; i++, j++) {
                if (memoryBoard[i][j] == PieceType::EMPTY) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x + SQUARE_SIZE * (j - memoryPosition.x),
                                     piece->getPosition().y + SQUARE_SIZE * (i - memoryPosition.y)));
                } else if (memoryBoard[i][j] == PieceType::BLACK_PAWN || memoryBoard[i][j] == PieceType::BLACK_ROOK ||
                           memoryBoard[i][j] == PieceType::BLACK_KNIGHT ||
                           memoryBoard[i][j] == PieceType::BLACK_BISHOP ||
                           memoryBoard[i][j] == PieceType::BLACK_QUEEN) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x + SQUARE_SIZE * (j - memoryPosition.x),
                                     piece->getPosition().y + SQUARE_SIZE * (i - memoryPosition.y)));
                    break;
                } else {
                    break;
                }
            }

            // Checking if can move backward
            for (int i = memoryPosition.y - 1, j = memoryPosition.x - 1; i >= 0 && j >= 0; i--, j--) {
                if (memoryBoard[i][j] == PieceType::EMPTY) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x - SQUARE_SIZE * (memoryPosition.x - j),
                                     piece->getPosition().y - SQUARE_SIZE * (memoryPosition.y - i)));
                } else if (memoryBoard[i][j] == PieceType::BLACK_PAWN || memoryBoard[i][j] == PieceType::BLACK_ROOK ||
                           memoryBoard[i][j] == PieceType::BLACK_KNIGHT ||
                           memoryBoard[i][j] == PieceType::BLACK_BISHOP ||
                           memoryBoard[i][j] == PieceType::BLACK_QUEEN) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x - SQUARE_SIZE * (memoryPosition.x - j),
                                     piece->getPosition().y - SQUARE_SIZE * (memoryPosition.y - i)));
                    break;
                } else {
                    break;
                }
            }

            // Checking if can move right
            for (int i = memoryPosition.y + 1, j = memoryPosition.x - 1; i < BOARD_SIZE && j >= 0; i++, j--) {
                if (memoryBoard[i][j] == PieceType::EMPTY) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x - SQUARE_SIZE * (memoryPosition.x - j),
                                     piece->getPosition().y + SQUARE_SIZE * (i - memoryPosition.y)));
                } else if (memoryBoard[i][j] == PieceType::BLACK_PAWN || memoryBoard[i][j] == PieceType::BLACK_ROOK ||
                           memoryBoard[i][j] == PieceType::BLACK_KNIGHT ||
                           memoryBoard[i][j] == PieceType::BLACK_BISHOP ||
                           memoryBoard[i][j] == PieceType::BLACK_QUEEN) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x - SQUARE_SIZE * (memoryPosition.x - j),
                                     piece->getPosition().y + SQUARE_SIZE * (i - memoryPosition.y)));
                    break;
                } else {
                    break;
                }
            }

            // Checking if can move left
            for (int i = memoryPosition.y - 1, j = memoryPosition.x + 1; i >= 0 && j < BOARD_SIZE; i--, j++) {
                if (memoryBoard[i][j] == PieceType::EMPTY) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x + SQUARE_SIZE * (j - memoryPosition.x),
                                     piece->getPosition().y - SQUARE_SIZE * (memoryPosition.y - i)));
                } else if (memoryBoard[i][j] == PieceType::BLACK_PAWN || memoryBoard[i][j] == PieceType::BLACK_ROOK ||
                           memoryBoard[i][j] == PieceType::BLACK_KNIGHT ||
                           memoryBoard[i][j] == PieceType::BLACK_BISHOP ||
                           memoryBoard[i][j] == PieceType::BLACK_QUEEN) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x + SQUARE_SIZE * (j - memoryPosition.x),
                                     piece->getPosition().y - SQUARE_SIZE * (memoryPosition.y - i)));
                    break;
                } else {
                    break;
                }
            }

            return possibleMoves;
            break;
        }

        case PieceType::BLACK_QUEEN: {
            // Checking if can move forward
            sf::Vector2i memoryPosition = piece->getMemoryPosition();

            // Checking if can move forward
            // y and x are reversed
            for (int i = memoryPosition.y + 1; i < BOARD_SIZE; i++) {
                if (memoryBoard[i][memoryPosition.x] == PieceType::EMPTY) {
                    possibleMoves.push_back(sf::Vector2f(
                        piece->getPosition().x, piece->getPosition().y + SQUARE_SIZE * (i - memoryPosition.y)));
                } else if (memoryBoard[i][memoryPosition.x] == PieceType::WHITE_PAWN ||
                           memoryBoard[i][memoryPosition.x] == PieceType::WHITE_ROOK ||
                           memoryBoard[i][memoryPosition.x] == PieceType::WHITE_KNIGHT ||
                           memoryBoard[i][memoryPosition.x] == PieceType::WHITE_BISHOP ||
                           memoryBoard[i][memoryPosition.x] == PieceType::WHITE_QUEEN) {
                    possibleMoves.push_back(sf::Vector2f(
                        piece->getPosition().x, piece->getPosition().y + SQUARE_SIZE * (i - memoryPosition.y)));
                    break;
                } else {
                    break;
                }
            }

            // Checking if can move backward
            for (int i = memoryPosition.y - 1; i >= 0; i--) {
                if (memoryBoard[i][memoryPosition.x] == PieceType::EMPTY) {
                    possibleMoves.push_back(sf::Vector2f(
                        piece->getPosition().x, piece->getPosition().y - SQUARE_SIZE * (memoryPosition.y - i)));
                } else if (memoryBoard[i][memoryPosition.x] == PieceType::WHITE_PAWN ||
                           memoryBoard[i][memoryPosition.x] == PieceType::WHITE_ROOK ||
                           memoryBoard[i][memoryPosition.x] == PieceType::WHITE_KNIGHT ||
                           memoryBoard[i][memoryPosition.x] == PieceType::WHITE_BISHOP ||
                           memoryBoard[i][memoryPosition.x] == PieceType::WHITE_QUEEN) {
                    possibleMoves.push_back(sf::Vector2f(
                        piece->getPosition().x, piece->getPosition().y - SQUARE_SIZE * (memoryPosition.y - i)));
                    break;
                } else {
                    break;
                }
            }

            // Checking if can move right
            for (int i = memoryPosition.x + 1; i < BOARD_SIZE; i++) {
                if (memoryBoard[memoryPosition.y][i] == PieceType::EMPTY) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x + SQUARE_SIZE * (i - memoryPosition.x),
                                                         piece->getPosition().y));
                } else if (memoryBoard[memoryPosition.y][i] == PieceType::WHITE_PAWN ||
                           memoryBoard[memoryPosition.y][i] == PieceType::WHITE_ROOK ||
                           memoryBoard[memoryPosition.y][i] == PieceType::WHITE_KNIGHT ||
                           memoryBoard[memoryPosition.y][i] == PieceType::WHITE_BISHOP ||
                           memoryBoard[memoryPosition.y][i] == PieceType::WHITE_QUEEN) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x + SQUARE_SIZE * (i - memoryPosition.x),
                                                         piece->getPosition().y));
                    break;
                } else {
                    break;
                }
            }

            // Checking if can move left
            for (int i = memoryPosition.x - 1; i >= 0; i--) {
                if (memoryBoard[memoryPosition.y][i] == PieceType::EMPTY) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x - SQUARE_SIZE * (memoryPosition.x - i),
                                                         piece->getPosition().y));
                } else if (memoryBoard[memoryPosition.y][i] == PieceType::WHITE_PAWN ||
                           memoryBoard[memoryPosition.y][i] == PieceType::WHITE_ROOK ||
                           memoryBoard[memoryPosition.y][i] == PieceType::WHITE_KNIGHT ||
                           memoryBoard[memoryPosition.y][i] == PieceType::WHITE_BISHOP ||
                           memoryBoard[memoryPosition.y][i] == PieceType::WHITE_QUEEN) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x - SQUARE_SIZE * (memoryPosition.x - i),
                                                         piece->getPosition().y));
                    break;
                } else {
                    break;
                }
            }

            // Checking if can move forward
            // y and x are reversed
            for (int i = memoryPosition.y + 1, j = memoryPosition.x + 1; i < BOARD_SIZE && j < BOARD_SIZE; i++, j++) {
                if (memoryBoard[i][j] == PieceType::EMPTY) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x + SQUARE_SIZE * (j - memoryPosition.x),
                                     piece->getPosition().y + SQUARE_SIZE * (i - memoryPosition.y)));
                } else if (memoryBoard[i][j] == PieceType::WHITE_PAWN || memoryBoard[i][j] == PieceType::WHITE_ROOK ||
                           memoryBoard[i][j] == PieceType::WHITE_KNIGHT ||
                           memoryBoard[i][j] == PieceType::WHITE_BISHOP ||
                           memoryBoard[i][j] == PieceType::WHITE_QUEEN) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x + SQUARE_SIZE * (j - memoryPosition.x),
                                     piece->getPosition().y + SQUARE_SIZE * (i - memoryPosition.y)));
                    break;
                } else {
                    break;
                }
            }

            // Checking if can move backward
            for (int i = memoryPosition.y - 1, j = memoryPosition.x - 1; i >= 0 && j >= 0; i--, j--) {
                if (memoryBoard[i][j] == PieceType::EMPTY) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x - SQUARE_SIZE * (memoryPosition.x - j),
                                     piece->getPosition().y - SQUARE_SIZE * (memoryPosition.y - i)));
                } else if (memoryBoard[i][j] == PieceType::WHITE_PAWN || memoryBoard[i][j] == PieceType::WHITE_ROOK ||
                           memoryBoard[i][j] == PieceType::WHITE_KNIGHT ||
                           memoryBoard[i][j] == PieceType::WHITE_BISHOP ||
                           memoryBoard[i][j] == PieceType::WHITE_QUEEN) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x - SQUARE_SIZE * (memoryPosition.x - j),
                                     piece->getPosition().y - SQUARE_SIZE * (memoryPosition.y - i)));
                    break;
                } else {
                    break;
                }
            }

            // Checking if can move right
            for (int i = memoryPosition.y + 1, j = memoryPosition.x - 1; i < BOARD_SIZE && j >= 0; i++, j--) {
                if (memoryBoard[i][j] == PieceType::EMPTY) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x - SQUARE_SIZE * (memoryPosition.x - j),
                                     piece->getPosition().y + SQUARE_SIZE * (i - memoryPosition.y)));
                } else if (memoryBoard[i][j] == PieceType::WHITE_PAWN || memoryBoard[i][j] == PieceType::WHITE_ROOK ||
                           memoryBoard[i][j] == PieceType::WHITE_KNIGHT ||
                           memoryBoard[i][j] == PieceType::WHITE_BISHOP ||
                           memoryBoard[i][j] == PieceType::WHITE_QUEEN) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x - SQUARE_SIZE * (memoryPosition.x - j),
                                     piece->getPosition().y + SQUARE_SIZE * (i - memoryPosition.y)));
                    break;
                } else {
                    break;
                }
            }

            // Checking if can move left
            for (int i = memoryPosition.y - 1, j = memoryPosition.x + 1; i >= 0 && j < BOARD_SIZE; i--, j++) {
                if (memoryBoard[i][j] == PieceType::EMPTY) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x + SQUARE_SIZE * (j - memoryPosition.x),
                                     piece->getPosition().y - SQUARE_SIZE * (memoryPosition.y - i)));
                } else if (memoryBoard[i][j] == PieceType::WHITE_PAWN || memoryBoard[i][j] == PieceType::WHITE_ROOK ||
                           memoryBoard[i][j] == PieceType::WHITE_KNIGHT ||
                           memoryBoard[i][j] == PieceType::WHITE_BISHOP ||
                           memoryBoard[i][j] == PieceType::WHITE_QUEEN) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x + SQUARE_SIZE * (j - memoryPosition.x),
                                     piece->getPosition().y - SQUARE_SIZE * (memoryPosition.y - i)));
                    break;
                } else {
                    break;
                }
            }

            return possibleMoves;
            break;
        }

        case PieceType::WHITE_KING: {
            // TODO: Implement castling

            // Checking if can move forward
            sf::Vector2i memoryPosition = piece->getMemoryPosition();

            // Checking if can move forward
            // y and x are reversed
            if (memoryPosition.y + 1 < BOARD_SIZE) {
                if (memoryBoard[memoryPosition.y + 1][memoryPosition.x] == PieceType::EMPTY) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x, piece->getPosition().y + SQUARE_SIZE));
                } else if (memoryBoard[memoryPosition.y + 1][memoryPosition.x] == PieceType::BLACK_PAWN ||
                           memoryBoard[memoryPosition.y + 1][memoryPosition.x] == PieceType::BLACK_ROOK ||
                           memoryBoard[memoryPosition.y + 1][memoryPosition.x] == PieceType::BLACK_KNIGHT ||
                           memoryBoard[memoryPosition.y + 1][memoryPosition.x] == PieceType::BLACK_BISHOP ||
                           memoryBoard[memoryPosition.y + 1][memoryPosition.x] == PieceType::BLACK_QUEEN) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x, piece->getPosition().y + SQUARE_SIZE));
                }
            }

            // Checking if can move backward
            if (memoryPosition.y - 1 >= 0) {
                if (memoryBoard[memoryPosition.y - 1][memoryPosition.x] == PieceType::EMPTY) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x, piece->getPosition().y - SQUARE_SIZE));
                } else if (memoryBoard[memoryPosition.y - 1][memoryPosition.x] == PieceType::BLACK_PAWN ||
                           memoryBoard[memoryPosition.y - 1][memoryPosition.x] == PieceType::BLACK_ROOK ||
                           memoryBoard[memoryPosition.y - 1][memoryPosition.x] == PieceType::BLACK_KNIGHT ||
                           memoryBoard[memoryPosition.y - 1][memoryPosition.x] == PieceType::BLACK_BISHOP ||
                           memoryBoard[memoryPosition.y - 1][memoryPosition.x] == PieceType::BLACK_QUEEN) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x, piece->getPosition().y - SQUARE_SIZE));
                }
            }

            // Checking if can move right
            if (memoryPosition.x + 1 < BOARD_SIZE) {
                if (memoryBoard[memoryPosition.y][memoryPosition.x + 1] == PieceType::EMPTY) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x + SQUARE_SIZE, piece->getPosition().y));
                } else if (memoryBoard[memoryPosition.y][memoryPosition.x + 1] == PieceType::BLACK_PAWN ||
                           memoryBoard[memoryPosition.y][memoryPosition.x + 1] == PieceType::BLACK_ROOK ||
                           memoryBoard[memoryPosition.y][memoryPosition.x + 1] == PieceType::BLACK_KNIGHT ||
                           memoryBoard[memoryPosition.y][memoryPosition.x + 1] == PieceType::BLACK_BISHOP ||
                           memoryBoard[memoryPosition.y][memoryPosition.x + 1] == PieceType::BLACK_QUEEN) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x + SQUARE_SIZE, piece->getPosition().y));
                }
            }

            // Checking if can move left
            if (memoryPosition.x - 1 >= 0) {
                if (memoryBoard[memoryPosition.y][memoryPosition.x - 1] == PieceType::EMPTY) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x - SQUARE_SIZE, piece->getPosition().y));
                } else if (memoryBoard[memoryPosition.y][memoryPosition.x - 1] == PieceType::BLACK_PAWN ||
                           memoryBoard[memoryPosition.y][memoryPosition.x - 1] == PieceType::BLACK_ROOK ||
                           memoryBoard[memoryPosition.y][memoryPosition.x - 1] == PieceType::BLACK_KNIGHT ||
                           memoryBoard[memoryPosition.y][memoryPosition.x - 1] == PieceType::BLACK_BISHOP ||
                           memoryBoard[memoryPosition.y][memoryPosition.x - 1] == PieceType::BLACK_QUEEN) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x - SQUARE_SIZE, piece->getPosition().y));
                }
            }

            // Checking if can move forward right
            if (memoryPosition.y + 1 < BOARD_SIZE && memoryPosition.x + 1 < BOARD_SIZE) {
                if (memoryBoard[memoryPosition.y + 1][memoryPosition.x + 1] == PieceType::EMPTY) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x + SQUARE_SIZE, piece->getPosition().y + SQUARE_SIZE));
                } else if (memoryBoard[memoryPosition.y + 1][memoryPosition.x + 1] == PieceType::BLACK_PAWN ||
                           memoryBoard[memoryPosition.y + 1][memoryPosition.x + 1] == PieceType::BLACK_ROOK ||
                           memoryBoard[memoryPosition.y + 1][memoryPosition.x + 1] == PieceType::BLACK_KNIGHT ||
                           memoryBoard[memoryPosition.y + 1][memoryPosition.x + 1] == PieceType::BLACK_BISHOP ||
                           memoryBoard[memoryPosition.y + 1][memoryPosition.x + 1] == PieceType::BLACK_QUEEN) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x + SQUARE_SIZE, piece->getPosition().y + SQUARE_SIZE));
                }
            }

            // Checking if can move forward left
            if (memoryPosition.y + 1 < BOARD_SIZE && memoryPosition.x - 1 >= 0) {
                if (memoryBoard[memoryPosition.y + 1][memoryPosition.x - 1] == PieceType::EMPTY) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x - SQUARE_SIZE, piece->getPosition().y + SQUARE_SIZE));
                } else if (memoryBoard[memoryPosition.y + 1][memoryPosition.x - 1] == PieceType::BLACK_PAWN ||
                           memoryBoard[memoryPosition.y + 1][memoryPosition.x - 1] == PieceType::BLACK_ROOK ||
                           memoryBoard[memoryPosition.y + 1][memoryPosition.x - 1] == PieceType::BLACK_KNIGHT ||
                           memoryBoard[memoryPosition.y + 1][memoryPosition.x - 1] == PieceType::BLACK_BISHOP ||
                           memoryBoard[memoryPosition.y + 1][memoryPosition.x - 1] == PieceType::BLACK_QUEEN) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x - SQUARE_SIZE, piece->getPosition().y + SQUARE_SIZE));
                }
            }

            // Checking if can move backward right
            if (memoryPosition.y - 1 >= 0 && memoryPosition.x + 1 < BOARD_SIZE) {
                if (memoryBoard[memoryPosition.y - 1][memoryPosition.x + 1] == PieceType::EMPTY) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x + SQUARE_SIZE, piece->getPosition().y - SQUARE_SIZE));
                } else if (memoryBoard[memoryPosition.y - 1][memoryPosition.x + 1] == PieceType::BLACK_PAWN ||
                           memoryBoard[memoryPosition.y - 1][memoryPosition.x + 1] == PieceType::BLACK_ROOK ||
                           memoryBoard[memoryPosition.y - 1][memoryPosition.x + 1] == PieceType::BLACK_KNIGHT ||
                           memoryBoard[memoryPosition.y - 1][memoryPosition.x + 1] == PieceType::BLACK_BISHOP ||
                           memoryBoard[memoryPosition.y - 1][memoryPosition.x + 1] == PieceType::BLACK_QUEEN) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x + SQUARE_SIZE, piece->getPosition().y - SQUARE_SIZE));
                }
            }

            // Checking if can move backward left
            if (memoryPosition.y - 1 >= 0 && memoryPosition.x - 1 >= 0) {
                if (memoryBoard[memoryPosition.y - 1][memoryPosition.x - 1] == PieceType::EMPTY) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x - SQUARE_SIZE, piece->getPosition().y - SQUARE_SIZE));
                } else if (memoryBoard[memoryPosition.y - 1][memoryPosition.x - 1] == PieceType::BLACK_PAWN ||
                           memoryBoard[memoryPosition.y - 1][memoryPosition.x - 1] == PieceType::BLACK_ROOK ||
                           memoryBoard[memoryPosition.y - 1][memoryPosition.x - 1] == PieceType::BLACK_KNIGHT ||
                           memoryBoard[memoryPosition.y - 1][memoryPosition.x - 1] == PieceType::BLACK_BISHOP ||
                           memoryBoard[memoryPosition.y - 1][memoryPosition.x - 1] == PieceType::BLACK_QUEEN) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x - SQUARE_SIZE, piece->getPosition().y - SQUARE_SIZE));
                }
            }

            return possibleMoves;
            break;
        }

        case PieceType::BLACK_KING: {
            // Checking if can move forward
            sf::Vector2i memoryPosition = piece->getMemoryPosition();

            // Checking if can move forward
            // y and x are reversed
            if (memoryPosition.y + 1 < BOARD_SIZE) {
                if (memoryBoard[memoryPosition.y + 1][memoryPosition.x] == PieceType::EMPTY) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x, piece->getPosition().y + SQUARE_SIZE));
                } else if (memoryBoard[memoryPosition.y + 1][memoryPosition.x] == PieceType::WHITE_PAWN ||
                           memoryBoard[memoryPosition.y + 1][memoryPosition.x] == PieceType::WHITE_ROOK ||
                           memoryBoard[memoryPosition.y + 1][memoryPosition.x] == PieceType::WHITE_KNIGHT ||
                           memoryBoard[memoryPosition.y + 1][memoryPosition.x] == PieceType::WHITE_BISHOP ||
                           memoryBoard[memoryPosition.y + 1][memoryPosition.x] == PieceType::WHITE_QUEEN) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x, piece->getPosition().y + SQUARE_SIZE));
                }
            }

            // Checking if can move backward
            if (memoryPosition.y - 1 >= 0) {
                if (memoryBoard[memoryPosition.y - 1][memoryPosition.x] == PieceType::EMPTY) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x, piece->getPosition().y - SQUARE_SIZE));
                } else if (memoryBoard[memoryPosition.y - 1][memoryPosition.x] == PieceType::WHITE_PAWN ||
                           memoryBoard[memoryPosition.y - 1][memoryPosition.x] == PieceType::WHITE_ROOK ||
                           memoryBoard[memoryPosition.y - 1][memoryPosition.x] == PieceType::WHITE_KNIGHT ||
                           memoryBoard[memoryPosition.y - 1][memoryPosition.x] == PieceType::WHITE_BISHOP ||
                           memoryBoard[memoryPosition.y - 1][memoryPosition.x] == PieceType::WHITE_QUEEN) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x, piece->getPosition().y - SQUARE_SIZE));
                }
            }

            // Checking if can move right
            if (memoryPosition.x + 1 < BOARD_SIZE) {
                if (memoryBoard[memoryPosition.y][memoryPosition.x + 1] == PieceType::EMPTY) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x + SQUARE_SIZE, piece->getPosition().y));
                    // Checking if can castle
                    if (memoryPosition.x + 3 < BOARD_SIZE) {
                        if (memoryBoard[memoryPosition.y][memoryPosition.x + 2] == PieceType::EMPTY &&
                            memoryBoard[memoryPosition.y][memoryPosition.x + 3] == PieceType::BLACK_ROOK) {
                            Piece* getRook = this->getPieceAtPosition(memoryPosition.y, memoryPosition.x + 3);
                            if (getRook->getPieceType() == PieceType::BLACK_ROOK &&
                                (piece->getIsFirstMove() && getRook->getIsFirstMove())) {
                                possibleMoves.push_back(
                                    sf::Vector2f(piece->getPosition().x + SQUARE_SIZE * 2, piece->getPosition().y));
                                piece->setCanCastleKingSide(true);
                                getRook->setCanCastleKingSide(true);
                            }
                        }
                    }
                } else if (memoryBoard[memoryPosition.y][memoryPosition.x + 1] == PieceType::WHITE_PAWN ||
                           memoryBoard[memoryPosition.y][memoryPosition.x + 1] == PieceType::WHITE_ROOK ||
                           memoryBoard[memoryPosition.y][memoryPosition.x + 1] == PieceType::WHITE_KNIGHT ||
                           memoryBoard[memoryPosition.y][memoryPosition.x + 1] == PieceType::WHITE_BISHOP ||
                           memoryBoard[memoryPosition.y][memoryPosition.x + 1] == PieceType::WHITE_QUEEN) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x + SQUARE_SIZE, piece->getPosition().y));
                }
            }

            // Checking if can move left
            if (memoryPosition.x - 1 >= 0) {
                if (memoryBoard[memoryPosition.y][memoryPosition.x - 1] == PieceType::EMPTY) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x - SQUARE_SIZE, piece->getPosition().y));
                    if (memoryPosition.x - 4 < BOARD_SIZE) {
                        if (memoryBoard[memoryPosition.y][memoryPosition.x - 2] == PieceType::EMPTY &&
                            memoryBoard[memoryPosition.y][memoryPosition.x - 3] == PieceType::EMPTY &&
                            memoryBoard[memoryPosition.y][memoryPosition.x - 4] == PieceType::BLACK_ROOK) {
                            Piece* getRook = this->getPieceAtPosition(memoryPosition.y, memoryPosition.x - 4);
                            if (getRook->getPieceType() == PieceType::BLACK_ROOK &&
                                (piece->getIsFirstMove() && getRook->getIsFirstMove())) {
                                possibleMoves.push_back(
                                    sf::Vector2f(piece->getPosition().x + SQUARE_SIZE * 2, piece->getPosition().y));
                                piece->setCanCastleKingSide(true);
                                getRook->setCanCastleKingSide(true);
                            }
                        }
                    }
                } else if (memoryBoard[memoryPosition.y][memoryPosition.x - 1] == PieceType::WHITE_PAWN ||
                           memoryBoard[memoryPosition.y][memoryPosition.x - 1] == PieceType::WHITE_ROOK ||
                           memoryBoard[memoryPosition.y][memoryPosition.x - 1] == PieceType::WHITE_KNIGHT ||
                           memoryBoard[memoryPosition.y][memoryPosition.x - 1] == PieceType::WHITE_BISHOP ||
                           memoryBoard[memoryPosition.y][memoryPosition.x - 1] == PieceType::WHITE_QUEEN) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x - SQUARE_SIZE, piece->getPosition().y));
                }
            }

            // Checking if can move forward right
            if (memoryPosition.y + 1 < BOARD_SIZE && memoryPosition.x + 1 < BOARD_SIZE) {
                if (memoryBoard[memoryPosition.y + 1][memoryPosition.x + 1] == PieceType::EMPTY) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x + SQUARE_SIZE, piece->getPosition().y + SQUARE_SIZE));
                } else if (memoryBoard[memoryPosition.y + 1][memoryPosition.x + 1] == PieceType::WHITE_PAWN ||
                           memoryBoard[memoryPosition.y + 1][memoryPosition.x + 1] == PieceType::WHITE_ROOK ||
                           memoryBoard[memoryPosition.y + 1][memoryPosition.x + 1] == PieceType::WHITE_KNIGHT ||
                           memoryBoard[memoryPosition.y + 1][memoryPosition.x + 1] == PieceType::WHITE_BISHOP ||
                           memoryBoard[memoryPosition.y + 1][memoryPosition.x + 1] == PieceType::WHITE_QUEEN) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x + SQUARE_SIZE, piece->getPosition().y + SQUARE_SIZE));
                }
            }

            // Checking if can move forward left
            if (memoryPosition.y + 1 < BOARD_SIZE && memoryPosition.x - 1 >= 0) {
                if (memoryBoard[memoryPosition.y + 1][memoryPosition.x - 1] == PieceType::EMPTY) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x - SQUARE_SIZE, piece->getPosition().y + SQUARE_SIZE));
                } else if (memoryBoard[memoryPosition.y + 1][memoryPosition.x - 1] == PieceType::WHITE_PAWN ||
                           memoryBoard[memoryPosition.y + 1][memoryPosition.x - 1] == PieceType::WHITE_ROOK ||
                           memoryBoard[memoryPosition.y + 1][memoryPosition.x - 1] == PieceType::WHITE_KNIGHT ||
                           memoryBoard[memoryPosition.y + 1][memoryPosition.x - 1] == PieceType::WHITE_BISHOP ||
                           memoryBoard[memoryPosition.y + 1][memoryPosition.x - 1] == PieceType::WHITE_QUEEN) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x - SQUARE_SIZE, piece->getPosition().y + SQUARE_SIZE));
                }
            }

            // Checking if can move backward right
            if (memoryPosition.y - 1 >= 0 && memoryPosition.x + 1 < BOARD_SIZE) {
                if (memoryBoard[memoryPosition.y - 1][memoryPosition.x + 1] == PieceType::EMPTY) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x + SQUARE_SIZE, piece->getPosition().y - SQUARE_SIZE));
                } else if (memoryBoard[memoryPosition.y - 1][memoryPosition.x + 1] == PieceType::WHITE_PAWN ||
                           memoryBoard[memoryPosition.y - 1][memoryPosition.x + 1] == PieceType::WHITE_ROOK ||
                           memoryBoard[memoryPosition.y - 1][memoryPosition.x + 1] == PieceType::WHITE_KNIGHT ||
                           memoryBoard[memoryPosition.y - 1][memoryPosition.x + 1] == PieceType::WHITE_BISHOP ||
                           memoryBoard[memoryPosition.y - 1][memoryPosition.x + 1] == PieceType::WHITE_QUEEN) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x + SQUARE_SIZE, piece->getPosition().y - SQUARE_SIZE));
                }
            }

            // Checking if can move backward left
            if (memoryPosition.y - 1 >= 0 && memoryPosition.x - 1 >= 0) {
                if (memoryBoard[memoryPosition.y - 1][memoryPosition.x - 1] == PieceType::EMPTY) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x - SQUARE_SIZE, piece->getPosition().y - SQUARE_SIZE));
                } else if (memoryBoard[memoryPosition.y - 1][memoryPosition.x - 1] == PieceType::WHITE_PAWN ||
                           memoryBoard[memoryPosition.y - 1][memoryPosition.x - 1] == PieceType::WHITE_ROOK ||
                           memoryBoard[memoryPosition.y - 1][memoryPosition.x - 1] == PieceType::WHITE_KNIGHT ||
                           memoryBoard[memoryPosition.y - 1][memoryPosition.x - 1] == PieceType::WHITE_BISHOP ||
                           memoryBoard[memoryPosition.y - 1][memoryPosition.x - 1] == PieceType::WHITE_QUEEN) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x - SQUARE_SIZE, piece->getPosition().y - SQUARE_SIZE));
                }
            }

            return possibleMoves;
            break;
        }

        case PieceType::BLACK_PAWN: {
            // Checking if can move forward
            sf::Vector2i memoryPosition = piece->getMemoryPosition();

            // Checking if can move forward
            // y and x are reversed
            if (memoryPosition.y + 1 < BOARD_SIZE) {
                if (memoryBoard[memoryPosition.y + 1][memoryPosition.x] == PieceType::EMPTY) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x, piece->getPosition().y + SQUARE_SIZE));
                    if (piece->getIsFirstMove() &&
                        memoryBoard[memoryPosition.y + 2][memoryPosition.x] == PieceType::EMPTY) {
                        possibleMoves.push_back(
                            sf::Vector2f(piece->getPosition().x, piece->getPosition().y + SQUARE_SIZE * 2));
                    }
                }
                if (memoryBoard[memoryPosition.y + 1][memoryPosition.x - 1] == PieceType::WHITE_PAWN ||
                    memoryBoard[memoryPosition.y + 1][memoryPosition.x - 1] == PieceType::WHITE_ROOK ||
                    memoryBoard[memoryPosition.y + 1][memoryPosition.x - 1] == PieceType::WHITE_KNIGHT ||
                    memoryBoard[memoryPosition.y + 1][memoryPosition.x - 1] == PieceType::WHITE_BISHOP ||
                    memoryBoard[memoryPosition.y + 1][memoryPosition.x - 1] == PieceType::WHITE_QUEEN) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x - SQUARE_SIZE, piece->getPosition().y + SQUARE_SIZE));
                }
                if (memoryBoard[memoryPosition.y + 1][memoryPosition.x + 1] == PieceType::WHITE_PAWN ||
                    memoryBoard[memoryPosition.y + 1][memoryPosition.x + 1] == PieceType::WHITE_ROOK ||
                    memoryBoard[memoryPosition.y + 1][memoryPosition.x + 1] == PieceType::WHITE_KNIGHT ||
                    memoryBoard[memoryPosition.y + 1][memoryPosition.x + 1] == PieceType::WHITE_BISHOP ||
                    memoryBoard[memoryPosition.y + 1][memoryPosition.x + 1] == PieceType::WHITE_QUEEN) {
                    possibleMoves.push_back(
                        sf::Vector2f(piece->getPosition().x + SQUARE_SIZE, piece->getPosition().y + SQUARE_SIZE));
                }
            }

            return possibleMoves;
            break;
        }

        default:
            break;
    }
    // TODO: Implement this function
    return std::vector<sf::Vector2f>();
}

void Movement::movePiece(Piece* piece, sf::Vector2i relativePosition) {
    // Smoothly move the piece to the given relative position
    // this->memoryBoard[piece->getMemoryPosition().y][piece->getMemoryPosition().x] = PieceType::EMPTY;
    // this->memoryBoard[relativePosition.y][relativePosition.x] = piece->getType();
    // piece->setPosition(sf::Vector2f(relativePosition.x * SQUARE_SIZE, relativePosition.y * SQUARE_SIZE));
}

void Movement::updateMemoryBoard(PieceType** memoryBoard) { this->memoryBoard = memoryBoard; }

Piece* Movement::getPieceAtPosition(int x, int y) { return this->board->getPiece(x, y); }
