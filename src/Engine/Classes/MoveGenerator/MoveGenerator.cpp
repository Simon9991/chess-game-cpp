#include "MoveGenerator.hpp"

std::vector<Move> MoveGenerator::generateLegalMoves(const EngineMemoryBoard& board, PieceColor color) {
    std::vector<Move> legalMoves;
    
    for (int square = 0; square < BOARD_SIZE * BOARD_SIZE; ++square) {
        int piece = board.getPiece(square);

        if (piece != 0 && board.getPieceColor(piece) == color) {
            switch (board.getPieceType(piece)) {
                case BasicPieceType::PAWN:
                    generatePawnMoves(board, square, legalMoves, color);
                    break;
                case BasicPieceType::KNIGHT:
                    generateKnightMoves(board, square, legalMoves);
                    break;
                case BasicPieceType::BISHOP:
                    generateBishopMoves(board, square, legalMoves);
                    break;
                case BasicPieceType::ROOK:
                    generateRookMoves(board, square, legalMoves);
                    break;
                case BasicPieceType::QUEEN:
                    generateQueenMoves(board, square, legalMoves);
                    break;
                case BasicPieceType::KING:
                    generateKingMoves(board, square, legalMoves);
                    break;
                default:
                    break;
            }
        }
    }
    
    return legalMoves;
}

void MoveGenerator::generatePawnMoves(const EngineMemoryBoard& board, int sourceSquare, std::vector<Move>& moves, PieceColor color) {

    // Get the rank and file of the source square
    int rank = sourceSquare / BOARD_SIZE;
    int file = sourceSquare % BOARD_SIZE;
    
    // Determine the direction of pawn movement based on the color
    int direction = (color == PieceColor::WHITE_PIECE) ? -1 : 1;
    
    // Check if the pawn can move one square forward
    int destinationSquare = sourceSquare + direction * BOARD_SIZE;
    if (board.isEmptySquare(destinationSquare)) {
        moves.emplace_back(sourceSquare, destinationSquare, board.getPiece(sourceSquare));
        
        // Check if the pawn is on its starting rank and can move two squares forward
        if ((color == PieceColor::WHITE_PIECE && rank == 6) || (color == PieceColor::BLACK_PIECE && rank == 1)) {
            destinationSquare += direction * BOARD_SIZE;
            if (board.isEmptySquare(destinationSquare)) {
                moves.emplace_back(sourceSquare, destinationSquare, board.getPiece(sourceSquare));
            }
        }
    }
    
    // Check if the pawn can capture diagonally
    int leftCaptureSquare = sourceSquare + direction * BOARD_SIZE - 1;
    if (board.isEnemyPiece(leftCaptureSquare, color)) {
        moves.emplace_back(sourceSquare, leftCaptureSquare, board.getPiece(sourceSquare), board.getPiece(leftCaptureSquare));
    }
    
    int rightCaptureSquare = sourceSquare + direction * BOARD_SIZE + 1;
    if (board.isEnemyPiece(rightCaptureSquare, color)) {
        moves.emplace_back(sourceSquare, rightCaptureSquare, board.getPiece(sourceSquare), board.getPiece(rightCaptureSquare));
    }
    
    // TODO: Handle en passant captures and pawn promotion moves if necessary
}


void MoveGenerator::generateKnightMoves(const EngineMemoryBoard& board, int sourceSquare, std::vector<Move>& moves) {
    // Add logic here to generate legal knight moves based on the current board position
}

void MoveGenerator::generateBishopMoves(const EngineMemoryBoard& board, int sourceSquare, std::vector<Move>& moves) {
    // Add logic here to generate legal bishop moves based on the current board position
}

void MoveGenerator::generateRookMoves(const EngineMemoryBoard& board, int sourceSquare, std::vector<Move>& moves) {
    // Add logic here to generate legal rook moves based on the current board position
}

void MoveGenerator::generateQueenMoves(const EngineMemoryBoard& board, int sourceSquare, std::vector<Move>& moves) {
    // Add logic here to generate legal queen moves based on the current board position
}

void MoveGenerator::generateKingMoves(const EngineMemoryBoard& board, int sourceSquare, std::vector<Move>& moves) {
    // Add logic here to generate legal king moves based on the
}
