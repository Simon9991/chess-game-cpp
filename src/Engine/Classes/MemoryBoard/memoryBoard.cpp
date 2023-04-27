#include "memoryBoard.hpp"

EngineMemoryBoard::EngineMemoryBoard(std::string fen) {
    int i = 0;
    int j = 0;

    this->playerTurn = PieceColor::WHITE_PIECE;

    this->memoryBoard = new PieceType *[BOARD_SIZE];

    std::cout << "Creating memory board..." << std::endl;
    while (i < BOARD_SIZE) {
        this->memoryBoard[i] = new PieceType[BOARD_SIZE];
        j = 0;

        while (j < BOARD_SIZE) {
            this->memoryBoard[i][j] = EMPTY;
            j++;
        }
        i++;
    }
    std::cout << "Memory board created" << std::endl;

    this->initBoard(fen);
}

EngineMemoryBoard::~EngineMemoryBoard() {
    for (int i = 0; i < BOARD_SIZE; i++)
        delete[] this->memoryBoard[i];
    delete[] this->memoryBoard;
}

void EngineMemoryBoard::printMemoryBoard() const {
    std::cout << "Memory board:" << std::endl;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++)
            std::cout << this->memoryBoard[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void EngineMemoryBoard::initBoard(std::string fen) {
    // Initializes the board with the given FEN string
    // fen is the FEN string
    size_t i = 0;
    int j = 0;
    int k = 0;

    // Setting up the memeryBoard fist
    // TODO: Change to a switch case
    // TODO: Add FEN validation
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
                this->memoryBoard[j][k] = PieceType::BLACK_PAWN;
            } else if (fen[i] == 'P') {
                this->memoryBoard[j][k] = PieceType::WHITE_PAWN;
            } else if (fen[i] == 'n') {
                this->memoryBoard[j][k] = PieceType::BLACK_KNIGHT;
            } else if (fen[i] == 'N') {
                this->memoryBoard[j][k] = PieceType::WHITE_KNIGHT;
            } else if (fen[i] == 'b') {
                this->memoryBoard[j][k] = PieceType::BLACK_BISHOP;
            } else if (fen[i] == 'B') {
                this->memoryBoard[j][k] = PieceType::WHITE_BISHOP;
            } else if (fen[i] == 'r') {
                this->memoryBoard[j][k] = PieceType::BLACK_ROOK;
            } else if (fen[i] == 'R') {
                this->memoryBoard[j][k] = PieceType::WHITE_ROOK;
            } else if (fen[i] == 'q') {
                this->memoryBoard[j][k] = PieceType::BLACK_QUEEN;
            } else if (fen[i] == 'Q') {
                this->memoryBoard[j][k] = PieceType::WHITE_QUEEN;
            } else if (fen[i] == 'k') {
                this->memoryBoard[j][k] = PieceType::BLACK_KING;
            } else if (fen[i] == 'K') {
                this->memoryBoard[j][k] = PieceType::WHITE_KING;
            }
            k++;
        }
        i++;
    }

    this->playerTurn = (fen.find("w") != std::string::npos) ? PieceColor::WHITE_PIECE : PieceColor::BLACK_PIECE;


}

void EngineMemoryBoard::updatePosition(PieceType **position) {
    this->memoryBoard = position;
}

bool EngineMemoryBoard::isLegalMove(int sourceSquare, int destinationSquare) const {
    if (!isWithinBounds(sourceSquare) || !isWithinBounds(destinationSquare))
        return false;

    // Add your logic here to determine if the move is legal based on the current position

    return true;  // Placeholder return statement
}

bool EngineMemoryBoard::isWithinBounds(int square) const {
    return square >= 0 && square < BOARD_SIZE * BOARD_SIZE;
}