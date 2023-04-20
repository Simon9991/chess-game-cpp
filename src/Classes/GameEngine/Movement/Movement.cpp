#include "movement.hpp"

#include "./../../../include/main.hpp"

Movement::Movement(PieceType** memoryBoard) { this->memoryBoard = memoryBoard; }

Movement::~Movement() {}

std::vector<sf::Vector2f> Movement::getPossibleMoves(Piece* piece) {
    std::vector<sf::Vector2f> possibleMoves;

    std::cout << "Getting possible moves" << std::endl;
    switch (piece->getType()) {
        std::cout << "Piece type: " << piece->getType() << std::endl;
        case PieceType::WHITE_PAWN: {
            std::cout << "White pawn" << std::endl;
            // Checking if can move forward
            sf::Vector2i memoryPosition = piece->getMemoryPosition();

            // printing the memory position
            std::cout << "Memory position: " << memoryPosition.x << "x" << memoryPosition.y << std::endl;

            // Checking if can move forward
            // y and x are reversed
            if (memoryPosition.y - 1 >= 0) {
                std::cout << "Checking if can move" << std::endl;
                if (memoryBoard[memoryPosition.y - 1][memoryPosition.x] == PieceType::EMPTY) {
                    // if (DEBUG)
                    //     std::cout << "Can move forward to: " << memoryPosition.x << "x" << memoryPosition.y - 1
                    //               << std::endl;
                    // TODO: Add the position to the vector
                    std::cout << "Can move forward to: " << memoryPosition.x << "x" << memoryPosition.y - 1
                              << std::endl;
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x, piece->getPosition().y - SQUARE_SIZE));
                } else {
                    std::cout << "Can't move forward" << std::endl;
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
