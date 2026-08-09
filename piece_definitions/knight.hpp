#include <array>
#include <vector>
#include <string>

#include "../chess_functions.hpp"

//ex: list_Knight_Move();
void list_Knight_Moves(
    std::string color,
    std::array<std::array<int, 8>, 8> board,
    std::vector<std::array<std::array<int, 8>, 8>> &possible_moves
) {
    int color_number;
    if (color == "white"){
        color_number = 2;
    }
    else if (color == "black"){
        color_number = -2;
    }
    for (int x=0; x<8; x++) {
        for (int y=0; y<8; y++) {
            if (board[x][y] == color_number) {
                if (!chessFunctions::is_same_color(board[x][y], board[x+1][y+2])) {
                    chessFunctions::record_possible_move (board, possible_moves, x, y, x+1, y+2);
                }
                if (!is_same_color(board[x][y], board[x+1][y-2])) {
                    chessFunctions::record_possible_move (board, possible_moves, x, y, x+1, y-2);
                }
                if (!is_same_color(board[x][y], board[x-1][y+2])) {
                    chessFunctions::record_possible_move (board, possible_moves, x, y, x-1, y+2);
                }
                if (!is_same_color(board[x][y], board[x-1][y-2])) {
                    chessFunctions::record_possible_move (board, possible_moves, x, y, x-1, y-2);
                }
                if (!is_same_color(board[x][y], board[x+2][y+1])) {
                    chessFunctions::record_possible_move (board, possible_moves, x, y, x+2, y+1);
                }
                if (!is_same_color(board[x][y], board[x+2][y-1])) {
                    chessFunctions::record_possible_move (board, possible_moves, x, y, x+2, y-1);
                }
                if (!is_same_color(board[x][y], board[x-2][y+1])) {
                    chessFunctions::record_possible_move (board, possible_moves, x, y, x-2, y+1);
                }
                if (!is_same_color(board[x][y], board[x-2][y-1])) {
                    chessFunctions::record_possible_move (board, possible_moves, x, y, x-2, y-1);
                }
            }
        }
    }
}