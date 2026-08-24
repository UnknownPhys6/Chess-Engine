#include <array>
#include <vector>
#include <string>
#include "../functions/functions.hpp"
#include "../board_state/board_state_struct.hpp"
#include "../team.hpp"


//ex: list_Black_Bishop_Moves();
std::vector<BoardStateStruct> BoardStateStruct::list_bishop_moves() {
    int color_number;
    std::vector<BoardStateStruct> moveStorage = {};
    if(turn == Team::White){color_number = 3;}
    if(turn == Team::Black){color_number = -3;}
    for (int x=0; x<8; x++) {
        for (int y=0; y<8; y++) {
            if (get_piece(x, y) == color_number) {
                //loop for range of attempted move
                for (int distance=1; distance<7; distance++) {
                    //if square is empty, record possible move
                    if (get_piece(x + distance, y + distance) == 0) {
                        moveStorage.push_back(record_move(x, y, x+distance, y+distance));
                    }
                    //if square has opposite color piece, record capture and break loop
                    if (is_different_color(get_piece(x, y), get_piece(x + distance, y + distance))) {
                        moveStorage.push_back(record_move(x, y, x+distance, y+distance));
                        break;
                    }
                    //if square has same color piece, break loop for direction.
                    if (is_same_color(get_piece(x, y), get_piece(x + distance, y + distance))) {
                        break;
                    }
                }
                for (int distance=1; distance<7; distance++) {
                    if (get_piece(x+distance, y-distance) == 0) {
                        moveStorage.push_back(record_move(x, y, x+distance, y-distance));
                    }
                    if (is_different_color(get_piece(x, y), get_piece(x+distance, y-distance))) {
                        moveStorage.push_back(record_move(x, y, x+distance, y-distance));
                        break;
                    }
                    if (is_same_color(get_piece(x, y), get_piece(x+distance, y-distance))) {
                        break;
                    }
                }
                for (int distance=1; distance<7; distance++) {
                    if (get_piece(x-distance, y+distance) == 0) {
                        moveStorage.push_back(record_move(x, y, x-distance, y+distance));
                    }
                    if (is_different_color(get_piece(x, y), get_piece(x-distance, y+distance))) {
                        moveStorage.push_back(record_move(x, y, x-distance, y+distance));
                        break;
                    }
                    if (is_same_color(get_piece(x, y), get_piece(x-distance, y+distance))) {
                        break;
                    }
                }
                for (int distance=1; distance<7; distance++) {
                    if (get_piece(x-distance, y-distance) == 0) {
                        moveStorage.push_back(record_move(x, y, x-distance, y-distance));
                    }
                    if (is_different_color(get_piece(x, y), get_piece(x-distance, y-distance))) {
                        moveStorage.push_back(record_move(x, y, x-distance, y-distance));
                        break;
                    }
                    if (is_same_color(get_piece(x, y), get_piece(x-distance, y-distance))) {
                        break;
                    }
                }
            }
        }
    }
    return moveStorage;
}