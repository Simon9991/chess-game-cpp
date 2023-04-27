#include "memoryBoard.hpp"

Board::Board(std::string fen) {
    int j = 0;
    int k = 0;

    // Setting the double vector to EMPTY
    while (j < BOARD_SIZE) {
        this->board.push_back(std::vector<Piece>());
        while (k < BOARD_SIZE) {
            this->board.at(j).push_back(Piece::EMPTY);
            k++;
        }
        k = 0;
        j++;
    }

    initBoard(fen);
}

void Board::initBoard(std::string fen) {
    // Initializes the board with the given FEN string
    // fen is the FEN string
    size_t i = 0;
    int j = 0;
    int k = 0;

    while (i < fen.length()) {
        if (fen[i] == '/') {
            j++;
            k = 0;
        } else if (fen[i] == ' ') {
            break;
        } else if (fen[i] >= '1' && fen[i] <= '8') {
            k += fen[i] - '0';
        } else {
            if (fen[i] == 'p') {
                this->board[j][k] = Piece::BLACK_PAWN;
            } else if (fen[i] == 'P') {
                this->board[j][k] = Piece::WHITE_PAWN;
            } else if (fen[i] == 'n') {
                this->board[j][k] = Piece::BLACK_KNIGHT;
            } else if (fen[i] == 'N') {
                this->board[j][k] = Piece::WHITE_KNIGHT;
            } else if (fen[i] == 'b') {
                this->board[j][k] = Piece::BLACK_BISHOP;
            } else if (fen[i] == 'B') {
                this->board[j][k] = Piece::WHITE_BISHOP;
            } else if (fen[i] == 'r') {
                this->board[j][k] = Piece::BLACK_ROOK;
            } else if (fen[i] == 'R') {
                this->board[j][k] = Piece::WHITE_ROOK;
            } else if (fen[i] == 'q') {
                this->board[j][k] = Piece::BLACK_QUEEN;
            } else if (fen[i] == 'Q') {
                this->board[j][k] = Piece::WHITE_QUEEN;
            } else if (fen[i] == 'k') {
                this->board[j][k] = Piece::BLACK_KING;
            } else if (fen[i] == 'K') {
                this->board[j][k] = Piece::WHITE_KING;
            }
            k++;
        }
        i++;
    }

    this->playerTurn = (fen.find("w") != std::string::npos) ? PieceColor::WHITE_PIECE : PieceColor::BLACK_PIECE;
}
