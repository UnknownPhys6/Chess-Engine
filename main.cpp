#include <array>
#include <iostream>
#include <vector>

#include "board_presets.hpp"
#include "chess_functions.hpp"

#include "piece_definitions/bishop.hpp"
#include "piece_definitions/king.hpp"
#include "piece_definitions/knight.hpp"
#include "piece_definitions/pawn.hpp"
#include "piece_definitions/queen.hpp"
#include "piece_definitions/rook.hpp"




class Chess {
    public:
        //set up an array for the board and en-passant board, and vectors to store board states
        std::array<std::array<int, 8> , 8> board;
        std::array<std::array<int, 8> , 8> enPassantBoard;
        std::vector<std::array<std::array<int, 8> , 8>> possible_moves;
        std::vector<std::array<std::array<int, 8> , 8>> legal_moves;


        //wraps up all the list piece moves into a single function
        void list_White_Moves() {
            pieceMoves::list_pawn_moves("white", board, enPassantBoard, possible_moves);
            pieceMoves::list_knight_moves("white", board, possible_moves);
            pieceMoves::list_bishop_moves("white", board, possible_moves);
            pieceMoves::list_rook_moves("white", board, possible_moves);
            pieceMoves::list_queen_moves("white", board, possible_moves);
            pieceMoves::list_king_moves("white", board, possible_moves);
        }
        void list_Black_Moves() {
            pieceMoves::list_pawn_moves("black", board, enPassantBoard, possible_moves);
            pieceMoves::list_knight_moves("black", board, possible_moves);
            pieceMoves::list_bishop_moves("black", board, possible_moves);
            pieceMoves::list_rook_moves("black", board, possible_moves);
            pieceMoves::list_queen_moves("black", board, possible_moves);
            pieceMoves::list_king_moves("black", board, possible_moves);
        }

};


int main(){
    //begin the fun stuff
    Chess game1{};
    presets::set_up_Chessboard(game1.board, game1.enPassantBoard, "test");
    presets::set_up_enpassant_board(game1.enPassantBoard);
    std::cout << "Chessboard looks like this before any shenanigans:" << std::endl;
    chessFunctions::print_Chessboard(game1.board);
    game1.list_White_Moves();
    std::cout << "Chessboard ending position" << std::endl;
    chessFunctions::print_Chessboard(game1.board);
    return 0;
}