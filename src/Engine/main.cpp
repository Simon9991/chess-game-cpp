// Header
// File contains main function for the engine (compiled only if 'make engine' is called)

#include "./include/main.hpp"

#include <fstream>
#include <iostream>

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

    Board *engineMemoryBoard = new Board(fen);
    engineMemoryBoard->print_board();

    MoveEvaluator *moveEvaluator = new MoveEvaluator(*engineMemoryBoard);
    std::cout << "Score: " << moveEvaluator->evaluate_position() << std::endl;

    Search *search = new Search(*engineMemoryBoard, *moveEvaluator, 4);

    std::cout << "Is it white's turn? 1 = WHITE_TURN: " << engineMemoryBoard->get_player_turn() << std::endl;
    search->print_best_move(engineMemoryBoard->get_player_turn());

    return 0;
}
