#include <array>
#include <vector>
#include <string>
#include "../chess_functions.hpp"


namespace pieceMoves{
    //Pawn WIP
    //ex: list_White_Pawn_Moves();
    void list_pawn_moves(
        std::string color,
        std::array<std::array<int, 8>, 8> board,
        std::array<std::array<int, 8>, 8> enPassantBoard,
        std::vector<std::array<std::array<int, 8>, 8>> &possible_moves
    ) {
        int colorNumber;
        if (color == "white"){
            colorNumber = 1;
        }
        if (color == "black"){
            colorNumber = -1;
        }
        for(int x=0; x<8; x++) {
            for(int y=0; y<8; y++) {
                if(board[x][y] == colorNumber) {
                    //move 1 space
                    //uses colorNumber to change direction of the pawn.
                    //if pawn is white, pawn will move in + x direction
                    //if pawn is black, pawn will move in - x direction
                    if (board[x + colorNumber][y] == 0) {
                        chessFunctions::record_possible_move (board, possible_moves, x, y, x+1, y);
                    }
                    //move 2 spaces
                    if (x==1 && board[x + colorNumber][y] == 0 && board[x + colorNumber + colorNumber][y] == 0) {
                        chessFunctions::record_possible_move (board, possible_moves, x, y, x+2, y);
                        enPassantBoard[x+1][y] = 1;
                    }
                    //capture diagonally
                    if (!chessFunctions::is_same_color(board[x][y], board[x + colorNumber][y+1])) {
                        chessFunctions::record_possible_move (board, possible_moves, x, y, x+1, y+1);
                    }
                    //capture diagonally
                    if (!chessFunctions::is_same_color(board[x][y], board[x + colorNumber][y-1])) {
                        chessFunctions::record_possible_move (board, possible_moves, x, y, x+1, y-1);
                    }
                    //en-passant
                    //cant be fucked rn to use colorNumber to invert all the right numbers for enPassantMoves. Will do it later.
                    if (colorNumber == 1){
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
                    if (colorNumber == -1){
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
    }
}