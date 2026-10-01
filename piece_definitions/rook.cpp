#include <array>
#include <vector>
#include <string>
#include <iostream>
#include "../functions/functions.hpp"
#include "../board_state/board_state.hpp"
#include "../team/team.hpp"


//erank: list_Black_Rook_Moves();
std::vector<BoardStateStruct> BoardStateStruct::list_rook_moves(){
    int color_number;
    std::vector<BoardStateStruct> moveStorage = {};
    if(turn == Team::White){color_number = 4;}
    if(turn == Team::Black){color_number = -4;}
    for (int rank=0; rank<8; rank++) {
        for (int file=0; file<8; file++) {
            if (get_piece(rank, file) == color_number) {
                //loop for range of attempted move
                for (int distance=1; distance<8; distance++) {
                    //if square is empty, record possible move
                    if (is_in_bounds(rank, file+distance) && get_piece(rank, file+distance) == 0) {
                        moveStorage.push_back(record_move(*this, rank, file, rank, file+distance));
                    }
                    //if square has white piece, record capture and break loop
                    if (is_in_bounds(rank, file+distance) && is_different_color(get_piece(rank, file), get_piece(rank, file+distance))) {
                        moveStorage.push_back(record_move(*this, rank, file, rank, file+distance));
                        break;
                    }
                    //if square has black piece, break loop for direction.
                    if (!is_in_bounds(rank, file+distance)|| is_same_color(get_piece(rank, file), get_piece(rank, file+distance))) {
                        break;
                    }
                }
                for (int distance=1; distance<8; distance++) {
                    if (is_in_bounds(rank+distance, file) && get_piece(rank+distance, file) == 0) {
                        moveStorage.push_back(record_move(*this, rank, file, rank+distance, file));
                    }
                    if (is_in_bounds(rank+distance, file) && is_different_color(get_piece(rank, file), get_piece(rank+distance, file))) {
                        moveStorage.push_back(record_move(*this, rank, file, rank+distance, file));
                        break;
                    }
                    if (!is_in_bounds(rank+distance, file) || is_same_color(get_piece(rank, file), get_piece(rank+distance, file))){
                        break;
                    }
                }
                for (int distance=1; distance<8; distance++) {
                    if (is_in_bounds(rank, file-distance) && get_piece(rank, file-distance) == 0) {
                        moveStorage.push_back(record_move(*this, rank, file, rank, file-distance));
                    }
                    if (is_in_bounds(rank, file-distance) && is_different_color(get_piece(rank, file), get_piece(rank, file-distance))) {
                        moveStorage.push_back(record_move(*this, rank, file, rank, file-distance));
                        break;
                    }
                    if (!is_in_bounds(rank, file-distance) || is_same_color(get_piece(rank, file), get_piece(rank, file-distance))) {
                        break;
                    }
                }
                for (int distance=1; distance<8; distance++) {
                    if (is_in_bounds(rank-distance, file) && get_piece(rank-distance, file) == 0) {
                        moveStorage.push_back(record_move(*this, rank, file, rank-distance, file));
                    }
                    if (is_in_bounds(rank-distance, file) && is_different_color(get_piece(rank, file), get_piece(rank-distance, file))) {
                        moveStorage.push_back(record_move(*this, rank, file, rank-distance, file));
                        break;
                    }
                    if (!is_in_bounds(rank-distance, file) || is_same_color(get_piece(rank, file), get_piece(rank-distance, file))) {
                        break;
                    }
                }
            }
        }
    }
    std::cout << "list_rook_moves found " << moveStorage.size() << " positions.\n";
    return moveStorage;
}

//now for finding attacked squares logic.
//yeah, this means alot of reused code, but I didnt want to modify the original with a flag system
void BoardStateStruct::find_squares_attacked_by_rook(Team team){
    int attackDelta = 1;
    if(team == Black){attackDelta = -1;}
    int color_number;
    std::vector<BoardStateStruct> moveStorage = {};
    if(team == White){color_number = 4;}
    if(team == Black){color_number = -4;}
    for (int rank=0; rank<8; rank++) {
        for (int file=0; file<8; file++) {
            if (get_piece(rank, file) == color_number) {
                //loop for range of attempted move
                for (int distance=1; distance<8; distance++) {
                    //if square is empty, record possible move
                    if (is_in_bounds(rank, file+distance) && get_piece(rank, file+distance) == 0) {mark_attacked_square(team, rank, file+distance);}
                    //if square has white piece, record capture and break loop
                    if (is_in_bounds(rank, file+distance) && get_piece(rank, file+distance) != 0) {mark_attacked_square(team, rank, file+distance); break;}
                }
                for (int distance=1; distance<8; distance++) {
                    if (is_in_bounds(rank+distance, file) && get_piece(rank+distance, file) == 0) {mark_attacked_square(team, rank+distance, file);}
                    if (is_in_bounds(rank+distance, file) && get_piece(rank+distance, file) != 0) {mark_attacked_square(team, rank+distance, file); break;}
                }
                for (int distance=1; distance<8; distance++) {
                    if (is_in_bounds(rank, file-distance) && get_piece(rank, file-distance) == 0) {mark_attacked_square(team, rank, file-distance);}
                    if (is_in_bounds(rank, file-distance) && get_piece(rank, file-distance) != 0) {mark_attacked_square(team, rank, file-distance); break;}
                }
                for (int distance=1; distance<8; distance++) {
                    if (is_in_bounds(rank-distance, file) && get_piece(rank-distance, file) == 0) {mark_attacked_square(team, rank-distance, file);}
                    if (is_in_bounds(rank-distance, file) && get_piece(rank-distance, file) != 0) {mark_attacked_square(team, rank-distance, file); break;}
                }
            }
        }
    }
}