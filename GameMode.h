/**
*@author Catherine McKay
*2378275
*camckay@chapman.edu
*@author Lawrence Leymarie
*2370408
*leymarie@chapman.edu
*CPSC350-01
*Assignment 3 - Game of Life: File 12 of 15
*@version 1.0
*GameMode Class
*
*/

#ifndef GAMEMODE_H
#define GAMEMODE_H
#include <iostream>
#include "GameBoard.h"
using namespace std;

class GameMode
{
    public:
        GameMode();

        ~GameMode();

        virtual int topRightCorner() = 0;
        virtual int topLeftCorner() = 0;
        virtual int bottomRightCorner() = 0;
        virtual int bottomLeftCorner() = 0;
        virtual int topEdge(int x, int y) = 0;
        virtual int bottomEdge(int x, int y) = 0;
        virtual int rightEdge(int x, int y) = 0;
        virtual int leftEdge(int x, int y) = 0;

        int regularCell(int x, int y);

        void start();

        void run();

        void handleNextGen(int neighbors, int x, int y);

        void swapReferences();

        void displayNewGen();

        bool isBoardStable();

        void promptForOutput();

        string returnNewGen();

    protected:
        GameBoard *gameBoard;

    private:
        GameBoard *newGen;

        bool pauseForOutput;
        bool enterForOutput;
        bool fileForOutput;
        int generation;

};

#endif
