#include <array>
#include <vector>
#include <string>
#include <iostream>
#include "../functions/functions.hpp"
#include "../board_state/board_state.hpp"
#include "../team.hpp"

std::vector<BoardStateStruct> BoardStateStruct::list_knight_moves() {
    int color_number;
    std::vector<BoardStateStruct> moveStorage = {};
    if(turn == White){color_number = 2;}
    if(turn == Black){color_number = -2;}
    for (int x=0; x<8; x++) {
        for (int y=0; y<8; y++) {
            if (get_piece(x, y) == color_number){ 
                if (is_in_bounds(x+1, y+2) && !is_same_color(get_piece(x, y), get_piece(x+1, y+2))) {moveStorage.push_back(record_move(*this, x, y, x+1, y+2));}
                if (is_in_bounds(x+1, y-2) && !is_same_color(get_piece(x, y), get_piece(x+1, y-2))) {moveStorage.push_back(record_move(*this, x, y, x+1, y-2));}
                if (is_in_bounds(x-1, y+2) && !is_same_color(get_piece(x, y), get_piece(x-1, y+2))) {moveStorage.push_back(record_move(*this, x, y, x-1, y+2));}
                if (is_in_bounds(x-1, y-2) && !is_same_color(get_piece(x, y), get_piece(x-1, y-2))) {moveStorage.push_back(record_move(*this, x, y, x-1, y-2));}
                if (is_in_bounds(x+2, y+1) && !is_same_color(get_piece(x, y), get_piece(x+2, y+1))) {moveStorage.push_back(record_move(*this, x, y, x+2, y+1));}
                if (is_in_bounds(x+2, y-1) && !is_same_color(get_piece(x, y), get_piece(x+2, y-1))) {moveStorage.push_back(record_move(*this, x, y, x+2, y-1));}
                if (is_in_bounds(x-2, y+1) && !is_same_color(get_piece(x, y), get_piece(x-2, y+1))) {moveStorage.push_back(record_move(*this, x, y, x-2, y+1));}
                if (is_in_bounds(x-2, y-1) && !is_same_color(get_piece(x, y), get_piece(x-2, y-1))) {moveStorage.push_back(record_move(*this, x, y, x-2, y-1));}
            }
        }
    }
    std::cout << "list_knight_moves found " << moveStorage.size() << " positions.\n";
    return moveStorage;
}