#include "memoryBoard.hpp"

EngineMemoryBoard::EngineMemoryBoard(std::string fen) {
    this->playerTurn = PieceColor::WHITE_PIECE;

    this->memoryBoard = new PieceType *[BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        this->memoryBoard[i] = new PieceType[BOARD_SIZE];
        for (int j = 0; j < BOARD_SIZE; j++)
            this->memoryBoard[i][j] = PieceType::EMPTY;
    }

    this->initBoard(fen);
}

EngineMemoryBoard::~EngineMemoryBoard() {
}

void EngineMemoryBoard::initBoard(std::string fen) {
    int i = 0;
    int j = 0;

    for (char c : fen) {
        if (c == '/') {
            i++;
            j = 0;
        } else if (c >= '1' && c <= '8') {
            for (int k = 0; k < c - '0'; k++)
                this->memoryBoard[i][j++] = PieceType::EMPTY;
        } else {
            switch (c) {
                case 'p':
                    this->memoryBoard[i][j++] = PieceType::BLACK_PAWN;
                    break;
                case 'r':
                    this->memoryBoard[i][j++] = PieceType::BLACK_ROOK;
                    break;
                case 'n':
                    this->memoryBoard[i][j++] = PieceType::BLACK_KNIGHT;
                    break;
                case 'b':
                    this->memoryBoard[i][j++] = PieceType::BLACK_BISHOP;
                    break;
                case 'q':
                    this->memoryBoard[i][j++] = PieceType::BLACK_QUEEN;
                    break;
                case 'k':
                    this->memoryBoard[i][j++] = PieceType::BLACK_KING;
                    break;
                case 'P':
                    this->memoryBoard[i][j++] = PieceType::WHITE_PAWN;
                    break;
                case 'R':
                    this->memoryBoard[i][j++] = PieceType::WHITE_ROOK;
                    break;
                case 'N':
                    this->memoryBoard[i][j++] = PieceType::WHITE_KNIGHT;
                    break;
                case 'B':
                    this->memoryBoard[i][j++] = PieceType::WHITE_BISHOP;
                    break;
                case 'Q':
                    this->memoryBoard[i][j++] = PieceType::WHITE_QUEEN;
                    break;
                case 'K':
                    this->memoryBoard[i][j++] = PieceType::WHITE_KING;
                    break;
                default:
                    break;
            }
        }
    }

    this->playerTurn = (fen.find("w") != std::string::npos) ? PieceColor::WHITE_PIECE : PieceColor::BLACK_PIECE;

    
}
