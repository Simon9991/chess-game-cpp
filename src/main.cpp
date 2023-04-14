#include "./include/main.hpp"

#include <fstream>
#include <iostream>

int main(int ac, char **av) {
    sf::RenderWindow window(sf::VideoMode(200, 200), APP_NAME);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    std::string fen = "";

    if (ac > 1) {
        // Opens the .txt path file and setup the FEN
        std::string fenPath = av[1];

        std::ifstream fenFile(fenPath);
        if (fenFile.is_open()) {
            std::cout << "File opened" << std::endl;
            std::getline(fenFile, fen);
            fenFile.close();
        } else {
            std::cout << "Unable to open file" << std::endl;
        }
        std::cout << "FEN: " << fen << std::endl;

    } else {
        // Load with default board
        std::cout << "No arguments" << std::endl;
        fen.assign("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");  // Default FEN, TODO: Create a macro
    }

    Board *board = new Board(fen);
    MouseInput mouseInput = MouseInput();
    // Piece *piece = new Piece(sf::Vector2f(1 * SQUARE_SIZE, 2 * SQUARE_SIZE), PAWN, WHITE, SQUARE_SIZE,
    //                          PieceColor::WHITE_PIECE, 1, 2);
    // Piece *king = new Piece(sf::Vector2f(0, 0), KING, MAGENTA, SQUARE_SIZE, PieceColor::BLACK_PIECE, 0, 0);

    window.setFramerateLimit(15);
    window.setVerticalSyncEnabled(true);
    window.setSize(sf::Vector2u(2000, 2000));
    std::cout << "Window size: " << window.getSize().x << "x" << window.getSize().y << std::endl
              << "Supposed size: " << WINDOW_SIZE << "x" << WINDOW_SIZE << std::endl;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        if (mouseInput.isClicked(window)) {
            std::cout << "Mouse clicked at " << mouseInput.getPositionClick(window).x << "x"
                      << mouseInput.getPositionClick(window).y << std::endl;
        }

        window.clear();
        board->draw(window);
        window.display();
    }

    // Free memory
    delete board;
    // delete piece;
    // delete king;

    return 0;
}
