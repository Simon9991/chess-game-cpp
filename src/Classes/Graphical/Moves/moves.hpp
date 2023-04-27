// Class which show small circles on the possible moves of the piece
// Path: src/Classes/Graphical/Moves/moves.cpp

#ifndef MOVES_HPP
#define MOVES_HPP

#include "./../../../include/main.hpp"

class Moves {
   public:
    Moves();
    ~Moves();
    // Drawing the possible moves
    void draw(sf::RenderWindow &window);
    // Set the possible moves
    void setPossibleMoves(std::vector<sf::Vector2f> possibleMoves);
    // Clearing the possible moves
    void clear();
    // Returns the relative possible moves
    sf::Vector2i getRelativePossibleMoves();

   private:
    std::vector<sf::CircleShape> possibleMoves;
};

#endif /* !MOVES_HPP */