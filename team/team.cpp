#include <iostream>
#include "team.hpp"



bool is_same_color(int a, int b){
    if ((a > 0 && b > 0) || (a < 0 && b < 0)){
        return true;
    }
    else return false;
}

bool is_different_color(int a, int b){
    if ((a > 0 && b < 0) || (a < 0 && b > 0)){
        return true;
    }
    else{
        return false;
    }
}

int turn_team_to_int(Team turn){
    switch (turn){
        case Team::White:
            return 1;
        case Team::Black:
            return -1;
        case Team::Neither:
            return 0;
    }
    std::cout << "turn_enum_to_int() " << "recieved bad input and was forced to return \"11\"." << std::endl;
    return 11;
}

std::string turn_team_to_string(Team turn){
    switch (turn){
        case Team::White:
            return "White";
        case Team::Black:
            return "Black";
        case Team::Neither:
            return "Neither";
    }
    std::cout << "turn_enum_to_string() " << "recieved bad input and was forced to return \"Error\"." << std::endl;
    return "Error";
}

Team get_color(int num){
    if ( num > 0){
        return Team::White;
    }
    if (num < 0){
        return Team::Black;
    }
    return Team::Neither;
}

std::string get_color_string(int num){
    if ( num > 0){
        return "white";
    }
    if (num < 0){
        return "black";
    }
    return "neither";
}

Team get_opposite_team(Team turn){
    if (turn == White){
        return Team::Black;
    }
    else if (turn == Black){
        return Team::White;
    }
    else{
        return Team::Neither;//should never run hopefully
    }
}