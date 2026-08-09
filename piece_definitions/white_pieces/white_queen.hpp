#include <array>
#include <vector>
#include "../../chess_functions.hpp"

//Queen
//ex: list_White_Queen_Moves();
void list_White_Queen_Moves(
    std::array<std::array<int, 8>, 8> board,
    std::vector<std::array<std::array<int, 8>, 8>> &possible_moves
) {
    for (int x=0; x<8; x++) {
        for (int y=0; y<8; y++) {
            if (board[x][y] == 5) {
                //loop for range of attempted move
                for (int distance=1; distance<7; distance++) {
                    //rook-like moves
                    //if square is empty, record possible move
                    if (board[x][y+distance] == 0) {
                        chessFunctions::record_possible_move (board, possible_moves, x, y, x, y+distance);
                    }
                    //if square has black piece, record capture and break loop
                    if (board[x][y+distance] < 0) {
                        chessFunctions::record_possible_move (board, possible_moves, x, y, x, y+distance);
                        break;
                    }
                    //if square has white piece, break loop for direction.
                    if (board[x][y+distance] > 0) {
                        break;
                    }
                }
                for (int distance=1; distance<7; distance++) {
                    if (board[x+distance][y] == 0) {
                        chessFunctions::record_possible_move (board, possible_moves, x, y, x+distance, y);
                    }
                    if (board[x+distance][y] < 0) {
                        chessFunctions::record_possible_move (board, possible_moves, x, y, x+distance, y);
                        break;
                    }
                    if (board[x+distance][y] > 0) {
                        break;
                    }
                }
                for (int distance=1; distance<7; distance++) {
                    if (board[x][y-distance] == 0) {
                        chessFunctions::record_possible_move (board, possible_moves, x, y, x, y-distance);
                    }
                    if (board[x][y-distance] < 0) {
                        chessFunctions::record_possible_move (board, possible_moves, x, y, x, y-distance);
                        break;
                    }
                    if (board[x][y-distance] > 0) {
                        break;
                    }
                }
                for (int distance=1; distance<7; distance++) {
                    if (board[x-distance][y] == 0) {
                        chessFunctions::record_possible_move (board, possible_moves, x, y, x-distance, y);
                    }
                    if (board[x-distance][y] < 0) {
                        chessFunctions::record_possible_move (board, possible_moves, x, y, x-distance, y);
                        break;
                    }
                    if (board[x-distance][y] > 0) {
                        break;
                    }
                }
                //bishop-like moves
                for (int distance=1; distance<7; distance++) {
                    if (board[x+distance][y+distance] == 0) {
                        chessFunctions::record_possible_move (board, possible_moves, x, y, x+distance, y+distance);
                    }
                    if (board[x+distance][y+distance] < 0) {
                        chessFunctions::record_possible_move (board, possible_moves, x, y, x+distance, y+distance);
                        break;
                    }
                    if (board[x+distance][y+distance] > 0) {
                        break;
                    }
                }
                for (int distance=1; distance<7; distance++) {
                    if (board[x+distance][y-distance] == 0) {
                        chessFunctions::record_possible_move (board, possible_moves, x, y, x+distance, y-distance);
                    }
                    if (board[x+distance][y-distance] < 0) {
                        chessFunctions::record_possible_move (board, possible_moves, x, y, x+distance, y-distance);
                        break;
                    }
                    if (board[x+distance][y-distance] > 0) {
                        break;
                    }
                }
                for (int distance=1; distance<7; distance++) {
                    //if square is empty, record possible move
                    if (board[x-distance][y+distance] == 0) {
                        chessFunctions::record_possible_move (board, possible_moves, x, y, x-distance, y+distance);
                    }
                    //if square has black piece, record capture and break loop
                    if (board[x-distance][y+distance] < 0) {
                        chessFunctions::record_possible_move (board, possible_moves, x, y, x-distance, y+distance);
                        break;
                    }
                    //if square has white piece, break loop for direction.
                    if (board[x-distance][y+distance] > 0) {
                        break;
                    }
                }
                for (int distance=1; distance<7; distance++) {
                    //if square is empty, record possible move
                    if (board[x-distance][y-distance] == 0) {
                        chessFunctions::record_possible_move (board, possible_moves, x, y, x-distance, y-distance);
                    }
                    //if square has black piece, record capture and break loop
                    if (board[x-distance][y-distance] < 0) {
                        chessFunctions::record_possible_move (board, possible_moves, x, y, x-distance, y-distance);
                        break;
                    }
                    //if square has white piece, break loop for direction.
                    if (board[x-distance][y-distance] > 0) {
                        break;
                    }
                }
            }
        }
    }
}