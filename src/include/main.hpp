#ifndef MAIN_HPP
#define MAIN_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

// Debug mode
#define DEBUG 1

// Defining Chess constants
#define APP_NAME "Chess"
#define SQUARE_SIZE 25
#define BOARD_SIZE 8
#define WINDOW_SIZE SQUARE_SIZE* BOARD_SIZE

// Defining Chess colors
#define WHITE sf::Color::White
#define BLACK sf::Color::Black
#define RED sf::Color::Red
#define GREEN sf::Color::Green
#define BLUE sf::Color::Blue
#define YELLOW sf::Color::Yellow
#define MAGENTA sf::Color::Magenta
#define DARK_GRAY sf::Color(64, 64, 64)
#define LIGHT_GRAY sf::Color(192, 192, 192)

// Defining Chess pieces
#define PAWN "Pawn"
#define ROOK "Rook"
#define KNIGHT "Knight"
#define BISHOP "Bishop"
#define QUEEN "Queen"
#define KING "King"

// Defining Chess pieces colors
#define WHITE_PIECE "White"
#define BLACK_PIECE "Black"

// Defining return values
#define SUCCESS 0
#define FAILURE -1
#define ERROR 84

#include "./../Classes/Graphical/Board/board.hpp"
#include "./../Classes/Graphical/Square/square.hpp"

#endif /* !MAIN_HPP */