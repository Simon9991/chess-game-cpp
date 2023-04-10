// SFML class which represents a 2D square
#ifndef SQUARE_HPP
#define SQUARE_HPP
#include <SFML/Graphics.hpp>

class Square {
   public:
    // Constructor
    Square(int x, int y, int size, sf::Color color);
    // Destructor
    ~Square();
    // Draw the square
    void draw(sf::RenderWindow &window);
    // Get the position of the square
    sf::Vector2f getPosition();
    // Get the size of the square
    int getSize();
    // Get the color of the square
    sf::Color getColor();
    // Set the position of the square
    void setPosition(sf::Vector2f position);
    // Set the size of the square
    void setSize(int size);
    // Set the color of the square
    void setColor(sf::Color color);
    // Return a NULL square
    static Square nullSquare();

   private:
    // Position of the square
    sf::Vector2f position;
    // Size of the square
    int size;
    // Color of the square
    sf::Color color;
    // SFML shape of the square
    sf::RectangleShape shape;
};

#endif /* !SQUARE_HPP */
