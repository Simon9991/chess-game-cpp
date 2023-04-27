#include "EnginePiece.hpp"

Piece::Piece(PieceType type, PieceColor color, int location) {
    this->color = color;
    this->type = type;
    this->location = location;
}

PieceType Piece::getType() const {
    return this->type;
}

PieceColor Piece::getColor() const {
    return color;
}

int Piece::getLocation() const {
    return location;
}

void Piece::setLocation(int newLocation) {
    location = newLocation;
}
