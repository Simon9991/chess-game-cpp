#include "piece.hpp"

#include "./../../../include/main.hpp"

Piece::Piece(sf::Vector2f position, PieceType type, sf::Color color, int size, PieceColor pieceColor, int x, int y) {
    this->position = position;
    this->x = x;
    this->y = y;
    this->type = type;
    this->color = color;
    this->pieceColor = pieceColor;
    this->shape = sf::CircleShape(size / 2);
    this->shape.setFillColor(color);
    this->shape.setPosition(position);

    this->size = size;

    if (DEBUG) {
        std::cout << "Piece created at " << this->x << "x" << this->y << std::endl;
        // Red outline
        this->shape.setOutlineColor(sf::Color::Red);
        this->shape.setOutlineThickness(1);
    }
}

Piece::~Piece() {}

sf::Vector2f Piece::getPosition() { return this->position; }

int Piece::getX() { return this->x; }

int Piece::getY() { return this->y; }

PieceType Piece::getType() { return this->type; }

sf::Color Piece::getColor() { return this->color; }

void Piece::setPosition(sf::Vector2f position) {
    this->position = position;
    this->x = position.x;
    this->y = position.y;
}

void Piece::draw(sf::RenderWindow &window) { window.draw(this->shape); }

PieceColor Piece::getPieceColor() { return this->pieceColor; }
