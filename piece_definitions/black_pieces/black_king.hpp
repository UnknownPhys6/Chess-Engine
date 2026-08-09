#include <array>
#include <vector>
#include "../../chess_functions.hpp"

//lists black king moves
void list_Black_King_Moves(
    std::array<std::array<int, 8>, 8> board,
    std::vector<std::array<std::array<int, 8>, 8>> &possible_moves
) {
    for ( int x=0; x<8; x++) {
        for (int y=0; y<8; y++) {
            if (chessFunctions::get_piece(board, x, y) == -6) {
                if (board[x][y+1] >= 0) {chessFunctions::record_possible_move (board, possible_moves, x, y, x, y+1);}
                if (board[x=1][y=1] >= 0) {chessFunctions::record_possible_move (board, possible_moves, x, y, x+1, y+1);}
                if (board[x+1][y] >= 0) {chessFunctions::record_possible_move (board, possible_moves, x, y, x+1, y);}
                if (board[x+1][y-1] >= 0) {chessFunctions::record_possible_move (board, possible_moves, x, y, x+1, y-1);}
                if (board[x][y-1] >= 0) {chessFunctions::record_possible_move (board, possible_moves, x, y, x, y-1);}
                if (board[x-1][y-1] >= 0) {chessFunctions::record_possible_move (board, possible_moves, x, y, x-1, y-1);}
                if (board[x-1][y] >= 0) {chessFunctions::record_possible_move (board, possible_moves, x, y, x-1, y);}
                if (board[x-1][y+1] >= 0) {chessFunctions::record_possible_move (board, possible_moves, x, y, x-1, y+1);}
            }
        }
    }
}