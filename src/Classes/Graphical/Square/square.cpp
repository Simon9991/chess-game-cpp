#include "square.hpp"

#include "./../../../include/main.hpp"

Square::Square(int x, int y, int size, sf::Color color) {
    this->position = sf::Vector2f(x, y);
    this->size = size;
    this->color = color;
    this->shape = sf::RectangleShape(sf::Vector2f(size, size));
    this->shape.setPosition(position);
    this->shape.setFillColor(color);

    if (DEBUG) {
        std::cout << "Square created at " << x << "x" << y << " with size " << size << " and color "
                  << color.toInteger() << std::endl;
        // this->shape.setOutlineColor(GREEN);
        // this->shape.setOutlineThickness(1);
    }
}

Square::~Square() {
    // Nothing to do
}

void Square::draw(sf::RenderWindow& window) { window.draw(this->shape); }

sf::Vector2f Square::getPosition() { return sf::Vector2f(); }

int Square::getSize() { return this->size; }

sf::Color Square::getColor() { return this->color; }

void Square::setPosition(sf::Vector2f position) { this->position = position; }

void Square::setSize(int size) { this->size = size; }

void Square::setColor(sf::Color color) { this->color = color; }
