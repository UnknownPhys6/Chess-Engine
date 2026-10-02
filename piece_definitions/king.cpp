#include <array>
#include <vector>
#include <string>
#include <iostream>
#include "../functions/functions.hpp"
#include "../board_state/board_state.hpp"
#include "../team/team.hpp"


std::vector<BoardStateStruct> BoardStateStruct::list_king_moves() {
    int color_number;
    std::vector<BoardStateStruct> moveStorage = {};
    if(turn == Team::White){color_number = 6;}
    if(turn == Team::Black){color_number = -6;}
    for (int rank=0; rank<8; rank++) {
        for (int file=0; file<8; file++) {
            if (get_piece(rank, file) == color_number) {
                if (is_in_bounds(rank, file+1) && !is_same_color(get_piece(rank, file), get_piece(rank,file+1))) {moveStorage.push_back(record_move(rank, file, rank, file+1));}
                if (is_in_bounds(rank+1, file+1) && !is_same_color(get_piece(rank, file), get_piece(rank+1,file+1))) {moveStorage.push_back(record_move(rank, file, rank+1, file+1));}
                if (is_in_bounds(rank+1, file) && !is_same_color(get_piece(rank, file), get_piece(rank+1,file))) {moveStorage.push_back(record_move(rank, file, rank+1, file));}
                if (is_in_bounds(rank+1, file-1) && !is_same_color(get_piece(rank, file), get_piece(rank+1,file-1))) {moveStorage.push_back(record_move(rank, file, rank+1, file-1));}
                if (is_in_bounds(rank, file-1) && !is_same_color(get_piece(rank, file), get_piece(rank,file-1))) {moveStorage.push_back(record_move(rank, file, rank, file-1));}
                if (is_in_bounds(rank-1, file-1) && !is_same_color(get_piece(rank, file), get_piece(rank-1,file-1))) {moveStorage.push_back(record_move(rank, file, rank-1, file-1));}
                if (is_in_bounds(rank-1, file) && !is_same_color(get_piece(rank, file), get_piece(rank-1,file))) {moveStorage.push_back(record_move(rank, file, rank-1, file));}
                if (is_in_bounds(rank-1, file+1) && !is_same_color(get_piece(rank, file), get_piece(rank-1,file+1))) {moveStorage.push_back(record_move(rank, file, rank-1, file+1));}
            }
        }
    }
    //white kingside castling
    if(turn == White){squaresAttackedByBlack = {}; find_squares_attacked_by_black();}
    if(turn == Black){squaresAttackedByWhite = {}; find_squares_attacked_by_white();}
    if(turn == White &&
        board[0][4] == 6 &&         //king is on e1
        board[0][7] == 4 &&         //rook is on h1
        !whiteKingHasMoved &&       //king hasnt mooved
        !whiteKingsRookHasMoved &&  //king's rook hasnt moved
        board[0][5]==0 &&           //the two squares inbetween the king and rook are empty
        board[0][6]==0 &&
        squaresAttackedByBlack[0][4] == 0 &&
        squaresAttackedByBlack[0][5] == 0 &&   //the king is not attacked
        squaresAttackedByBlack[0][6] == 0      //the square the king ends up on is not attacked
    ){
        std::cout << "White can kingside castle. Making move...\n";
        BoardStateStruct boardStateCopy = *this;
        boardStateCopy.board[0][6] = 6;
        boardStateCopy.board[0][5] = 4;
        boardStateCopy.board[0][4] = 0;
        boardStateCopy.board[0][7] = 0;
        boardStateCopy.whiteKingHasMoved = true;
        boardStateCopy.whiteKingsRookHasMoved = true;
        boardStateCopy.canEnPassant = false;
        boardStateCopy.turn = get_opposite_team(turn);
        moveStorage.push_back(boardStateCopy);
    }
    //white queenside castling
    if(turn == White &&
        board[0][0] == 4 &&
        board[0][4] == 6 &&
        !whiteKingHasMoved &&
        !whiteQueensRookHasMoved &&
        board[0][1] == 0 &&
        board[0][2] == 0 &&
        board[0][3] == 0 &&
        squaresAttackedByBlack[0][2] == 0 &&
        squaresAttackedByBlack[0][3] == 0 &&
        squaresAttackedByBlack[0][4] == 0
    ){
        std::cout << "White can queenside castle. Making move...\n";
        BoardStateStruct boardStateCopy = *this;
        boardStateCopy.board[0][2] = 6;
        boardStateCopy.board[0][3] = 4;
        boardStateCopy.board[0][0] = 0;
        boardStateCopy.board[0][4] = 0;
        boardStateCopy.whiteKingHasMoved = true;
        boardStateCopy.whiteQueensRookHasMoved = true;
        boardStateCopy.canEnPassant = false;
        boardStateCopy.turn = get_opposite_team(turn);
        moveStorage.push_back(boardStateCopy);
    }
    //black kingside castling
    if(turn == Black &&
        board[7][4] == -6 &&
        board[7][7] == -4 &&
        !blackKingHasMoved &&
        !blackKingsRookHasMoved &&
        board[7][5] == 0 &&
        board[7][6] == 0 &&
        squaresAttackedByWhite[7][4] == 0 &&
        squaresAttackedByWhite[7][5] == 0 &&
        squaresAttackedByWhite[7][6] == 0
    ){
        std::cout << "Black can kingside castle. Making move...\n";
        BoardStateStruct boardStateCopy = *this;
        boardStateCopy.board[7][6] = -6;
        boardStateCopy.board[7][5] = -4;
        boardStateCopy.board[7][4] = 0;
        boardStateCopy.board[7][7] = 0;
        boardStateCopy.blackKingHasMoved = true;
        boardStateCopy.blackKingsRookHasMoved = true;
        boardStateCopy.canEnPassant = false;
        boardStateCopy.turn = get_opposite_team(turn);
        moveStorage.push_back(boardStateCopy);
    }
    //black queenside castling
    if(turn == Black &&
        board[7][0] == -4 &&
        board[7][4] == -6 &&
        !blackKingHasMoved &&
        !blackQueensRookHasMoved &&
        board[7][1] == 0 &&
        board[7][2] == 0 &&
        board[7][3] == 0 &&
        squaresAttackedByWhite[7][2] == 0 &&
        squaresAttackedByWhite[7][3] == 0 &&
        squaresAttackedByWhite[7][4] == 0
    ){
        std::cout << "Black can queenside castle. Making move...\n";
        BoardStateStruct boardStateCopy = *this;
        boardStateCopy.board[7][2] = -6;
        boardStateCopy.board[7][3] = -4;
        boardStateCopy.board[7][0] = 0;
        boardStateCopy.board[7][4] = 0;
        boardStateCopy.blackKingHasMoved = true;
        boardStateCopy.blackQueensRookHasMoved = true;
        boardStateCopy.canEnPassant = false;
        boardStateCopy.turn = get_opposite_team(turn);
        moveStorage.push_back(boardStateCopy);
    }
    
    std::cout << "list_king_moves found " << moveStorage.size() << " positions.\n";
    return moveStorage;
}


