#include "mouse_input.hpp"

MouseInput::MouseInput() {
    this->position = sf::Vector2i(0, 0);
    this->positionClick = sf::Vector2i(0, 0);
    this->clicked = false;
}

MouseInput::~MouseInput() {}

sf::Vector2i MouseInput::getPosition(sf::RenderWindow& window) {
    this->position = sf::Mouse::getPosition(window);
    return this->position;
}

bool MouseInput::isClicked(sf::RenderWindow& window) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        this->positionClick = sf::Mouse::getPosition(window);
        this->clicked = true;
    } else {
        this->clicked = false;
    }
    return this->clicked;
}

sf::Vector2i MouseInput::getPositionClick(sf::RenderWindow& window) {
    if (this->clicked) {
        this->positionClick = sf::Mouse::getPosition(window);
        return this->positionClick;
    } else {
        return sf::Vector2i(0, 0);
    }
}
