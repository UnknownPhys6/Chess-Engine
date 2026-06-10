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
        //set up an array for the board and en-passant board, and vectors to store board states
        std::array<std::array<int, 8> , 8> board;
        std::array<std::array<int, 8> , 8> enPassantBoard;
        std::vector<std::array<std::array<int, 8> , 8>> possible_moves;
        std::vector<std::array<std::array<int, 8> , 8>> legal_moves;


        //is_in_bounds(x, y);
        //returns true or false based on whether the input coords are in-bounds.
        [[nodiscard]] static  bool is_in_bounds(const int x, const int y) {
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
        void set_up_Chessboards(const std::string& position) {
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
                     }//Y  0   1   2   3   4   5   6   7
                };
            }
            if (position == "test") {
                board = {
                    {                                     //X (first)
                        { 0,  0,  0,  0,  0,  0,  0,  0}, //0
                        { 0,  0,  0,  0,  0,  0,  0,  0}, //1
                        { 0,  0,  0,  0,  0,  0,  0,  0}, //2
                        { 0,  0,  0,  1, -1,  0,  0,  0}, //3
                        { 0,  0,  0,  0,  0,  0,  0,  0}, //4
                        { 0,  0,  0,  0,  0,  0,  0,  0}, //5
                        { 0,  0,  0,  0,  0,  0,  0,  0}, //6
                        { 0,  0,  0,  0,  0,  0,  0,  0}, //7
                    }//Y  0   1   2   3   4   5   6   7
                };
            }
        };


        //initialize enPassantBoard to all 0s
        void initialize_enPassantBoard() {
            enPassantBoard = {
                {
                    { 0,  0,  0,  0,  0,  0,  0,  0}, //0
                    { 0,  0,  0,  0,  0,  0,  0,  0}, //1
                    { 0,  0,  0,  1,  0,  0,  0,  0}, //2
                    { 0,  0,  0,  0,  0,  0,  0,  0}, //3
                    { 0,  0,  0,  0,  0,  0,  0,  0}, //4
                    { 0,  0,  0,  0,  0,  0,  0,  0}, //5
                    { 0,  0,  0,  0,  0,  0,  0,  0}, //6
                    { 0,  0,  0,  0,  0,  0,  0,  0}, //7
                }
            };
        }

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
                const int piece_holder = get_piece(x2, y2);
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

        //scrubs the en-passant board of the specified piece. Use only 1 or -1 here,
        //as those correspond to white and black pawn en-passants respectively
        //ex: scrub_En_Passant_Board(1);
        void scrub_En_Passant_Board(const int& piece) {
            for (int x=0; x<8; x++) {
                for (int y=0; y<8; y++) {
                    if (enPassantBoard[x][y] == piece) {
                        enPassantBoard[x][y] = 0;
                    }
                }
            }
        }

        //Pawn WIP
        //ex: list_White_Pawn_Moves();
        void list_White_Pawn_Moves() {
            for(int x=0; x<8; x++) {
                for(int y=0; y<8; y++) {
                    if(board[x][y] == 1) {
                        //move 1 space
                        if (board[x+1][y] == 0) {
                            record_temp_move (x, y, x+1, y);
                        }
                        //move 2 spaces
                        if (x==1 && board[x+1][y] == 0 && board[x+2][y] == 0) {
                            record_temp_move (x, y, x+2, y);
                            enPassantBoard[x+1][y] = 1;
                        }
                        //capture diagonally
                        if (board[x+1][y+1] < 0) {
                            record_temp_move (x, y, x+1, y+1);
                        }
                        //capture diagonally
                        if (board[x+1][y-1] < 0) {
                            record_temp_move (x, y, x+1, y-1);
                        }
                        //en-passant
                        if (board[x][y+1] == -1 && enPassantBoard[x+1][y+1] == -1) {
                            board[x+1][y+1] = 1;
                            board[x][y] = 0;
                            board[x][y+1] = 0;
                            possible_moves.push_back(board);
                            board[x][y] = 1;
                            board[x][y+1] = -1;
                            board[x+1][y+1] = 0;
                        }
                        if (board[x][y-1] == -1 && enPassantBoard[x+1][y-1] == -1) {
                            board[x+1][y-1] = 1;
                            board[x][y] = 0;
                            board[x][y-1] = 0;
                            possible_moves.push_back(board);
                            board[x][y] = 1;
                            board[x][y-1] = -1;
                            board[x+1][y-1] = 0;
                        }
                    }
                }
            }
        }
        //ex: list_Black_Pawn_Moves();
        void list_Black_Pawn_Moves() {
            for(int x=0; x<8; x++) {
                for(int y=0; y<8; y++) {
                    if(board[x][y] == -1) {
                        //move 1 space
                        if (board[x-1][y] == 0) {
                            record_temp_move (x, y, x-1, y);
                        }
                        //move 2 spaces
                        if (x == 6 && board[x-1][y] == 0 && board[x-2][y] == 0) {
                            record_temp_move (x, y, x+2, y);
                            enPassantBoard[x-1][y] = -1;
                        }
                        //capture diagonally
                        if (board[x-1][y+1] < 0) {
                            record_temp_move (x, y, x-1, y+1);
                        }
                        //capture diagonally
                        if (board[x-1][y-1] < 0) {
                            record_temp_move (x, y, x-1, y-1);
                        }
                        //en-passant
                        if (board[x][y+1] == 1 && enPassantBoard[x-1][y+1] == 1) {
                            board[x-1][y+1] = -1;
                            board[x][y] = 0;
                            board[x][y+1] = 0;
                            possible_moves.push_back(board);
                            board[x][y] = -1;
                            board[x][y+1] = 1;
                            board[x-1][y+1] = 0;
                        }
                        if (board[x][y-1] == 1 && enPassantBoard[x-1][y-1] == 1) {
                            board[x-1][y-1] = -1;
                            board[x][y] = 0;
                            board[x][y-1] = 0;
                            possible_moves.push_back(board);
                            board[x][y] = -1;
                            board[x][y-1] = 1;
                            board[x-1][y-1] = 0;
                        }
                    }
                }
            }
        }

        //White Knight
        //ex: list_White_Knight_Move();
        void list_White_Knight_Moves() {
             for (int i=0; i<8; i++) {
                 for (int j=0; j<8; j++) {
                     if (board[i][j] == 2) {
                         if (board[i+1][j+2] <= 0) {
                             record_temp_move (i, j, i+1, j+2);
                         }
                         if (board[i+1][j-2] <= 0) {
                             record_temp_move (i, j, i+1, j-2);
                         }
                         if (board[i-1][j+2] <= 0) {
                             record_temp_move (i, j, i-1, j+2);
                         }
                         if (board[i-1][j-2] <= 0) {
                             record_temp_move (i, j, i-1, j-2);
                         }
                         if (board[i+2][j+1] <= 0) {
                             record_temp_move (i, j, i+2, j+1);
                         }
                         if (board[i+2][j-1] <= 0) {
                             record_temp_move (i, j, i+2, j-1);
                         }
                         if (board[i-2][j+1] <= 0) {
                             record_temp_move (i, j, i-2, j+1);
                         }
                         if (board[i-2][j-1] <= 0) {
                             record_temp_move (i, j, i-2, j-1);
                         }
                    }
                }
            }
        }
        //ex: list_Black_Knight_Move();
        void list_Black_Knight_Moves() {
            for (int i=0; i<8; i++) {
                for (int j=0; j<8; j++) {
                    if (board[i][j] == -2) {
                        if (board[i+1][j+2] >= 0) {
                            record_temp_move (i, j, i+1, j+2);
                        }
                        if (board[i+1][j-2] >= 0) {
                            record_temp_move (i, j, i+1, j-2);
                        }
                        if (board[i-1][j+2] >= 0) {
                            record_temp_move (i, j, i-1, j+2);
                        }
                        if (board[i-1][j-2] >= 0) {
                            record_temp_move (i, j, i-1, j-2);
                        }
                        if (board[i+2][j+1] >= 0) {
                            record_temp_move (i, j, i+2, j+1);
                        }
                        if (board[i+2][j-1] >= 0) {
                            record_temp_move (i, j, i+2, j-1);
                        }
                        if (board[i-2][j+1] >= 0) {
                            record_temp_move (i, j, i-2, j+1);
                        }
                        if (board[i-2][j-1] >= 0) {
                            record_temp_move (i, j, i-2, j-1);
                        }
                    }
                }
            }
        }

        //White Bishop
        //lists all the bishop moves
        //ex: list_White_Bishop_Moves();
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
        //ex: list_White_Bishop_Moves();
        void list_Black_Bishop_Moves() {
            for ( int x=0; x<8; x++) {
                for (int y=0; y<8; y++) {
                    if (board[x][y] == -3) {
                        //loop for range of attempted move
                        for (int distance=1; distance<7; distance++) {
                            //if square is empty, record possible move
                            if (board[x+distance][y+distance] == 0) {
                                record_temp_move (x, y, x+distance, y+distance);
                            }
                            //if square has black piece, record capture and break loop
                            if (board[x+distance][y+distance] > 0) {
                                record_temp_move (x, y, x+distance, y+distance);
                                break;
                            }
                            //if square has white piece, break loop for direction.
                            if (board[x+distance][y+distance] < 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x+distance][y-distance] == 0) {
                                record_temp_move (x, y, x+distance, y-distance);
                            }
                            if (board[x+distance][y-distance] > 0) {
                                record_temp_move (x, y, x+distance, y-distance);
                                break;
                            }
                            if (board[x+distance][y-distance] < 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x-distance][y+distance] == 0) {
                                record_temp_move (x, y, x-distance, y+distance);
                            }
                            if (board[x-distance][y+distance] > 0) {
                                record_temp_move (x, y, x-distance, y+distance);
                                break;
                            }
                            if (board[x-distance][y+distance] < 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x-distance][y-distance] == 0) {
                                record_temp_move (x, y, x-distance, y-distance);
                            }
                            if (board[x-distance][y-distance] > 0) {
                                record_temp_move (x, y, x-distance, y-distance);
                                break;
                            }
                            if (board[x-distance][y-distance] < 0) {
                                break;
                            }
                        }
                    }
                }
            }
        }

        //White Rook
        //Lists possible rook moves
        //ex: list_White_Rook_Moves();
        void list_White_Rook_Moves() {
            for ( int x=0; x<8; x++) {
                for (int y=0; y<8; y++) {
                    if (board[x][y] == 4) {
                        //loop for range of attempted move
                        for (int distance=1; distance<7; distance++) {
                            //if square is empty, record possible move
                            if (board[x][y+distance] == 0) {
                                record_temp_move (x, y, x, y+distance);
                            }
                            //if square has black piece, record capture and break loop
                            if (board[x][y+distance] < 0) {
                                record_temp_move (x, y, x, y+distance);
                                break;
                            }
                            //if square has white piece, break loop for direction.
                            if (board[x][y+distance] > 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            //if square is empty, record possible move
                            if (board[x+distance][y] == 0) {
                                record_temp_move (x, y, x+distance, y);
                            }
                            //if square has black piece, record capture and break loop
                            if (board[x+distance][y] < 0) {
                                record_temp_move (x, y, x+distance, y);
                                break;
                            }
                            //if square has white piece, break loop for direction.
                            if (board[x+distance][y] > 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            //if square is empty, record possible move
                            if (board[x][y-distance] == 0) {
                                record_temp_move (x, y, x, y-distance);
                            }
                            //if square has black piece, record capture and break loop
                            if (board[x][y-distance] < 0) {
                                record_temp_move (x, y, x, y-distance);
                                break;
                            }
                            //if square has white piece, break loop for direction.
                            if (board[x][y-distance] > 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            //if square is empty, record possible move
                            if (board[x-distance][y] == 0) {
                                record_temp_move (x, y, x-distance, y);
                            }
                            //if square has black piece, record capture and break loop
                            if (board[x-distance][y] < 0) {
                                record_temp_move (x, y, x-distance, y);
                                break;
                            }
                            //if square has white piece, break loop for direction.
                            if (board[x-distance][y] > 0) {
                                break;
                            }
                        }
                    }
                }
            }
        }
        //ex: list_Black_Rook_Moves();
        void list_Black_Rook_Moves() {
            for ( int x=0; x<8; x++) {
                for (int y=0; y<8; y++) {
                    if (board[x][y] == -4) {
                        //loop for range of attempted move
                        for (int distance=1; distance<7; distance++) {
                            //if square is empty, record possible move
                            if (board[x][y+distance] == 0) {
                                record_temp_move (x, y, x, y+distance);
                            }
                            //if square has white piece, record capture and break loop
                            if (board[x][y+distance] > 0) {
                                record_temp_move (x, y, x, y+distance);
                                break;
                            }
                            //if square has black piece, break loop for direction.
                            if (board[x][y+distance] < 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x+distance][y] == 0) {
                                record_temp_move (x, y, x+distance, y);
                            }
                            if (board[x+distance][y] > 0) {
                                record_temp_move (x, y, x+distance, y);
                                break;
                            }
                            if (board[x+distance][y] < 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x][y-distance] == 0) {
                                record_temp_move (x, y, x, y-distance);
                            }
                            if (board[x][y-distance] > 0) {
                                record_temp_move (x, y, x, y-distance);
                                break;
                            }
                            if (board[x][y-distance] < 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x-distance][y] == 0) {
                                record_temp_move (x, y, x-distance, y);
                            }
                            if (board[x-distance][y] > 0) {
                                record_temp_move (x, y, x-distance, y);
                                break;
                            }
                            if (board[x-distance][y] < 0) {
                                break;
                            }
                        }
                    }
                }
            }
        }

        //Queen
        //ex: list_White_Queen_Moves();
        void list_White_Queen_Moves() {
            for (int x=0; x<8; x++) {
                for (int y=0; y<8; y++) {
                    if (board[x][y] == 5) {
                        //loop for range of attempted move
                        for (int distance=1; distance<7; distance++) {
                            //rook-like moves
                            //if square is empty, record possible move
                            if (board[x][y+distance] == 0) {
                                record_temp_move (x, y, x, y+distance);
                            }
                            //if square has black piece, record capture and break loop
                            if (board[x][y+distance] < 0) {
                                record_temp_move (x, y, x, y+distance);
                                break;
                            }
                            //if square has white piece, break loop for direction.
                            if (board[x][y+distance] > 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x+distance][y] == 0) {
                                record_temp_move (x, y, x+distance, y);
                            }
                            if (board[x+distance][y] < 0) {
                                record_temp_move (x, y, x+distance, y);
                                break;
                            }
                            if (board[x+distance][y] > 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x][y-distance] == 0) {
                                record_temp_move (x, y, x, y-distance);
                            }
                            if (board[x][y-distance] < 0) {
                                record_temp_move (x, y, x, y-distance);
                                break;
                            }
                            if (board[x][y-distance] > 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x-distance][y] == 0) {
                                record_temp_move (x, y, x-distance, y);
                            }
                            if (board[x-distance][y] < 0) {
                                record_temp_move (x, y, x-distance, y);
                                break;
                            }
                            if (board[x-distance][y] > 0) {
                                break;
                            }
                        }
                        //bishop-like moves
                        for (int distance=1; distance<7; distance++) {
                            if (board[x+distance][y+distance] == 0) {
                                record_temp_move (x, y, x+distance, y+distance);
                            }
                            if (board[x+distance][y+distance] < 0) {
                                record_temp_move (x, y, x+distance, y+distance);
                                break;
                            }
                            if (board[x+distance][y+distance] > 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x+distance][y-distance] == 0) {
                                record_temp_move (x, y, x+distance, y-distance);
                            }
                            if (board[x+distance][y-distance] < 0) {
                                record_temp_move (x, y, x+distance, y-distance);
                                break;
                            }
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
        //ex: list_Black_Queen_Moves();
        void list_Black_Queen_Moves() {
            for (int x=0; x<8; x++) {
                for (int y=0; y<8; y++) {
                    if (board[x][y] == -5) {
                        //loop for range of attempted move
                        for (int distance=1; distance<7; distance++) {
                            //rook-like moves
                            ////if square is empty, record possible move
                            if (board[x][y+distance] == 0) {
                                record_temp_move (x, y, x, y+distance);
                            }
                            //if square has white piece, record capture and break loop
                            if (board[x][y+distance] > 0) {
                                record_temp_move (x, y, x, y+distance);
                                break;
                            }
                            //if square has black piece, break loop for direction.
                            if (board[x][y+distance] < 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x+distance][y] == 0) {
                                record_temp_move (x, y, x+distance, y);
                            }
                            if (board[x+distance][y] > 0) {
                                record_temp_move (x, y, x+distance, y);
                                break;
                            }
                            if (board[x+distance][y] < 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x][y-distance] == 0) {
                                record_temp_move (x, y, x, y-distance);
                            }
                            if (board[x][y-distance] > 0) {
                                record_temp_move (x, y, x, y-distance);
                                break;
                            }
                            if (board[x][y-distance] < 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x-distance][y] == 0) {
                                record_temp_move (x, y, x-distance, y);
                            }
                            if (board[x-distance][y] > 0) {
                                record_temp_move (x, y, x-distance, y);
                                break;
                            }
                            if (board[x-distance][y] < 0) {
                                break;
                            }
                        }
                        //bishop-like moves
                        for (int distance=1; distance<7; distance++) {
                            if (board[x+distance][y+distance] == 0) {
                                record_temp_move (x, y, x+distance, y+distance);
                            }
                            if (board[x+distance][y+distance] > 0) {
                                record_temp_move (x, y, x+distance, y+distance);
                                break;
                            }
                            if (board[x+distance][y+distance] < 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x+distance][y-distance] == 0) {
                                record_temp_move (x, y, x+distance, y-distance);
                            }
                            if (board[x+distance][y-distance] > 0) {
                                record_temp_move (x, y, x+distance, y-distance);
                                break;
                            }
                            if (board[x+distance][y-distance] < 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x-distance][y+distance] == 0) {
                                record_temp_move (x, y, x-distance, y+distance);
                            }
                            if (board[x-distance][y+distance] > 0) {
                                record_temp_move (x, y, x-distance, y+distance);
                                break;
                            }
                            if (board[x-distance][y+distance] < 0) {
                                break;
                            }
                        }
                        for (int distance=1; distance<7; distance++) {
                            if (board[x-distance][y-distance] == 0) {
                                record_temp_move (x, y, x-distance, y-distance);
                            }
                            if (board[x-distance][y-distance] > 0) {
                                record_temp_move (x, y, x-distance, y-distance);
                                break;
                            }
                            if (board[x-distance][y-distance] < 0) {
                                break;
                            }
                        }
                    }
                }
            }
        }

        //lists white king moves
        void list_White_King_Moves() {
            for ( int x=0; x<8; x++) {
                for (int y=0; y<8; y++) {
                    if (get_piece(x,y) == 6) {
                        if (board[x][y+1] <= 0) {record_temp_move (x, y, x, y+1);}      //W1
                        if (board[x+1][y+1] <= 0) {record_temp_move (x, y, x+1, y+1);}  //W2
                        if (board[x+1][y] <= 0) {record_temp_move (x, y, x+1, y);}       //W3
                        if (board[x+1][y-1] <= 0) {record_temp_move (x, y, x+1, y-1);}  //W4
                        if (board[x][y-1] <= 0) {record_temp_move (x, y, x, y-1);}      //W5
                        if (board[x-1][y-1] <= 0) {record_temp_move (x, y, x-1, y-1);}  //W6
                        if (board[x-1][y] <= 0) {record_temp_move (x, y, x-1, y);}      //W7
                        if (board[x-1][y+1] <= 0) {record_temp_move (x, y, x-1, y+1);}  //W8
                    }
                }
            }
        }
        //lists black king moves
        void list_Black_King_Moves() {
            for ( int x=0; x<8; x++) {
                for (int y=0; y<8; y++) {
                    if (get_piece(x,y) == -6) {
                        if (board[x][y+1] >= 0) {record_temp_move (x, y, x, y+1);}
                        if (board[x=1][y=1] >= 0) {record_temp_move (x, y, x+1, y+1);}
                        if (board[x+1][y] >= 0) {record_temp_move (x, y, x+1, y);}
                        if (board[x+1][y-1] >= 0) {record_temp_move (x, y, x+1, y-1);}
                        if (board[x][y-1] >= 0) {record_temp_move (x, y, x, y-1);}
                        if (board[x-1][y-1] >= 0) {record_temp_move (x, y, x-1, y-1);}
                        if (board[x-1][y] >= 0) {record_temp_move (x, y, x-1, y);}
                        if (board[x-1][y+1] >= 0) {record_temp_move (x, y, x-1, y+1);}
                    }
                }
            }
        }

        //wraps up all the list piece moves into a single function
        void list_White_Moves() {
            list_White_Pawn_Moves();
            list_White_Knight_Moves();
            list_White_Bishop_Moves();
            list_White_Rook_Moves();
            list_White_Queen_Moves();
            list_White_King_Moves();
        }
        void list_Black_Moves() {
            list_Black_Pawn_Moves();
            list_Black_Knight_Moves();
            list_Black_Bishop_Moves();
            list_Black_Rook_Moves();
            list_Black_Queen_Moves();
            list_Black_King_Moves();
        }

};


int main(){
    //begin the fun stuff
    Chess game1{};
    game1.set_up_Chessboards("test");
    game1.initialize_enPassantBoard();
    std::cout << "Chessboard looks like this before any shenanigans:" << std::endl;
    game1.print_Chessboard();
    game1.list_White_Moves();
    std::cout << "Chessboard ending position" << std::endl;
    game1.print_Chessboard();
    return 0;
}