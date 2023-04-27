// Class Board, a chess board is made of 64 squares
#ifndef ENGINE_MEMORYBOARD_HPP
#define ENGINE_MEMORYBOARD_HPP

#include "./../../include/main.hpp"

class Board {
public:
    // Constructor
    Board() {
        reset_board();
    }

    // Constructor with FEN string
    Board(std::string fen);

    void reset_board() {
        board = {
            {Piece::WHITE_ROOK, Piece::WHITE_KNIGHT, Piece::WHITE_BISHOP, Piece::WHITE_QUEEN, Piece::WHITE_KING, Piece::WHITE_BISHOP, Piece::WHITE_KNIGHT, Piece::WHITE_ROOK},
            {Piece::WHITE_PAWN, Piece::WHITE_PAWN, Piece::WHITE_PAWN, Piece::WHITE_PAWN, Piece::WHITE_PAWN, Piece::WHITE_PAWN, Piece::WHITE_PAWN, Piece::WHITE_PAWN},
            {Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY},
            {Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY},
            {Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY},
            {Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY},
            {Piece::BLACK_PAWN, Piece::BLACK_PAWN, Piece::BLACK_PAWN, Piece::BLACK_PAWN, Piece::BLACK_PAWN, Piece::BLACK_PAWN, Piece::BLACK_PAWN, Piece::BLACK_PAWN},
            {Piece::BLACK_ROOK, Piece::BLACK_KNIGHT, Piece::BLACK_BISHOP, Piece::BLACK_QUEEN, Piece::BLACK_KING, Piece::BLACK_BISHOP, Piece::BLACK_KNIGHT, Piece::BLACK_ROOK}
        };
    }

    Piece get_piece(int row, int col) const {
        return board[row][col];
    }

    void set_piece(int row, int col, Piece piece) {
        board[row][col] = piece;
    }

    void print_board() const {
        for (const auto& row : board) {
            for (const auto& piece : row) {
                std::cout << static_cast<int>(piece) << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    std::vector<std::vector<Piece>> board;
    void initBoard(std::string fen);
    PieceColor playerTurn;
};


#endif /* !ENGINE_MEMORYBOARD_HPP */
