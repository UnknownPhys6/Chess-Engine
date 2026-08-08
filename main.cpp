#include <array>
#include <iostream>
#include <vector>

#include "board_presets.hpp"
#include "chess_functions.hpp"

/*TODO
 *stuff idk
 *
 *
 */


class Chess {
    public:
        //set up an array for the board and en-passant board, and vectors to store board states
        std::array<std::array<int, 8> , 8> board;
        std::array<std::array<int, 8> , 8> enPassantBoard;
        std::vector<std::array<std::array<int, 8> , 8>> possible_moves;
        std::vector<std::array<std::array<int, 8> , 8>> legal_moves;



        //Pawn WIP
        //ex: list_White_Pawn_Moves();
        void list_White_Pawn_Moves() {
            for(int x=0; x<8; x++) {
                for(int y=0; y<8; y++) {
                    if(board[x][y] == 1) {
                        //move 1 space
                        if (board[x+1][y] == 0) {
                            chessFunctions::record_temp_move (board, possible_moves, x, y, x+1, y);
                        }
                        //move 2 spaces
                        if (x==1 && board[x+1][y] == 0 && board[x+2][y] == 0) {
                            chessFunctions::record_temp_move (board, possible_moves, x, y, x+2, y);
                            enPassantBoard[x+1][y] = 1;
                        }
                        //capture diagonally
                        if (board[x+1][y+1] < 0) {
                            chessFunctions::record_temp_move (board, possible_moves, x, y, x+1, y+1);
                        }
                        //capture diagonally
                        if (board[x+1][y-1] < 0) {
                            chessFunctions::record_temp_move (board, possible_moves, x, y, x+1, y-1);
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
        //ex: list_Black_Pawn_Moves();
        void list_Black_Pawn_Moves() {
            for(int x=0; x<8; x++) {
                for(int y=0; y<8; y++) {
                    if(board[x][y] == -1) {
                        //move 1 space
                        if (board[x-1][y] == 0) {
                            chessFunctions::record_temp_move (board, possible_moves, x, y, x-1, y);
                        }
                        //move 2 spaces
                        if (x == 6 && board[x-1][y] == 0 && board[x-2][y] == 0) {
                            chessFunctions::record_temp_move (board, possible_moves, x, y, x+2, y);
                            enPassantBoard[x-1][y] = -1;
                        }
                        //capture diagonally
                        if (board[x-1][y+1] < 0) {
                            chessFunctions::record_temp_move (board, possible_moves, x, y, x-1, y+1);
                        }
                        //capture diagonally
                        if (board[x-1][y-1] < 0) {
                            chessFunctions::record_temp_move (board, possible_moves, x, y, x-1, y-1);
                        }
                        //en-passant
                        if (board[x][y+1] == 1 && enPassantBoard[x-1][y+1] == 1) {
                            board[x-1][y+1] = -1;
                            board[x][y] = 0;
                            board[x][y+1] = 0;
                            possible_moves.push_back(board);
                            board[x][y] = -1;
                            board[x][y+1] = 1;
                            board[x-1][y+1] = 0;
                        }
                        if (board[x][y-1] == 1 && enPassantBoard[x-1][y-1] == 1) {
                            board[x-1][y-1] = -1;
                            board[x][y] = 0;
                            board[x][y-1] = 0;
                            possible_moves.push_back(board);
                            board[x][y] = -1;
                            board[x][y-1] = 1;
                            board[x-1][y-1] = 0;
                        }
                    }
                }
            }
        }

        //White Knight
        //ex: list_White_Knight_Move();
        void list_White_Knight_Moves() {
             for (int i=0; i<8; i++) {
                 for (int j=0; j<8; j++) {
                     if (board[i][j] == 2) {
                         if (board[i+1][j+2] <= 0) {
                            chessFunctions::record_temp_move (board, possible_moves, i, j, i+1, j+2);
                         }
                         if (board[i+1][j-2] <= 0) {
                            chessFunctions::record_temp_move (board, possible_moves, i, j, i+1, j-2);
                         }
                         if (board[i-1][j+2] <= 0) {
                            chessFunctions::record_temp_move (board, possible_moves, i, j, i-1, j+2);
                         }
                         if (board[i-1][j-2] <= 0) {
                            chessFunctions::record_temp_move (board, possible_moves, i, j, i-1, j-2);
                         }
                         if (board[i+2][j+1] <= 0) {
                            chessFunctions::record_temp_move (board, possible_moves, i, j, i+2, j+1);
                         }
                         if (board[i+2][j-1] <= 0) {
                            chessFunctions::record_temp_move (board, possible_moves, i, j, i+2, j-1);
                         }
                         if (board[i-2][j+1] <= 0) {
                            chessFunctions::record_temp_move (board, possible_moves, i, j, i-2, j+1);
                         }
                         if (board[i-2][j-1] <= 0) {
                            chessFunctions::record_temp_move (board, possible_moves, i, j, i-2, j-1);
                         }
                    }
                }
            }
        }
        //ex: list_Black_Knight_Move();
        void list_Black_Knight_Moves() {
            for (int i=0; i<8; i++) {
                for (int j=0; j<8; j++) {
                    if (board[i][j] == -2) {
                        if (board[i+1][j+2] >= 0) {
                            chessFunctions::record_temp_move (board, possible_moves, i, j, i+1, j+2);
                        }
                        if (board[i+1][j-2] >= 0) {
                            chessFunctions::record_temp_move (board, possible_moves, i, j, i+1, j-2);
                        }
                        if (board[i-1][j+2] >= 0) {
                            chessFunctions::record_temp_move (board, possible_moves, i, j, i-1, j+2);
                        }
                        if (board[i-1][j-2] >= 0) {
                            chessFunctions::record_temp_move (board, possible_moves, i, j, i-1, j-2);
                        }
                        if (board[i+2][j+1] >= 0) {
                            chessFunctions::record_temp_move (board, possible_moves, i, j, i+2, j+1);
                        }
                        if (board[i+2][j-1] >= 0) {
                            chessFunctions::record_temp_move (board, possible_moves, i, j, i+2, j-1);
                        }
                        if (board[i-2][j+1] >= 0) {
                            chessFunctions::record_temp_move (board, possible_moves, i, j, i-2, j+1);
                        }
                        if (board[i-2][j-1] >= 0) {
                            chessFunctions::record_temp_move (board, possible_moves, i, j, i-2, j-1);
                        }
                    }
                }
            }
        }

        //White Bishop
        //lists all the bishop moves
        //ex: list_White_Bishop_Moves();
        void list_White_Bishop_Moves() {
            for ( int x=0; x<8; x++) {
                for (int y=0; y<8; y++) {
                    if (board[x][y] == 3) {
                        //loop for range of attempted move
                        for (int distance=1; distance<7; distance++) {
                            //if square is empty, record possible move
                            if (board[x+distance][y+distance] == 0) {
                                chessFunctions::record_temp_move (board, possible_moves, x, y, x+distance, y+distance);
                            }
                            //if square has black piece, record capture and break loop
                            if (board[x+distance][y+distance] < 0) {
                                chessFunctions::record_temp_move (board, possible_moves, x, y, x+distance, y+distance);
                                break;
                            }
                            //if square has white piece, break loop for direction.
                            if (board[x+distance][y+distance] > 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            //if square is empty, record possible move
                            if (board[x+distance][y-distance] == 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x+distance, y-distance);
                            }
                            //if square has black piece, record capture and break loop
                            if (board[x+distance][y-distance] < 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x+distance, y-distance);
                                break;
                            }
                            //if square has white piece, break loop for direction.
                            if (board[x+distance][y-distance] > 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            //if square is empty, record possible move
                            if (board[x-distance][y+distance] == 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x-distance, y+distance);
                            }
                            //if square has black piece, record capture and break loop
                            if (board[x-distance][y+distance] < 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x-distance, y+distance);
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
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x-distance, y-distance);
                            }
                            //if square has black piece, record capture and break loop
                            if (board[x-distance][y-distance] < 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x-distance, y-distance);
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
        //ex: list_White_Bishop_Moves();
        void list_Black_Bishop_Moves() {
            for ( int x=0; x<8; x++) {
                for (int y=0; y<8; y++) {
                    if (board[x][y] == -3) {
                        //loop for range of attempted move
                        for (int distance=1; distance<7; distance++) {
                            //if square is empty, record possible move
                            if (board[x+distance][y+distance] == 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x+distance, y+distance);
                            }
                            //if square has black piece, record capture and break loop
                            if (board[x+distance][y+distance] > 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x+distance, y+distance);
                                break;
                            }
                            //if square has white piece, break loop for direction.
                            if (board[x+distance][y+distance] < 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x+distance][y-distance] == 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x+distance, y-distance);
                            }
                            if (board[x+distance][y-distance] > 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x+distance, y-distance);
                                break;
                            }
                            if (board[x+distance][y-distance] < 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x-distance][y+distance] == 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x-distance, y+distance);
                            }
                            if (board[x-distance][y+distance] > 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x-distance, y+distance);
                                break;
                            }
                            if (board[x-distance][y+distance] < 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x-distance][y-distance] == 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x-distance, y-distance);
                            }
                            if (board[x-distance][y-distance] > 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x-distance, y-distance);
                                break;
                            }
                            if (board[x-distance][y-distance] < 0) {
                                break;
                            }
                        }
                    }
                }
            }
        }

        //White Rook
        //Lists possible rook moves
        //ex: list_White_Rook_Moves();
        void list_White_Rook_Moves() {
            for ( int x=0; x<8; x++) {
                for (int y=0; y<8; y++) {
                    if (board[x][y] == 4) {
                        //loop for range of attempted move
                        for (int distance=1; distance<7; distance++) {
                            //if square is empty, record possible move
                            if (board[x][y+distance] == 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x, y+distance);
                            }
                            //if square has black piece, record capture and break loop
                            if (board[x][y+distance] < 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x, y+distance);
                                break;
                            }
                            //if square has white piece, break loop for direction.
                            if (board[x][y+distance] > 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            //if square is empty, record possible move
                            if (board[x+distance][y] == 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x+distance, y);
                            }
                            //if square has black piece, record capture and break loop
                            if (board[x+distance][y] < 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x+distance, y);
                                break;
                            }
                            //if square has white piece, break loop for direction.
                            if (board[x+distance][y] > 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            //if square is empty, record possible move
                            if (board[x][y-distance] == 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x, y-distance);
                            }
                            //if square has black piece, record capture and break loop
                            if (board[x][y-distance] < 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x, y-distance);
                                break;
                            }
                            //if square has white piece, break loop for direction.
                            if (board[x][y-distance] > 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            //if square is empty, record possible move
                            if (board[x-distance][y] == 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x-distance, y);
                            }
                            //if square has black piece, record capture and break loop
                            if (board[x-distance][y] < 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x-distance, y);
                                break;
                            }
                            //if square has white piece, break loop for direction.
                            if (board[x-distance][y] > 0) {
                                break;
                            }
                        }
                    }
                }
            }
        }
        //ex: list_Black_Rook_Moves();
        void list_Black_Rook_Moves() {
            for ( int x=0; x<8; x++) {
                for (int y=0; y<8; y++) {
                    if (board[x][y] == -4) {
                        //loop for range of attempted move
                        for (int distance=1; distance<7; distance++) {
                            //if square is empty, record possible move
                            if (board[x][y+distance] == 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x, y+distance);
                            }
                            //if square has white piece, record capture and break loop
                            if (board[x][y+distance] > 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x, y+distance);
                                break;
                            }
                            //if square has black piece, break loop for direction.
                            if (board[x][y+distance] < 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x+distance][y] == 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x+distance, y);
                            }
                            if (board[x+distance][y] > 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x+distance, y);
                                break;
                            }
                            if (board[x+distance][y] < 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x][y-distance] == 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x, y-distance);
                            }
                            if (board[x][y-distance] > 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x, y-distance);
                                break;
                            }
                            if (board[x][y-distance] < 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x-distance][y] == 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x-distance, y);
                            }
                            if (board[x-distance][y] > 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x-distance, y);
                                break;
                            }
                            if (board[x-distance][y] < 0) {
                                break;
                            }
                        }
                    }
                }
            }
        }

        //Queen
        //ex: list_White_Queen_Moves();
        void list_White_Queen_Moves() {
            for (int x=0; x<8; x++) {
                for (int y=0; y<8; y++) {
                    if (board[x][y] == 5) {
                        //loop for range of attempted move
                        for (int distance=1; distance<7; distance++) {
                            //rook-like moves
                            //if square is empty, record possible move
                            if (board[x][y+distance] == 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x, y+distance);
                            }
                            //if square has black piece, record capture and break loop
                            if (board[x][y+distance] < 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x, y+distance);
                                break;
                            }
                            //if square has white piece, break loop for direction.
                            if (board[x][y+distance] > 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x+distance][y] == 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x+distance, y);
                            }
                            if (board[x+distance][y] < 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x+distance, y);
                                break;
                            }
                            if (board[x+distance][y] > 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x][y-distance] == 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x, y-distance);
                            }
                            if (board[x][y-distance] < 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x, y-distance);
                                break;
                            }
                            if (board[x][y-distance] > 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x-distance][y] == 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x-distance, y);
                            }
                            if (board[x-distance][y] < 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x-distance, y);
                                break;
                            }
                            if (board[x-distance][y] > 0) {
                                break;
                            }
                        }
                        //bishop-like moves
                        for (int distance=1; distance<7; distance++) {
                            if (board[x+distance][y+distance] == 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x+distance, y+distance);
                            }
                            if (board[x+distance][y+distance] < 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x+distance, y+distance);
                                break;
                            }
                            if (board[x+distance][y+distance] > 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x+distance][y-distance] == 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x+distance, y-distance);
                            }
                            if (board[x+distance][y-distance] < 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x+distance, y-distance);
                                break;
                            }
                            if (board[x+distance][y-distance] > 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            //if square is empty, record possible move
                            if (board[x-distance][y+distance] == 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x-distance, y+distance);
                            }
                            //if square has black piece, record capture and break loop
                            if (board[x-distance][y+distance] < 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x-distance, y+distance);
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
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x-distance, y-distance);
                            }
                            //if square has black piece, record capture and break loop
                            if (board[x-distance][y-distance] < 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x-distance, y-distance);
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
        //ex: list_Black_Queen_Moves();
        void list_Black_Queen_Moves() {
            for (int x=0; x<8; x++) {
                for (int y=0; y<8; y++) {
                    if (board[x][y] == -5) {
                        //loop for range of attempted move
                        for (int distance=1; distance<7; distance++) {
                            //rook-like moves
                            ////if square is empty, record possible move
                            if (board[x][y+distance] == 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x, y+distance);
                            }
                            //if square has white piece, record capture and break loop
                            if (board[x][y+distance] > 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x, y+distance);
                                break;
                            }
                            //if square has black piece, break loop for direction.
                            if (board[x][y+distance] < 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x+distance][y] == 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x+distance, y);
                            }
                            if (board[x+distance][y] > 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x+distance, y);
                                break;
                            }
                            if (board[x+distance][y] < 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x][y-distance] == 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x, y-distance);
                            }
                            if (board[x][y-distance] > 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x, y-distance);
                                break;
                            }
                            if (board[x][y-distance] < 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x-distance][y] == 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x-distance, y);
                            }
                            if (board[x-distance][y] > 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x-distance, y);
                                break;
                            }
                            if (board[x-distance][y] < 0) {
                                break;
                            }
                        }
                        //bishop-like moves
                        for (int distance=1; distance<7; distance++) {
                            if (board[x+distance][y+distance] == 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x+distance, y+distance);
                            }
                            if (board[x+distance][y+distance] > 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x+distance, y+distance);
                                break;
                            }
                            if (board[x+distance][y+distance] < 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x+distance][y-distance] == 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x+distance, y-distance);
                            }
                            if (board[x+distance][y-distance] > 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x+distance, y-distance);
                                break;
                            }
                            if (board[x+distance][y-distance] < 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x-distance][y+distance] == 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x-distance, y+distance);
                            }
                            if (board[x-distance][y+distance] > 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x-distance, y+distance);
                                break;
                            }
                            if (board[x-distance][y+distance] < 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x-distance][y-distance] == 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x-distance, y-distance);
                            }
                            if (board[x-distance][y-distance] > 0) {
                               chessFunctions::record_temp_move (board, possible_moves, x, y, x-distance, y-distance);
                                break;
                            }
                            if (board[x-distance][y-distance] < 0) {
                                break;
                            }
                        }
                    }
                }
            }
        }

        //lists white king moves
        void list_White_King_Moves() {
            for ( int x=0; x<8; x++) {
                for (int y=0; y<8; y++) {
                    if (chessFunctions::get_piece(board, x, y) == 6) {
                        if (board[x][y+1] <= 0) {chessFunctions::record_temp_move (board, possible_moves, x, y, x, y+1);}      //W1
                        if (board[x+1][y+1] <= 0) {chessFunctions::record_temp_move (board, possible_moves, x, y, x+1, y+1);}  //W2
                        if (board[x+1][y] <= 0) {chessFunctions::record_temp_move (board, possible_moves, x, y, x+1, y);}       //W3
                        if (board[x+1][y-1] <= 0) {chessFunctions::record_temp_move (board, possible_moves, x, y, x+1, y-1);}  //W4
                        if (board[x][y-1] <= 0) {chessFunctions::record_temp_move (board, possible_moves, x, y, x, y-1);}      //W5
                        if (board[x-1][y-1] <= 0) {chessFunctions::record_temp_move (board, possible_moves, x, y, x-1, y-1);}  //W6
                        if (board[x-1][y] <= 0) {chessFunctions::record_temp_move (board, possible_moves, x, y, x-1, y);}      //W7
                        if (board[x-1][y+1] <= 0) {chessFunctions::record_temp_move (board, possible_moves, x, y, x-1, y+1);}  //W8
                    }
                }
            }
        }
        //lists black king moves
        void list_Black_King_Moves() {
            for ( int x=0; x<8; x++) {
                for (int y=0; y<8; y++) {
                    if (chessFunctions::get_piece(board, x, y) == -6) {
                        if (board[x][y+1] >= 0) {chessFunctions::record_temp_move (board, possible_moves, x, y, x, y+1);}
                        if (board[x=1][y=1] >= 0) {chessFunctions::record_temp_move (board, possible_moves, x, y, x+1, y+1);}
                        if (board[x+1][y] >= 0) {chessFunctions::record_temp_move (board, possible_moves, x, y, x+1, y);}
                        if (board[x+1][y-1] >= 0) {chessFunctions::record_temp_move (board, possible_moves, x, y, x+1, y-1);}
                        if (board[x][y-1] >= 0) {chessFunctions::record_temp_move (board, possible_moves, x, y, x, y-1);}
                        if (board[x-1][y-1] >= 0) {chessFunctions::record_temp_move (board, possible_moves, x, y, x-1, y-1);}
                        if (board[x-1][y] >= 0) {chessFunctions::record_temp_move (board, possible_moves, x, y, x-1, y);}
                        if (board[x-1][y+1] >= 0) {chessFunctions::record_temp_move (board, possible_moves, x, y, x-1, y+1);}
                    }
                }
            }
        }

        //wraps up all the list piece moves into a single function
        void list_White_Moves() {
            list_White_Pawn_Moves();
            list_White_Knight_Moves();
            list_White_Bishop_Moves();
            list_White_Rook_Moves();
            list_White_Queen_Moves();
            list_White_King_Moves();
        }
        void list_Black_Moves() {
            list_Black_Pawn_Moves();
            list_Black_Knight_Moves();
            list_Black_Bishop_Moves();
            list_Black_Rook_Moves();
            list_Black_Queen_Moves();
            list_Black_King_Moves();
        }

};


int main(){
    //begin the fun stuff
    Chess game1{};
    presets::set_up_Chessboard(game1.board, game1.enPassantBoard, "test");
    presets::set_up_enpassant_board(game1.enPassantBoard);
    std::cout << "Chessboard looks like this before any shenanigans:" << std::endl;
    chessFunctions::print_Chessboard(game1.board);
    game1.list_White_Moves();
    std::cout << "Chessboard ending position" << std::endl;
    chessFunctions::print_Chessboard(game1.board);
    return 0;
}