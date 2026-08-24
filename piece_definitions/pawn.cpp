#include <array>
#include <vector>
#include <string>
#include <iostream>
#include "../board_state/board_state_struct.hpp"
#include "../team.hpp"

void do_double_pawn_move(std::vector<BoardStateStruct> &moveStorage, int x, int y){
    
}


//Pawn WIP
//ex: list_pawn_moves();
std::vector<BoardStateStruct> BoardStateStruct::list_pawn_moves() {
    std::vector<BoardStateStruct> moveStorage = {};
    int colorNumber;
    if (turn == White){
        colorNumber = 1;
    }
    if (turn == Black){
        colorNumber = -1;
    }
    for(int x=0; x<8; x++) {
        for(int y=0; y<8; y++) {
            if(get_piece(x, y) == colorNumber) {
                //uses colorNumber to change direction of the pawn.
                //if pawn is white, pawn will move in +x direction
                //if pawn is black, pawn will move in -x direction
                
                //move 1 space
                if (get_piece(x+colorNumber, y) == 0) {
                    std::cout << turn_team_to_string(turn) + " pawn moves forward 1 space." << std::endl;
                    record_move(x, y, x + colorNumber, y);
                }
                //move 2 spaces
                if (((colorNumber == 1 && x == 1) || (colorNumber == -1 && x == 6)) && get_piece(x+colorNumber, y) == 0 && get_piece(x + 2 * colorNumber, y) == 0) {
                    std::cout << turn_team_to_string(turn) + " pawn moves forward 2 spaces." << std::endl;
                    int colorNumber = turn_team_to_int(turn);
                    set_square(x+2*colorNumber, y, get_piece(x, y)); //set destination square to pawn value
                    set_square(x, y, 0); //set source square to 0
                    enPassantXCoord = x+2*colorNumber;
                    enPassantYCoord = y;
                    enPassantTurn = get_opposite_team(turn);
                    moveStorage.push_back(*this);
                }
                //capture diagonally
                if (is_different_color(get_piece(x, y), get_piece(x + colorNumber, y+1))) {
                    std::cout << turn_team_to_string(turn) + " pawn captures diagonally." << std::endl;
                    record_move(x, y, x + colorNumber, y+1);
                }
                //capture diagonally
                if (is_different_color(get_piece(x, y), get_piece(x + colorNumber, y-1))) {
                    std::cout << turn_team_to_string(turn) + " pawn captures diagonally." << std::endl;
                    record_move(x, y, x + colorNumber, y-1);
                }
                //en-passant left
                if(get_piece(x, y) == colorNumber && //the source square is the right team
                    get_piece(x, y-colorNumber) == -colorNumber && //the square to be captured is the other team
                    enPassantXCoord == x && //the x coord (rank) is lined up
                    enPassantYCoord == y-colorNumber //the pawn is directly to the right
                ){
                    set_square(x+colorNumber, y-colorNumber, colorNumber);//set board[x+turn][y-turn] (the destination square) to the turn number
                    set_square(x, y, 0);//set original square to 0 (the piece is no longer there)
                    set_square(x, y-colorNumber, 0);//set the captured piece's square to 0 (because its captured)
                    enPassantTurn = Team::Neither;
                    moveStorage.push_back(*this);//push the board state to the position vector
                }
                if(get_piece(x, y) == colorNumber && //the source square is the right team
                    get_piece(x, y+colorNumber) == -colorNumber && //the square to be captured is the other team
                    enPassantXCoord == x && //the x coord (rank) is lined up
                    enPassantYCoord == y+colorNumber //the pawn is directly to the right
                ){
                    set_square(x+colorNumber, y+colorNumber, colorNumber); //set board[x+turn][y-turn] (the destination square) to the turn number
                    set_square(x, y, 0);//set original square to 0 (the piece is no longer there)
                    set_square(x, y+colorNumber, 0);//set the captured piece's square to 0 (because its captured)
                    enPassantTurn = Team::Neither;
                    moveStorage.push_back(*this);//push the board state to the position vector
                }
            }
        }
    }
    return moveStorage;
}