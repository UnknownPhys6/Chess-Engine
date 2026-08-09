#include <array>
#include <vector>
#include "../../chess_functions.hpp"

//lists white king moves
void list_White_King_Moves(
    std::array<std::array<int, 8>, 8> board,
    std::vector<std::array<std::array<int, 8>, 8>> &possible_moves
) {
    for ( int x=0; x<8; x++) {
        for (int y=0; y<8; y++) {
            if (chessFunctions::get_piece(board, x, y) == 6) {
                if (board[x][y+1] <= 0) {chessFunctions::record_possible_move (board, possible_moves, x, y, x, y+1);}      //W1
                if (board[x+1][y+1] <= 0) {chessFunctions::record_possible_move (board, possible_moves, x, y, x+1, y+1);}  //W2
                if (board[x+1][y] <= 0) {chessFunctions::record_possible_move (board, possible_moves, x, y, x+1, y);}       //W3
                if (board[x+1][y-1] <= 0) {chessFunctions::record_possible_move (board, possible_moves, x, y, x+1, y-1);}  //W4
                if (board[x][y-1] <= 0) {chessFunctions::record_possible_move (board, possible_moves, x, y, x, y-1);}      //W5
                if (board[x-1][y-1] <= 0) {chessFunctions::record_possible_move (board, possible_moves, x, y, x-1, y-1);}  //W6
                if (board[x-1][y] <= 0) {chessFunctions::record_possible_move (board, possible_moves, x, y, x-1, y);}      //W7
                if (board[x-1][y+1] <= 0) {chessFunctions::record_possible_move (board, possible_moves, x, y, x-1, y+1);}  //W8
            }
        }
    }
}