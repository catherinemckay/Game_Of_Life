/**
*@author Catherine McKay
*2378275
*camckay@chapman.edu
*@author Lawrence Leymarie
*2370408
*leymarie@chapman.edu
*CPSC350-01
*Assignment 3 - Game of Life: File 11 of 15
*@version 1.0
*GameMode Class
*
*/
#include "GameMode.h"
#include "ClassicMode.h"
#include "DoughnutMode.h"
#include "gameBoard.h"
#include "MirrorMode.h"
#include "FileProcessor.h"
#include <cstdlib>
#include <thread>
#include <chrono>
#include <string>


// Constructor
GameMode::GameMode()
{
    gameBoard = new GameBoard();
    newGen = new GameBoard(*gameBoard);
    pauseForOutput = false;
    enterForOutput = false;
    fileForOutput = false;
    generation = -1;
}

// Destructor
GameMode::~GameMode()
{
    delete gameBoard;
    delete newGen;
}

/*
checks cell positions
polymorphic call on methods to count neighbors
creates next generation based on neighbors
*/
void GameMode::run()
{
    int neighbors;
    for(int i = 0; i < gameBoard->getGridRows(); ++i)
    {
        for(int j = 0; j < gameBoard->getGridColumns(); ++j)
        {
            if(i == 0 && j == 0)
            {
                neighbors = topLeftCorner();
            }
            else if(i == 0 && j > 0 && j < gameBoard->getGridColumns() -1)
            {
                neighbors = topEdge(i,j);
            }
            else if(i == 0 && j == gameBoard->getGridColumns() -1)
            {
                neighbors = topRightCorner();
            }
            else if(i > 0 && i < gameBoard->getGridRows() -1 && j == 0)
            {
                neighbors = leftEdge(i,j);
            }
            else if(i > 0 && i < gameBoard->getGridRows() -1 && j == gameBoard->getGridColumns() - 1)
            {
                neighbors = rightEdge(i,j);
            }
            else if(i == gameBoard->getGridRows() -1 && j == 0)
            {
                neighbors = bottomLeftCorner();
            }
            else if(i == gameBoard->getGridRows() -1 && j > 0 && j < gameBoard->getGridColumns() -1)
            {
                neighbors = bottomEdge(i, j);
            }
            else if(i == gameBoard->getGridRows() - 1 && j == gameBoard->getGridColumns() -1)
            {
                neighbors = bottomRightCorner();
            }
            else
            {
                neighbors = regularCell(i,j);
            }

            handleNextGen(neighbors, i, j);
        }
    }
}


/*
prompts to create game board
runs output options
*/
void GameMode::start()
{
    string strGenerations;
    cout << endl;
    cout << "Generation 0:" << endl;
    gameBoard->displayGameBoard();
    cout << endl;

    promptForOutput();
    bool isGameRunning = true;

    while(isGameRunning)
    {
        run();

        if(isBoardStable())
        {
            cout << "completed" << endl;
            isGameRunning = false;
        }
        else
        {
            if(pauseForOutput)
            {
                displayNewGen();
                this_thread::sleep_for(chrono::milliseconds(1000));
            }
            else if(enterForOutput)
            {
                displayNewGen();
                cin.get();
            }
            else if(fileForOutput)
            {
                strGenerations += returnNewGen();
                FileProcessor fileProcessor;
                fileProcessor.sendToFile(strGenerations);
            }
        }
    }
    cout << "Press \"Enter\" to exit simulation" << endl;
    cin.ignore();
    cin.get();
}


/*
update generation
return new generation
*/
string GameMode::returnNewGen()
{
    string newGenStr;
    newGenStr.push_back('\n');
    swapReferences();
    generation++;
    newGenStr += "Generation " + to_string(generation) + '\n';
    newGenStr += newGen->returnGameBoardString();
    return newGenStr;
}


/*
displays new generations
*/
void GameMode::displayNewGen()
{
    swapReferences();
    generation++;
    cout << "Generation " << generation << endl;
    newGen->displayGameBoard();
    cout << endl;
}

/*
prompts user for output type
*/
void GameMode::promptForOutput()
{
    int userInput;
    cout << "How would you like the program to output?" << endl;
    cout << "1 if you would like a brief pause between generations" << endl;
    cout << "2 if you would like to press the \"enter\" key between generations" << endl;
    cout << "3 if you would like to output to a file" << endl;

    while(true)
    {
        cin >> userInput;

        if(userInput == 1)
        {
            cout << endl;
            pauseForOutput = true;
            break;
        }
        else if(userInput == 2)
        {
            cout << endl;
            enterForOutput = true;
            break;
        }
        else if(userInput == 3)
        {
            cout << endl;
            fileForOutput = true;
            break;
        }
        else
        {
            cout << endl;
            cout << "Not a valid output mode, try again." << endl;
        }
    }
}

/*
checks if gameboard updated with appropriate generation
*/
bool GameMode::isBoardStable()
{
    for(int i=0; i < gameBoard->getGridRows(); ++i)
    {
        for(int j=0; j < gameBoard->getGridColumns(); ++j)
        {
            if(gameBoard->getCell(i, j) != newGen->getCell(i, j))
            {
                return false;
            }
        }
    }
    return true;
}


/*
updates gameboard with new generation
*/
void GameMode::swapReferences()
{
    GameBoard *temp = gameBoard;
    gameBoard = newGen;
    newGen = temp;
}

/*
updates new generation according to neighbor count
*/
void GameMode::handleNextGen(int neighbors, int x, int y)
{
    if(neighbors <= 1)
    {
        newGen->killCell(x, y);
    }
    else if(neighbors == 2)
    {
        if(gameBoard->isCellPopulated(x, y))
        {
            newGen->populateCell(x, y);
        }
        else
        {
            newGen->killCell(x, y);
        }
    }
    else if(neighbors == 3)
    {
        newGen->populateCell(x, y);
    }
    else if(neighbors >= 4)
    {
        newGen->killCell(x, y);
    }
}

/*
handles neighbor count for a regular cell
used in all modes
*/
int GameMode::regularCell(int x, int y){
    int neighbors=0;

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
