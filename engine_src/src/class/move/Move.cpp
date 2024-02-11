#include "Move.hpp"

#include <array>
#include <iostream>
#include <ostream>
#include <vector>

namespace Engine {
    MoveGenerator::MoveGenerator(const Board &board) : board(board) {}

    std::array<Bitboard, PIECE_NB> MoveGenerator::generateMoves() {
        std::array<Bitboard, PIECE_NB> moves;
        const Color side_to_move = board.getSideToMove();

        const Bitboard pawn_moves = generatePawnMoves(side_to_move);

        moves[PAWN] = pawn_moves;

        std::cout << moves[PAWN] << std::endl;

        return moves;
    }

    Bitboard MoveGenerator::generatePawnMoves(Color side_to_move) {
        Bitboard pawns =
            board.getBitboard(side_to_move == WHITE ? W_PAWN : B_PAWN);
        // TODO: check if pawn can capture/move forward
        Bitboard enemyPawns =
            board.getBitboard(side_to_move == WHITE ? B_PAWN : W_PAWN);
        Bitboard pawn_moves = 0ULL;

        while (pawns) {
            const int lsbIndex = getLSBIndex(pawns);

            Rank r = static_cast<Rank>(lsbIndex / 8);
            File f = static_cast<File>(lsbIndex % 8);

            Square sq = make_square(f, r);

            if (side_to_move == WHITE) {
                if (r == RANK_2) {
                    pawn_moves |= sq << 16;
                } else {
                    pawn_moves |= sq << 8;
                }
            } else {
                if (r == RANK_7) {
                    pawn_moves |= sq >> 16;
                } else {
                    pawn_moves |= sq >> 8;
                }
            }

            // TODO: handle captures

            // TODO: handle promotion
            //
            // TODO: handle en passant

            pawns &= pawns - 1;
        }

        return pawn_moves;
    }

    // helper
    void MoveGenerator::print(std::array<Bitboard, PIECE_NB> moves) const {
        // TODO: print all moves
    }

    void MoveGenerator::print(Bitboard bb) const {

        for (int rank = RANK_8; rank >= RANK_1; --rank) {
            std::cout << rank + 1 << " "; // Print rank number
            for (int file = FILE_A; file <= FILE_H; ++file) {
                Square square = make_square(File(file), Rank(rank));
                if (bb & (1ULL << square)) {
                    std::cout << "X ";
                } else {
                    std::cout << ". ";
                }
            }
            std::cout << "\n";
        }
    }

} // namespace Engine
