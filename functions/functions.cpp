#include <iostream>
#include "functions.hpp"

bool is_in_bounds(const int x, const int y) {
    if ((x >= 0) && (x <= 7) && (y >= 0) && (y <= 7)) {
        return true;
    }
    std::cerr << "[DEBUG] Referenced square fell out of bounds, coordinates (" << x << ", " << y << "). Returning \"False\"..." << std::endl;
    return false;
}

std::string file_to_str(int file){
    if(file==0){return "A";}
    if(file==1){return "B";}
    if(file==2){return "C";}
    if(file==3){return "D";}
    if(file==4){return "E";}
    if(file==5){return "F";}
    if(file==6){return "G";}
    if(file==7){return "H";}
    std::cerr << "argument for file (" << file << ") fell outside of specified range (0-7 inclusive)!";
    return "err";
}