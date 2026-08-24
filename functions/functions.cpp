#include <iostream>
#include <vector>
#include "../board_state/board_state_struct.hpp"
#include "../team.hpp"

bool is_in_bounds(const int x, const int y) {
    if ((x >= 0) && (x <= 7) && (y >= 0) && (y <= 7)) {
        return true;
    }
    std::cout << "Referenced square fell out of bounds, coordinates (" << x << ", " << y << "). Returning \"False\"..." << std::endl;
    return false;
}

void print_positions(std::vector<BoardStateStruct> positions){
    for (BoardStateStruct& item : positions){
        item.print_chessboard();
    }
}

std::vector<BoardStateStruct> add_vBSS(std::vector<BoardStateStruct> vector1, std::vector<BoardStateStruct> vector2){
    for(BoardStateStruct& item : vector1){
        vector2.push_back(item);
    }
    return vector2;
}

bool king_is_present(BoardStateStruct boardState, Team color){
    int num=1;
    if(color == White){num=1;}
    if(color == Black){num=-1;}
    for (int x=0; x<8; x++){
        for (int y=0; y<8; y++){
            int piece = boardState.get_piece(x, y);
            if ((get_color(piece) == color) && (piece = 6*num )){return true;}
        }
    }
    return false;
}
