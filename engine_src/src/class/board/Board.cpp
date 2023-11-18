#include "Board.hpp"
#include <ostream>
#include <iostream>
#include <sstream>

namespace Engine {
    Board::Board(const std::string& fen) {
        this->bitboards.fill(0);
        this->side_to_move = WHITE;
        this->castling_rights = ANY_CASTLING;
        this->en_passant_square = SQ_NONE;
        this->fifty_move_counter = 0;
        this->ply = 0;

        init(fen);
    }

    Board::~Board() {}

    void Board::init(const std::string& fen) {
        std::istringstream fenStream(fen);
        std::string boardPart, activeColor, castlingRights, enPassant, halfMove, fullMove;

        // Read FEN components
        fenStream >> boardPart >> activeColor >> castlingRights >> enPassant >> halfMove >> fullMove;

        // Clear board state
        clearBoard();

        // Parse board part for piece placement
        parseBoardPart(boardPart);

        // Set active color
        this->side_to_move = (activeColor == "w") ? WHITE : BLACK;

        // Parse castling rights
        this->castling_rights = parseCastlingRights(castlingRights);

        // Parse en passant square
        // this->en_passant_square = parseEnPassantSquare(enPassant);

        // Set halfmove and fullmove counters
        this->fifty_move_counter = std::stoi(halfMove);
        this->ply = (std::stoi(fullMove) - 1) * 2 + (this->side_to_move == BLACK ? 1 : 0);
    }

    CastlingRights Board::parseCastlingRights(const std::string& castlingRights) {
        CastlingRights rights = NO_CASTLING;

        for (char c : castlingRights) {
            switch (c) {
                case 'K': rights = static_cast<CastlingRights>(rights | WHITE_OO);  break;
                case 'Q': rights = static_cast<CastlingRights>(rights | WHITE_OOO); break;
                case 'k': rights = static_cast<CastlingRights>(rights | BLACK_OO);  break;
                case 'q': rights = static_cast<CastlingRights>(rights | BLACK_OOO); break;
                case '-': break;
                default: /* Handle invalid character if needed */; break;
            }
        }

        return rights;
    }

    Square Board::parseEnPassantSquare(const std::string& enPassant) {
        if (enPassant == "-") {
            return SQ_NONE;
        }

        // Assuming the squareStr is a valid square (e.g., "e3")
        int file = enPassant[0] - 'a'; // Convert file from 'a'-'h' to 0-7
        int rank = enPassant[1] - '1'; // Convert rank from '1'-'8' to 0-7

        return make_square(File(file), Rank(7 - rank));
    }

    void Board::clearBoard() {
        this->bitboards.fill(0);
    }

    void Board::parseBoardPart(const std::string& boardPart) {
        Square square = SQ_A8; // Start from the top-left square of the board

        for (char c : boardPart) {
            if (isdigit(c)) {
                // Numeric character: Skip the given number of squares
                square = Square(square + (c - '0'));
            } else if (c == '/') {
                // Slash character: Move to the next rank
                square = Square(square - 16); // Move down one rank
            } else {
                // Piece character: Set the bit for this piece on this square
                Piece piece = charToPiece(c);
                if (piece != NO_PIECE) {
                    setPieceOnSquare(piece, square);
                    square = Square(square + 1); // Move to the next square
                }
            }
        }
    }

    Piece Board::charToPiece(char c) const {
        switch (c) {
            case 'P': return W_PAWN;
            case 'N': return W_KNIGHT;
            case 'B': return W_BISHOP;
            case 'R': return W_ROOK;
            case 'Q': return W_QUEEN;
            case 'K': return W_KING;
            case 'p': return B_PAWN;
            case 'n': return B_KNIGHT;
            case 'b': return B_BISHOP;
            case 'r': return B_ROOK;
            case 'q': return B_QUEEN;
            case 'k': return B_KING;
            default:  return NO_PIECE;
        }
    }

    void Board::setPieceOnSquare(Piece piece, Square square) {
        // Set the bit for this piece on this square
        // Assuming bitboards is a std::array<Bitboard, PIECE_NB>
        bitboards[piece] |= (1ULL << square);
    }

    void Board::print() const {
        for (int rank = RANK_8; rank >= RANK_1; --rank) {
            std::cout << rank + 1 << " "; // Print rank number
            for (int file = FILE_A; file <= FILE_H; ++file) {
                Square square = make_square(File(file), Rank(rank));
                Piece piece = pieceOnSquare(square);
                char pieceChar = pieceToChar(piece);
                std::cout << pieceChar << " ";
            }
            std::cout << "\n";
        }

        std::cout << "  a b c d e f g h\n"; // Print file letters
    }

    Piece Board::pieceOnSquare(Square square) const {
        // Iterate through all piece types and check if the bit is set
        for (int pt = W_PAWN; pt <= B_KING; ++pt) {
            if (bitboards[pt] & (1ULL << square)) {
                return static_cast<Piece>(pt);
            }
        }
        return NO_PIECE;
    }

    char Board::pieceToChar(Piece piece) const {
        switch (piece) {
            case W_PAWN: return 'P';
            case W_KNIGHT: return 'N';
            case W_BISHOP: return 'B';
            case W_ROOK: return 'R';
            case W_QUEEN: return 'Q';
            case W_KING: return 'K';
            case B_PAWN: return 'p';
            case B_KNIGHT: return 'n';
            case B_BISHOP: return 'b';
            case B_ROOK: return 'r';
            case B_QUEEN: return 'q';
            case B_KING: return 'k';
            default: return '.';
        }
    }

};
