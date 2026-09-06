#include <array>
#include <vector>
#include <string>
#include <iostream>
#include "../functions/functions.hpp"
#include "../board_state/board_state.hpp"
#include "../team/team.hpp"

std::vector<BoardStateStruct> BoardStateStruct::list_knight_moves() {
    int color_number;
    std::vector<BoardStateStruct> moveStorage = {};
    if(turn == White){color_number = 2;}
    if(turn == Black){color_number = -2;}
    for (int rank=0; rank<8; rank++) {
        for (int file=0; file<8; file++) {
            if (get_piece(rank, file) == color_number){ 
                if (is_in_bounds(rank+1, file+2) && !is_same_color(get_piece(rank, file), get_piece(rank+1, file+2))) {moveStorage.push_back(record_move(*this, rank, file, rank+1, file+2));}
                if (is_in_bounds(rank+1, file-2) && !is_same_color(get_piece(rank, file), get_piece(rank+1, file-2))) {moveStorage.push_back(record_move(*this, rank, file, rank+1, file-2));}
                if (is_in_bounds(rank-1, file+2) && !is_same_color(get_piece(rank, file), get_piece(rank-1, file+2))) {moveStorage.push_back(record_move(*this, rank, file, rank-1, file+2));}
                if (is_in_bounds(rank-1, file-2) && !is_same_color(get_piece(rank, file), get_piece(rank-1, file-2))) {moveStorage.push_back(record_move(*this, rank, file, rank-1, file-2));}
                if (is_in_bounds(rank+2, file+1) && !is_same_color(get_piece(rank, file), get_piece(rank+2, file+1))) {moveStorage.push_back(record_move(*this, rank, file, rank+2, file+1));}
                if (is_in_bounds(rank+2, file-1) && !is_same_color(get_piece(rank, file), get_piece(rank+2, file-1))) {moveStorage.push_back(record_move(*this, rank, file, rank+2, file-1));}
                if (is_in_bounds(rank-2, file+1) && !is_same_color(get_piece(rank, file), get_piece(rank-2, file+1))) {moveStorage.push_back(record_move(*this, rank, file, rank-2, file+1));}
                if (is_in_bounds(rank-2, file-1) && !is_same_color(get_piece(rank, file), get_piece(rank-2, file-1))) {moveStorage.push_back(record_move(*this, rank, file, rank-2, file-1));}
            }
        }
    }
    std::cout << "list_knight_moves found " << moveStorage.size() << " positions.\n";
    return moveStorage;
}