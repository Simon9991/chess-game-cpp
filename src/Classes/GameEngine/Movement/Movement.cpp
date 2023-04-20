#include "movement.hpp"

#include "./../../../include/main.hpp"

Movement::Movement(PieceType** memoryBoard) { this->memoryBoard = memoryBoard; }

Movement::~Movement() {}

std::vector<sf::Vector2f> Movement::getPossibleMoves(Piece* piece) {
    std::vector<sf::Vector2f> possibleMoves;

    switch (piece->getType()) {
        case PieceType::WHITE_PAWN: {
            // Checking if can move forward
            sf::Vector2i memoryPosition = piece->getMemoryPosition();

            // Checking if can move forward
            // y and x are reversed
            if (memoryPosition.y - 1 >= 0) {
                std::cout << "Checking if can move" << std::endl;
                if (memoryBoard[memoryPosition.y - 1][memoryPosition.x] == PieceType::EMPTY) {
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x, piece->getPosition().y - SQUARE_SIZE));
                } else {
                    if (memoryBoard[memoryPosition.y - 1][memoryPosition.x - 1] == PieceType::BLACK_PAWN) {
                        possibleMoves.push_back(
                            sf::Vector2f(piece->getPosition().x - SQUARE_SIZE, piece->getPosition().y - SQUARE_SIZE));
                    }
                    if (memoryBoard[memoryPosition.y - 1][memoryPosition.x + 1] == PieceType::BLACK_PAWN) {
                        possibleMoves.push_back(
                            sf::Vector2f(piece->getPosition().x + SQUARE_SIZE, piece->getPosition().y - SQUARE_SIZE));
                    }
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
