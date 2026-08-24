#include <array>
#include <vector>
#include <string>
#include "../functions/functions.hpp"
#include "../board_state/board_state_struct.hpp"
#include "../team.hpp"


//ex: list_Black_Rook_Moves();
std::vector<BoardStateStruct> BoardStateStruct::list_rook_moves(){
    int color_number;
    std::vector<BoardStateStruct> moveStorage = {};
    if(turn == Team::White){color_number = 4;}
    if(turn == Team::Black){color_number = 4;}
    for (int x=0; x<8; x++) {
        for (int y=0; y<8; y++) {
            if (get_piece(x, y) == color_number) {
                //loop for range of attempted move
                for (int distance=1; distance<7; distance++) {
                    //if square is empty, record possible move
                    if (get_piece(x, y+distance) == 0) {
                        moveStorage.push_back(record_move(x, y, x, y+distance));
                    }
                    //if square has white piece, record capture and break loop
                    if (is_different_color(get_piece(x, y), get_piece(x, y+distance))) {
                        moveStorage.push_back(record_move(x, y, x, y+distance));
                        break;
                    }
                    //if square has black piece, break loop for direction.
                    if (is_same_color(get_piece(x, y), get_piece(x, y+distance))) {
                        break;
                    }
                }
                for (int distance=1; distance<7; distance++) {
                    if (get_piece(x+distance, y) == 0) {
                        moveStorage.push_back(record_move(x, y, x+distance, y));
                    }
                    if (is_different_color(get_piece(x, y), get_piece(x+distance, y))) {
                        moveStorage.push_back(record_move(x, y, x+distance, y));
                        break;
                    }
                    if (is_same_color(get_piece(x, y), get_piece(x+distance, y))) {
                        break;
                    }
                }
                for (int distance=1; distance<7; distance++) {
                    if (get_piece(x, y-distance) == 0) {
                        moveStorage.push_back(record_move(x, y, x, y-distance));
                    }
                    if (is_different_color(get_piece(x, y), get_piece(x, y-distance))) {
                        moveStorage.push_back(record_move(x, y, x, y-distance));
                        break;
                    }
                    if (is_same_color(get_piece(x, y), get_piece(x, y-distance))) {
                        break;
                    }
                }
                for (int distance=1; distance<7; distance++) {
                    if (get_piece(x-distance, y) == 0) {
                        moveStorage.push_back(record_move(x, y, x-distance, y));
                    }
                    if (is_different_color(get_piece(x, y), get_piece(x-distance, y))) {
                        moveStorage.push_back(record_move(x, y, x-distance, y));
                        break;
                    }
                    if (is_same_color(get_piece(x, y), get_piece(x-distance, y))) {
                        break;
                    }
                }
            }
        }
    }
    return moveStorage;
}