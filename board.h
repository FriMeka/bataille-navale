#ifndef BOARD_H
#define BOARD_H
#include "struct.h"

Board initBoard(int size_board);

void addBoat(Board board,Boat b);

void shootBoat(Board board,int x,int y);

void displayBoard(Board b,int player);

void displayTile_Player(Tile t);

void displayTile_CPU(Tile t);

#endif
