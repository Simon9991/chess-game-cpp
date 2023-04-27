#ifndef PIECE_HPP
#define PIECE_HPP

#include "./../../include/main.hpp"


enum class EnginePieceType {
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING
};


class Piece {
public:
    // Constructor
    Piece(EnginePieceType type, PieceColor color, int location);
    // Destructor
    ~Piece();
    // Get the type of the piece
    EnginePieceType getType() const;
    // Get the color of the piece
    PieceColor getColor() const;
    // Get the location of the piece
    int getLocation() const;
    // Set the location of the piece
    void setLocation(int newLocation);

    // Add additional methods as needed for calculating valid moves

private:
    EnginePieceType type;
    PieceColor color;
    int location;
};

#endif