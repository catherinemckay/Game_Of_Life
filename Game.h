/**
*@author Catherine McKay
*2378275
*camckay@chapman.edu
*@author Lawrence Leymarie
*2370408
*leymarie@chapman.edu
*CPSC350-01
*Assignment 3 - Game of Life: File 8 of 15
*@version 1.0
*Game Class
*
*/

#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "GameBoard.h"
using namespace std;

/*
Class definition for Game which only contains the method that
starts the simulation.
This class is used so that we can write as little as possible in main.cpp
*/
class Game
{
    public:
        Game();

        ~Game();

        void play();
};

#endif
