#include <array>
#include <vector>
#include <string>
#include "../../chess_functions.hpp"

//ex: list_Black_Knight_Move();
void list_Black_Knight_Moves(
    std::string color_number,
    std::array<std::array<int, 8>, 8> board,
    std::vector<std::array<std::array<int, 8>, 8>> &possible_moves
) {
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (board[i][j] == -2) {
                if (board[i+1][j+2] >= 0) {
                    chessFunctions::record_possible_move (board, possible_moves, i, j, i+1, j+2);
                }
                if (board[i+1][j-2] >= 0) {
                    chessFunctions::record_possible_move (board, possible_moves, i, j, i+1, j-2);
                }
                if (board[i-1][j+2] >= 0) {
                    chessFunctions::record_possible_move (board, possible_moves, i, j, i-1, j+2);
                }
                if (board[i-1][j-2] >= 0) {
                    chessFunctions::record_possible_move (board, possible_moves, i, j, i-1, j-2);
                }
                if (board[i+2][j+1] >= 0) {
                    chessFunctions::record_possible_move (board, possible_moves, i, j, i+2, j+1);
                }
                if (board[i+2][j-1] >= 0) {
                    chessFunctions::record_possible_move (board, possible_moves, i, j, i+2, j-1);
                }
                if (board[i-2][j+1] >= 0) {
                    chessFunctions::record_possible_move (board, possible_moves, i, j, i-2, j+1);
                }
                if (board[i-2][j-1] >= 0) {
                    chessFunctions::record_possible_move (board, possible_moves, i, j, i-2, j-1);
                }
            }
        }
    }
}