#include <fstream>
#include <iostream>

#include "./class/board/Board.hpp"
#include "types.hpp"

std::string fen_getter(const std::string &file) {
    if (file.empty()) {
        return std::string(Engine::START_FEN);
    }

    std::ifstream ifs(file);
    std::string fen;
    std::getline(ifs, fen);

    return fen;
}

int main(int ac, char **av) {
    std::string arg = "";

    if (ac > 1) {
        arg = av[1];
    }

    std::string fen = fen_getter(arg);
    std::cout << fen << std::endl;

    Engine::Board board(fen);
    board.print();

    return 0;
}
