/**
\file game.c
\author Theo Seng
\version 1.0
\date December 23, 2023
\brief Contains the functions linked to the structure Game
*/

#include "game.h"

/**
\fn Game createGame(int size_board,int N_boat)
\author Theo Seng
\version 1.0
\date December 23, 2023
\brief Create a Game entity according to the parameters given
\param N_boat Number of Boat in the Game for each side
\return Game entity
*/
Game createGame(int size_board,int N_boat){
    Board b1;
    Board b2;
    b1=initBoard(size_board);
    b2=initBoard(size_board);

    
    Boat* t1=NULL;
    Boat* t2=NULL;
    t1=malloc(N_boat*sizeof(Boat));
    if(t1==NULL){
        printf("malloc error");
        exit(1);
    }
    t2=malloc(N_boat*sizeof(Boat));
    if(t2==NULL){
        printf("malloc error");
        exit(2);
    }

    int n=0;
    Boat boat;
    while(n<N_boat){
        boat.size=-1;
        while(boat.size==-1){
            int x;
            int y;
            int o;

            x=rand()%size_board;
            y=rand()%size_board;
            o=rand()%2;

            boat=createBoat(2+n,x,y,o,b1);
        }
        t1[n]=boat;
        addBoat(b1,boat);
        n=n+1;
        printf("Placed %d boats out of %d\n",n,N_boat*2);
    }
    n=0;
    while(n<N_boat){
        boat.size=-1;
        while(boat.size==-1){
            int x;
            int y;
            int o;

            x=rand()%size_board;
            y=rand()%size_board;
            o=rand()%2;

            boat=createBoat(2+n,x,y,o,b2);
        }
        t2[n]=boat;
        addBoat(b2,boat);
        n=n+1;
        printf("Placed %d boats out of %d\n",n+N_boat,N_boat*2);
    }


    Game g;
    g.b1=b1;
    g.b2=b2;
    g.tab1=t1;
    g.tab2=t2;

    return g;
}

/**
\fn int turnPlayer(Game g)
\author Theo Seng
\version 1.0
\date December 23, 2023
\brief The function that handle the Player's turn
\return 1 if the player shot to let the main function know that it's the CPU's turn
\return 2 if the player displayed their board
\return 3 if the player displayed the CPU's board
\return 4 if the player wants to quit the game
*/
int turnPlayer(Game g){
    int res=0;
    int mode=0;
    printf("What will you do?\n");
    printf("[1]Shoot\n");
    printf("[2]Look at your board\n");
    printf("[3]Look at the CPU's board\n");
    printf("[4]Quit the game\n");
    while(res!=1||((mode!=1)&&(mode!=2)&&(mode!=3)&&(mode!=4))){
        res=scanf("%d",&mode);
    }
    if(mode==1){
        res=0;
        int x=-1;
        int y=-1;
        Board board;
        board=g.b2;

        printf("Input the x coordinate :");
        while(res!=1||x<0||x>(board.size-1)){
            res=scanf("%d",&x);
        }
        printf("Input the y coordinate :");
        while(res!=1||y<0||y>(board.size-1)){
            res=scanf("%d",&y);
        }

        printf("You are going to attempt to shot (%d,%d)\n",x,y);
        shootBoat(g.b2,x,y);
        return 1;
    }
    else if(mode==2){
        displayBoard(g.b1,1);
        return 2;    
    }
    else if(mode==3){
        displayBoard(g.b2,2);
        return 3;    
    }
    else if(mode==4){
        return 4;
    }
}
/**
\fn int turnCPU(Game g)
\author Theo Seng
\version 1.0
\date December 23, 2023
\brief The function that handle the CPU's turn
*/
void turnCPU(Game g){
    printf("\n");
    printf("**CPU's turn**\n");
    Board board;
    board=g.b1;
    int size;
    size=board.size;
    
    int x;
    int y;
    x=rand()%size;
    y=rand()%size;

    Tile tile;
    tile=board.p[x][y];

    while(tile!=WATER&&tile!=BOAT){
        x=rand()%size;
        y=rand()%size;
        tile=board.p[x][y];
    }

    printf("The CPU is going to attempt to shot (%d,%d)\n",x,y);
    shootBoat(g.b1,x,y);
}
