/**
*@author Catherine McKay
*2378275
*camckay@chapman.edu
*@author Lawrence Leymarie
*2370408
*leymarie@chapman.edu
*CPSC350-01
*Assignment 3 - Game of Life: File 4 of 15
*@version 1.0
*Doughnut Mode Class
*
*/

#ifndef DOUGHNUTMODE_H
#define DOUGHNUTMODE_H
#include <iostream>
#include "GameMode.h"
using namespace std;

/*
Class definition for the doughnut game mode
*/
class DoughnutMode : public GameMode
{
    public:
        DoughnutMode();

        ~DoughnutMode();

        int topLeftCorner();
        int topRightCorner();
        int bottomLeftCorner();
        int bottomRightCorner();
        int topEdge(int x, int y);
        int bottomEdge(int x, int y);
        int rightEdge(int x, int y);
        int leftEdge(int x, int y);

    private:

};

#endif
