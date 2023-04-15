#include "Movement.hpp"

#include "./../../../include/main.hpp"

Movement::Movement(Piece* piece, PieceType** memoryBoard) {
    this->piece = piece;
    this->possibleMoves = std::vector<sf::Vector2f>();
    this->memoryBoard = memoryBoard;
}

Movement::~Movement() {
    delete this->piece;
    this->possibleMoves.clear();
}

std::vector<sf::Vector2f> Movement::getPossibleMoves() {
    switch (piece->getType()) {
        case PieceType::PAWN:
            // Checking the piece color
            if (piece->getPieceColor() == PieceColor::WHITE_PIECE) {
                // Checking if can move forward
                if (this->memoryBoard[this->piece->getX()][this->piece->getY() - 1] == PieceType::EMPTY) {
                    this->possibleMoves.push_back(sf::Vector2f(this->piece->getX(), this->piece->getY() - 1));
                    if (DEBUG) {
                        std::cout << "Piece " << this->piece->getX() << "x" << this->piece->getY() << " can move to "
                                  << this->piece->getX() << "x" << this->piece->getY() - 1 << std::endl;
                    }
                }
            }

            return this->possibleMoves;
            break;
        default:
            break;
    }
    // TODO: Implement this function
    return std::vector<sf::Vector2f>();
}

std::vector<sf::Vector2f> Movement::getPossibleMoves(sf::Vector2f position) { return std::vector<sf::Vector2f>(); }

std::vector<sf::Vector2f> Movement::getPossibleMoves(int x, int y) { return std::vector<sf::Vector2f>(); }

std::vector<sf::Vector2f> Movement::getPossibleMoves(int x, int y, sf::Vector2f position) {
    return std::vector<sf::Vector2f>();
}
