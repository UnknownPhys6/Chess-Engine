#pragma once

#include <iostream>
#include <array>
#include <vector>

#include "board_state.hpp"

namespace chessFunctions {


    //is_in_bounds(board, x, y);
    //returns true or false based on whether the input coords are in-bounds.
    static bool is_in_bounds(const int x, const int y) {
        if ((x >= 0) && (x <= 7) && (y >= 0) && (y <= 7)) {
            return true;
        }
        std::cout << "Referenced square fell out of bounds, coordinates (" << x << ", " << y << "). Returning \"False\"..." << std::endl;
        return false;
    }


    //returns true if the sign of both colors is the same, otherwise, returns False.
    //Has no bounds checking.
    bool is_same_color(int a, int b){
        if ((a > 0 && b > 0) || (a < 0 && b < 0)){
            return true;
        }
        else return false;
    }


    //returns true if one number is positive (excluding 0) and the other is negative
    //is_different_color(a, b)
    bool is_different_color(int a, int b){
        if ((a > 0 && b < 0) || (a < 0 && b > 0)){
            return true;
        }
        else{
            return false;
        }
    }


    //clears the chessboard to all 0s. Takes one argument.
    //clear_Chessboard(board)
    void clear_Chessboard(BoardStateStruct boardState) {
        boardState.board = {};
    };


    //Takes (x,y) coords for args.
    //Gets the piece of a given square with OOB checking
    int get_piece(const BoardStateStruct boardState, const int i, const int j) {
        if (is_in_bounds(i, j)) {
            return boardState.board[i][j];
        }else {
            return 9;
       }
    }


    //takes the board as an argument, and prints it out using the standard iostream
    //print_Chessboard(board)
    void const print_chessboard(BoardStateStruct boardState) {
        std::cout << "The Chessboard looks like this:" << std::endl;
        for (int i = 7; i >= 0; i--) {
            std::cout << i << " |";
            for (int j = 0; j < 8; j++) {
                if (boardState.board[i][j] < 0){
                    std::cout << boardState.board[i][j] << " ";
                }else {
                    std::cout << " " << boardState.board[i][j] << " ";
                }
            }
            std::cout << "\n";
        }
        std::cout << "   _______________________" << std::endl;
        std::cout << "    A  B  C  D  E  F  G  H" << std::endl << std::endl;
    }


    //-object.set_square(x, y, value)
    //-sets a square to the specified value
    //-has OOB detection
    void set_square(BoardStateStruct &boardState, const int x, const int y, const int value) {
        if (is_in_bounds(x, y)) {
            boardState.board[x][y] = value;
        }
    }


    //record_temp_move(board, possiblemoves, x1, y1, x2, y2);
    //moves piece from first set of coords to second set of coords. Checks for OOB errors.
    void record_possible_move (
        BoardStateStruct boardState,
        std::vector<BoardStateStruct> &possible_moves,
        const int x1,
        const int y1,
        const int x2,
        const int y2){
        if (is_in_bounds(x1, y1) && is_in_bounds(x2, y2)) {
            const int piece_holder = get_piece(boardState, x2, y2);
            boardState.board[x2][y2] = get_piece(boardState, x1, y1);
            boardState.board[x1][y1] = 0;
            boardState.enPassantTurn = Neither;
            //print_chessboard(boardState);
            possible_moves.push_back(boardState);

        }
    }

    //takes a Team enum as an argument (datatype that could be White, Black, or Neither)
    //and returns a string of "White", "Black", or "Neither", accordingly.
    std::string turn_enum_to_string(Team turn){
        switch (turn){
            case Team::White:
                return "White";
            case Team::Black:
                return "Black";
            case Team::Neither:
                return "Neither";
        }
        std::cout << "turn_enum_to_string() " << "recieved bad input and was forced to return \"Error\"." << std::endl;
        return "Error";
    }

    int turn_enum_to_int(Team turn){
        switch (turn){
            case Team::White:
                return 1;
            case Team::Black:
                return -1;
            case Team::Neither:
                return 0;
        }
        std::cout << "turn_enum_to_int() " << "recieved bad input and was forced to return \"11\"." << std::endl;
        return 11;
    }

    void print_positions(std::vector<BoardStateStruct> possible_positions){
        for (const auto& item : possible_positions){
            print_chessboard(item);
        }
    }

    const Team get_color(int num){
        if ( num > 0){
            return White;
        }
        if (num < 0){
            return Black;
        }
        return Neither;
    }

    const std::string get_color_string(int num){
        if ( num > 0){
            return "white";
        }
        if (num < 0){
            return "black";
        }
        return "neither";
    }

    void list_piece_locations(BoardStateStruct boardState){
        std::string color;
        for (int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                int piece = chessFunctions::get_piece(boardState, i, j);
                if (piece < 0){
                    chessFunctions::set_square(boardState, i, j, -piece);
                    color = "black";
                }else{
                    color = "white";
                }
                switch (chessFunctions::get_piece(boardState, i, j)){
                    case 1:{std::cout<<"There is a "<<color<<" pawn on ("<<i<<", "<<j<<")."<<std::endl; break;}
                    case 2:{std::cout<<"There is a "<<color<<" knight on ("<<i<<", "<<j<<")."<<std::endl; break;}
                    case 3:{std::cout<<"There is a "<<color<<" bishop on ("<<i<<", "<<j<<")."<<std::endl; break;}
                    case 4:{std::cout<<"There is a "<<color<<" rook on ("<<i<<", "<<j<<")."<<std::endl; break;}
                    case 5:{std::cout<<"There is a "<<color<<" queen on ("<<i<<", "<<j<<")."<<std::endl; break;}
                    case 6:{std::cout<<"There is a "<<color<<" king on ("<<i<<", "<<j<<")."<<std::endl; break;}
                }
            }
        }
    }

    Team get_opposite_team(Team turn){
        if (turn == White){
            return Team::Black;
        }
        else if (turn == Black){
            return Team::White;
        }
        else{
            return Neither;//should never run hopefully
        }
    }
};
