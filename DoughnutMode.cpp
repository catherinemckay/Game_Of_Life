/**
*@author Catherine McKay
*2378275
*camckay@chapman.edu
*@author Lawrence Leymarie
*2370408
*leymarie@chapman.edu
*CPSC350-01
*Assignment 3 - Game of Life: File 3 of 15
*@version 1.0
*Doughnut Mode Class
*
*/

#include "DoughnutMode.h"
#include "GameBoard.h"

// Constructor
DoughnutMode::DoughnutMode(){}

// Destructor
DoughnutMode::~DoughnutMode(){}

/*
counts neighbors for top left corner condition
*/
int DoughnutMode::topLeftCorner(){
    int neighbors = 0;
    if(gameBoard->isCellPopulated(0,1)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(0, gameBoard->getGridColumns() - 1)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(1, 0)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(1, 1)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(1, gameBoard->getGridColumns() - 1)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(gameBoard->getGridRows() - 1, 0)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(gameBoard->getGridRows() - 1, 1)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(gameBoard->getGridRows() - 1, gameBoard->getGridColumns() - 1)){
        neighbors++;
    }
    return neighbors;
}

/*
counts neighbors for top right corner condition
*/
int DoughnutMode::topRightCorner(){
    int neighbors = 0;
    if(gameBoard->isCellPopulated(0, 0)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(0, gameBoard->getGridColumns() - 2)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(1, 0)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(1, gameBoard->getGridColumns() - 2)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(1, gameBoard->getGridColumns() - 1)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(gameBoard->getGridRows() -1, 0)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(gameBoard->getGridRows() - 1, gameBoard->getGridColumns() - 2)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(gameBoard->getGridRows() - 1, gameBoard->getGridColumns() - 1)){
        neighbors++;
    }
    return neighbors;
}

/*
counts neighbors for bottom left corner condition
*/
int DoughnutMode::bottomLeftCorner(){
    int neighbors = 0;
    if(gameBoard->isCellPopulated(0, 0)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(0, 1)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(0, gameBoard->getGridColumns() - 1)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(gameBoard->getGridRows() - 2, 0)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(gameBoard->getGridRows() - 2, 1)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(gameBoard->getGridRows() - 2, gameBoard->getGridColumns() - 1)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(gameBoard->getGridRows() - 1, 1)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(gameBoard->getGridRows() - 1, gameBoard->getGridColumns() - 1)){
        neighbors++;
    }
    return neighbors;
}

/*
counts neighbors for bottom right corner condition
*/
int DoughnutMode::bottomRightCorner(){
    int neighbors = 0;
    if(gameBoard->isCellPopulated(0, 0)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(0, gameBoard->getGridColumns() - 2)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(0, gameBoard->getGridColumns() - 1)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(gameBoard->getGridRows() - 2, 0)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(gameBoard->getGridRows() - 2, gameBoard->getGridColumns() - 2)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(gameBoard->getGridRows() - 2, gameBoard->getGridColumns() - 1)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(gameBoard->getGridRows() - 1, 0)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(gameBoard->getGridRows() - 1, gameBoard->getGridColumns() - 2)){
        neighbors++;
    }
    return neighbors;
}

/*
counts neighbors for top edge condition
*/
int DoughnutMode::topEdge(int x, int y){
    int neighbors = 0;
    if(gameBoard->isCellPopulated(x, y - 1)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(x, y + 1)){
        neighbors++;
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
    if(gameBoard->isCellPopulated(gameBoard->getGridRows() - 1, y)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(gameBoard->getGridRows() - 1, y - 1)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(gameBoard->getGridRows() - 1, y + 1)){
        neighbors++;
    }
    return neighbors;
}

/*
counts neighbors for bottom edge condition
*/
int DoughnutMode::bottomEdge(int x, int y){
    int neighbors = 0;
    if(gameBoard->isCellPopulated(x, y - 1)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(x, y + 1)){
        neighbors++;
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
    if(gameBoard->isCellPopulated(0, y)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(0, y - 1)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(0, y + 1)){
        neighbors++;
    }
    return neighbors;
}

/*
counts neighbors for left edge ondition
*/
int DoughnutMode::leftEdge(int x, int y){
    int neighbors = 0;
    if(gameBoard->isCellPopulated(x, y + 1)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(x - 1, y)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(x - 1, y + 1)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(x + 1, y)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(x + 1, y + 1)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(x - 1, gameBoard->getGridColumns() - 1)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(x, gameBoard->getGridColumns() - 1)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(x + 1, gameBoard->getGridColumns() - 1)){
        neighbors++;
    }
    return neighbors;
}

/*
counts neighbors for right edge condition
*/
int DoughnutMode::rightEdge(int x, int y){
    int neighbors = 0;
    if(gameBoard->isCellPopulated(x, y - 1)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(x - 1, y)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(x - 1, y - 1)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(x + 1, y)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(x + 1, y - 1)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(x - 1, 0)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(x, 0)){
        neighbors++;
    }
    if(gameBoard->isCellPopulated(x + 1, 0)){
        neighbors++;
    }
    return neighbors;
}
