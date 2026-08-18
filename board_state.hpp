#pragma once
#include <array>

enum Team {
    White,
    Black,
    Neither
};


//used to store data about the current state of the board.
//saves:
//The X and Y coords of the enPassant Square,
//the team that can perform the enPassant,
//whose turn it is, and
//the array of arrays that holds the pieces of the board.
struct BoardStateStruct{
    int enPassantXCoord;
    int enPassantYCoord;
    Team enPassantTurn;
    Team turn;
    std::array<std::array<int, 8>, 8> board;
    float evaluation;

    void print_boardState(){
        std::cout << "boardState.enPassantXCoord = " << enPassantXCoord << std::endl;
        std::cout << "boardState.enPassantYCoord = " << enPassantYCoord << std::endl;
        std::cout << "boardState.enPassantTurn = " << enPassantTurn << std::endl;
        std::cout << "boardState.turn = " << turn << std::endl;
        std::cout << "boardState.evaluation = " << evaluation << std::endl;
    }
};

