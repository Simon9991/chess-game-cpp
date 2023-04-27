#include "EngineMove.hpp"

Move::Move(int sourceSquare, int destinationSquare, int piece, int capturedPiece, bool isPromotion)
    : sourceSquare(sourceSquare), destinationSquare(destinationSquare), piece(piece), capturedPiece(capturedPiece), promotion(isPromotion) {}

int Move::getSourceSquare() const {
    return sourceSquare;
}

int Move::getDestinationSquare() const {
    return destinationSquare;
}

int Move::getPiece() const {
    return piece;
}

int Move::getCapturedPiece() const {
    return capturedPiece;
}

bool Move::isPromotion() const {
    return promotion;
}
