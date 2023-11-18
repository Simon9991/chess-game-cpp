#ifndef BOARD_HPP
#define BOARD_HPP

#include "../../types.hpp"
#include <array>
#include <string>

namespace Engine {
    class Board {
        public:
            Board(const std::string& fen);
            ~Board();

            void print() const;
        private:
            // private members
            std::array<Bitboard, PIECE_NB> bitboards;
            Color side_to_move;
            CastlingRights castling_rights;
            Square en_passant_square;
            int fifty_move_counter;
            int ply;

            // private methods
            void init(const std::string& fen);
            void clearBoard();
            void parseBoardPart(const std::string& boardPart);
            CastlingRights parseCastlingRights(const std::string& castlingRights);
            Square parseEnPassantSquare(const std::string& enPassant);
            Piece charToPiece(char c) const;
            void setPieceOnSquare(Piece piece, Square square);
            Piece pieceOnSquare(Square square) const;
            char pieceToChar(Piece piece) const;
   };
}

#endif // BOARD_HPP

