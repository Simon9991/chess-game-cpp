#ifndef MAIN_HPP
#define MAIN_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

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

// Defining Chess colors
#define WHITE sf::Color::White
#define BLACK sf::Color::Black
#define RED sf::Color::Red
#define GREEN sf::Color::Green
#define BLUE sf::Color::Blue
#define YELLOW sf::Color::Yellow
#define MAGENTA sf::Color::Magenta
#define CYAN sf::Color::Cyan
#define DARK_GRAY sf::Color(64, 64, 64)
#define LIGHT_GRAY sf::Color(212, 212, 212)

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
#include "./../Classes/Piece/EnginePiece.hpp"
#include "./../Classes/MoveGenerator/MoveGenerator.hpp"



#endif /* !MAIN_HPP */
