#include <iostream>
#include <vector>

#include "../functions/functions.hpp"
#include "board_state_struct.hpp"

void BoardStateStruct::print_chessboard(){
    std::cout << "The Chessboard looks like this:" << std::endl;
    for (int i = 7; i >= 0; i--) {
        std::cout << i << " |";
        for (int j = 0; j < 8; j++) {
            if (board[i][j] < 0){
                std::cout << board[i][j] << " ";
            }else {
                std::cout << " " << board[i][j] << " ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "   _______________________" << std::endl;
    std::cout << "    A  B  C  D  E  F  G  H" << std::endl << std::endl;
}

void BoardStateStruct::print_boardState(){
    print_chessboard();
    std::cout << "boardState.enPassantXCoord = " << enPassantXCoord << std::endl;
    std::cout << "boardState.enPassantYCoord = " << enPassantYCoord << std::endl;
    std::cout << "boardState.enPassantTurn = " << enPassantTurn << std::endl;
    std::cout << "boardState.turn = " << turn << std::endl;
    std::cout << "boardState.evaluation = " << evaluation << std::endl;
}


//-object.set_square(x, y, value)
//-sets a square to the specified value
//-has OOB detection
void BoardStateStruct::set_square(const int x, const int y, const int value) {
    if (is_in_bounds(x, y)) {
        board[x][y] = value;
    }
}


//clears the chessboard to all 0s. Takes one argument.
//clear_Chessboard(board)
void BoardStateStruct::clear_Chessboard(BoardStateStruct boardState) {
    boardState.board = {};
};


//Takes (x,y) coords for args.
//Gets the piece of a given square with OOB checking
int BoardStateStruct::get_piece(const int i, const int j){
    if (is_in_bounds(i, j)) {
        return board[i][j];
    }else {
        return 9;
    }
}


BoardStateStruct BoardStateStruct::record_move(int x1, int y1, int x2, int y2){
    if (is_in_bounds(x1, y1) && is_in_bounds(x2, y2)) {
        const int piece_holder = get_piece(x2, y2);
        board[x2][y2] = get_piece(x1, y1);
        board[x1][y1] = 0;
        enPassantTurn = Team::Neither;
        //print_chessboard(boardState);
        return *this;
    }else{
        std::cout << "Coords fell out of bounds. Returning an unchanged BSS to avoid compile/runtime errors.\n";
        return *this;
    }
}


void BoardStateStruct::list_piece_locations(){
    std::string color;
    for (int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            int piece = get_piece(i, j);
            if (piece < 0){
                set_square(i, j, -piece);
                color = "black";
            }else{
                color = "white";
            }
            switch (get_piece(i, j)){
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

//sets up enPassantBoard.
void BoardStateStruct::set_enpassant(int x, int y, Team turn){
    enPassantXCoord = x;
    enPassantYCoord = y;
    enPassantTurn = turn;
}

//Sets up the Chessboard in the standard position
//takes three (3) arguments.
//set_up_Chessboards(board, enPassantBoard, "arg")
void BoardStateStruct::set_up_chessboard(std::string position) {
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
        enPassantTurn = Team::White;
        enPassantXCoord = 2;
        enPassantYCoord = 4;
    }
    else {
        std::cout << "set_up_chessboard recieved an unrecognized arg for \"position\".";
    }
}

std::vector<BoardStateStruct> BoardStateStruct::find_moves() {
    std::vector<BoardStateStruct> moveStorage = {};

    std::cout << "doing pawn moves..." << std::endl;
    moveStorage = add_vBSS(moveStorage, list_pawn_moves());
    std::cout << "...pawn done\n";

    std::cout << "doing knight moves..." << std::endl;
    moveStorage = add_vBSS(moveStorage, list_knight_moves());
    std::cout << "...knight done\n";
    
    std::cout << "doing bishop moves..." << std::endl;
    moveStorage = add_vBSS(moveStorage, list_bishop_moves());
    std::cout << "...bishop done\n";

    std::cout << "doing rook moves..." << std::endl;
    moveStorage = add_vBSS(moveStorage, list_rook_moves());
    std::cout << "...rook done\n";

    std::cout << "doing queen moves..." << std::endl;
    moveStorage = add_vBSS(moveStorage, list_queen_moves());
    std::cout << "...queen done\n";

    std::cout << "doing king moves..." << std::endl;
    moveStorage = add_vBSS(moveStorage, list_king_moves());
    std::cout << "...king done\n";
    
    return moveStorage;
}

/* WIP
std::vector<BoardStateStruct> BoardStateStruct::list_legal_moves(){
    for(auto& item : possibleMoves){
        std::vector<BoardStateStruct> move_holder = {};
        item.find_moves();
    }
}
*/