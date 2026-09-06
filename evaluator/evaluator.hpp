#include "../board_state/board_state.hpp"

class Evaluator {
    public:
        float find_handcrafted_eval();


        
        float evaluate_king_safety_ratio();     //determines how safe the king is
        float evaluate_piece_activity_ratio();  //determines how active the pieces are. Maybe by counting the number of moves, biasing towards captures?
        float evaluate_piece_safety_ratio();    //determines how safe the pieces are. Counts unguarded pieces, pieces attacked by enemy pieces of lower value, ect.
};