#pragma once

#include <array>
#include <vector>
#include "../team.hpp"

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


    //print_chessboard is called on a boardStateStruct object, and prints it out using the standard iostream
    //print_Chessboard(board)
    void print_chessboard();

    //prints out the boardState. All info.
    void print_boardState();

    //-object.set_square(x, y, value)
    //-sets a square to the specified value
    //-has OOB detection
    void set_square(const int x, const int y, const int value);

    //clears the chessboard to all 0s. Takes one argument.
    //clear_Chessboard(board)
    void clear_Chessboard(BoardStateStruct boardState);

    //Takes (x,y) coords for args.
    //Gets the piece of a given square with OOB checking
    int get_piece(const int i, const int j);

    //(x,y) source coord, (x,y) destination coord
    //returns the BSS that results from moving the piece on the specified square to the other specified square.
    BoardStateStruct record_move(int x1, int y1, int x2, int y2);

    //prints out all the pieces on the board and their coords.
    void list_piece_locations();

    //used to set the enPassantXCoord, enPassantYCoord, and enPassantTurn, all in one action. probably isnt necessary imo.
    void set_enpassant(int x, int y, Team turn);

    //sets up the board to a preset based on what input arg you pass, eg "standard"
    void set_up_chessboard(std::string position);

    std::vector<BoardStateStruct> list_pawn_moves();
    std::vector<BoardStateStruct> list_knight_moves();
    std::vector<BoardStateStruct> list_bishop_moves();
    std::vector<BoardStateStruct> list_rook_moves();
    std::vector<BoardStateStruct> list_queen_moves();
    std::vector<BoardStateStruct> list_king_moves();

    //Returns a vBSS containing all possible moves from the BSS the method is called on.
    //Is basically a wrapper for the 6 piece moves.
    std::vector<BoardStateStruct> find_moves();

    /* WIP
    std::vector<BoardStateStruct> list_legal_moves();
    */
};