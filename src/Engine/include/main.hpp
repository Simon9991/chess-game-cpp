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
    BLACK_KING,
    EMPTY
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

#endif /* !MAIN_HPP */
