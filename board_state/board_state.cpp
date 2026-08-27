#include <iostream>
#include <vector>
#include "board_state.hpp"
#include "../functions/functions.hpp"

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
    std::cout << "boardState.enPassantTurn = " << turn_team_to_string(enPassantTurn) << std::endl;
    std::cout << "boardState.turn = " << turn_team_to_string(turn) << std::endl;
    std::cout << "boardState.evaluation = " << evaluation << std::endl;
}


//-object.set_square(x, y, value)
//-sets a square to the specified value
//-has OOB detection
void BoardStateStruct::set_square(const int x, const int y, const int value) {
    if (is_in_bounds(x, y)) {
        board[y][x] = value; //has to be y,x instead of x,y like you'd expect becuase these values are reversed, modifying the first value modifies the file, not the rank.
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


BoardStateStruct record_move(BoardStateStruct boardState, int x1, int y1, int x2, int y2){
    const int piece_holder = boardState.get_piece(x2, y2);
    boardState.board[x2][y2] = boardState.get_piece(x1, y1);
    boardState.board[x1][y1] = 0;
    boardState.enPassantTurn = Team::Neither;
    boardState.turn = get_opposite_team(boardState.turn);
    return boardState;
}


void BoardStateStruct::list_piece_locations(){
    std::string color;
    for (int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            int piece = get_piece(i, j);
            if (piece < 0){
                piece= -piece;
                color = "black";
            }else{
                color = "white";
            }
            switch (get_piece(i, j)){
                case 1:{std::cout<<"There is a "<<color<<" pawn on ("<<j<<", "<<i<<")."<<std::endl; break;}
                case 2:{std::cout<<"There is a "<<color<<" knight on ("<<j<<", "<<i<<")."<<std::endl; break;}
                case 3:{std::cout<<"There is a "<<color<<" bishop on ("<<j<<", "<<i<<")."<<std::endl; break;}
                case 4:{std::cout<<"There is a "<<color<<" rook on ("<<j<<", "<<i<<")."<<std::endl; break;}
                case 5:{std::cout<<"There is a "<<color<<" queen on ("<<j<<", "<<i<<")."<<std::endl; break;}
                case 6:{std::cout<<"There is a "<<color<<" king on ("<<j<<", "<<i<<")."<<std::endl; break;}
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
//takes one (1) argument.
//set_up_Chessboards("arg")
void BoardStateStruct::set_up_chessboard(std::string position) {
    //sets up the regular board
    if (position == "standard") {
        std::cout << "Setting position to 'standard'.\n";
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
        turn = White;
    }
    else if (position == "test") {
        std::cout << "setting position to 'test'.\n";
        board = {
            {                                     //X (first)
                { -6,  0,  0, 0,  0,  0,  0,  0}, //0
                { 0,  0,  0,  0,  0,  0,  0,  0}, //1
                { 0,  0,  0,  0,  0,  0,  0,  0}, //2
                { 0,  0,  0,  0,  0,  0,  0,  0}, //3
                { 0,  0,  0,  1,  -1,  0,  0,  0}, //4
                { 0,  0,  0,  0,  0,  0,  0,  0}, //5
                { 0,  0,  0,  0,  0,  0,  0,  0}, //6
                { 0,  0,  0,  0,  0,  0,  0,  6}, //7
            }//Y  0   1   2   3   4   5   6   7
        };
        turn = White;
        enPassantTurn = Team::White;
        enPassantXCoord = 3;
        enPassantYCoord = 4;
        
    }
    else {
        std::cout << "set_up_chessboard recieved an unrecognized arg for \"position\".";
    }
}

std::vector<BoardStateStruct> BoardStateStruct::list_possible_moves() {
    std::vector<BoardStateStruct> moveStorage = {};

    std::cout << "doing pawn moves..." << std::endl;
    moveStorage = combine_vBSS(moveStorage, list_pawn_moves());
    std::cout << "...pawn done\n";

    std::cout << "doing knight moves..." << std::endl;
    moveStorage = combine_vBSS(moveStorage, list_knight_moves());
    std::cout << "...knight done\n";
    
    std::cout << "doing bishop moves..." << std::endl;
    moveStorage = combine_vBSS(moveStorage, list_bishop_moves());
    std::cout << "...bishop done\n";

    std::cout << "doing rook moves..." << std::endl;
    moveStorage = combine_vBSS(moveStorage, list_rook_moves());
    std::cout << "...rook done\n";

    std::cout << "doing queen moves..." << std::endl;
    moveStorage = combine_vBSS(moveStorage, list_queen_moves());
    std::cout << "...queen done\n";

    std::cout << "doing king moves..." << std::endl;
    moveStorage = combine_vBSS(moveStorage, list_king_moves());
    std::cout << "...king done\n";
    
    return moveStorage;
}

std::vector<BoardStateStruct> combine_vBSS(std::vector<BoardStateStruct> vector1, std::vector<BoardStateStruct> vector2){
    for(BoardStateStruct& item : vector1){
        vector2.push_back(item);
    }
    return vector2;
}

bool king_is_present(BoardStateStruct boardState, Team color){
    int num=1;
    if(color == White){num=1;}
    if(color == Black){num=-1;}
    for (int x=0; x<8; x++){
        for (int y=0; y<8; y++){
            int piece = boardState.get_piece(x, y);
            if ((get_color(piece) == color) && (piece == 6*num )){return true;}
        }
    }
    return false;
}

bool king_in_all(std::vector<BoardStateStruct> positions, Team color){
    for (BoardStateStruct item : positions){
        if (!king_is_present(item, color)){
            return false;
        }
    }
    return true;
}

std::vector<BoardStateStruct> BoardStateStruct::list_legal_moves(){
    std::vector<BoardStateStruct> possibleMoves = list_possible_moves();
    std::vector<BoardStateStruct> legalMoveStorage = {};
    int startingPositionCounter = possibleMoves.size();
    int rejectedCounter = 0;
    for(auto& item : possibleMoves){
        std::vector<BoardStateStruct> responses = item.list_possible_moves();
        if(king_in_all(responses, turn)){
            legalMoveStorage.push_back(item);
        }else{
            std::cout << "position was rejected for being illegal.\n";
            rejectedCounter++;
        }
    }
    std::cout << "list_possible_moves returned " << startingPositionCounter << " moves, and list_legal_moves rejected " << rejectedCounter << " of them, returning " << legalMoveStorage.size() << " positions.\n";
    return legalMoveStorage;
}

void print_positions(std::vector<BoardStateStruct> positions){
    std::cout << "There are " << positions.size() << " positions\n";
    for (BoardStateStruct& item : positions){
        item.print_chessboard();
    }
}