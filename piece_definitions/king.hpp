#pragma once

#include <array>
#include <vector>
#include <string>
#include "../chess_functions.hpp"


namespace pieceMoves{
    //lists black king moves
    void list_king_moves(
        BoardStateStruct boardState,
        std::vector<BoardStateStruct> &possible_moves
    ) {
        int color_number;
        if (boardState.turn == Team::White){color_number = 6;}
        else if (boardState.turn == Team::Black){color_number = -6;}
        for (int x=0; x<8; x++) {
            for (int y=0; y<8; y++) {
                std::cout << "test 1: x = " << x << " y = " << y << "\n";
                if (chessFunctions::get_piece(boardState, x, y) == color_number) {
                    if (chessFunctions::is_different_color(chessFunctions::get_piece(boardState, x, y), chessFunctions::get_piece(boardState, x,y+1))) {chessFunctions::record_possible_move (boardState, possible_moves, x, y, x, y+1);}
                    if (chessFunctions::is_different_color(chessFunctions::get_piece(boardState, x, y), chessFunctions::get_piece(boardState, x+1,y+1))) {chessFunctions::record_possible_move (boardState, possible_moves, x, y, x+1, y+1);}
                    if (chessFunctions::is_different_color(chessFunctions::get_piece(boardState, x, y), chessFunctions::get_piece(boardState, x+1,y))) {chessFunctions::record_possible_move (boardState, possible_moves, x, y, x+1, y);}
                    if (chessFunctions::is_different_color(chessFunctions::get_piece(boardState, x, y), chessFunctions::get_piece(boardState, x+1,y-1))) {chessFunctions::record_possible_move (boardState, possible_moves, x, y, x+1, y-1);}
                    if (chessFunctions::is_different_color(chessFunctions::get_piece(boardState, x, y), chessFunctions::get_piece(boardState, x,y-1))) {chessFunctions::record_possible_move (boardState, possible_moves, x, y, x, y-1);}
                    if (chessFunctions::is_different_color(chessFunctions::get_piece(boardState, x, y), chessFunctions::get_piece(boardState, x-1,y-1))) {chessFunctions::record_possible_move (boardState, possible_moves, x, y, x-1, y-1);}
                    if (chessFunctions::is_different_color(chessFunctions::get_piece(boardState, x, y), chessFunctions::get_piece(boardState, x-1,y))) {chessFunctions::record_possible_move (boardState, possible_moves, x, y, x-1, y);}
                    if (chessFunctions::is_different_color(chessFunctions::get_piece(boardState, x, y), chessFunctions::get_piece(boardState, x-1,y+1))) {chessFunctions::record_possible_move (boardState, possible_moves, x, y, x-1, y+1);}
                    std::cout << "test 2: x = " << x << " y = " << y << "\n";

                }
            }
        }
    }
}