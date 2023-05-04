#ifndef MOVE_HPP
#define MOVE_HPP

#include "./../../include/main.hpp"

class Move {
   public:
    Move() = default;
    Move(int start_row, int start_col, int end_row, int end_col)
        : start_row(start_row), start_col(start_col), end_row(end_row), end_col(end_col) {}

    int get_start_row() const { return start_row; }

    int get_start_col() const { return start_col; }

    int get_end_row() const { return end_row; }

    int get_end_col() const { return end_col; }

    void print_move() const {
        // Convert move coordinates to chess notation
        char start_col = 'a' + this->get_start_col();
        int start_row = 8 - this->get_start_row();
        char end_col = 'a' + this->get_end_col();
        int end_row = 8 - this->get_end_row();

        // Print move
        std::cout << start_col << start_row << " -> " << end_col << end_row;
    }

   private:
    int start_row;
    int start_col;
    int end_row;
    int end_col;
};

#endif
