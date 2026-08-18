#pragma once

#include <array>
#include <vector>
#include <string>
#include "../chess_functions.hpp"


namespace pieceMoves{
    //ex: list_Knight_Move();
    void list_knight_moves(
        BoardStateStruct boardState,
        std::vector<BoardStateStruct> &possible_moves
    ) {
        int color_number;
        if (boardState.turn == Team::White){
            color_number = 2;
        }
        else if (boardState.turn == Team::Black){
            color_number = -2;
        }
        for (int x=0; x<8; x++) {
            for (int y=0; y<8; y++) {
                if (chessFunctions::get_piece(boardState, x, y) == color_number) {
                    if (!chessFunctions::is_same_color(chessFunctions::get_piece(boardState, x, y), chessFunctions::get_piece(boardState, x+1, y+2))) {
                        chessFunctions::record_possible_move (boardState, possible_moves, x, y, x+1, y+2);
                    }
                    if (!chessFunctions::is_same_color(chessFunctions::get_piece(boardState, x, y), chessFunctions::get_piece(boardState, x+1, y-2))) {
                        chessFunctions::record_possible_move (boardState, possible_moves, x, y, x+1, y-2);
                    }
                    if (!chessFunctions::is_same_color(chessFunctions::get_piece(boardState, x, y), chessFunctions::get_piece(boardState, x-1, y+2))) {
                        chessFunctions::record_possible_move (boardState, possible_moves, x, y, x-1, y+2);
                    }
                    if (!chessFunctions::is_same_color(chessFunctions::get_piece(boardState, x, y), chessFunctions::get_piece(boardState, x-1, y-2))) {
                        chessFunctions::record_possible_move (boardState, possible_moves, x, y, x-1, y-2);
                    }
                    if (!chessFunctions::is_same_color(chessFunctions::get_piece(boardState, x, y), chessFunctions::get_piece(boardState, x+2, y+1))) {
                        chessFunctions::record_possible_move (boardState, possible_moves, x, y, x+2, y+1);
                    }
                    if (!chessFunctions::is_same_color(chessFunctions::get_piece(boardState, x, y), chessFunctions::get_piece(boardState, x+2, y-1))) {
                        chessFunctions::record_possible_move (boardState, possible_moves, x, y, x+2, y-1);
                    }
                    if (!chessFunctions::is_same_color(chessFunctions::get_piece(boardState, x, y), chessFunctions::get_piece(boardState, x-2, y+1))) {
                        chessFunctions::record_possible_move (boardState, possible_moves, x, y, x-2, y+1);
                    }
                    if (!chessFunctions::is_same_color(chessFunctions::get_piece(boardState, x, y), chessFunctions::get_piece(boardState, x-2, y-1))) {
                        chessFunctions::record_possible_move (boardState, possible_moves, x, y, x-2, y-1);
                    }
                }
            }
        }
    }
}