#include <iostream>
#include <vector>
#include "board_state.hpp"
#include "../functions/functions.hpp"

void BoardStateStruct::print_chessboard(){
    std::cout << "The Chessboard looks like this:" << std::endl;
    for (int rank = 7; rank >= 0; rank--) {
        std::cout << rank << " |";
        for (int file = 0; file < 8; file++) {
            if (board[rank][file] < 0){
                std::cout << board[rank][file] << " ";
            }else {
                std::cout << " " << board[rank][file] << " ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "   _______________________" << std::endl;
    std::cout << "    A  B  C  D  E  F  G  H" << std::endl << std::endl;
}

void BoardStateStruct::print_boardState(){
    print_chessboard();
    std::cout << "boardState.enPassantRank = " << enPassantRank << std::endl;
    std::cout << "boardState.enPassantFile = " << enPassantFile << std::endl;
    std::cout << "boardState.canEnPassant = " << canEnPassant << std::endl;
    std::cout << "boardState.turn = " << turn_team_to_string(turn) << std::endl;
    std::cout << "boardState.evaluation = " << evaluation << std::endl;
}


//-object.set_square(x, y, value)
//-sets a square to the specified value
//-has OOB detection
void BoardStateStruct::set_square(const int rank, const int file, const int value) {
    if (is_in_bounds(rank, file)) {
        board[rank][file] = value;
    }
}


//clears the chessboard to all 0s. Takes one argument.
//clear_Chessboard(board)
void BoardStateStruct::clear_Chessboard(BoardStateStruct boardState) {
    boardState.board = {};
};


//Takes (x,y) coords for args.
//Gets the piece of a given square with OOB checking
int BoardStateStruct::get_piece(const int rank, const int file){
    if (is_in_bounds(rank, file)) {
        return board[rank][file];
    }else {
        return 9;
    }
}


BoardStateStruct record_move(BoardStateStruct boardState, int startRank, int startFile, int endRank, int endFile){
    //set king's "has moved" state to true for castling rights purposes
    if(boardState.get_piece(startRank, startFile) == 6){boardState.whiteKingHasMoved = true;}
    if(boardState.get_piece(startRank, startFile) == -6){boardState.blackKingHasMoved = true;}

    //set the Rooks' "has moved" state to true for the same reason.
    if(startRank == 0 && startFile == 0 && boardState.get_piece(startRank, startFile) == 4){boardState.whiteQueensRookHasMoved = true;}
    if(startRank == 0 && startFile == 7 && boardState.get_piece(startRank, startFile) == 4){boardState.whiteKingsRookHasMoved = true;}
    if(startRank == 7 && startFile == 0 && boardState.get_piece(startRank, startFile) == -4){boardState.blackQueensRookHasMoved = true;}
    if(startRank == 7 && startFile == 7 && boardState.get_piece(startRank, startFile) == -4){boardState.blackKingsRookHasMoved = true;}

    boardState.board[endRank][endFile] = boardState.get_piece(startRank, startFile);
    boardState.board[startRank][startFile] = 0;
    boardState.canEnPassant = false;
    boardState.turn = get_opposite_team(boardState.turn);
    return boardState;
}

std::vector<BoardStateStruct> BoardStateStruct::handle_possible_promotion(int startRank, int endRank, int file){
    std::vector<BoardStateStruct> moveStorage = {};
    if (turn == White && startRank == 7){
        for(int promotionPiece=2; promotionPiece<6; promotionPiece++){
            set_square(endRank, file, promotionPiece);
            canEnPassant = false;
            moveStorage.push_back(*this);
        }
    }
    return moveStorage;
}

void BoardStateStruct::list_piece_locations(){
    std::string color;
    for (int rank=0; rank<8; rank++){
        for(int file=0; file<8; file++){
            int piece = get_piece(rank, file);
            if (piece < 0){
                piece= -piece;
                color = "black";
            }else{
                color = "white";
            }
            switch (get_piece(rank, file)){
                case 1:{std::cout<<"There is a "<<color<<" pawn on "<<file_to_str(file)<<rank<<"\n"; break;}
                case 2:{std::cout<<"There is a "<<color<<" knight on "<<file_to_str(file)<<rank<<"\n"; break;}
                case 3:{std::cout<<"There is a "<<color<<" bishop on "<<file_to_str(file)<<rank<<"\n"; break;}
                case 4:{std::cout<<"There is a "<<color<<" rook on "<<file_to_str(file)<<rank<<"\n"; break;}
                case 5:{std::cout<<"There is a "<<color<<" queen on "<<file_to_str(file)<<rank<<"\n"; break;}
                case 6:{std::cout<<"There is a "<<color<<" king on "<<file_to_str(file)<<rank<<"\n"; break;}
            }
        }
    }
}

//sets up enPassantBoard.
void BoardStateStruct::set_enpassant(int rank, int file, Team turn){
    //coords reversed because it makes more sense visually
    enPassantRank = rank;
    enPassantFile = file;
    canEnPassant = turn;
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
                { 1,  1,  1,  1,  0,  1,  1,  1}, //1
                { 0,  0,  0,  0,  0,  0,  0,  0}, //2
                { 0,  0,  0, -1,  1,  0,  0,  0}, //3       //remember to flip these boards vertically in your head, because the top row is the first one.
                { 0,  0,  0,  0,  0,  0,  0,  0}, //4
                { 0,  0,  0,  0,  0,  0,  0,  0}, //5
                {-1, -1, -1,  0, -1, -1, -1, -1}, //6
                {-4, -2, -3, -5, -6, -3, -2, -4}, //7
            }//Y  0   1   2   3   4   5   6   7
        };
        turn = Black;
    }
    else if (position == "test") {
        std::cout << "setting position to 'test'.\n";
        board = {
            {                                     //X (first)
                { -6,  0,  0, 0,  0,  0,  0,  0}, //0
                { 0,  0,  0,  0,  0,  0,  0,  0}, //1
                { 0,  0,  0,  0,  0,  0,  0,  0}, //2
                { 0,  0,  0,  0,  0,  0,  0,  0}, //3
                { 0,  0,  0,  0,  0,  0,  0,  0}, //4
                { 0,  0,  0,  0,  0,  0,  0,  0}, //5
                { 0,  0,  0,  0,  0,  0,  0,  0}, //6
                { 0,  0,  0,  0,  -5,  0,  0,  6}, //7
            }//Y  0   1   2   3   4   5   6   7
        };
        turn = White;
        canEnPassant = Team::White;
        enPassantRank = 3;
        enPassantFile = 4;
        
    }
    else {
        std::cout << "set_up_chessboard recieved an unrecognized arg for \"position\".";
    }
}

