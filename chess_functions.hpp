#include <iostream>
#include <array>
#include <vector>

namespace chessFunctions {


    //clears the chessboard to all 0s. Takes one (1) argument.
    //clear_chessboard(board)
    void clear_Chessboard(std::array<std::array<int, 8>, 8> &board) {
        std::fill(board[0][0], board[0][0]+64, 0);
    };


    //-object.set_square(x, y, value)
    //-sets a square to the specified value
    //-has OOB detection
    void set_square(std::array<std::array<int, 8>, 8> &board, const int x, const int y, const int value) {
        if (x < 0 || x > 7 || y < 0 || y > 7) {
            std::cout << "Invalid Chessboard index : (" << x << ", " << y << ")\n";
        }else {
            board[x][y] = value;
        }
    }


    //scrubs the en-passant board of the specified piece. Use only 1 or -1 here,
    //as those correspond to white and black pawn en-passants respectively
    //ex: scrub_En_Passant_Board(1);
    void scrub_En_Passant_Board(std::array<std::array<int, 8>, 8> &enPassantBoard, const int& piece) {
        for (int x=0; x<8; x++) {
            for (int y=0; y<8; y++) {
                if (enPassantBoard[x][y] == piece) {
                    enPassantBoard[x][y] = 0;
                }
            }
        }
    }


    //record_temp_move(board, possiblemoves, x1, y1, x2, y2);
    //moves piece from first set of coords to second set of coords. Checks for OOB errors.
    void record_possible_move (
        std::array<std::array<int, 8>, 8> board,
        std::vector<std::array<std::array<int, 8>, 8>> possible_moves,
        const int x1,
        const int y1,
        const int x2,
        const int y2){
        if (x1 < 0 || x1 >= 8 || y1 < 0 || y1 >= 8 || x2 < 0 || x2 >= 8 || y2 < 0 || y2 >= 8) {
            std::cout << "Invalid Chessboard index : (" << x1 << ", " << y1 << ") or (" << x2 << ", " << y2 << ")\n";
        }else {
            const int piece_holder = get_piece(board, x2, y2);
            board[x2][y2] = get_piece(board, x1, y1);
            board[x1][y1] = 0;
            print_Chessboard(board);    //remove later
            possible_moves.push_back(board);
            board[x1][y1] = get_piece(board, x2, y2);
            board[x2][y2] = piece_holder;
        }
    }


    //is_in_bounds(board, x, y);
    //returns true or false based on whether the input coords are in-bounds.
    static bool is_in_bounds(std::array<std::array<int, 8>, 8> board, const int x, const int y) {
        if (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
            return true;
        }
        return false;
    }


    //Takes (x,y) coords for args.
    //Gets the piece of a given square with OOB checking
    int get_piece(const std::array<std::array<int, 8>, 8> board, const int i, const int j) {
        if (!is_in_bounds(board, i, j)) {
            std::cout << "Invalid Chessboard index : (" << i << ", " << j << ")\n";
        }else {
            return board[i][j];
       }
    }


    //takes the board as an argument, and prints it out using the standard iostream
    //print_Chessboard(board)
    void const print_Chessboard(std::array<std::array<int, 8>, 8> &board) {
        std::cout << "The Chessboard looks like this:";
        for (int i = 7; i >= 0; i--) {
            std::cout << "\n";
            for (int j = 0; j < 8; j++) {
                if (board[i][j] < 0){
                    std::cout << board[i][j] << " ";
                }else {
                    std::cout << " " << board[i][j] << " ";
                }
            }
        }
        std::cout << "\n";
    }

    bool is_same_color(int num1, int num2){
        if ((num1 > 0 && num2> 0) || (num1 < 0 && num2 < 0)){
            return true;
        }
        else return false;
    }
};


