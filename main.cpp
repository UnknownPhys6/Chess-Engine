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
        BoardStateStruct boardState;
        std::vector<BoardStateStruct> possibleMoves;
        std::vector<BoardStateStruct> legal_moves;
        

        //wraps up all the list piece moves into a single function
        void list_white_moves(BoardStateStruct boardState) {
            boardState.turn = Team::White;
            std::cout << "doing pawn moves..." << std::endl;
            pieceMoves::list_pawn_moves(boardState, possibleMoves);
            
            std::cout << "doing knight moves..." << std::endl;
            pieceMoves::list_knight_moves(boardState, possibleMoves);

            std::cout << "doing bishop moves..." << std::endl;
            pieceMoves::list_bishop_moves(boardState, possibleMoves);

            std::cout << "doing rook moves..." << std::endl;
            pieceMoves::list_rook_moves(boardState, possibleMoves);

            std::cout << "doing queen moves..." << std::endl;
            pieceMoves::list_queen_moves(boardState, possibleMoves);

            std::cout << "doing king moves..." << std::endl;
            pieceMoves::list_king_moves(boardState, possibleMoves);
            std::cout << "...king done\n";
        }


        void list_black_moves(BoardStateStruct boardState) {
            boardState.turn = Team::Black;
            std::cout << "doing pawn moves..." << std::endl;
            pieceMoves::list_pawn_moves(boardState, possibleMoves);

            std::cout << "doing knight moves..." << std::endl;
            pieceMoves::list_knight_moves(boardState, possibleMoves);
            
            std::cout << "doing bishop moves..." << std::endl;
            pieceMoves::list_bishop_moves(boardState, possibleMoves);

            std::cout << "doing rook moves..." << std::endl;
            pieceMoves::list_rook_moves(boardState, possibleMoves);

            std::cout << "doing queen moves..." << std::endl;
            pieceMoves::list_queen_moves(boardState, possibleMoves);

            std::cout << "doing king moves..." << std::endl;
            pieceMoves::list_king_moves(boardState, possibleMoves);
            std::cout << "...king done\n";
        }
};


int main(){
    //begin the fun stuff
    Chess game1{};
    presets::set_Up_Chessboard(game1.boardState, "standard");
    presets::set_enpassant(game1.boardState, 2, 3, Team::Neither);

    std::cout << "Chessboard looks like this before any shenanigans:" << std::endl;
    chessFunctions::print_chessboard(game1.boardState);
    chessFunctions::list_piece_locations(game1.boardState);

    game1.list_white_moves(game1.boardState);
    std::cout << "Here's all generated possible positions:" << std::endl;
    chessFunctions::print_positions(game1.possibleMoves);    

    game1.boardState.print_boardState();

    std::cout << "Press Enter to continue...";
    std::cin.get();
    return 0;
}
