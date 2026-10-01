#pragma once

#include <array>
#include <vector>
#include "../team/team.hpp"

//used to store data about the current state of the board.
//saves:
//The X and Y coords of the enPassant Square,
//the team that can perform the enPassant,
//whose turn it is, and
//the array of arrays that holds the pieces of the board.
struct BoardStateStruct{
    int enPassantRank = 0;
    int enPassantFile = 0;
    bool canEnPassant = false;
    Team turn = White;
    std::array<std::array<int, 8>, 8> board = {};
    std::array<std::array<int, 8>, 8> squaresAttackedByWhite = {};
    std::array<std::array<int, 8>, 8> squaresAttackedByBlack = {};
    std::array<std::array<int, 8>, 8> netAttacks = {};

    float evaluation = 0.0f;
    bool whiteKingHasMoved = false;
    bool whiteKingsRookHasMoved = false;
    bool whiteQueensRookHasMoved = false;
    bool blackKingHasMoved = false;
    bool blackKingsRookHasMoved = false;
    bool blackQueensRookHasMoved = false;
    


    //print_chessboard is called on a boardStateStruct object, and prints it out using the standard iostream
    //print_Chessboard(board)
    void print_chessboard();

    //prints out the boardState. All info.
    void print_boardState();

    void print_en_passant_visual();

    //-object.set_square(x, y, value)
    //-sets a square to the specified value
    //-has OOB detection
    void set_square(const int rank, const int file, const int value);

    //clears the chessboard to all 0s. Takes one argument.
    //clear_Chessboard(board)
    void clear_Chessboard(BoardStateStruct boardState);

    //Takes (x,y) coords for args.
    //Gets the piece of a given square with OOB checking
    int get_piece(const int rank, const int file);



    //prints out all the pieces on the board and their coords.
    void list_piece_locations();

    //used to set the enPassantXCoord, enPassantYCoord, and enPassantTurn, all in one action. probably isnt necessary imo.
    void set_enpassant(int rank, int file, Team turn);

    //sets up the board to a preset based on what input arg you pass, eg "standard"
    void set_up_chessboard(std::string position);

    std::vector<BoardStateStruct> list_pawn_moves();
    std::vector<BoardStateStruct> list_knight_moves();
    std::vector<BoardStateStruct> list_bishop_moves();
    std::vector<BoardStateStruct> list_rook_moves();
    std::vector<BoardStateStruct> list_queen_moves();
    std::vector<BoardStateStruct> list_king_moves();

    //prints out the locations of every piece on the board, if there is a pawn on a given coord, it'll print it.
    void list_piece_locations(BoardStateStruct boardState);

    //returns true if there is a king of the specified team on the board, and false otherwise.
    bool king_is_present(BoardStateStruct boardState, Team color);

    //Returns a vBSS containing all possible moves from the BSS the method is called on.
    //Is basically a wrapper for the 6 piece moves.
    std::vector<BoardStateStruct> list_possible_moves(int logging);

    //takes a BoardStateStruct calls list_legal_moves on a copy of it,
    //sorts through the vBSS and only selects positions from which all of opposite team's possible moves
    //end in positions where team's King still remains on the board.
    std::vector<BoardStateStruct> list_legal_moves();
    
    std::vector<BoardStateStruct> handle_possible_promotion(int startRank, int endRank, int file);
    
    //marks the given coords of a BoardStateStruct's with a 1. Signals that the given square is attacked by some piece
    void mark_attacked_square(Team team, int rank, int file);



    void find_squares_attacked_by_pawn(Team team);
    void find_squares_attacked_by_knight(Team team);
    void find_squares_attacked_by_bishop(Team team);
    void find_squares_attacked_by_rook(Team team);
    void find_squares_attacked_by_queen(Team team);
    void find_squares_attacked_by_king(Team team);
    
    //is called on a BSS and fills out its array with squares attacked by the other team
    //primarily used for generating castling rights.
    void find_squares_attacked_by_white();
    void find_squares_attacked_by_black();

    //fills out the netAttacks grid by running find_squares_squares_attacked_by (white and black)
    //then adding the two together. a square attacked once by white and twice by black will read -1.
    void find_net_attacks();

    //prints out a grid of squares like printBoard, but for the attackMap.
    //WARNING, doesnt reset and refill the attackMap, only prints what it currently sees
    //remember to reset and rediscover attacked squares when appropriate.
    void print_squares_attacked_by(Team team);

    
    void reset_squaresAttackedByWhite();
    void reset_squaresAttackedByBlack();

};


//(x,y) source coord, (x,y) destination coord
//returns the BSS that results from moving the piece on the specified square to the other specified square.
BoardStateStruct record_move(BoardStateStruct boardState, int startRank, int startFile, int endRank, int endFile);


//takes two vBSS (vectors of BoardStateStruct) and combines them to get a bigger vector.
std::vector<BoardStateStruct> combine_vBSS(std::vector<BoardStateStruct> vector1, std::vector<BoardStateStruct> vector2);

//returns true if all positions have the specified king in them.
bool king_in_all(std::vector<BoardStateStruct> positions, Team color);

//takes a vector of boardStates,
//prints the postitions passed to it. 
void print_positions(std::vector<BoardStateStruct> positions);