std::vector<BoardStateStruct> BoardStateStruct::list_possible_moves(int enableLogging = 0) {
    std::vector<BoardStateStruct> moveStorage = {};
    if(enableLogging == 1){std::cout << "doing pawn moves..." << std::endl;}
    moveStorage = combine_vBSS(moveStorage, list_pawn_moves());
    if(enableLogging == 1){std::cout << "...pawn done\n";}

    if(enableLogging == 1){std::cout << "doing knight moves..." << std::endl;}
    moveStorage = combine_vBSS(moveStorage, list_knight_moves());
    if(enableLogging == 1){std::cout << "...knight done\n";}
    
    if(enableLogging == 1){std::cout << "doing bishop moves..." << std::endl;}
    moveStorage = combine_vBSS(moveStorage, list_bishop_moves());
    if(enableLogging == 1){std::cout << "...bishop done\n";}

    if(enableLogging == 1){std::cout << "doing rook moves..." << std::endl;}
    moveStorage = combine_vBSS(moveStorage, list_rook_moves());
    if(enableLogging == 1){std::cout << "...rook done\n";}

    if(enableLogging == 1){std::cout << "doing queen moves..." << std::endl;}
    moveStorage = combine_vBSS(moveStorage, list_queen_moves());
    if(enableLogging == 1){std::cout << "...queen done\n";}

    if(enableLogging == 1){std::cout << "doing king moves..." << std::endl;}
    moveStorage = combine_vBSS(moveStorage, list_king_moves());
    if(enableLogging == 1){std::cout << "...king done\n";}
    
    return moveStorage;
}

std::array<std::array<int, 8>, 8> BoardStateStruct::find_squares_attacked_by(Team team){
    
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
    for (int rank=0; rank<8; rank++){
        for (int file=0; file<8; file++){
            int piece = boardState.get_piece(rank, file);
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


void BoardStateStruct::print_en_passant_visual(){
    BoardStateStruct temp_board;
    temp_board.board = {};
    temp_board.board[enPassantRank][enPassantFile] = turn_team_to_int(turn);
    temp_board.print_chessboard();
}