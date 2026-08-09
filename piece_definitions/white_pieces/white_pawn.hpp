#include <array>
#include <vector>
#include "../../chess_functions.hpp"


//Pawn WIP
//ex: list_White_Pawn_Moves();
void list_White_Pawn_Moves(
    std::array<std::array<int, 8>, 8> board,
    std::array<std::array<int, 8>, 8> enPassantBoard,
    std::vector<std::array<std::array<int, 8>, 8>> &possible_moves
) {
    for(int x=0; x<8; x++) {
        for(int y=0; y<8; y++) {
            if(board[x][y] == 1) {
                //move 1 space
                if (board[x+1][y] == 0) {
                    chessFunctions::record_possible_move (board, possible_moves, x, y, x+1, y);
                }
                //move 2 spaces
                if (x==1 && board[x+1][y] == 0 && board[x+2][y] == 0) {
                    chessFunctions::record_possible_move (board, possible_moves, x, y, x+2, y);
                    enPassantBoard[x+1][y] = 1;
                }
                //capture diagonally
                if (board[x+1][y+1] < 0) {
                    chessFunctions::record_possible_move (board, possible_moves, x, y, x+1, y+1);
                }
                //capture diagonally
                if (board[x+1][y-1] < 0) {
                    chessFunctions::record_possible_move (board, possible_moves, x, y, x+1, y-1);
                }
                //en-passant
                if (board[x][y+1] == -1 && enPassantBoard[x+1][y+1] == -1) {
                    board[x+1][y+1] = 1;
                    board[x][y] = 0;
                    board[x][y+1] = 0;
                    possible_moves.push_back(board);
                    board[x][y] = 1;
                    board[x][y+1] = -1;
                    board[x+1][y+1] = 0;
                }
                if (board[x][y-1] == -1 && enPassantBoard[x+1][y-1] == -1) {
                    board[x+1][y-1] = 1;
                    board[x][y] = 0;
                    board[x][y-1] = 0;
                    possible_moves.push_back(board);
                    board[x][y] = 1;
                    board[x][y-1] = -1;
                    board[x+1][y-1] = 0;
                }
            }
        }
    }
}