#ifndef MOVE_HPP
#define MOVE_HPP

#include <array>
#include <vector>

#include "../../types.hpp"
#include "../board/Board.hpp"

namespace Engine {

    class MoveGenerator {
      public:
        MoveGenerator(const Board &board);
        std::array<Bitboard, PIECE_NB> generateMoves();

        // helper
        void print(std::array<Bitboard, PIECE_NB> moves) const;
        void print(Bitboard bb) const;

      private:
        const Board &board;
        Bitboard generatePawnMoves(Color side_to_move);

        // LSB pop
        int getLSBIndex(Bitboard bb) { return __builtin_ctzll(bb); }
    };
} // namespace Engine

#endif // MOVE_HPP
