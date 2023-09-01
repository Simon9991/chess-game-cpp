#ifndef MOVEGENERATOR_HPP
#define MOVEGENERATOR_HPP

#include "./../../include/main.hpp"

class MoveGenerator {
   public:
    MoveGenerator(const Board& board) : board(board) {}

    std::vector<Move> generate_moves(bool is_white_turn) const;
    std::vector<Move> generate_moves_for_piece(int row, int col) const;
    bool is_move_legal(const Move& move) const;

   private:
    const Board& board;

    std::vector<Move> generate_pawn_moves(int row, int col) const;
    std::vector<Move> generate_rook_moves(int row, int col) const;
    std::vector<Move> generate_knight_moves(int row, int col) const;
    std::vector<Move> generate_bishop_moves(int row, int col) const;
    std::vector<Move> generate_queen_moves(int row, int col) const;
    std::vector<Move> generate_king_moves(int row, int col) const;

    bool is_move_in_bounds(int row, int col) const;
    bool is_king_in_check_after_move(const Move& move) const;
    bool is_white_piece(Piece piece) const;
    bool is_black_piece(Piece piece) const;
};

#endif
