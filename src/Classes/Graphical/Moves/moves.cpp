#include "moves.hpp"

#include "./../../../include/main.hpp"

Moves::Moves() { this->possibleMoves = std::vector<sf::CircleShape>(); }

Moves::~Moves() {}

void Moves::draw(sf::RenderWindow& window) {
    for (size_t i = 0; i < possibleMoves.size(); i++) {
        window.draw(possibleMoves[i]);
    }
}

void Moves::setPossibleMoves(std::vector<sf::Vector2f> possibleMoves) {
    this->possibleMoves = std::vector<sf::CircleShape>();
    float circleRadius = SQUARE_SIZE / 2 * 0.2;
    for (int i = 0; i < possibleMoves.size(); i++) {
        sf::CircleShape circle;
        circle.setRadius(circleRadius);
        // Grey color
        circle.setFillColor(sf::Color(192, 192, 192));
        circle.setOutlineColor(sf::Color::Black);
        circle.setOutlineThickness(1);
        sf::Vector2f squarePosition = possibleMoves[i];
        sf::Vector2f squareCenter = squarePosition + sf::Vector2f(SQUARE_SIZE / 2, SQUARE_SIZE / 2);
        sf::Vector2f circlePosition = squareCenter - sf::Vector2f(circleRadius, circleRadius);
        circle.setPosition(circlePosition);
        this->possibleMoves.push_back(circle);
    }
}

void Moves::clear() { this->possibleMoves = std::vector<sf::CircleShape>(); }

sf::Vector2i Moves::getRelativePossibleMoves() { return sf::Vector2i(); }
