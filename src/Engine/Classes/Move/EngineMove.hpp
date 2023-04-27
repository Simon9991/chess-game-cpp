#ifndef MOVE_HPP
#define MOVE_HPP

class Move {
public:
    Move(int start_row, int start_col, int end_row, int end_col)
        : start_row(start_row), start_col(start_col), end_row(end_row), end_col(end_col) {}

    int get_start_row() const {
        return start_row;
    }

    int get_start_col() const {
        return start_col;
    }

    int get_end_row() const {
        return end_row;
    }

    int get_end_col() const {
        return end_col;
    }

    void print_move() const {
        std::cout << "Move from (" << start_row << ", " << start_col << ") to (" << end_row << ", " << end_col << ")" << std::endl;
    }

private:
    int start_row;
    int start_col;
    int end_row;
    int end_col;
};


#endif
