#include <array>
#include <vector>
#include <string>
#include "../board_state/board_state_struct.hpp"
#include "../team.hpp"

std::vector<BoardStateStruct> BoardStateStruct::list_knight_moves() {
    int color_number;
    std::vector<BoardStateStruct> moveStorage = {};
    if(turn == White){color_number = 2;}
    if(turn == Black){color_number = -2;}
    for (int x=0; x<8; x++) {
        for (int y=0; y<8; y++) {
            if (get_piece(x, y) == color_number) {
                if (!is_same_color(get_piece(x, y), get_piece(x+1, y+2))) {
                    record_move(x, y, x+1, y+2);
                }
                if (!is_same_color(get_piece(x, y), get_piece(x+1, y-2))) {
                    record_move(x, y, x+1, y-2);
                }
                if (!is_same_color(get_piece(x, y), get_piece(x-1, y+2))) {
                    record_move(x, y, x-1, y+2);
                }
                if (!is_same_color(get_piece(x, y), get_piece(x-1, y-2))) {
                    record_move(x, y, x-1, y-2);
                }
                if (!is_same_color(get_piece(x, y), get_piece(x+2, y+1))) {
                    record_move(x, y, x+2, y+1);
                }
                if (!is_same_color(get_piece(x, y), get_piece(x+2, y-1))) {
                    record_move(x, y, x+2, y-1);
                }
                if (!is_same_color(get_piece(x, y), get_piece(x-2, y+1))) {
                    record_move(x, y, x-2, y+1);
                }
                if (!is_same_color(get_piece(x, y), get_piece(x-2, y-1))) {
                    record_move(x, y, x-2, y-1);
                }
            }
        }
    }
    return moveStorage;
}