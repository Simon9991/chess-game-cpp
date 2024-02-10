#include "Move.hpp"

#include <array>
#include <vector>

namespace Engine {
    MoveGenerator::MoveGenerator(const Board &board) : board(board) {}

    std::array<Bitboard, PIECE_NB> MoveGenerator::generateMoves() {
        std::array<Bitboard, PIECE_NB> moves;

        generatePawnMoves(board.getSideToMove());

        return moves;
    }

    Bitboard MoveGenerator::generatePawnMoves(Color side_to_move) {
        /* Bitboard pawns = board.getBitboard(side_to_move == WHITE ? W_PAWN :
         * B_PAWN); */
        /* Bitboard pawn_moves = 0ULL; */
        /**/
        /* while (pawns) { */
        /*     Square square = pop_lsb(&pawns); */
        /*     pawn_moves |= (side_to_move == WHITE ? northOne(square) :
         * southOne(square)); */
        /* } */
    }
} // namespace Engine
