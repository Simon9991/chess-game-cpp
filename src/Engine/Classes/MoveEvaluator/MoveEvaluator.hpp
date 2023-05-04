#ifndef MOVE_EVALUATOR_HPP
#define MOVE_EVALUATOR_HPP

#include "./../../include/main.hpp"

class MoveEvaluator {
   public:
    // Constructor
    MoveEvaluator(const Board& board);

    // Evaluates the current position and returns a score
    int evaluate_position() const;

   private:
    // Evaluation functions
    int material_balance() const;
    int piece_activity() const;
    int pawn_structure() const;
    int king_safety() const;

    // Additional evaluation functions can be added here

    // Calculates the number of squares around the king that are attacked by the opponent
    int king_tropism() const;

    // Reference to the board object
    const Board& board;

    // Helper functions
    bool is_white_piece(Piece piece) const {
        return piece >= Piece::WHITE_PAWN && piece <= Piece::WHITE_KING;
    }
};

#endif  // MOVE_EVALUATOR_HPP
