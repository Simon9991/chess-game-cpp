#include "Movement.hpp"

#include "./../../../include/main.hpp"

Movement::Movement(Piece* piece) {
    this->piece = piece;
    this->possibleMoves = std::vector<sf::Vector2f>();
}

Movement::~Movement() {
    delete this->piece;
    this->possibleMoves.clear();
}

std::vector<sf::Vector2f> Movement::getPossibleMoves() {
    switch (piece->getType()) {
        case Pieces::PAWN:
            // Can only move forward by the same amount of SQUARE_SIZE
            return std::vector<sf::Vector2f>{
                sf::Vector2f(this->piece->getPosition().x, this->piece->getPosition().y + SQUARE_SIZE)};
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
