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

      private:
        const Board &board;
        Bitboard generatePawnMoves(Color side_to_move);
    };
} // namespace Engine

#endif // MOVE_HPP
