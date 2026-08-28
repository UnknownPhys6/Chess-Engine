#include <array>
#include <vector>
#include <string>
#include <iostream>
#include "../functions/functions.hpp"
#include "../board_state/board_state.hpp"
#include "../team.hpp"


std::vector<BoardStateStruct> BoardStateStruct::list_king_moves() {
    int color_number;
    std::vector<BoardStateStruct> moveStorage = {};
    if(turn == Team::White){color_number = 6;}
    if(turn == Team::Black){color_number = -6;}
    for (int rank=0; rank<8; rank++) {
        for (int file=0; file<8; file++) {
            if (get_piece(rank, file) == color_number) {
                if (is_in_bounds(rank, file+1) && !is_same_color(get_piece(rank, file), get_piece(rank,file+1))) {moveStorage.push_back(record_move(*this, rank, file, rank, file+1));}
                if (is_in_bounds(rank+1, file+1) && !is_same_color(get_piece(rank, file), get_piece(rank+1,file+1))) {moveStorage.push_back(record_move(*this, rank, file, rank+1, file+1));}
                if (is_in_bounds(rank+1, file) && !is_same_color(get_piece(rank, file), get_piece(rank+1,file))) {moveStorage.push_back(record_move(*this, rank, file, rank+1, file));}
                if (is_in_bounds(rank+1, file-1) && !is_same_color(get_piece(rank, file), get_piece(rank+1,file-1))) {moveStorage.push_back(record_move(*this, rank, file, rank+1, file-1));}
                if (is_in_bounds(rank, file-1) && !is_same_color(get_piece(rank, file), get_piece(rank,file-1))) {moveStorage.push_back(record_move(*this, rank, file, rank, file-1));}
                if (is_in_bounds(rank-1, file-1) && !is_same_color(get_piece(rank, file), get_piece(rank-1,file-1))) {moveStorage.push_back(record_move(*this, rank, file, rank-1, file-1));}
                if (is_in_bounds(rank-1, file) && !is_same_color(get_piece(rank, file), get_piece(rank-1,file))) {moveStorage.push_back(record_move(*this, rank, file, rank-1, file));}
                if (is_in_bounds(rank-1, file+1) && !is_same_color(get_piece(rank, file), get_piece(rank-1,file+1))) {moveStorage.push_back(record_move(*this, rank, file, rank-1, file+1));}
            }
        }
    }
    std::cout << "list_king_moves found " << moveStorage.size() << " positions.\n";
    return moveStorage;
}