#ifndef BOAT_H
#define BOAT_H

#include "struct.h"
Boat createBoat(int size,int x,int y,Orientation o,Board b);

int isWrecked(Boat b, Board board);

int allWrecked(Boat* t,int N_boat, Board board);
#endif
