#include <string>
#include <array>
#include <iostream>


namespace presets {
 //Sets up the Chessboard in the standard position
    //takes three (3) arguments.
    //set_up_Chessboards(board, enPassantBoard, "arg")
    void set_up_Chessboard(std::array<std::array<int, 8>, 8> &board, std::array<std::array<int, 8>, 8> &enPassantBoard, const std::string position) {
        //sets up the regular board
        if (position == "standard") {
            board = {
                {                                     //X (first)
                    { 4,  2,  3,  5,  6,  3,  2,  4}, //0
                    { 1,  1,  1,  1,  1,  1,  1,  1}, //1
                    { 0,  0,  0,  0,  0,  0,  0,  0}, //2
                    { 0,  0,  0,  0,  0,  0,  0,  0}, //3
                    { 0,  0,  0,  0,  0,  0,  0,  0}, //4
                    { 0,  0,  0,  0,  0,  0,  0,  0}, //5
                    {-1, -1, -1, -1, -1, -1, -1, -1}, //6
                    {-4, -2, -3, -5, -6, -3, -2, -4}, //7
                }//Y  0   1   2   3   4   5   6   7
            };
        }
        else if (position == "test") {
            board = {
                {                                     //X (first)
                    { 0,  0,  0,  0,  0,  0,  0,  0}, //0
                    { 0,  0,  0,  0,  0,  0,  0,  0}, //1
                    { 0,  0,  0,  0,  0,  0,  0,  0}, //2
                    { 0,  0,  0,  1, -1,  0,  0,  0}, //3
                    { 0,  0,  0,  0,  0,  0,  0,  0}, //4
                    { 0,  0,  0,  0,  0,  0,  0,  0}, //5
                    { 0,  0,  0,  0,  0,  0,  0,  0}, //6
                    { 0,  0,  0,  0,  0,  0,  0,  0}, //7
                }//Y  0   1   2   3   4   5   6   7
            };
        }
        else {
            std::cout << "set_up_chessboard recieved an unrecognized postion argument.";
        }
    };


        //sets up enPassantBoard.
        void set_up_enpassant_board(std::array<std::array<int, 8>, 8> enPassantBoard){
            enPassantBoard = {
                {
                    { 0,  0,  0,  0,  0,  0,  0,  0}, //0
                    { 0,  0,  0,  0,  0,  0,  0,  0}, //1
                    { 0,  0,  0,  1,  0,  0,  0,  0}, //2
                    { 0,  0,  0,  0,  0,  0,  0,  0}, //3
                    { 0,  0,  0,  0, -1,  0,  0,  0}, //4
                    { 0,  0,  0,  0,  0,  0,  0,  0}, //5
                    { 0,  0,  0,  0,  0,  0,  0,  0}, //6
                    { 0,  0,  0,  0,  0,  0,  0,  0}, //7
                }
            };
        }
        
    
};