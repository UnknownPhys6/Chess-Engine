#include <array>
#include <iostream>
#include <vector>

/*TODO
 *stuff idk
 *
 *
 */


class Chess {
    public:
        //set up an array for the board, and vectors to store board states
        std::array<std::array<int, 8> , 8> board;
        std::vector<std::array<std::array<int, 8> , 8>> possible_moves;
        std::vector<std::array<std::array<int, 8> , 8>> legal_moves;


        //is_in_bounds(x, y);
        //returns true or false based on whether the input coords are in-bounds.
        [[nodiscard]] bool is_in_bounds(const int x, const int y) const {
            if (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
                return true;
            }
            return false;
        }

        //prints the board out to the screen
        //takes no arguments
        void print_Chessboard() const {
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

        //clears the chessboard to all 0s. Takes no arguments
        void clear_Chessboard() {
            std::fill(&board[0][0], &board[0][0]+64, 0);
        };

        //Sets up the Chessboard in the standard position
        //takes one argument.
        //set_up_Chessboard("arg")
        void set_up_Chessboard(const std::string& position) {
            if (position == "standard") {
                board = {
                     {                                     //X (first)
                         { 4,  2,  3,  5,  6,  3,  2,  4}, //0
                         { 1,  1,  1,  1,  1,  1,  1,  1}, //1
                         { 0,  0,  0,  0,  0,  0,  0,  0}, //2
                         { 0,  0,  0,  0,  0,  0,  0,  0}, //3
                         { 0,  0,  0,  0,  0,  0,  0,  0}, //4
                         { 0,  0,  0,  0,  0,  0,  0,  0}, //5
                         {-1, -1, -1, -1, -1, -1, -1, -1}, //6
                         {-4, -2, -3, -5, -6, -3, -2, -4}, //7
                     }
                };//Y  0   1   2   3   4   5   6   7
            }
            if (position == "test") {
                board = {
                    {                                     //X (first)
                        { 0,  0,  0,  0,  0,  0,  0,  0}, //0
                        { 0,  0,  0,  0,  0,  0,  0,  0}, //1
                        { 0,  0,  0,  0,  0,  1,  0,  0}, //2
                        { 0,  0,  0,  0,  0,  0,  0,  0}, //3
                        { 0,  0,  0,  3,  0,  0,  0,  0}, //4
                        { 0,  0,  0,  0,  0,  0,  0,  0}, //5
                        { 0,  0,  0,  0,  0, -1,  0,  0}, //6
                        { 0,  0,  0,  0,  0,  0,  0,  0}, //7
                    }
                };   //Y  0   1   2   3   4   5   6   7
            }
        };

        //Takes (x,y) coords for args.
        //Gets the piece of a given square with OOB checking
        [[nodiscard]] int get_piece (const int i, const int j) const {
            if (!is_in_bounds(i, j)) {
                std::cout << "Invalid Chessboard index : (" << i << ", " << j << ")\n";
            }else {
                return board[i][j];
            }
        }

        //record_temp_move(x1, y1, x2, y2);
        //moves piece from first set of coords to second set of coords. Checks for OOB errors.
        void record_temp_move (const int x1, const int y1, const int x2, const int y2){
            if (x1 < 0 || x1 >= 8 || y1 < 0 || y1 >= 8 || x2 < 0 || x2 >= 8 || y2 < 0 || y2 >= 8) {
                std::cout << "Invalid Chessboard index : (" << x1 << ", " << y1 << ") or (" << x2 << ", " << y2 << ")\n";
            }else {
                int piece_holder = get_piece(x2, y2);
                board[x2][y2] = get_piece(x1, y1);
                board[x1][y1] = 0;
                print_Chessboard();
                possible_moves.push_back(board);
                board[x1][y1] = get_piece(x2, y2);
                board[x2][y2] = piece_holder;
            }
        }

        //-object.set_square(x, y, value)
        //-sets a square to the specified value
        //-has OOB detection
        void set_square(const int x, const int y, const int value) {
            if (x < 0 || x > 7 || y < 0 || y > 7) {
                std::cout << "Invalid Chessboard index : (" << x << ", " << y << ")\n";
            }else {
                board[x][y] = value;
            }
        }

        //Black Pawn
        //records moves to possible_moves
        //requires no arguments.
        void list_White_Pawn_Moves() {
            int piece_holder;
            for(int i=0; i<8; i++) {
                for(int j=0; j<8; j++) {
                    if(board[i][j] == 1) {
                        if (i == 1) {
                            if (board[i+1][j] == 0) {
                                record_temp_move (i, j, i+1, j);
                            }
                            if (board[i+1][j] == 0 && board[i+2][j] == 0) {
                                record_temp_move (i, j, i+2, j);
                            }
                            if (board[i+1][j+1] < 0) {
                                record_temp_move (i, j, i+1, j+1);
                            }
                            if (board[i+1][j-1] < 0) {
                                record_temp_move (i, j, i+1, j-1);
                            }
                        }
                    }
                }
            }
        }

        //White Knight
        //records moves to possible_moves
        //requires no arguments.
        void list_White_Knight_Move() {
             for (int i=0; i<8; i++) {
                for (int j=0; j<8; j++) {
                    if (board[i][j] == 2) {
                        if (board[i+1][j+2] < 0) {
                            record_temp_move (i, j, i+1, j+2);
                        }
                        if (board[i+1][j-2] < 0) {
                            record_temp_move (i, j, i+1, j-2);
                        }
                        if (board[i-1][j+2] < 0) {
                            record_temp_move (i, j, i-1, j+2);
                        }
                        if (board[i-1][j-2] < 0) {
                            record_temp_move (i, j, i-1, j-2);
                        }
                        if (board[i+2][j+1] < 0) {
                            record_temp_move (i, j, i+2, j+1);
                        }
                        if (board[i+2][j-1] < 0) {
                            record_temp_move (i, j, i+2, j-1);
                        }
                        if (board[i-2][j+1] < 0) {
                            record_temp_move (i, j, i-2, j+1);
                        }
                        if (board[i-2][j-1] < 0) {
                            record_temp_move (i, j, i-2, j-1);
                        }
                    }
                }
            }
        }

        //White Bishop
        //currently bugged
        void list_White_Bishop_Moves() {
            for ( int x=0; x<8; x++) {
                for (int y=0; y<8; y++) {
                    if (board[x][y] == 3) {
                        //loop for range of attempted move
                        for (int distance=1; distance<7; distance++) {
                            //if square is empty, record possible move
                            if (board[x+distance][y+distance] == 0) {
                                record_temp_move (x, y, x+distance, y+distance);
                            }
                            //if square has black piece, record capture and break loop
                            if (board[x+distance][y+distance] < 0) {
                                record_temp_move (x, y, x+distance, y+distance);
                                break;
                            }
                            //if square has white piece, break loop for direction.
                            if (board[x+distance][y+distance] > 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            //if square is empty, record possible move
                            if (board[x+distance][y-distance] == 0) {
                                record_temp_move (x, y, x+distance, y-distance);
                            }
                            //if square has black piece, record capture and break loop
                            if (board[x+distance][y-distance] < 0) {
                                record_temp_move (x, y, x+distance, y-distance);
                                break;
                            }
                            //if square has white piece, break loop for direction.
                            if (board[x+distance][y-distance] > 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            //if square is empty, record possible move
                            if (board[x-distance][y+distance] == 0) {
                                record_temp_move (x, y, x-distance, y+distance);
                            }
                            //if square has black piece, record capture and break loop
                            if (board[x-distance][y+distance] < 0) {
                                record_temp_move (x, y, x-distance, y+distance);
                                break;
                            }
                            //if square has white piece, break loop for direction.
                            if (board[x-distance][y+distance] > 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            //if square is empty, record possible move
                            if (board[x-distance][y-distance] == 0) {
                                record_temp_move (x, y, x-distance, y-distance);
                            }
                            //if square has black piece, record capture and break loop
                            if (board[x-distance][y-distance] < 0) {
                                record_temp_move (x, y, x-distance, y-distance);
                                break;
                            }
                            //if square has white piece, break loop for direction.
                            if (board[x-distance][y-distance] > 0) {
                                break;
                            }
                        }
                    }
                }
            }
        }


};


int main(){
    //begin the fun stuff
    Chess game1{};
    game1.set_up_Chessboard("test");
    std::cout << "Chessboard looks like this before any schenanagins:" << std::endl;
    game1.print_Chessboard();
    game1.list_White_Bishop_Moves();
    std::cout << "Chessboard ending position" << std::endl;
    game1.print_Chessboard();
    return 0;
}