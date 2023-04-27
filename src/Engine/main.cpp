// Header
// File contains main function for the engine (compiled only if 'make engine' is called)

#include <iostream>
#include <fstream>

#include "./include/main.hpp"

int main(int ac, char **av) {
    std::string fen = "";

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

    EngineMemoryBoard *engineMemoryBoard = new EngineMemoryBoard(fen);
    engineMemoryBoard->printMemoryBoard();

    return 0;
}
