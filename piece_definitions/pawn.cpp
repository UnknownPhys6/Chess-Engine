#include <array>
#include <vector>
#include <string>
#include <iostream>
#include "../functions/functions.hpp"
#include "../board_state/board_state.hpp"
#include "../team.hpp"

//Pawn WIP
//this code is ugly. Rewrite it later.
//ex: list_pawn_moves();
std::vector<BoardStateStruct> BoardStateStruct::list_pawn_moves() {
    this->print_chessboard();
    std::vector<BoardStateStruct> moveStorage = {};
    int colorNumber;
    if(turn == White){colorNumber = 1;}
    if(turn == Black){colorNumber = -1;}
    for(int x=0; x<8; x++) {
        for(int y=0; y<8; y++) {
            if(get_piece(x, y) == colorNumber) {
                //uses colorNumber to change direction of the pawn.
                //if pawn is white, pawn will move in +x direction
                //if pawn is black, pawn will move in -x direction
                
                //move 1 space
                if (is_in_bounds(x+colorNumber, y) && get_piece(x+colorNumber, y) == 0) {
                    std::cout << turn_team_to_string(turn) + " pawn moves forward 1 space." << std::endl;
                    moveStorage.push_back(record_move(*this, x, y, x + colorNumber, y));
                }

                //move 2 spaces
                if (((colorNumber == 1 && x == 1) || (colorNumber == -1 && x == 6))
                    && is_in_bounds(x+colorNumber, y)
                    && is_in_bounds(x+2*colorNumber, y)
                    && get_piece(x+colorNumber, y) == 0
                    && get_piece(x+2*colorNumber, y) == 0) {

                    std::cout << turn_team_to_string(turn) + " pawn moves forward 2 spaces." << std::endl;
                    BoardStateStruct tempBoardState = record_move(*this, x, y, x+2*colorNumber, y);
                    tempBoardState.enPassantXCoord = x+2*colorNumber;
                    tempBoardState.enPassantYCoord = y;
                    moveStorage.push_back(tempBoardState);
                }

                //capture diagonally
                if (is_in_bounds(x+colorNumber, y+1)
                    && is_different_color(get_piece(x, y), get_piece(x + colorNumber, y+1))) {

                    std::cout << turn_team_to_string(turn) + " pawn captures diagonally." << std::endl;
                    moveStorage.push_back(record_move(*this, x, y, x + colorNumber, y+1));
                }

                //capture diagonally
                if (is_in_bounds(x+colorNumber, y-1)
                    && is_different_color(get_piece(x, y), get_piece(x + colorNumber, y-1))) {

                    std::cout << turn_team_to_string(turn) + " pawn captures diagonally." << std::endl;
                    moveStorage.push_back(record_move(*this, x, y, x + colorNumber, y-1));
                }

                //en-passant left
                if(get_piece(x, y) == colorNumber && //the source square is the right team
                    is_in_bounds(x, y-colorNumber) &&
                    get_piece(x, y-colorNumber) == -colorNumber && //the square to be captured is the other team
                    enPassantXCoord == x && //the x coord (rank) is lined up
                    enPassantYCoord == y-colorNumber && //the pawn is directly to the left
                    is_in_bounds(enPassantXCoord, enPassantYCoord)
                ){
                    BoardStateStruct boardStateCopy = *this;
                    boardStateCopy.set_square(x+colorNumber, y-colorNumber, colorNumber);//set board[x+turn][y-turn] (the destination square) to the turn number
                    boardStateCopy.set_square(x, y, 0);//set original square to 0 (the piece is no longer there)
                    boardStateCopy.set_square(x, y-colorNumber, 0);//set the captured piece's square to 0 (because its captured)
                    boardStateCopy.enPassantTurn = Team::Neither;
                    boardStateCopy.turn = get_opposite_team(boardStateCopy.turn);
                    moveStorage.push_back(boardStateCopy);//push the board state to the position vector
                }

                //en-passant right
                if(get_piece(x, y) == colorNumber && //the source square is the right team
                    is_in_bounds(x, y+colorNumber) &&
                    get_piece(x, y+colorNumber) == -colorNumber && //the square to be captured is the other team
                    enPassantXCoord == x && //the x coord (rank) is lined up
                    enPassantYCoord == y+colorNumber && //the pawn is directly to the right
                    is_in_bounds(enPassantXCoord, enPassantYCoord)
                ){
                    BoardStateStruct boardStateCopy = *this;
                    boardStateCopy.set_square(x+colorNumber, y+colorNumber, colorNumber); //set board[x+turn][y-turn] (the destination square) to the turn number
                    boardStateCopy.set_square(x, y, 0);//set original square to 0 (the piece is no longer there)
                    boardStateCopy.set_square(x, y+colorNumber, 0);//set the captured piece's square to 0 (because its captured)
                    boardStateCopy.enPassantTurn = Team::Neither;
                    boardStateCopy.turn = get_opposite_team(boardStateCopy.turn);
                    moveStorage.push_back(boardStateCopy);//push the board state to the position vector
                }
            }
        }
    }
    std::cout << "list_pawn_moves found " << moveStorage.size() << " positions.\n";
    return moveStorage;
}