#pragma once

#include <string>
#include <array>
#include <iostream>

#include "board_state.hpp"

namespace presets {
    //Sets up the Chessboard in the standard position
    //takes three (3) arguments.
    //set_up_Chessboards(board, enPassantBoard, "arg")
    void set_Up_Chessboard(BoardStateStruct &boardState, const std::string position) {
        //sets up the regular board
        if (position == "standard") {
            boardState.board = {
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
            boardState.board = {
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
            boardState.enPassantTurn = Team::White;
            boardState.enPassantXCoord = 2;
            boardState.enPassantYCoord = 4;
        }
        else {
            std::cout << "set_up_chessboard recieved an unrecognized arguement for \"position\".";
        }
    };


        //sets up enPassantBoard.
        void set_enpassant(BoardStateStruct boardState, int x, int y, Team turn){
            boardState.enPassantXCoord = x;
            boardState.enPassantYCoord = y;
            boardState.enPassantTurn = turn;
        }
        
    
};