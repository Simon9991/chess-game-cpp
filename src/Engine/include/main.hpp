#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <vector>

// Debug mode
#define DEBUG 1

// Defining Chess constants
#define APP_NAME "Chess++"
#define SQUARE_SIZE 15 * 10
#define BOARD_SIZE 8
#define WINDOW_SIZE SQUARE_SIZE* BOARD_SIZE * 10
#define PIECE_SIZE SQUARE_SIZE * 1

constexpr int windowSize = SQUARE_SIZE * BOARD_SIZE;
constexpr char defaultFen[] = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";


// Defining Chess pieces
// TODO: Add WHITE_EN_PASSANT and BLACK_EN_PASSANT (used in movement.cpp for pawn movement to check if the pawn can be
// taken en passant)
enum PieceType {
    WHITE_PAWN = 1,
    WHITE_KNIGHT = 2,
    WHITE_BISHOP = 3,
    WHITE_ROOK = 4,
    WHITE_QUEEN = 5,
    WHITE_KING = 6,
    BLACK_PAWN = -1,
    BLACK_KNIGHT = -2,
    BLACK_BISHOP = -3,
    BLACK_ROOK = -4,
    BLACK_QUEEN = -5,
    BLACK_KING = -6,
    EMPTY = 0,
};


enum class Piece {
    EMPTY = 0,
    WHITE_PAWN,
    WHITE_ROOK,
    WHITE_KNIGHT,
    WHITE_BISHOP,
    WHITE_QUEEN,
    WHITE_KING,
    BLACK_PAWN,
    BLACK_ROOK,
    BLACK_KNIGHT,
    BLACK_BISHOP,
    BLACK_QUEEN,
    BLACK_KING
};

enum BasicPieceType {
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING,
    EMPTY_PIECE = 0,
};

enum PieceColor { WHITE_PIECE, BLACK_PIECE };

// Player turn
enum PlayerTurn { WHITE_TURN, BLACK_TURN };

// Defining return values
constexpr int SUCCESS = 0;
constexpr int FAILURE = -1;
constexpr int ERROR = 84;


// Engine includes
#include "./../Classes/MemoryBoard/memoryBoard.hpp"
#include "./../Classes/Move/EngineMove.hpp"
#include "./../Classes/MoveGenerator/MoveGenerator.hpp"



#endif /* !MAIN_HPP */
