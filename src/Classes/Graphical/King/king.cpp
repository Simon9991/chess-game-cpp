#include "king.hpp"

#include "./../../../include/main.hpp"

King::King(int x, int y, int size, sf::Color color) {
    this->x = x;
    this->y = y;
    this->position = sf::Vector2f(x, y);
    this->size = size;
    this->color = color;
    this->shape = sf::CircleShape(size / 2);
    this->shape.setPosition(position);
    this->shape.setFillColor(color);

    if (DEBUG) {
        std::cout << "King created at " << x << "x" << y << " with size " << size << " and color " << color.toInteger()
                  << std::endl;
        this->shape.setOutlineColor(GREEN);
        this->shape.setOutlineThickness(1);
    }
}

King::~King() {}

void King::draw(sf::RenderWindow& window) { window.draw(this->shape); }

sf::Vector2f King::getPosition() { return this->position; }

int King::getSize() { return this->size; }

sf::Color King::getColor() { return this->color; }

void King::setPosition(sf::Vector2f position) {
    this->position = position;
    this->shape.setPosition(position);
}

void King::setSize(int size) {
    this->size = size;
    this->shape.setRadius(size / 2);
}

void King::setColor(sf::Color color) {
    this->color = color;
    this->shape.setFillColor(color);
}
