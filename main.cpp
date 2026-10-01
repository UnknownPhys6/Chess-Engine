#include <array>
#include <iostream>
#include <fstream>
#include <vector>

#include "board_state/board_state.hpp"
#include "functions/functions.hpp"
#include "team/team.hpp"
#include "chess.hpp"


int main(){
    std::ofstream debugFile("debug.txt");
    std::cerr.rdbuf(debugFile.rdbuf());

    //instanciate stuff
    Chess game1{};
    
    //sets up the board
    game1.boardState.set_up_chessboard("test");

    
    //prints out chessboard information
    std::cout << "Chessboard looks like this before any shenanigans:\n";
    game1.boardState.print_boardState();
    game1.boardState.list_piece_locations();
    game1.boardState.print_en_passant_visual();
    game1.boardState.find_squares_attacked_by_white();
    game1.boardState.print_squares_attacked_by(White);

    

    //find and prints moves.
    std::vector<BoardStateStruct> legalMoves = game1.boardState.list_legal_moves();
    std::cout << "Here's all generated legal positions:\n";
    print_positions(legalMoves);




    //end of program, cin.get to prevent it from closing instantly
    std::cout << "Press Enter to continue...";
    std::cin.get();
    return 0;
}
