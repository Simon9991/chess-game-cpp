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
    this->isFirstMove = true;
    this->canCastleKingSide = true;
    this->canCastleQueenSide = true;

    this->size = SQUARE_SIZE / 2;

    // if (DEBUG) {
    //     std::cout << "Empty piece created at " << this->x << "x" << this->y << std::endl;
    //     // Red outline
    //     this->shape.setOutlineColor(sf::Color::Red);
    //     this->shape.setOutlineThickness(1);
    // }
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
    this->isFirstMove = true;
    this->canCastleKingSide = true;
    this->canCastleQueenSide = true;

    switch (type) {
        case PieceType::WHITE_PAWN:
            this->image = new Image(WHITE_PAWN_PATH, position, sf::Vector2f(size, size));
            break;
        case PieceType::WHITE_ROOK:
            this->image = new Image(WHITE_ROOK_PATH, position, sf::Vector2f(size, size));
            this->canCastleKingSide = true;
            this->canCastleQueenSide = true;
            break;
        case PieceType::WHITE_KNIGHT:
            this->image = new Image(WHITE_KNIGHT_PATH, position, sf::Vector2f(size, size));
            break;
        case PieceType::WHITE_BISHOP:
            this->image = new Image(WHITE_BISHOP_PATH, position, sf::Vector2f(size, size));
            break;
        case PieceType::WHITE_QUEEN:
            this->image = new Image(WHITE_QUEEN_PATH, position, sf::Vector2f(size, size));
            break;
        case PieceType::WHITE_KING:
            this->image = new Image(WHITE_KING_PATH, position, sf::Vector2f(size, size));
            this->canCastleKingSide = true;
            this->canCastleQueenSide = true;
            break;
        case PieceType::BLACK_PAWN:
            this->image = new Image(BLACK_PAWN_PATH, position, sf::Vector2f(size, size));
            break;
        case PieceType::BLACK_ROOK:
            this->image = new Image(BLACK_ROOK_PATH, position, sf::Vector2f(size, size));
            this->canCastleKingSide = true;
            this->canCastleQueenSide = true;
            break;
        case PieceType::BLACK_KNIGHT:
            this->image = new Image(BLACK_KNIGHT_PATH, position, sf::Vector2f(size, size));
            break;
        case PieceType::BLACK_BISHOP:
            this->image = new Image(BLACK_BISHOP_PATH, position, sf::Vector2f(size, size));
            break;
        case PieceType::BLACK_QUEEN:
            this->image = new Image(BLACK_QUEEN_PATH, position, sf::Vector2f(size, size));
            break;
        case PieceType::BLACK_KING:
            this->image = new Image(BLACK_KING_PATH, position, sf::Vector2f(size, size));
            this->canCastleKingSide = true;
            this->canCastleQueenSide = true;
            break;
        default:
            break;
    }
}

Piece::~Piece() {}

sf::Vector2f Piece::getPosition() { return this->position; }

sf::Vector2i Piece::getMemoryPosition() {
    sf::Vector2i memoryPosition;
    memoryPosition.x = this->x;
    memoryPosition.y = this->y;
    return memoryPosition;
}

int Piece::getX() { return this->x; }

int Piece::getY() { return this->y; }

PieceType Piece::getType() { return this->type; }

sf::Color Piece::getColor() { return this->color; }

void Piece::setPosition(sf::Vector2f position, int x, int y) {
    this->position = position;
    this->x = x;
    this->y = y;
    this->shape.setPosition(position);
    this->image->setPosition(position);
}

void Piece::draw(sf::RenderWindow &window) {
    // window.draw(this->shape);
    if (this->type != PieceType::EMPTY) {
        this->image->draw(window);
    }
}

PieceColor Piece::getPieceColor() { return this->pieceColor; }

PieceType Piece::getPieceType() { return this->type; }

Image *Piece::getImage() { return this->image; }

PieceColor Piece::getOppositeColor() {
    if (this->pieceColor == PieceColor::WHITE_PIECE)
        return PieceColor::BLACK_PIECE;
    else
        return PieceColor::WHITE_PIECE;
}

bool Piece::getIsFirstMove() { return this->isFirstMove; }

void Piece::setIsFirstMove(bool isFirstMove) { this->isFirstMove = isFirstMove; }

bool Piece::getCanCastleKingSide() { return false; }

void Piece::setCanCastleKingSide(bool canCastleKingSide) {
    // std::cout << "Can castle king side: " << canCastleKingSide << std::endl;
    this->canCastleKingSide = canCastleKingSide;
}

bool Piece::getCanCastleQueenSide() { return false; }

void Piece::setCanCastleQueenSide(bool canCastleQueenSide) {
    // std::cout << "Can castle queen side: " << canCastleQueenSide << std::endl;
    this->canCastleQueenSide = canCastleQueenSide;
}
