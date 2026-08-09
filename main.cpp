#include <array>
#include <iostream>
#include <vector>

#include "board_presets.hpp"
#include "chess_functions.hpp"

#include "piece_definitions/white_pieces/white_bishop.hpp"
#include "piece_definitions/white_pieces/white_king.hpp"
#include "piece_definitions/white_pieces/white_knight.hpp"
#include "piece_definitions/white_pieces/white_pawn.hpp"
#include "piece_definitions/white_pieces/white_queen.hpp"
#include "piece_definitions/white_pieces/white_rook.hpp"
#include "piece_definitions/black_pieces/black_bishop.hpp"
#include "piece_definitions/black_pieces/black_king.hpp"
#include "piece_definitions/black_pieces/black_knight.hpp"
#include "piece_definitions/black_pieces/black_pawn.hpp"
#include "piece_definitions/black_pieces/black_queen.hpp"
#include "piece_definitions/black_pieces/black_rook.hpp"



class Chess {
    public:
        //set up an array for the board and en-passant board, and vectors to store board states
        std::array<std::array<int, 8> , 8> board;
        std::array<std::array<int, 8> , 8> enPassantBoard;
        std::vector<std::array<std::array<int, 8> , 8>> possible_moves;
        std::vector<std::array<std::array<int, 8> , 8>> legal_moves;


        //wraps up all the list piece moves into a single function
        void list_White_Moves() {
            list_White_Pawn_Moves(board, enPassantBoard, possible_moves);
            list_White_Knight_Moves(board, possible_moves);
            list_White_Bishop_Moves(board, possible_moves);
            list_White_Rook_Moves(board, possible_moves);
            list_White_Queen_Moves(board, possible_moves);
            list_White_King_Moves(board, possible_moves);
        }
        void list_Black_Moves() {
            list_Black_Pawn_Moves(board, enPassantBoard, possible_moves);
            list_Black_Knight_Moves(board, possible_moves);
            list_Black_Bishop_Moves(board, possible_moves);
            list_Black_Rook_Moves(board, possible_moves);
            list_Black_Queen_Moves(board, possible_moves);
            list_Black_King_Moves(board, possible_moves);
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