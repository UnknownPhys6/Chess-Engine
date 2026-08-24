#include <array>
#include <vector>
#include <string>
#include "../functions/functions.hpp"
#include "../board_state/board_state_struct.hpp"
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
                if (is_different_color(get_piece(x, y), get_piece(x,y+1))) {moveStorage.push_back(record_move(x, y, x, y+1));}
                if (is_different_color(get_piece(x, y), get_piece(x+1,y+1))) {moveStorage.push_back(record_move(x, y, x+1, y+1));}
                if (is_different_color(get_piece(x, y), get_piece(x+1,y))) {moveStorage.push_back(record_move(x, y, x+1, y));}
                if (is_different_color(get_piece(x, y), get_piece(x+1,y-1))) {moveStorage.push_back(record_move(x, y, x+1, y-1));}
                if (is_different_color(get_piece(x, y), get_piece(x,y-1))) {moveStorage.push_back(record_move(x, y, x, y-1));}
                if (is_different_color(get_piece(x, y), get_piece(x-1,y-1))) {moveStorage.push_back(record_move(x, y, x-1, y-1));}
                if (is_different_color(get_piece(x, y), get_piece(x-1,y))) {moveStorage.push_back(record_move(x, y, x-1, y));}
                if (is_different_color(get_piece(x, y), get_piece(x-1,y+1))) {moveStorage.push_back(record_move(x, y, x-1, y+1));}
            }
        }
    }
    return moveStorage;
}