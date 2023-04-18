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
#define PIECE_SIZE SQUARE_SIZE * 1

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

// Defining image paths
#define WHITE_PAWN_PATH "./src/Assets/Pieces/w_pawn.png"
#define WHITE_ROOK_PATH "./src/Assets/Pieces/w_rook.png"
#define WHITE_KNIGHT_PATH "./src/Assets/Pieces/w_knight.png"
#define WHITE_BISHOP_PATH "./src/Assets/Pieces/w_bishop.png"
#define WHITE_QUEEN_PATH "./src/Assets/Pieces/w_queen.png"
#define WHITE_KING_PATH "./src/Assets/Pieces/w_king.png"
#define BLACK_PAWN_PATH "./src/Assets/Pieces/b_pawn.png"
#define BLACK_ROOK_PATH "./src/Assets/Pieces/b_rook.png"
#define BLACK_KNIGHT_PATH "./src/Assets/Pieces/b_knight.png"
#define BLACK_BISHOP_PATH "./src/Assets/Pieces/b_bishop.png"
#define BLACK_QUEEN_PATH "./src/Assets/Pieces/b_queen.png"
#define BLACK_KING_PATH "./src/Assets/Pieces/b_king.png"

// Defining return values
#define SUCCESS 0
#define FAILURE -1
#define ERROR 84

#include "./../Classes/GameEngine/Movement/movement.hpp"
#include "./../Classes/Graphical/Board/board.hpp"
#include "./../Classes/Graphical/Image/image.hpp"
#include "./../Classes/Graphical/King/king.hpp"
#include "./../Classes/Graphical/Moves/moves.hpp"
#include "./../Classes/Graphical/Piece/piece.hpp"
#include "./../Classes/Graphical/Square/square.hpp"
#include "./../Classes/Input/MouseInput/mouse_input.hpp"

#endif /* !MAIN_HPP */
