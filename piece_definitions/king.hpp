#include <array>
#include <vector>
#include <string>
#include "../chess_functions.hpp"

//lists black king moves
void list_Black_King_Moves(
    std::string color,
    std::array<std::array<int, 8>, 8> board,
    std::vector<std::array<std::array<int, 8>, 8>> &possible_moves
) {
    int color_number;
    if (color == "white"){
        color_number = 6;
    }
    else if (color == "black"){
        color_number = -6;
    }

    for ( int x=0; x<8; x++) {
        for (int y=0; y<8; y++) {
            if (chessFunctions::get_piece(board, x, y) == color_number) {
                if (!is_same_color(board[x][y], board[x][y+1])) {chessFunctions::record_possible_move (board, possible_moves, x, y, x, y+1);}
                if (!is_same_color(board[x][y], board[x=1][y=1])) {chessFunctions::record_possible_move (board, possible_moves, x, y, x+1, y+1);}
                if (!is_same_color(board[x][y], board[x+1][y])) {chessFunctions::record_possible_move (board, possible_moves, x, y, x+1, y);}
                if (!is_same_color(board[x][y], board[x+1][y-1])) {chessFunctions::record_possible_move (board, possible_moves, x, y, x+1, y-1);}
                if (!is_same_color(board[x][y], board[x][y-1])) {chessFunctions::record_possible_move (board, possible_moves, x, y, x, y-1);}
                if (!is_same_color(board[x][y], board[x-1][y-1])) {chessFunctions::record_possible_move (board, possible_moves, x, y, x-1, y-1);}
                if (!is_same_color(board[x][y], board[x-1][y])) {chessFunctions::record_possible_move (board, possible_moves, x, y, x-1, y);}
                if (!is_same_color(board[x][y], board[x-1][y+1])) {chessFunctions::record_possible_move (board, possible_moves, x, y, x-1, y+1);}
            }
        }
    }
}