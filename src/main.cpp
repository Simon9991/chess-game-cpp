#include "./include/main.hpp"

#include <fstream>
#include <iostream>

int main(int ac, char **av) {
    std::string fen = "";

    // Setting anti-aliasing
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    int windowSize = SQUARE_SIZE * BOARD_SIZE;

    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), APP_NAME, sf::Style::Default, settings);
    window.setFramerateLimit(15);
    window.setVerticalSyncEnabled(true);

    if (ac > 1) {
        // Opens the .txt path file and setup the FEN
        std::string fenPath = av[1];

        std::ifstream fenFile(fenPath);
        if (fenFile.is_open()) {
            std::getline(fenFile, fen);
            fenFile.close();
        } else
            std::cout << "Unable to open file" << std::endl;
    } else
        fen.assign(defaultFen);

    Board *board = new Board(fen);
    MouseInput mouseInput = MouseInput();
    Movement movement = Movement(board->getMemoryBoard(), board);
    Moves moves = Moves();

    Piece *piece = nullptr;

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
                sf::Vector2i relativePosition = sf::Vector2i(possibleMove.x / SQUARE_SIZE / 100, possibleMove.y / SQUARE_SIZE / 100);
                Square *square = board->getRelativeSquare(relativePosition);
                square->setPossibleMove(true);
            }

            if (mouseInput.isClicked(window) == true) {
                sf::Vector2i mousePosition = mouseInput.getRelativePositionClick();
                Square *squareOfPossibleMove = board->getRelativeSquare(mousePosition);

                if (squareOfPossibleMove != nullptr && squareOfPossibleMove->isPossibleMove()) {
                    sf::Vector2f position = sf::Vector2f(mouseInput.getRelativePositionClick().x * SQUARE_SIZE, mouseInput.getRelativePositionClick().y * SQUARE_SIZE);
                    board->movePiece(piece, position);

                    // Reset possible moves of the squares
                    board->resetPossibleMoves();
                    moves.clear();
                    board->setPlayerTurn(board->getPlayerTurn() == PieceColor::WHITE_PIECE ? PieceColor::BLACK_PIECE : PieceColor::WHITE_PIECE);  // To comment if you want to play multiple times with the same color
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

    delete board;

    return 0;
}
