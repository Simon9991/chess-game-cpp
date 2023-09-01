// Class Board, for the engine, there are multiple bitboards for each piece type, and one for all pieces
#ifndef ENGINE_BOARD_HPP
#define ENGINE_BOARD_HPP

#include <iostream>
#include <unordered_map>
#include <vector>

struct Move {
    int startSquare;
    int endSquare;
    bool isCastling = false;
    bool isEnPassant = false;
    char promotionPiece = '\0';  // 'Q', 'R', 'B', 'N' for promotions
    int capturedPiece = 0;       // 0 if no piece captured, 1-12 for piece captured
};

enum class TURN { WHITE, BLACK };

class Board {
   public:
    Board(const std::string &fen) { this->parseFEN(fen); }

    uint64_t pieces[12];
    uint64_t enPassant = 0;
    bool castlingRights[4] = {false, false, false, false};
    TURN sideToMove = TURN::WHITE;

    void parseFEN(const std::string &fen);

    // Prints the board to the console.
    void print_board() const;

    int evaluate();

    int legalMovesForPawn(int position, bool isWhite);

    int legalMovesForKnight(int position);

    int legalMovesForBishop(int position);

    int legalMovesForRook(int position);

    int legalMovesForQueen(int position);

    int activityScore();

    void makeMove(Move move);
    void undoMove(Move move);
    std::vector<Move> generateLegalMoves();
    int getPieceAt(int square);

    // // Function to execute a move on the board.
    // void execute_move(const Move& move);

    // // Function to undo a move on the board.
    // void undo_move(const Move& move);

    // // Checks if the king is in check
    // bool is_king_in_check(bool is_white_turn) const;

    // // Returns true if the player to move is white, false if black
    // bool get_player_turn() const { return side_to_move == PieceColor::WHITE_PIECE; }
};

#endif  // ENGINE_BOARD_HPP