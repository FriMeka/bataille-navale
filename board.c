/**
\file board.c
\author Theo Seng
\version 1.0
\date December 23, 2023
\brief Contains the functions linked to the structure Board
*/

#include "board.h"

/**
\fn Board initBoard(int size_board)
\author Theo Seng
\version 1.0
\date December 23, 2023
\brief Function that returns a clean board
\return Board with all Tile being WATER
*/
Board initBoard(int size_board){
    Board b;
    Tile** p=NULL;
    
    p=malloc(size_board*sizeof(Tile*));
    if(p==NULL){
        printf("malloc error");
        exit(1);
    }

    for(int i=0;i<size_board;i++){
        p[i]=malloc(size_board*sizeof(Tile));
        if(p[i]==NULL){
            printf("malloc error");
            exit(2);
        }
    }
    
    for(int i=0;i<size_board;i++){
        for(int j=0;j<size_board;j++){
            p[i][j]=WATER;
        }
    }
    b.size=size_board;
    b.p=p;
    return b;
}

/**
\fn void addBoat(Board board,Boat b)
\author Theo Seng
\version 1.0
\date December 23, 2023
\brief Function that adds a Boat to the Board (changes the according Tiles of the Board by BOAT Tile)
*/
void addBoat(Board board,Boat b){
    int x;
    int y;
    int size;
    x=b.x_ref;
    y=b.y_ref;
    size=b.size;
    
    if(size<=0||x<0||y<0){
        printf("this boat is not valid");
        exit(11);
    }

    if(b.orientation==HORIZONTAL){
        if((x+size)>board.size){
            printf("this boat is not valid");
            exit(12);
        }

        for(int i=0;i<size;i++){
            board.p[x+i][y]=BOAT;
        }
    }
    else{
        if((y+size)>board.size){
            printf("this boat is not valid");
            exit(13);
        }

        for(int i=0;i<size;i++){
            board.p[x][y+i]=BOAT;
        }
    }
}

/**
\fn void shootBoat(Board board,int x,int y)
\author Theo Seng
\version 1.0
\date December 23, 2023
\brief Function that checks the content of board.p[x][y] and changes it to WRECK if this Tile is BOAT or to WATER_SHOT if it's WATER
*/
void shootBoat(Board board,int x,int y){
    if(x<0||y<0||x>(board.size-1)||y>(board.size-1)){
        printf("this move is impossible");
        exit(21);
    }
    
    Tile tile;
    tile=board.p[x][y];
    if(tile==BOAT){
        printf("->It's a hit!\n");
        board.p[x][y]=WRECK;
    }
    else{
        printf("->Missed!\n");   
        if(tile==WATER){
            board.p[x][y]=WATER_SHOT;
        }
    }
}

/**
\fn void displayTile_Player(Tile t)
\author Theo Seng
\version 1.0
\date December 23, 2023
\brief Function that prints the corresponding emoji according to the Tile
*/
void displayTile_Player(Tile t){
    if(t==WATER){
        printf("%2s","🌊");
    }
    else if(t==WATER_SHOT){
        printf("%2s","❌");
    }
    else if(t==BOAT){
        printf("%2s","🚢");
    }
    else if(t==WRECK){
        printf("%2s","💥");
    }
}

/**
\fn void displayTile_CPU(Tile t)
\author Theo Seng
\version 1.0
\date December 23, 2023
\brief Function that prints the corresponding emoji according to the Tile but hides BOAT to the player by showing WATER
*/
void displayTile_CPU(Tile t){
    if(t==WATER){
        printf("%2s","🌊");
    }
    else if(t==WATER_SHOT){
        printf("%2s","❌");
    }
    else if(t==BOAT){
        printf("%2s","🌊");
    }
    else if(t==WRECK){
        printf("%2s","💥");
    }
}

/**
\fn void displayBoard(Board b,int player)
\author Theo Seng
\version 1.0
\date December 23, 2023
\brief Function that displays a player's Board or a CPU's Board
\param player is either 1 (Player) or 2 (CPU)
*/
void displayBoard(Board b,int player){
    if(player==1){
        printf("X 0");
        for(int i=1;i<b.size;i++){
            printf("%2d",i);
        }
        printf("\n");

        for(int i=0;i<b.size;i++){
            printf("%d ",i);
            for(int j=0;j<b.size;j++){
                displayTile_Player(b.p[j][i]);
            }
            printf("\n");
        }
    }
    else if(player==2){
        printf("X 0");
        for(int i=1;i<b.size;i++){
            printf("%2d",i);
        }
        printf("\n");

        for(int i=0;i<b.size;i++){
            printf("%d ",i);
            for(int j=0;j<b.size;j++){
                displayTile_CPU(b.p[j][i]);
            }
            printf("\n");
        }
    }
    else{
        printf("not a valid value for player for the displayBoard function");
    }
}