void BoardStateStruct::find_squares_attacked_by_king(Team team) {
    int attackDelta = 1;
    if(team == Black){attackDelta = -1;}
    int color_number;
    std::vector<BoardStateStruct> moveStorage = {};
    if(team == White){color_number = 6;}
    if(team == Black){color_number = -6;}
    for (int rank=0; rank<8; rank++) {
        for (int file=0; file<8; file++) {
            if (get_piece(rank, file) == color_number) {
                if (is_in_bounds(rank, file+1) && !is_same_color(get_piece(rank, file), get_piece(rank,file+1))) {mark_attacked_square(team, rank, file+1);}
                if (is_in_bounds(rank+1, file+1) && !is_same_color(get_piece(rank, file), get_piece(rank+1,file+1))) {mark_attacked_square(team, rank+1, file+1);}
                if (is_in_bounds(rank+1, file) && !is_same_color(get_piece(rank, file), get_piece(rank+1,file))) {mark_attacked_square(team, rank+1, file);}
                if (is_in_bounds(rank+1, file-1) && !is_same_color(get_piece(rank, file), get_piece(rank+1,file-1))) {mark_attacked_square(team, rank+1, file-1);}
                if (is_in_bounds(rank, file-1) && !is_same_color(get_piece(rank, file), get_piece(rank,file-1))) {mark_attacked_square(team, rank, file-1);}
                if (is_in_bounds(rank-1, file-1) && !is_same_color(get_piece(rank, file), get_piece(rank-1,file-1))) {mark_attacked_square(team, rank-1, file-1);}
                if (is_in_bounds(rank-1, file) && !is_same_color(get_piece(rank, file), get_piece(rank-1,file))) {mark_attacked_square(team, rank-1, file);}
                if (is_in_bounds(rank-1, file+1) && !is_same_color(get_piece(rank, file), get_piece(rank-1,file+1))) {mark_attacked_square(team, rank-1, file+1);}
            }
        }
    }
}
