#include <array>
#include <vector>
#include <string>
#include <iostream>
#include "../functions/functions.hpp"
#include "../board_state/board_state.hpp"
#include "../team/team.hpp"

//erank: list_Black_Queen_Moves("white", board, possible_moves);
std::vector<BoardStateStruct> BoardStateStruct::list_queen_moves(){
    int color_number;
    std::vector<BoardStateStruct> moveStorage = {};
    if(turn == Team::White){color_number = 5;}
    if(turn == Team::Black){color_number = -5;}
    for ( int rank=0; rank<8; rank++) {
        for (int file=0; file<8; file++) {
            if (get_piece(rank, file) == color_number){
                //loop for range of attempted move
                //rook-like moves
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
                    //if square has black piece, or is OOB, break loop for direction.
                    if (!is_in_bounds(rank, file+distance) || is_same_color(get_piece(rank, file), get_piece(rank, file+distance))) {
                        break;
                    }
                }
                for (int distance=1; distance<8; distance++) {
                    if (is_in_bounds(rank+distance, file) && get_piece(rank+distance, file) == 0) {
                        moveStorage.push_back(record_move(*this, rank, file, rank+distance, file));
                    }
                    if (is_in_bounds(rank+distance, file) && is_different_color(get_piece(rank, file), get_piece(rank+distance, file))) {
                        moveStorage.push_back(record_move(*this, rank, file, rank+distance, file));
                    }
                    if (!is_in_bounds(rank+distance, file) || is_same_color(get_piece(rank, file), get_piece(rank+distance, file))) {
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
                //bishop-like moves
                for (int distance=1; distance<8; distance++) {
                    //if square is empty, record possible move
                    if (is_in_bounds(rank+distance, file+distance) && get_piece(rank+distance, file+distance) == 0) {
                        moveStorage.push_back(record_move(*this, rank, file, rank+distance, file+distance));
                    }
                    //if square has opposite color piece, record capture and break loop
                    if (is_in_bounds(rank+distance, file+distance) && is_different_color(get_piece(rank, file), get_piece(rank+distance, file+distance))) {
                        moveStorage.push_back(record_move(*this, rank, file, rank+distance, file+distance));
                        break;
                    }
                    //if square has same color piece, break loop for direction.
                    if (!is_in_bounds(rank+distance, file+distance) || is_same_color(get_piece(rank, file), get_piece(rank+distance, file+distance))) {
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
    std::cout << "list_queen_moves found " << moveStorage.size() << " positions.\n";
    return moveStorage;
}