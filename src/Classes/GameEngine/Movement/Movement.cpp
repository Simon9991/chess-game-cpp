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
                if (memoryBoard[memoryPosition.y - 1][memoryPosition.x] == PieceType::EMPTY) {
                    if (DEBUG)
                        std::cout << "Can move forward to: " << memoryPosition.x << "x" << memoryPosition.y - 1
                                  << std::endl;
                    // TODO: Add the position to the vector
                    possibleMoves.push_back(sf::Vector2f(piece->getPosition().x, piece->getPosition().y - SQUARE_SIZE));
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
