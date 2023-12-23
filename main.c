/**
\file main.c
\author Theo Seng
\version 1.0
\date December 23, 2023
\brief Contains the main function for a Battleship game
*/


#define NB_BOAT 3
#define SIZE_BOARD 6
#include "game.h"


/**
\fn int main()
\author Theo Seng
\version 1.0
\date December 23, 2023
\brief The main function for a Battleship game
\return 0 if main function executated proprely
*/
int main(){
    printf("Battleship\n");
    srand(time(NULL));
    Game g;
    g=createGame(SIZE_BOARD,NB_BOAT);
    int cleared=0;
    int mode=0;
    while(cleared!=1&&cleared!=2){
        printf("\n");
        printf("**Player's turn**\n");
        while(mode!=1){
            mode=turnPlayer(g);

            if(mode==4){
                for(int i=0;i<SIZE_BOARD;i++){
                    free(g.b1.p[i]);
                    free(g.b2.p[i]);
                }
                free(g.b1.p);
                free(g.b2.p);
                free(g.tab1);
                free(g.tab2);
                return 0;
            }

        }
        mode=0;
        if(allWrecked(g.tab2,NB_BOAT,g.b2)==1){
            cleared=1;
        }


        else{
            turnCPU(g);
            if(allWrecked(g.tab1,NB_BOAT,g.b1)==1){
                cleared=2;
            }
        }
    }

    if(cleared==1){
        printf("*****YOU WON!!!*****\n");
    }
    else if(cleared==2){
        printf("The CPU won. What a shame.\n");
    }


    for(int i=0;i<SIZE_BOARD;i++){
        free(g.b1.p[i]);
        free(g.b2.p[i]);
    }
    free(g.b1.p);
    free(g.b2.p);
    free(g.tab1);
    free(g.tab2);

    return 0;
}
