/**
\file boat.c
\author Theo Seng
\version 1.0
\date December 23, 2023
\brief Contains the functions linked to the structure Boat
*/

#include "boat.h"

/**
\fn Boat createBoat(int size,int x,int y,Orientation o,Board b)
\author Theo Seng
\version 1.0
\date December 23, 2023
\brief Create a Boat entity according to the parameters given
\return a Boat with negative size if the parameters are wrong or if it's overlapping with an another Boat
*/
Boat createBoat(int size,int x,int y,Orientation o,Board b){
    Boat boat;
    
    boat.size=-1;

    if(size<=0||x<0||y<0){
        printf("wrong parameters\n");
        return boat;
    }
    

    if(o==HORIZONTAL){
        if((x+size)<=b.size){
            for(int i=0;i<size;i++){
                if((b.p[x+i])[y]==BOAT||(b.p[x+i])[y]==WRECK){
                    return boat;
                }
            }
            boat.size=size;
            boat.x_ref=x;
            boat.y_ref=y;
            boat.orientation=o;
        }
        else{
            return boat;
        }
    }
    else{
        if((y+size)<=b.size){
            for(int i=0;i<size;i++){
                if((b.p[x])[y+i]==BOAT||(b.p[x])[y+i]==WRECK){
                    return boat;
                }
            }
            boat.size=size;
            boat.x_ref=x;
            boat.y_ref=y;
            boat.orientation=o;
        }
        else{
            return boat;
        }
    }
    return boat;
}

/**
\fn int isWrecked(Boat b, Board board)
\author Theo Seng
\version 1.0
\date December 23, 2023
\brief Boolean function that test if a Boat is completly wrecked
\return 1 if it's wrecked
\return 0 otherwise
*/
int isWrecked(Boat b, Board board){
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
            Tile tile;
            tile=board.p[x+i][y];
            if(tile!=WRECK){
                return 0;
            }
        }
    }
    else{
        if((y+size)>board.size){
            printf("this boat is not valid");
            exit(13);
        }

        for(int i=0;i<size;i++){
            Tile tile;
            tile=board.p[x][y+i];
            if(tile!=WRECK){
                return 0;
            }
        }
    }
    return 1;
}

/**
\fn int isWrecked(Boat b, Board board)
\author Theo Seng
\version 1.0
\date December 23, 2023
\brief Boolean function that test if all Boat in a table are wrecked
\return 1 if all Boat are wrecked
\return 0 otherwise
*/
int allWrecked(Boat* t,int N_boat, Board board){
    for(int i=0;i<N_boat;i++){
        if(isWrecked(t[i],board)==0){
            return 0;
        }
    }
    return 1;
}
