#pragma once
#include <vector>

#include "../board_state/board_state_struct.hpp"

//Returns true if both x and y fall within the bounds 0-7 (inclusive)
//is_in_bounds(x, y)
bool is_in_bounds(const int x, const int y);

//takes a vector of boardStates,
//prints the postitions passed to it. 
void print_positions(std::vector<BoardStateStruct> positions);

//combines two vBSS
std::vector<BoardStateStruct> add_vBSS(std::vector<BoardStateStruct> vector1, std::vector<BoardStateStruct> vector2);

//returns true if the specified king is somewhere on the board.
//king_is_present(boardState, white) returns true if a white king is on the board.
bool king_is_present(BoardStateStruct boardState, Team color);


//prints out the locations of every piece on the board, if there is a pawn on a given coord, it'll print it.
void list_piece_locations(BoardStateStruct boardState);


//returns true if there is a king of the specified team on the board, and false otherwise.
bool king_is_present(BoardStateStruct boardState, Team color);

//takes two vBSS (vectors of BoardStateStruct) and combines them to get a bigger vector.
std::vector<BoardStateStruct> add_vBSS(std::vector<BoardStateStruct> vector1, std::vector<BoardStateStruct> vector2);