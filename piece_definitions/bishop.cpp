#include <array>
#include <vector>
#include <string>
#include <iostream>
#include "../functions/functions.hpp"
#include "../board_state/board_state.hpp"
#include "../team/team.hpp"


std::vector<BoardStateStruct> BoardStateStruct::list_bishop_moves() {
    int color_number;
    std::vector<BoardStateStruct> moveStorage = {};
    if(turn == Team::White){color_number = 3;}
    if(turn == Team::Black){color_number = -3;}
    for (int rank=0; rank<8; rank++) {
        for (int file=0; file<8; file++) {
            if (get_piece(rank, file) == color_number) {
                //loop for range of attempted move
                for (int distance=1; distance<8; distance++) {
                    //if square is empty, record possible move
                    if (is_in_bounds(rank+distance, file+distance) && get_piece(rank+distance, file+distance) == 0) {
                        moveStorage.push_back(record_move(*this, rank, file, rank+distance, file+distance));
                    }
                    //if square has opposite color piece, record capture and break loop
                    if (is_in_bounds(rank+distance, file+distance) && is_different_color(get_piece(rank, file), get_piece(rank+distance, file + distance))) {
                        moveStorage.push_back(record_move(*this, rank, file, rank+distance, file+distance));
                        break;
                    }
                    //if square has same color piece, break loop for direction.
                    if (!is_in_bounds(rank+distance, file+distance) || is_same_color(get_piece(rank, file), get_piece(rank+distance, file + distance))) {
                        break;
                    }
                }
                for (int distance=1; distance<8; distance++) {
                    if (is_in_bounds(rank+distance, file-distance) && get_piece(rank+distance, file-distance) == 0) {
                        moveStorage.push_back(record_move(*this, rank, file, rank+distance, file-distance));
                    }
                    if (is_in_bounds(rank+distance, file-distance) && is_different_color(get_piece(rank, file), get_piece(rank+distance, file-distance))) {
                        moveStorage.push_back(record_move(*this, rank, file, rank+distance, file-distance));
                        break;
                    }
                    if (!is_in_bounds(rank+distance, file-distance) || is_same_color(get_piece(rank, file), get_piece(rank+distance, file-distance))) {
                        break;
                    }
                }
                for (int distance=1; distance<8; distance++) {
                    if (is_in_bounds(rank-distance, file+distance) && get_piece(rank-distance, file+distance) == 0) {
                        moveStorage.push_back(record_move(*this, rank, file, rank-distance, file+distance));
                    }
                    if (is_in_bounds(rank-distance, file+distance) && is_different_color(get_piece(rank, file), get_piece(rank-distance, file+distance))) {
                        moveStorage.push_back(record_move(*this, rank, file, rank-distance, file+distance));
                        break;
                    }
                    if (!is_in_bounds(rank-distance, file+distance) || is_same_color(get_piece(rank, file), get_piece(rank-distance, file+distance))) {
                        break;
                    }
                }
                for (int distance=1; distance<8; distance++) {
                    if (is_in_bounds(rank-distance, file-distance) && get_piece(rank-distance, file-distance) == 0) {
                        moveStorage.push_back(record_move(*this, rank, file, rank-distance, file-distance));
                    }
                    if (is_in_bounds(rank-distance, file-distance) && is_different_color(get_piece(rank, file), get_piece(rank-distance, file-distance))) {
                        moveStorage.push_back(record_move(*this, rank, file, rank-distance, file-distance));
                        break;
                    }
                    if (!is_in_bounds(rank-distance, file-distance) || is_same_color(get_piece(rank, file), get_piece(rank-distance, file-distance))) {
                        break;
                    }
                }
            }
        }
    }
    std::cout << "list_bishop_moves found " << moveStorage.size() << " positions.\n";
    return moveStorage;
}