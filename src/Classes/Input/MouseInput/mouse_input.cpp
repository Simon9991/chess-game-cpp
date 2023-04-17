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

Piece* MouseInput::isClickedOnPiece(sf::RenderWindow& window, Board* board) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        this->positionClick = sf::Mouse::getPosition(window);
        this->clicked = true;
    } else {
        this->clicked = false;
    }
    if (this->clicked) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board->getPieceType(i, j) != PieceType::EMPTY) {
                    if (board->getPiece(i, j)->getImage()->getSprite()->getGlobalBounds().contains(
                            this->positionClick.x, this->positionClick.y)) {
                        return board->getPiece(i, j);
                    }
                }
            }
        }
    }
    return nullptr;
}

// sf::Vector2i MouseInput::getPositionClick(sf::RenderWindow& window) {
//     if (this->clicked) {
//         this->positionClick = sf::Mouse::getPosition(window);
//         return this->positionClick;
//     } else {
//         return sf::Vector2i(0, 0);
//     }
// }
