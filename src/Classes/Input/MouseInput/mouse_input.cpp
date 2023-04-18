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
        std::cout << "Clicked on " << this->positionClick.x << "x" << this->positionClick.y << std::endl;
        sf::Vector2i relativePosition =
            sf::Vector2i(this->positionClick.x / SQUARE_SIZE / 10, this->positionClick.y / SQUARE_SIZE / 10);
        std::cout << "Relative position: " << relativePosition.x << "x" << relativePosition.y << std::endl;
        this->clicked = true;
    } else {
        this->clicked = false;
    }

    // Search in the memoryBoard for a piece (using relativePosition)
    if (this->clicked) {
        if (board->getPieceType(relativePosition.x, relativePosition.y) != PieceType::EMPTY) {
            std::cout << "Found a piece: " << board->getPieceType(relativePosition.x, relativePosition.y) << std::endl;
            // return board->getPiece(relativePosition.x, relativePosition.y);
        }
    }

    // if (this->clicked) {
    //     for (int i = 0; i < BOARD_SIZE; i++) {
    //         std::cout << "i: " << i << std::endl;
    //         for (int j = 0; j < BOARD_SIZE; j++) {
    //             std::cout << "j: " << j << std::endl;
    //             if (board->getPieceType(i, j) != PieceType::EMPTY) {
    //                 std::cout << "piece: " << board->getPieceType(i, j) << std::endl;
    //                 if (board->getPiece(i, j)->getImage()->getSprite()->getGlobalBounds().contains(
    //                         this->positionClick.x, this->positionClick.y)) {
    //                     std::cout << "Found a piece" << std::endl;
    //                     return board->getPiece(i, j);
    //                     // return nullptr;
    //                 }
    //             }
    //         }
    //     }
    // }
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
