#include "piece.hpp"

#include "./../../../include/main.hpp"

Piece::Piece(sf::Vector2f position, int x, int y) {
    // Creates an "EMPTY" piece, it has no color and is totally transparent
    this->position = position;
    this->x = x;
    this->y = y;
    this->type = PieceType::EMPTY;
    this->color = sf::Color::Transparent;
    this->shape = sf::CircleShape(SQUARE_SIZE / 2);
    this->shape.setFillColor(color);
    this->shape.setPosition(position);

    this->size = SQUARE_SIZE / 2;

    if (DEBUG) {
        std::cout << "Empty piece created at " << this->x << "x" << this->y << std::endl;
        // Red outline
        this->shape.setOutlineColor(sf::Color::Red);
        this->shape.setOutlineThickness(1);
    }
}

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

    // Creating an Image to display
    sf::Image image;
    if (!image.loadFromFile("./src/Assets/Sprites/w_king.png")) {
        std::cout << "Error loading the image" << std::endl;
    } else {
        std::cout << "Image loaded" << std::endl;
    }
    sf::Texture texture;
    texture.loadFromImage(image);
    this->sprite = sf::Sprite();
    this->sprite.setTexture(texture);
    this->sprite.setPosition(100, 100);
    this->sprite.setScale(0.6, 0.6);

    if (DEBUG) {
        std::cout << "Piece created at " << this->x << "x" << this->y << " value: " << this->type
                  << " color: " << this->pieceColor << std::endl;
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

void Piece::draw(sf::RenderWindow &window) {
    window.draw(this->shape);
    window.draw(this->sprite);
}

PieceColor Piece::getPieceColor() { return this->pieceColor; }

PieceType Piece::getPieceType() { return this->type; }
