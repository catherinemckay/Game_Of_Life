/**
*@author Catherine McKay
*2378275
*camckay@chapman.edu
*@author Lawrence Leymarie
*2370408
*leymarie@chapman.edu
*CPSC350-01
*Assignment 3 - Game of Life: File 10 of 15
*@version 1.0
*GameBoard Class
*
*/

#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <iostream>
#include <random>
#include "FileProcessor.h"
using namespace std;

class GameBoard
{
    private:
        int gridColumns;
        int gridRows;
        char **grid;

    public:

        GameBoard();

        GameBoard(GameBoard const &gameboard);

        ~GameBoard();

        void displayGameBoard();

        string returnGameBoardString();

        void populateRandomGrid(int columns, int rows, float density);

        void populateGridFromFile(string fileName);

        void build2dArray();

        bool isCellPopulated(int x, int y);

        void promptForBoardStyle();

        void promptForRandomGrid();

        void promptForMapFile();

        int getGridRows();

        int getGridColumns();

        void populateCell(int x, int y);

        void killCell(int x, int y);

        char getCell(int x, int y);
};

#endif
