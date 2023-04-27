#ifndef MOVE_HPP
#define MOVE_HPP

class Move {
public:
    Move(int sourceSquare, int destinationSquare, int piece, int capturedPiece = 0, bool isPromotion = false);

    int getSourceSquare() const;
    int getDestinationSquare() const;
    int getPiece() const;
    int getCapturedPiece() const;
    bool isPromotion() const;

private:
    int sourceSquare;
    int destinationSquare;
    int piece;
    int capturedPiece;
    bool promotion;
};

#endif
