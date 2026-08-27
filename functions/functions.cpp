#include <iostream>
#include "functions.hpp"

bool is_in_bounds(const int x, const int y) {
    if ((x >= 0) && (x <= 7) && (y >= 0) && (y <= 7)) {
        return true;
    }
    std::cerr << "[DEBUG] Referenced square fell out of bounds, coordinates (" << x << ", " << y << "). Returning \"False\"..." << std::endl;
    return false;
}
