#include "./include/main.hpp"

#include <fstream>
#include <iostream>

int main(int ac, char **av) {
    std::string fen = "";

    // Setting anti-aliasing
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(200, 200), APP_NAME, sf::Style::Default, settings);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    if (ac > 1) {
        // Opens the .txt path file and setup the FEN
        std::string fenPath = av[1];

        std::ifstream fenFile(fenPath);
        if (fenFile.is_open()) {
            // std::cout << "File opened" << std::endl;
            std::getline(fenFile, fen);
            fenFile.close();
        } else {
            std::cout << "Unable to open file" << std::endl;
        }
        // std::cout << "FEN: " << fen << std::endl;

    } else {
        // Load with default board
        // std::cout << "No arguments" << std::endl;
        fen.assign("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");  // Default FEN, TODO: Create a macro
    }

    Board *board = new Board(fen);
    MouseInput mouseInput = MouseInput();
    Movement movement = Movement(board->getMemoryBoard());
    Moves moves = Moves();

    Piece *piece = nullptr;

    window.setFramerateLimit(15);
    window.setVerticalSyncEnabled(true);
    window.setSize(sf::Vector2u(2000, 2000));
    // std::cout << "Window size: " << window.getSize().x << "x" << window.getSize().y << std::endl
    //           << "Supposed size: " << WINDOW_SIZE << "x" << WINDOW_SIZE << std::endl;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed) window.close();

        piece = mouseInput.isClickedOnPiece(window, board, piece);
        if (piece != nullptr) {
            std::vector<sf::Vector2f> possibleMoves = movement.getPossibleMoves(piece);
            moves.setPossibleMoves(possibleMoves);

            // For each possible move, we set the square to possible move
            for (sf::Vector2f possibleMove : possibleMoves) {
                sf::Vector2i relativePosition =
                    sf::Vector2i(possibleMove.x / SQUARE_SIZE, possibleMove.y / SQUARE_SIZE);
                Square *square = board->getRelativeSquare(relativePosition);
                square->setPossibleMove(true);
            }

            if (mouseInput.isClicked(window) == true) {
                sf::Vector2i mousePosition = mouseInput.getRelativePositionClick();
                Square *squareOfPossibleMove = board->getRelativeSquare(mousePosition);

                if (squareOfPossibleMove != nullptr && squareOfPossibleMove->isPossibleMove()) {
                    sf::Vector2f position = sf::Vector2f(mouseInput.getRelativePositionClick().x * SQUARE_SIZE,
                                                         mouseInput.getRelativePositionClick().y * SQUARE_SIZE);
                    board->movePiece(piece, position);
                    // Reset possible moves of the squares
                    board->resetPossibleMoves();
                    moves.clear();
                    board->setPlayerTurn(board->getPlayerTurn() == PieceColor::WHITE_PIECE
                                             ? PieceColor::BLACK_PIECE
                                             : PieceColor::WHITE_PIECE);  // To comment if you want to play multiple
                                                                          // times with the same color
                    piece = nullptr;
                    squareOfPossibleMove = nullptr;
                    movement.updateMemoryBoard(board->getMemoryBoard());
                }
            }
        }

        window.clear();
        board->draw(window);
        moves.draw(window);
        window.display();
    }

    // Free memory
    delete board;

    return 0;
}
