/**
*@author Catherine McKay
*2378275
*camckay@chapman.edu
*@author Lawrence Leymarie
*2370408
*leymarie@chapman.edu
*CPSC350-01
*Assignment 3 - Game of Life: File 6 of 15
*@version 1.0
*FileProcessor Class
*
*/

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
using namespace std;

/*
Class definition for handling file input and output
*/
class FileProcessor{
    private:
        int gridColumns;
        int gridRows;


    public:
        FileProcessor();
        ~FileProcessor();

        void sendToFile(string content);

        string processFile(string inputFile);
};

#endif
