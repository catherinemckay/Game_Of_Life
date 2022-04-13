/**
*@author Catherine McKay
*2378275
*camckay@chapman.edu
*@author Lawrence Leymarie
*2370408
*leymarie@chapman.edu
*CPSC350-01
*Assignment 3 - Game of Life: File 15 of 15
*@version 1.0
*Mirror Mode Class
*
*/

#ifndef MIRRORMODE_H
#define MIRRORMODE_H
#include <iostream>
#include "GameMode.h"
using namespace std;

class MirrorMode : public GameMode
{
    public:
        MirrorMode();

        ~MirrorMode();

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
