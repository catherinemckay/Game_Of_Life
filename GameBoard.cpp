/**
*@author Catherine McKay
*2378275
*camckay@chapman.edu
*@author Lawrence Leymarie
*2370408
*leymarie@chapman.edu
*CPSC350-01
*Assignment 3 - Game of Life: File 9 of 15
*@version 1.0
*GameBoard Class
*
*/

#include "GameBoard.h"

// Constructor builds an empty 2d array
GameBoard::GameBoard()
{
    promptForBoardStyle();
}

/*
Copy contructor takes dereference of another gameBoard as param
*/
GameBoard::GameBoard(GameBoard const &gameBoard)
{
    gridRows = gameBoard.gridRows;
    gridColumns = gameBoard.gridColumns;

    grid = new char* [gridRows];
    for(int i=0; i < gridRows; ++i)
    {
        grid[i] = new char[gridColumns];
    }

    for(int i=0; i < gridRows; ++i)
    {
        for(int j=0; j < gridColumns; ++j)
        {
            grid[i][j] = gameBoard.grid[i][j];
        }
    }
}

// Destructor destructs 2d array
GameBoard::~GameBoard()
{
    for(int i=0;i < gridRows; i++)
    {
        delete[] grid[i];
    }
    delete[] grid;
}

/*
displays game board
*/
void GameBoard::displayGameBoard()
{
    for(int i=0; i < gridRows; ++i)
    {
        for(int j=0; j < gridColumns; ++j)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

/*
returns game board by appending string of all the chars o
*/
string GameBoard::returnGameBoardString()
{
    string board;

    for(int i=0;i < gridRows; ++i)
    {
        for(int j=0; j < gridColumns; ++j)
        {
            board.push_back(grid[i][j]);
        }
        board.push_back('\n');
    }
    return board;
}


/*
creates an empty 2D array with appropriate rows and columns
*/
void GameBoard::build2dArray()
{
    grid = new char* [gridRows];
    for(int i=0; i < gridRows; ++i)
    {
        grid[i] = new char[gridColumns];
    }
}

/*
populates a grid from user input file
*/
void GameBoard::populateGridFromFile(string fileName){
    FileProcessor fileProcessor;
    string content;
    content = (fileProcessor.processFile(fileName));

    int idx = 1;
    gridRows = content[0]-48;
    gridColumns = content[1]-48;
    build2dArray();

    for(int i = 0; i < gridRows; ++i)
    {
        for(int j=0; j < gridColumns; ++j)
        {
            grid[i][j] = content[++idx];
        }
    }
}

/*
asks user for columns, rows, & density for random grid
*/
void GameBoard::promptForRandomGrid()
{
    int inputRows;
    int inputColumns;
    float inputDensity;

    cout << "Enter the number of rows:" << endl;
    cin >> inputRows;
    cout << "Enter the number of columns:" << endl;
    cin >> inputColumns;
    cout << "Enter the population density(0 to 1):" << endl;
    while(true)
    {
        cin >> inputDensity;
        if(inputDensity >= 0 && inputDensity <= 1)
        {
            break;
        }
    }

    populateRandomGrid(inputRows, inputColumns, inputDensity);
}

/*
populates random grid with an input density
*/
void GameBoard::populateRandomGrid(int rows, int columns, float inputDensity)
{
    srand((unsigned)time(NULL));
    gridRows = rows;
    gridColumns = columns;
    build2dArray();
    for(int i=0; i < gridRows; ++i)
    {
        for(int j=0; j < gridColumns; ++j)
        {
            if(rand() % 100 < inputDensity*100)
            {
                grid[i][j] = 'X';
            }
            else
            {
                grid[i][j] = '-';
            }
        }
    }
}

/*
prompts user for file path for grid
*/
void GameBoard::promptForMapFile()
{
    string filePath;
    cout << "Enter the path to the map file" << endl;
    cin >> filePath;

    populateGridFromFile(filePath);
}

/*
prompts user for board style
random or from file
*/
void GameBoard::promptForBoardStyle()
{
    int userInput;
    cout << "How would you like to create your board?" << endl;
    cout << "1 if you would like to start with a random configuration" << endl;
    cout << "2 if you would like to start with a file input" << endl;
    while(true)
    {
        cin >> userInput;

        if(userInput == 1)
        {
            cout << endl;
            promptForRandomGrid();
            break;
        }
        else if(userInput == 2)
        {
            cout << endl;
            promptForMapFile();
            break;
        }
        else
        {
            cout << endl;
            cout << "please enter valid option" << endl;
        }
    }
}

/*
bool to check if a specified cell is populated
*/
bool GameBoard::isCellPopulated(int x, int y)
{
    return (grid[x][y] == 'X');
}

/*
Acessor for rows
*/
int GameBoard::getGridRows()
{
    return gridRows;
}

/*
Acessor for columns
*/
int GameBoard::getGridColumns()
{
    return gridColumns;
}

/*
Populates cell
*/
void GameBoard::populateCell(int x, int y)
{
    grid[x][y] = 'X';
}

/*
Kills cell
*/
void GameBoard::killCell(int x, int y)
{
    grid[x][y] = '-';
}

/*
Returns cell
*/
char GameBoard::getCell(int x, int y)
{
    return grid[x][y];
}
