#include <array>
#include <vector>
#include <string>
#include <iostream>
#include "../functions/functions.hpp"
#include "../board_state/board_state.hpp"
#include "../team.hpp"

//lists black king moves
std::vector<BoardStateStruct> BoardStateStruct::list_king_moves() {
    int color_number;
    std::vector<BoardStateStruct> moveStorage = {};
    if(turn == Team::White){color_number = 6;}
    if(turn == Team::Black){color_number = -6;}
    for (int x=0; x<8; x++) {
        for (int y=0; y<8; y++) {
                if (get_piece(x, y) == color_number) {
                if (is_in_bounds(x, y+1) && !is_same_color(get_piece(x, y), get_piece(x,y+1))) {moveStorage.push_back(record_move(*this, x, y, x, y+1));}
                if (is_in_bounds(x+1, y+1) && !is_same_color(get_piece(x, y), get_piece(x+1,y+1))) {moveStorage.push_back(record_move(*this, x, y, x+1, y+1));}
                if (is_in_bounds(x+1, y) && !is_same_color(get_piece(x, y), get_piece(x+1,y))) {moveStorage.push_back(record_move(*this, x, y, x+1, y));}
                if (is_in_bounds(x+1, y-1) && !is_same_color(get_piece(x, y), get_piece(x+1,y-1))) {moveStorage.push_back(record_move(*this, x, y, x+1, y-1));}
                if (is_in_bounds(x, y-1) && !is_same_color(get_piece(x, y), get_piece(x,y-1))) {moveStorage.push_back(record_move(*this, x, y, x, y-1));}
                if (is_in_bounds(x-1, y-1) && !is_same_color(get_piece(x, y), get_piece(x-1,y-1))) {moveStorage.push_back(record_move(*this, x, y, x-1, y-1));}
                if (is_in_bounds(x-1, y) && !is_same_color(get_piece(x, y), get_piece(x-1,y))) {moveStorage.push_back(record_move(*this, x, y, x-1, y));}
                if (is_in_bounds(x-1, y+1) && !is_same_color(get_piece(x, y), get_piece(x-1,y+1))) {moveStorage.push_back(record_move(*this, x, y, x-1, y+1));}
            }
        }
    }
    std::cout << "list_king_moves found " << moveStorage.size() << " positions.\n";
    return moveStorage;
}