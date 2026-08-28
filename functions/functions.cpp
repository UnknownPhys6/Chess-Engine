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
    if(file==0){return "a";}
    if(file==1){return "b";}
    if(file==2){return "c";}
    if(file==3){return "d";}
    if(file==4){return "e";}
    if(file==5){return "f";}
    if(file==6){return "g";}
    if(file==7){return "h";}
    std::cerr << "argument for file (" << file << ") fell outside of specified range (0-7 inclusive)!";
    return "err";
}