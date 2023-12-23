/**
\file struct.h
\author Theo Seng
\version 1.0
\date December 23, 2023
\brief Contains all the enumerations, structures and base library for this project
*/

#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
\enum Tile
\date December 23,2023
\brief List of all possible states a Tile can be 
*/
typedef enum{
    WATER,
    WATER_SHOT,
    BOAT,
    WRECK,
}Tile;
/**
\enum Orientation
\date December 23,2023
\brief Used to see if a Boat is HORINZONTAL or VERTICAL
*/
typedef enum{
    HORIZONTAL,
    VERTICAL,
}Orientation;
/**
\struct Boat
\date December 23,2023
\brief A structure for the boats in this game of Battleship.
\var x_ref is the x coordonate of the leftmost tile
\var y_ref is the y coordonate of the upmost tile
*/
typedef struct{
    int size;
    int x_ref;
    int y_ref;
    Orientation orientation;
}Boat;
/**
\struct Board
\date December 23,2023
\brief A structure for the boards in this game of Battleship.
\var p is table of the same size as the variable size in the structure Board with each value being a table of the same size as the variable size.
*/
typedef struct{
    Tile** p;
    int size;
}Board;
/**
\struct Game
\date December 23,2023
\brief A structure that has every relevant information for playing a game of Battleship.
\var b1 is the Board of the player.
\var b2 is the Board of the CPU.
\var tab1 is a table containing every Boat of the player.
\var tab2 is a table containing every Boat of the CPU.
*/
typedef struct{
    Board b1;
    Board b2;
    Boat* tab1;
    Boat* tab2;
}Game;
#endif
