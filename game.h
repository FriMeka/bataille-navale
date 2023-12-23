#ifndef GAME_H
#define GAME_H

#include "struct.h"
#include "boat.h"
#include "board.h"
Game createGame(int size_board,int N_boat);

int turnPlayer(Game g);
    
void turnCPU(Game g);
#endif
