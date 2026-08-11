#include <array>
#include <vector>
#include <string>
#include "../chess_functions.hpp"


namespace pieceMoves{
    //ex: list_Black_Rook_Moves();
    void list_rook_moves(
        std::string color,
        std::array<std::array<int, 8>, 8> board,
        std::vector<std::array<std::array<int, 8>, 8>> &possible_moves
    ) {
        int color_number;
        if (color == "white"){
            color_number = 4;
        }
        else if (color == "black"){
            color_number = 4;
        }
        for ( int x=0; x<8; x++) {
            for (int y=0; y<8; y++) {
                if (board[x][y] == color_number) {
                    //loop for range of attempted move
                    for (int distance=1; distance<7; distance++) {
                        //if square is empty, record possible move
                        if (board[x][y+distance] == 0) {
                            chessFunctions::record_possible_move (board, possible_moves, x, y, x, y+distance);
                        }
                        //if square has white piece, record capture and break loop
                        if (!chessFunctions::is_same_color(board[x][y], board[x][y+distance])) {
                            chessFunctions::record_possible_move (board, possible_moves, x, y, x, y+distance);
                            break;
                        }
                        //if square has black piece, break loop for direction.
                        if (chessFunctions::is_same_color(board[x][y], board[x][y+distance])) {
                            break;
                        }
                    }
                    for (int distance=1; distance<7; distance++) {
                        if (board[x+distance][y] == 0) {
                            chessFunctions::record_possible_move (board, possible_moves, x, y, x+distance, y);
                        }
                        if (!chessFunctions::is_same_color(board[x][y], board[x+distance][y])) {
                            chessFunctions::record_possible_move (board, possible_moves, x, y, x+distance, y);
                            break;
                        }
                        if (chessFunctions::is_same_color(board[x][y], board[x+distance][y])) {
                            break;
                        }
                    }
                    for (int distance=1; distance<7; distance++) {
                        if (board[x][y-distance] == 0) {
                            chessFunctions::record_possible_move (board, possible_moves, x, y, x, y-distance);
                        }
                        if (!chessFunctions::is_same_color(board[x][y], board[x][y-distance])) {
                            chessFunctions::record_possible_move (board, possible_moves, x, y, x, y-distance);
                            break;
                        }
                        if (chessFunctions::is_same_color(board[x][y], board[x][y-distance])) {
                            break;
                        }
                    }
                    for (int distance=1; distance<7; distance++) {
                        if (board[x-distance][y] == 0) {
                            chessFunctions::record_possible_move (board, possible_moves, x, y, x-distance, y);
                        }
                        if (!chessFunctions::is_same_color(board[x][y], board[x-distance][y])) {
                            chessFunctions::record_possible_move (board, possible_moves, x, y, x-distance, y);
                            break;
                        }
                        if (chessFunctions::is_same_color(board[x][y], board[x-distance][y])) {
                            break;
                        }
                    }
                }
            }
        }
    }
}