#include <array>
#include <vector>
#include <string>
#include <iostream>
#include "../functions/functions.hpp"
#include "../board_state/board_state.hpp"
#include "../team/team.hpp"

//Pawn WIP
//this code is ugly. Rewrite it later.
//erank: list_pawn_moves();
std::vector<BoardStateStruct> BoardStateStruct::list_pawn_moves() {
    this->print_chessboard();
    std::vector<BoardStateStruct> moveStorage = {};
    int colorNumber;
    if(turn == White){colorNumber = 1;}
    if(turn == Black){colorNumber = -1;}
    for(int rank=0; rank<8; rank++) {
        for(int file=0; file<8; file++) {
            if(get_piece(rank, file) == colorNumber) {
                //uses colorNumber to change direction of the pawn.
                //if pawn is white, pawn will move in +rank direction
                //if pawn is black, pawn will move in -rank direction
                
                //move 1 space
                if (is_in_bounds(rank+colorNumber, file) && get_piece(rank+colorNumber, file) == 0) {
                    moveStorage.push_back(record_move(*this, rank, file, rank + colorNumber, file));
                }

                //move 2 spaces
                if (((colorNumber == 1 && rank == 1) || (colorNumber == -1 && rank == 6))
                    && is_in_bounds(rank+2*colorNumber, file)
                    && get_piece(rank+colorNumber, file) == 0
                    && get_piece(rank+2*colorNumber, file) == 0) {

                    BoardStateStruct tempBoardState = record_move(*this, rank, file, rank+2*colorNumber, file);
                    tempBoardState.enPassantRank = rank+2*colorNumber;
                    tempBoardState.enPassantFile = file;
                    tempBoardState.canEnPassant = true;
                    moveStorage.push_back(tempBoardState);
                }

                //capture diagonally
                if (is_in_bounds(rank+colorNumber, file+1)
                    && is_different_color(get_piece(rank, file), get_piece(rank + colorNumber, file+1))) {

                    moveStorage.push_back(record_move(*this, rank, file, rank + colorNumber, file+1));
                }

                //capture diagonally
                if (is_in_bounds(rank+colorNumber, file-1)
                    && is_different_color(get_piece(rank, file), get_piece(rank + colorNumber, file-1))) {

                    moveStorage.push_back(record_move(*this, rank, file, rank + colorNumber, file-1));
                }

                //en-passant left
                if(get_piece(rank, file) == colorNumber && //the source square is the right team
                    is_in_bounds(rank, file-colorNumber) &&
                    get_piece(rank, file-colorNumber) == -colorNumber && //the square to be captured is the other team
                    enPassantRank == rank && //the rank coord (rank) is lined up
                    enPassantFile == file-colorNumber && //the pawn is directly to the left
                    is_in_bounds(enPassantRank, enPassantFile)
                ){
                    BoardStateStruct boardStateCopy = *this;
                    boardStateCopy.set_square(rank+colorNumber, file-colorNumber, colorNumber);//set board[rank+turn][y-turn] (the destination square) to the turn number
                    boardStateCopy.set_square(rank, file, 0);//set original square to 0 (the piece is no longer there)
                    boardStateCopy.set_square(rank, file-colorNumber, 0);//set the captured piece's square to 0 (because its captured)
                    boardStateCopy.canEnPassant = Team::Neither;
                    boardStateCopy.turn = get_opposite_team(boardStateCopy.turn);
                    moveStorage.push_back(boardStateCopy);//push the board state to the position vector
                }

                //en-passant right
                if(get_piece(rank, file) == colorNumber && //the source square is the right team
                    is_in_bounds(rank, file+colorNumber) &&
                    get_piece(rank, file+colorNumber) == -colorNumber && //the square to be captured is the other team
                    enPassantRank == rank && //the rank coord (rank) is lined up
                    enPassantFile == file+colorNumber && //the pawn is directly to the right
                    is_in_bounds(enPassantRank, enPassantFile)
                ){
                    BoardStateStruct boardStateCopy = *this;
                    boardStateCopy.set_square(rank+colorNumber, file+colorNumber, colorNumber); //set board[rank+turn][y-turn] (the destination square) to the turn number
                    boardStateCopy.set_square(rank, file, 0);//set original square to 0 (the piece is no longer there)
                    boardStateCopy.set_square(rank, file+colorNumber, 0);//set the captured piece's square to 0 (because its captured)
                    boardStateCopy.canEnPassant = Team::Neither;
                    boardStateCopy.turn = get_opposite_team(boardStateCopy.turn);
                    moveStorage.push_back(boardStateCopy);//push the board state to the position vector
                }
            }
        }
    }
    std::cout << "list_pawn_moves found " << moveStorage.size() << " positions.\n";
    return moveStorage;
}