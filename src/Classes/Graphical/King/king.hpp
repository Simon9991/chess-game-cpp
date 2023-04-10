#ifndef KING_HPP
#define KING_HPP

#include <SFML/Graphics.hpp>

#include "./../../../include/main.hpp"

class King {
   public:
    // Constructor
    King(int x, int y, int size, sf::Color color);
    // Destructor
    ~King();
    // Draw the king
    void draw(sf::RenderWindow &window);
    // Get the position of the king
    sf::Vector2f getPosition();
    // Get the size of the king
    int getSize();
    // Get the color of the king
    sf::Color getColor();
    // Set the position of the king
    void setPosition(sf::Vector2f position);
    // Set the size of the king
    void setSize(int size);
    // Set the color of the king
    void setColor(sf::Color color);

   private:
    // Graphical Position of the king
    sf::Vector2f position;
    // Logical position of the king
    int x;
    int y;
    // Size of the king
    int size;
    // Color of the king
    sf::Color color;
    // SFML shape of the king
    sf::CircleShape shape;
};

#endif /* !KING_HPP */