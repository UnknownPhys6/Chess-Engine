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