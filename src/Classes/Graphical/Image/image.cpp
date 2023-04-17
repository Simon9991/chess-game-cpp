#include "image.hpp"

Image::Image(std::string path, sf::Vector2f position, sf::Vector2f size, sf::Color color) {
    this->texture = new sf::Texture();
    this->sprite = new sf::Sprite();
    this->position = position;
    this->size = size;
    this->color = color;
    this->load(path);

    if (DEBUG) {
        std::cout << "Image created at " << this->position.x << "x" << this->position.y << std::endl;
    }
}

Image::Image(std::string path, sf::Vector2f position, sf::Vector2f size) {
    this->texture = new sf::Texture();
    this->sprite = new sf::Sprite();
    this->position = position;
    this->size = size;
    this->color = sf::Color::White;
    this->load(path);

    if (DEBUG) {
        std::cout << "Image created at " << this->position.x << "x" << this->position.y << std::endl;
    }
}

Image::~Image() {
    delete this->texture;
    delete this->sprite;
}

void Image::load(std::string path) {
    this->texture->loadFromFile(path);
    this->sprite->setTexture(*this->texture);
    this->sprite->setPosition(this->position);
    this->sprite->setScale(this->size.x / this->texture->getSize().x, this->size.y / this->texture->getSize().y);
    this->sprite->setColor(this->color);
}

void Image::draw(sf::RenderWindow& window) { window.draw(*this->sprite); }

void Image::setPosition(sf::Vector2f position) {
    this->position = position;
    this->sprite->setPosition(this->position);
}

void Image::setSize(sf::Vector2f size) {
    this->size = size;
    this->sprite->setScale(this->size.x / this->texture->getSize().x, this->size.y / this->texture->getSize().y);
}

void Image::setColor(sf::Color color) {
    this->color = color;
    this->sprite->setColor(this->color);
}

sf::Vector2f Image::getPosition() { return this->position; }

sf::Vector2f Image::getSize() { return this->size; }

sf::Color Image::getColor() { return this->color; }
