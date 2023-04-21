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

sf::Vector2i MouseInput::getRelativePositionClick() {
    if (this->clicked) {
        return sf::Vector2i(this->positionClick.x / SQUARE_SIZE / 10, this->positionClick.y / SQUARE_SIZE / 10);
    } else {
        return sf::Vector2i(0, 0);
    }
}

sf::Vector2f MouseInput::getPositionClick() {
    if (this->clicked) {
        return sf::Vector2f(this->positionClick.x, this->positionClick.y);
    } else {
        return sf::Vector2f(0, 0);
    }
}

bool MouseInput::isClicked(sf::RenderWindow& window) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        this->positionClick = sf::Mouse::getPosition(window);
        this->clicked = true;
    } else
        this->clicked = false;

    return this->clicked;
}

Piece* MouseInput::isClickedOnPiece(sf::RenderWindow& window, Board* board, Piece* oldPiece) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        this->positionClick = sf::Mouse::getPosition(window);
        // std::cout << "Clicked on " << this->positionClick.x << "x" << this->positionClick.y << std::endl;
        this->clicked = true;
    } else
        this->clicked = false;

    // Search in the memoryBoard for a piece (using relativePosition)
    if (this->clicked) {
        sf::Vector2i relativePosition =
            sf::Vector2i(this->positionClick.x / SQUARE_SIZE / 10, this->positionClick.y / SQUARE_SIZE / 10);
        // std::cout << "Relative position: " << relativePosition.x << "x" << relativePosition.y << std::endl;
        Piece* foundPiece = board->getPiece(relativePosition.y, relativePosition.x);
        if (foundPiece != nullptr && foundPiece->getType() != PieceType::EMPTY) {
            // std::cout << "Found a piece: " << board->getPieceType(relativePosition.y, relativePosition.x) <<
            // std::endl;
            if (foundPiece != nullptr && foundPiece->getPieceColor() != board->getPlayerTurn()) {
                return oldPiece;
            }
            std::cout << "Type of the piece on Square:  " << foundPiece->getType() << std::endl;
            std::cout << "Is the square possible? " << board->getRelativeSquare(relativePosition)->isPossibleMove()
                      << std::endl;
            std::cout << "Can castle king side? " << foundPiece->getCanCastleKingSide() << std::endl
                      << "Can castle queen side? " << foundPiece->getCanCastleQueenSide() << std::endl;
            if (oldPiece != nullptr && board->getRelativeSquare(relativePosition)->isPossibleMove() &&
                foundPiece->getIsFirstMove() &&
                (foundPiece->getType() == PieceType::BLACK_ROOK || foundPiece->getType() == PieceType::WHITE_ROOK)) {
                std::cout << "Found that you are trying to castle" << std::endl;
                return oldPiece;
            }
            if (oldPiece != nullptr && oldPiece->getPieceColor() != foundPiece->getPieceColor()) {
                return oldPiece;
            }
            return foundPiece;
        }
    }
    return oldPiece;
}

void MouseInput::setClicked(bool clicked) { this->clicked = clicked; }

bool MouseInput::getClicked() { return this->clicked; }
