#pragma once

#include <string>

enum Team {
    White,
    Black,
    Neither
};

//returns true if both args are above or below 0.
//returns False if either arg is 0, or if one is pos and the other is neg.
//is_same_color(a, b)
bool is_same_color(int a, int b);

//returns true if args are opposite sides of 0.
//differs from negation of is_same_color because one or both args being 0 still returns false
bool is_different_color(int a, int b);

//returns 1 for white, and -1 for black.
int turn_team_to_int(Team turn);

//takes a Team and returns that word as a string.
std::string turn_team_to_string(Team team);

//takes in an int, returns white if num > 0, and black if num < 0
Team get_color(int num);

//same as get_color, but returns at as a string. eg "white" instead of white.
std::string get_color_string(int num);

//takes in white an returns black, or vice-versa
Team get_opposite_team(Team turn);
