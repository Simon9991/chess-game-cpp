#include "./include/main.hpp"

int main(int ac, char **av, char **env) {
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    Square whiteSquare = Square(0, 0, 100, sf::Color::White);
    Board *board = new Board();

    window.setFramerateLimit(30);
    window.setVerticalSyncEnabled(true);
    window.setSize(sf::Vector2u(WINDOW_SIZE, WINDOW_SIZE));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        window.clear();
        board->draw(window);
        window.display();
    }

    return 0;
}
