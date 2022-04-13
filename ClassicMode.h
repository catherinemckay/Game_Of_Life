/**
*@author Catherine McKay
*2378275
*camckay@chapman.edu
*@author Lawrence Leymarie
*2370408
*leymarie@chapman.edu
*CPSC350-01
*Assignment 3 - Game of Life: File 2 of 15
*@version 1.0
*Classic Mode Class
*
*/

#ifndef CLASSICMODE_H
#define CLASSICMODE_H
#include <iostream>
#include "GameMode.h"
using namespace std;

/*
Class definition for the classic game mode
*/
class ClassicMode : public GameMode
{
    public:
        ClassicMode();

        ~ClassicMode();

        int topLeftCorner();
        int topRightCorner();
        int bottomLeftCorner();
        int bottomRightCorner();
        int topEdge(int x, int y);
        int bottomEdge(int x, int y);
        int rightEdge(int x, int y);
        int leftEdge(int x, int y);
};

#endif
