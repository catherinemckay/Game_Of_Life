/**
*@author Catherine McKay
*2378275
*camckay@chapman.edu
*@author Lawrence Leymarie
*2370408
*leymarie@chapman.edu
*CPSC350-01
*Assignment 3 - Game of Life: File 7 of 15
*@version 1.0
*Game Class
*
*/

#include "Game.h"
#include "ClassicMode.h"
#include "DoughnutMode.h"
#include "MirrorMode.h"

// Constructor
Game::Game(){}

// Destructor
Game::~Game(){}


/*
prompts user for mode
starts appropriate game mode
*/
void Game::play()
{
    int mode;

    cout << "Enter type of game mode: " << endl;
    cout << "1 for Classic Mode" << endl;
    cout << "2 for Doughnut Mode" << endl;
    cout << "3 for Mirror Mode" << endl;

    while(true)
    {
        cin >> mode;
        if(mode == 1)
        {
            cout << endl;
            ClassicMode c;
            c.start();
            break;
        }
        else if(mode == 2)
        {
            cout << endl;
            DoughnutMode d;
            d.start();
            break;
        }
        else if(mode == 3)
        {
            cout << endl;
            MirrorMode m;
            m.start();
            break;
        }
        else
        {
            cout << endl;
            cout << "Not a valid game mode, try again." << endl;
        }
    }
}
