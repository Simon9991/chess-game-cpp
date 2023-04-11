#ifndef MAIN_HPP
#define MAIN_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

// Debug mode
#define DEBUG 1

// Font
#define FONT "src/Assets/Fonts/Lato/Lato-Regular.ttf"

// Defining Chess constants
#define APP_NAME "Chess"
#define SQUARE_SIZE 25
#define BOARD_SIZE 8
#define WINDOW_SIZE SQUARE_SIZE* BOARD_SIZE * 10
#define PIECE_SIZE SQUARE_SIZE * 0.75

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
#define LIGHT_GRAY sf::Color(192, 192, 192)

// Defining Chess pieces
enum PieceType { PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING, EMPTY };
enum PieceColor { WHITE_PIECE, BLACK_PIECE };

// Defining return values
#define SUCCESS 0
#define FAILURE -1
#define ERROR 84

#include "./../Classes/Graphical/Board/board.hpp"
#include "./../Classes/Graphical/King/king.hpp"
#include "./../Classes/Graphical/Piece/piece.hpp"
#include "./../Classes/Graphical/Square/square.hpp"
#include "./../Classes/Input/MouseInput/mouse_input.hpp"

#endif /* !MAIN_HPP */