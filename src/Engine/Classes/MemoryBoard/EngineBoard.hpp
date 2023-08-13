// Class Board, for the engine, there are multiple bitboards for each piece type, and one for all pieces
#ifndef ENGINE_BOARD_HPP
#define ENGINE_BOARD_HPP

#include "./../../include/main.hpp"

class Board {
   public:
    Board(std::string fen);
    ~Board();

    // Add public methods to retrieve information or update the board.

   protected:
    // Bitboards for each piece type
    U64 pawns[2];
    U64 knights[2];
    U64 bishops[2];
    U64 rooks[2];
    U64 queens[2];
    U64 kings[2];

    // Bitboards for all pieces, by color
    U64 pieces[2];  // pieces[0] = all white pieces, pieces[1] = all black pieces

    // Bitboards for occupied and empty squares
    U64 occupied_squares;
    U64 empty_squares;

    // Additional board state
    int castling_rights;
    int en_passant_square;
    bool side_to_move;  // true for white, false for black
    int halfmove_clock;
    int fullmove_number;

    // Add utility methods and other internal members as necessary.
};

#endif  // ENGINE_BOARD_HPP