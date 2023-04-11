#include "./include/main.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(200, 200), APP_NAME);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    Board *board = new Board();
    MouseInput mouseInput = MouseInput();
    Piece *piece = new Piece(sf::Vector2f(0, 25), PAWN, WHITE, SQUARE_SIZE);
    Piece *king = new Piece(sf::Vector2f(0, 0), KING, MAGENTA, SQUARE_SIZE);

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

        // while (mouseInput.isClicked(window)) {
        //     std::cout << "Mouse clicked at " << mouseInput.getPositionClick(window).x << "x"
        //               << mouseInput.getPositionClick(window).y << std::endl;
        // }

        window.clear();
        board->draw(window);
        king->draw(window);
        piece->draw(window);
        window.display();
    }

    // Free memory
    delete board;
    delete piece;
    delete king;

    return 0;
}
