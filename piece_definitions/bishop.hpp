#pragma once

#include <array>
#include <vector>
#include <string>
#include "../chess_functions.hpp"


namespace pieceMoves{
    //ex: list_Black_Bishop_Moves();
    void list_bishop_moves(
        BoardStateStruct boardState,
        std::vector<BoardStateStruct> &possible_moves
    ) {
        int color_number;
        if (boardState.turn == Team::White){color_number = 3;}
        else if (boardState.turn == Team::Black){color_number = -3;}
        for (int x=0; x<8; x++) {
            for (int y=0; y<8; y++) {
                if (chessFunctions::get_piece(boardState, x, y) == color_number) {
                    //loop for range of attempted move
                    for (int distance=1; distance<7; distance++) {
                        //if square is empty, record possible move
                        if (chessFunctions::get_piece(boardState, x + distance, y + distance) == 0) {
                            chessFunctions::record_possible_move (boardState, possible_moves, x, y, x+distance, y+distance);
                        }
                        //if square has opposite color piece, record capture and break loop
                        if (chessFunctions::is_different_color(chessFunctions::get_piece(boardState, x, y), chessFunctions::get_piece(boardState, x + distance, y + distance))) {
                            chessFunctions::record_possible_move (boardState, possible_moves, x, y, x+distance, y+distance);
                            break;
                        }
                        //if square has same color piece, break loop for direction.
                        if (chessFunctions::is_same_color(chessFunctions::get_piece(boardState, x, y), chessFunctions::get_piece(boardState, x + distance, y + distance))) {
                            break;
                        }
                    }
                    for (int distance=1; distance<7; distance++) {
                        if (chessFunctions::get_piece(boardState, x+distance, y-distance) == 0) {
                            chessFunctions::record_possible_move (boardState, possible_moves, x, y, x+distance, y-distance);
                        }
                        if (chessFunctions::is_different_color(chessFunctions::get_piece(boardState, x, y), chessFunctions::get_piece(boardState, x+distance, y-distance))) {
                            chessFunctions::record_possible_move (boardState, possible_moves, x, y, x+distance, y-distance);
                            break;
                        }
                        if (chessFunctions::is_same_color(chessFunctions::get_piece(boardState, x, y), chessFunctions::get_piece(boardState, x+distance, y-distance))) {
                            break;
                        }
                    }
                    for (int distance=1; distance<7; distance++) {
                        if (chessFunctions::get_piece(boardState, x-distance, y+distance) == 0) {
                            chessFunctions::record_possible_move (boardState, possible_moves, x, y, x-distance, y+distance);
                        }
                        if (chessFunctions::is_different_color(chessFunctions::get_piece(boardState, x, y), chessFunctions::get_piece(boardState, x-distance, y+distance))) {
                            chessFunctions::record_possible_move (boardState, possible_moves, x, y, x-distance, y+distance);
                            break;
                        }
                        if (chessFunctions::is_same_color(chessFunctions::get_piece(boardState, x, y), chessFunctions::get_piece(boardState, x-distance, y+distance))) {
                            break;
                        }
                    }
                    for (int distance=1; distance<7; distance++) {
                        if (chessFunctions::get_piece(boardState, x-distance, y-distance) == 0) {
                            chessFunctions::record_possible_move (boardState, possible_moves, x, y, x-distance, y-distance);
                        }
                        if (chessFunctions::is_different_color(chessFunctions::get_piece(boardState, x, y), chessFunctions::get_piece(boardState, x-distance, y-distance))) {
                            chessFunctions::record_possible_move (boardState, possible_moves, x, y, x-distance, y-distance);
                            break;
                        }
                        if (chessFunctions::is_same_color(chessFunctions::get_piece(boardState, x, y), chessFunctions::get_piece(boardState, x-distance, y-distance))) {
                            break;
                        }
                    }
                }
            }
        }
    }    
}