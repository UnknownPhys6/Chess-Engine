#pragma once

#include <array>
#include <vector>
#include <string>
#include "../chess_functions.hpp"
#include "../board_state.hpp"


namespace pieceMoves{

    //records enPassant moves.
    //has possible move checking and OOB checking
    void try_enPassant_left(BoardStateStruct boardState, std::vector<BoardStateStruct> &possibleMoves, int colorNumber, int x, int y
    ) {
        std::cout << "test 1" << std::endl;
        if(chessFunctions::get_piece(boardState, x, y) == colorNumber && //the source square is the right team
            chessFunctions::get_piece(boardState, x, y-colorNumber) == -colorNumber && //the square to be captured is the other team
            boardState.enPassantXCoord == x && //the x coord (rank) is lined up
            boardState.enPassantYCoord == y-colorNumber //the pawn is directly to the right
        ){
                std::cout << "pawn captures enPassant 1" << std::endl;
                chessFunctions::set_square(boardState, x+colorNumber, y-colorNumber, colorNumber);//set board[x+turn][y-turn] (the destination square) to the turn number
                chessFunctions::set_square(boardState, x, y, 0);//set original square to 0 (the piece is no longer there)
                chessFunctions::set_square(boardState, x, y-colorNumber, 0);//set the captured piece's square to 0 (because its captured)
                boardState.enPassantTurn = Neither;
                possibleMoves.push_back(boardState);//push the board state to the position vector
        }
    }
    void try_enPassant_right(BoardStateStruct boardState, std::vector<BoardStateStruct> &possibleMoves, int colorNumber, int x, int y) {
        std::cout << "test 2" << std::endl;
        if(chessFunctions::get_piece(boardState, x, y) == colorNumber && //the source square is the right team
            chessFunctions::get_piece(boardState, x, y+colorNumber) == -colorNumber && //the square to be captured is the other team
            boardState.enPassantXCoord == x && //the x coord (rank) is lined up
            boardState.enPassantYCoord == y+colorNumber //the pawn is directly to the right
        ){
            std::cout << "pawn captures enPassant 2" << std::endl;
            chessFunctions::set_square(boardState, x+colorNumber, y+colorNumber, colorNumber); //set board[x+turn][y-turn] (the destination square) to the turn number
            chessFunctions::set_square(boardState, x, y, 0);//set original square to 0 (the piece is no longer there)
            chessFunctions::set_square(boardState, x, y+colorNumber, 0);//set the captured piece's square to 0 (because its captured)
            boardState.enPassantTurn = Neither;
            possibleMoves.push_back(boardState);//push the board state to the position vector
        }
    }

    void do_double_pawn_move(BoardStateStruct boardState, std::vector<BoardStateStruct> &possibleMoves, int x, int y){
        int colorNumber = chessFunctions::turn_enum_to_int(boardState.turn);
        chessFunctions::set_square(boardState, x+2*colorNumber, y, chessFunctions::get_piece(boardState, x, y)); //set destination square to pawn value
        chessFunctions::set_square(boardState, x, y, 0); //set source square to 0
        boardState.enPassantXCoord = x+2*colorNumber;
        boardState.enPassantYCoord = y;
        boardState.enPassantTurn = chessFunctions::get_opposite_team(boardState.turn);
        possibleMoves.push_back(boardState);
        //chessFunctions::print_chessboard(boardState);
    }


    //Pawn WIP
    //ex: list_White_Pawn_Moves();
    void list_pawn_moves(
        BoardStateStruct boardState,
        std::vector<BoardStateStruct> &possibleMoves
    ) {
        int colorNumber;
        if (boardState.turn == Team::White){
            colorNumber = 1;
        }
        if (boardState.turn == Team::Black){
            colorNumber = -1;
        }
        for(int x=0; x<8; x++) {
            for(int y=0; y<8; y++) {
                if(chessFunctions::get_piece(boardState, x, y) == colorNumber) {
                    //uses colorNumber to change direction of the pawn.
                    //if pawn is white, pawn will move in +x direction
                    //if pawn is black, pawn will move in -x direction
                    
                    //move 1 space
                    if (chessFunctions::get_piece(boardState, x+colorNumber, y) == 0) {
                        std::cout << chessFunctions::turn_enum_to_string(boardState.turn) + " pawn moves forward 1 space." << std::endl;
                        chessFunctions::record_possible_move (boardState, possibleMoves, x, y, x + colorNumber, y);
                    }
                    //move 2 spaces
                    if (((colorNumber == 1 && x == 1) || (colorNumber == -1 && x == 6)) && chessFunctions::get_piece(boardState, x+colorNumber, y) == 0 && chessFunctions::get_piece(boardState, x + 2 * colorNumber, y) == 0) {
                        std::cout << chessFunctions::turn_enum_to_string(boardState.turn) + " pawn moves forward 2 spaces." << std::endl;
                        do_double_pawn_move(boardState, possibleMoves, x, y);
                    }
                    //capture diagonally
                    if (chessFunctions::is_different_color(chessFunctions::get_piece(boardState, x, y), chessFunctions::get_piece(boardState, x + colorNumber, y+1))) {
                        std::cout << chessFunctions::turn_enum_to_string(boardState.turn) + " pawn captures diagonally." << std::endl;
                        chessFunctions::record_possible_move (boardState, possibleMoves, x, y, x + colorNumber, y+1);
                    }
                    //capture diagonally
                    if (chessFunctions::is_different_color(chessFunctions::get_piece(boardState, x, y), chessFunctions::get_piece(boardState, x + colorNumber, y-1))) {
                        std::cout << chessFunctions::turn_enum_to_string(boardState.turn) + " pawn captures diagonally." << std::endl;
                        chessFunctions::record_possible_move (boardState, possibleMoves, x, y, x + colorNumber, y-1);
                    }
                    //en-passant
                    try_enPassant_left(boardState, possibleMoves, colorNumber, x, y);
                    try_enPassant_right(boardState, possibleMoves, colorNumber, x, y);
                }
            }
        }
    }
}