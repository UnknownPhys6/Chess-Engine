#include <array>
#include <iostream>
#include <vector>

#include "board_state/board_state_struct.hpp"
#include "functions/functions.hpp"
#include "chess.hpp"


int main(){
    //begin the fun stuff
    Chess game1{};
    BoardStateStruct boardState;

    game1.boardState.set_up_chessboard("standard");
    game1.boardState.set_enpassant(2, 3, Team::Neither);

    std::cout << "Chessboard looks like this before any shenanigans:" << std::endl;
    game1.boardState.print_chessboard();
    game1.boardState.list_piece_locations();

    boardState.list_pawn_moves();
    std::cout << "Here's all generated possible positions:" << std::endl;
    print_positions(game1.possibleMoves);    

    game1.boardState.print_boardState();

    std::cout << "Press Enter to continue...";
    std::cin.get();
    return 0;
}
