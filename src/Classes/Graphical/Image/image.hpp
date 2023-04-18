// Class used to store an image

#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "./../../../include/main.hpp"

class Image {
   private:
    /* data */
    sf::Texture *texture;
    sf::Sprite *sprite;
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Color color;

   public:
    // Constructor
    Image(std::string path, sf::Vector2f position, sf::Vector2f size, sf::Color color);
    // Constructor without color
    Image(std::string path, sf::Vector2f position, sf::Vector2f size);
    // Destructor
    ~Image();
    // Load an image
    void load(std::string path);
    // Draw the image
    void draw(sf::RenderWindow &window);
    // Set the position of the image
    void setPosition(sf::Vector2f position);
    // Set the size of the image
    void setSize(sf::Vector2f size);
    // Set the color of the image
    void setColor(sf::Color color);
    // Get the position of the image
    sf::Vector2f getPosition();
    // Get the size of the image
    sf::Vector2f getSize();
    // Get the color of the image
    sf::Color getColor();
    // Get the sprite of the image
    sf::Sprite *getSprite();
};

#endif /* !IMAGE_HPP */