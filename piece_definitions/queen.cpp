#include <array>
#include <vector>
#include <string>
#include <iostream>
#include "../functions/functions.hpp"
#include "../board_state/board_state.hpp"
#include "../team.hpp"

//ex: list_Black_Queen_Moves("white", board, possible_moves);
std::vector<BoardStateStruct> BoardStateStruct::list_queen_moves(){
    int color_number;
    std::vector<BoardStateStruct> moveStorage = {};
    if(turn == Team::White){color_number = 5;}
    if(turn == Team::Black){color_number = -5;}
    for ( int x=0; x<8; x++) {
        for (int y=0; y<8; y++) {
            if (get_piece(x, y) == color_number){
                //loop for range of attempted move
                //rook-like moves
                for (int distance=1; distance<8; distance++) {
                    //if square is empty, record possible move
                    if (is_in_bounds(x, y+distance) && get_piece(x, y+distance) == 0) {
                        moveStorage.push_back(record_move(*this, x, y, x, y+distance));
                    }
                    //if square has white piece, record capture and break loop
                    if (is_in_bounds(x, y+distance) && is_different_color(get_piece(x, y), get_piece(x, y+distance))) {
                        moveStorage.push_back(record_move(*this, x, y, x, y+distance));
                        break;
                    }
                    //if square has black piece, or is OOB, break loop for direction.
                    if (!is_in_bounds(x, y+distance) || is_same_color(get_piece(x, y), get_piece(x, y+distance))) {
                        break;
                    }
                }
                for (int distance=1; distance<8; distance++) {
                    if (is_in_bounds(x+distance, y) && get_piece(x+distance, y) == 0) {
                        moveStorage.push_back(record_move(*this, x, y, x+distance, y));
                    }
                    if (is_in_bounds(x+distance, y) && is_different_color(get_piece(x, y), get_piece(x+distance, y))) {
                        moveStorage.push_back(record_move(*this, x, y, x+distance, y));
                    }
                    if (!is_in_bounds(x+distance, y) || is_same_color(get_piece(x, y), get_piece(x+distance, y))) {
                        break;
                    }
                }
                for (int distance=1; distance<8; distance++) {
                    if (is_in_bounds(x, y-distance) && get_piece(x, y-distance) == 0) {
                        moveStorage.push_back(record_move(*this, x, y, x, y-distance));
                    }
                    if (is_in_bounds(x, y-distance) && is_different_color(get_piece(x, y), get_piece(x, y-distance))) {
                        moveStorage.push_back(record_move(*this, x, y, x, y-distance));
                        break;
                    }
                    if (!is_in_bounds(x, y-distance) || is_same_color(get_piece(x, y), get_piece(x, y-distance))) {
                        break;
                    }
                }
                for (int distance=1; distance<8; distance++) {
                    if (is_in_bounds(x-distance, y) && get_piece(x-distance, y) == 0) {
                        moveStorage.push_back(record_move(*this, x, y, x-distance, y));
                    }
                    if (is_in_bounds(x-distance, y) && is_different_color(get_piece(x, y), get_piece(x-distance, y))) {
                        moveStorage.push_back(record_move(*this, x, y, x-distance, y));
                        break;
                    }
                    if (!is_in_bounds(x-distance, y) || is_same_color(get_piece(x, y), get_piece(x-distance, y))) {
                        break;
                    }
                }
                //bishop-like moves
                for (int distance=1; distance<8; distance++) {
                    //if square is empty, record possible move
                    if (is_in_bounds(x+distance, y+distance) && get_piece(x+distance, y+distance) == 0) {
                        moveStorage.push_back(record_move(*this, x, y, x+distance, y+distance));
                    }
                    //if square has opposite color piece, record capture and break loop
                    if (is_in_bounds(x+distance, y+distance) && is_different_color(get_piece(x, y), get_piece(x+distance, y+distance))) {
                        moveStorage.push_back(record_move(*this, x, y, x+distance, y+distance));
                        break;
                    }
                    //if square has same color piece, break loop for direction.
                    if (!is_in_bounds(x+distance, y+distance) || is_same_color(get_piece(x, y), get_piece(x+distance, y+distance))) {
                        break;
                    }
                }
                for (int distance=1; distance<8; distance++) {
                    if (is_in_bounds(x+distance, y-distance) && get_piece(x+distance, y-distance) == 0) {
                        moveStorage.push_back(record_move(*this, x, y, x+distance, y-distance));
                    }
                    if (is_in_bounds(x+distance, y-distance) && is_different_color(get_piece(x, y), get_piece(x+distance, y-distance))) {
                        moveStorage.push_back(record_move(*this, x, y, x+distance, y-distance));
                        break;
                    }
                    if (!is_in_bounds(x+distance, y-distance) || is_same_color(get_piece(x, y), get_piece(x+distance, y-distance))) {
                        break;
                    }
                }
                for (int distance=1; distance<8; distance++) {
                    if (is_in_bounds(x-distance, y+distance) && get_piece(x-distance, y+distance) == 0) {
                        moveStorage.push_back(record_move(*this, x, y, x-distance, y+distance));
                    }
                    if (is_in_bounds(x-distance, y+distance) && is_different_color(get_piece(x, y), get_piece(x-distance, y+distance))) {
                        moveStorage.push_back(record_move(*this, x, y, x-distance, y+distance));
                        break;
                    }
                    if (!is_in_bounds(x-distance, y+distance) || is_same_color(get_piece(x, y), get_piece(x-distance, y+distance))) {
                        break;
                    }
                }
                for (int distance=1; distance<8; distance++) {
                    if (is_in_bounds(x-distance, y-distance) && get_piece(x-distance, y-distance) == 0) {
                        moveStorage.push_back(record_move(*this, x, y, x-distance, y-distance));
                    }
                    if (is_in_bounds(x-distance, y-distance) && is_different_color(get_piece(x, y), get_piece(x-distance, y-distance))) {
                        moveStorage.push_back(record_move(*this, x, y, x-distance, y-distance));
                        break;
                    }
                    if (!is_in_bounds(x-distance, y-distance) || is_same_color(get_piece(x, y), get_piece(x-distance, y-distance))) {
                        break;
                    }
                }
            }
        }
    }
    std::cout << "list_queen_moves found " << moveStorage.size() << " positions.\n";
    return moveStorage;
}