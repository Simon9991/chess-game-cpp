#ifndef MOVEGENERATOR_HPP
#define MOVEGENERATOR_HPP

#include "./../../include/main.hpp"

class Board;

class MoveGenerator {
   public:
    MoveGenerator(const Board& board)
        : board(board) {}

    // Generate moves for all pieces on the board
    std::vector<Move> generate_moves(bool is_white_turn) const;

    // Generate moves for a specific piece at a given position
    std::vector<Move> generate_moves_for_piece(Piece piece, int row, int col) const;

    // Validate if a move is legal according to the rules of chess
    bool is_move_legal(const Move& move) const;

   private:
    const Board& board;

    // Helper methods for generating moves for each piece type
    std::vector<Move> generate_pawn_moves(int row, int col) const;
    std::vector<Move> generate_rook_moves(int row, int col) const;
    std::vector<Move> generate_knight_moves(int row, int col) const;
    std::vector<Move> generate_bishop_moves(int row, int col) const;
    std::vector<Move> generate_queen_moves(int row, int col) const;
    std::vector<Move> generate_king_moves(int row, int col) const;

    // Helper methods for move validation
    bool is_move_in_bounds(int row, int col) const;
    bool is_move_blocked(const Move& move) const;
    bool is_move_capturing_own_piece(const Move& move) const;
    bool is_king_in_check_after_move(const Move& move) const;
    bool is_white_piece(Piece piece) const;
    bool is_black_piece(Piece piece) const;
};

#endif
