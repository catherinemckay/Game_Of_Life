/**
*@author Catherine McKay
*2378275
*camckay@chapman.edu
*@author Lawrence Leymarie
*2370408
*leymarie@chapman.edu
*CPSC350-01
*Assignment 3 - Game of Life: File 14 of 15
*@version 1.0
*Mirror Mode Class
*
*/

#include "MirrorMode.h"
#include "GameBoard.h"

MirrorMode::MirrorMode(){}

MirrorMode::~MirrorMode(){}

/*
counts neighbors for top left corner condition
*/
int MirrorMode::topLeftCorner(){
    int neighbors = 0;
    if(gameBoard->isCellPopulated(0, 0)){
        neighbors+= 3;
    }
    if(gameBoard->isCellPopulated(0,1)){
        neighbors+= 2;
    }
    if(gameBoard->isCellPopulated(1, 0)){
        neighbors+= 2;
    }
    if(gameBoard->isCellPopulated(1, 1)){
        neighbors++;
    }
    return neighbors;
}

/*
counts neighbors for top right corner condition
*/
int MirrorMode::topRightCorner(){
    int neighbors = 0;
    if(gameBoard->isCellPopulated(0, gameBoard->getGridColumns() - 1)){
        neighbors+= 3;
    }
    if(gameBoard->isCellPopulated(0, gameBoard->getGridColumns() - 2)){
        neighbors+= 2;
    }
    if(gameBoard->isCellPopulated(1, gameBoard->getGridColumns() - 1)){
        neighbors+= 2;
    }
    if(gameBoard->isCellPopulated(1, gameBoard->getGridColumns() - 2)){
        neighbors++;
    }
    return neighbors;
}

/*
counts neighbors for bottom left corner condition
*/
int MirrorMode::bottomLeftCorner(){
    int neighbors = 0;
    if(gameBoard->isCellPopulated(gameBoard->getGridRows() -1, 0)){
        neighbors+= 3;
    }
    if(gameBoard->isCellPopulated(gameBoard->getGridRows() -2,0)){
        neighbors+= 2;
    }
    if(gameBoard->isCellPopulated(gameBoard->getGridRows() -1,1)){
        neighbors+= 2;
    }
    if(gameBoard->isCellPopulated(gameBoard->getGridRows() -2,1)){
        neighbors++;
    }
    return neighbors;
}

/*
counts neighbors for bottom right corner condition
*/
int MirrorMode::bottomRightCorner(){
    int neighbors = 0;
    if(gameBoard->isCellPopulated(gameBoard->getGridRows() -1 , gameBoard->getGridColumns() - 1)){
        neighbors+= 3;
    }
    if(gameBoard->isCellPopulated(gameBoard->getGridRows() - 2, gameBoard->getGridColumns() - 1)){
        neighbors+= 2;
    }
    if(gameBoard->isCellPopulated(gameBoard->getGridRows() - 1, gameBoard->getGridColumns() - 2)){
        neighbors+= 2;
    }
    if(gameBoard->isCellPopulated(gameBoard->getGridRows() - 2, gameBoard->getGridColumns() - 2)){
        neighbors++;
    }
    return neighbors;
}

/*
counts neighbors for top edge condition
*/
int MirrorMode::topEdge(int x, int y){
    int neighbors = 0;
    if(gameBoard->isCellPopulated(x,y)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(x, y - 1)){
        neighbors+= 2;
    }
    if(gameBoard->isCellPopulated(x, y + 1)){
        neighbors+= 2;
    }
    if(gameBoard->isCellPopulated(x + 1, y)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(x + 1, y - 1)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(x + 1, y + 1)){
        neighbors++;
    }
    return neighbors;
}

/*
counts neighbors for bottom edge condition
*/
int MirrorMode::bottomEdge(int x, int y){
    int neighbors = 0;
        if(gameBoard->isCellPopulated(x,y)){
        neighbors++;
        }
        if(gameBoard->isCellPopulated(x, y - 1)){
            neighbors+= 2;
        }
        if(gameBoard->isCellPopulated(x, y + 1)){
            neighbors+= 2;
        }
        if(gameBoard->isCellPopulated(x - 1, y)){
            neighbors++;
        }
        if(gameBoard->isCellPopulated(x - 1, y - 1)){
            neighbors++;
        }
        if(gameBoard->isCellPopulated(x - 1, y + 1)){
            neighbors++;
        }
        return neighbors;
}

/*
counts neighbors for left edge condition
*/
int MirrorMode::leftEdge(int x, int y){
    int neighbors = 0;
    if(gameBoard->isCellPopulated(x,y)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(x, y + 1)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(x - 1, y)){
        neighbors+= 2;
    }
    if(gameBoard->isCellPopulated(x - 1, y + 1)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(x + 1, y)){
        neighbors+= 2;
    }
    if(gameBoard->isCellPopulated(x + 1, y + 1)){
        neighbors++;
    }
    return neighbors;
}

/*
counts neighbors for right edge condition
*/
int MirrorMode::rightEdge(int x, int y){
    int neighbors = 0;
    if(gameBoard->isCellPopulated(x,y)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(x, y -1)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(x - 1, y - 1)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(x - 1, y)){
        neighbors+= 2;
    }
    if(gameBoard->isCellPopulated(x + 1, y - 1)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(x + 1, y)){
        neighbors+= 2;
    }
    return neighbors;
}
