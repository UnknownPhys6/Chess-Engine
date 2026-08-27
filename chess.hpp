#include "board_state/board_state.hpp"

class Chess {
    public:
        //set up an array for the board and en-passant board, and vectors to store board states
        BoardStateStruct boardState;
        std::vector<BoardStateStruct> possibleMoves;
        std::vector<BoardStateStruct> legalMoves;
};