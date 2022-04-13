/**
*@author Catherine McKay
*2378275
*camckay@chapman.edu
*@author Lawrence Leymarie
*2370408
*leymarie@chapman.edu
*CPSC350-01
*Assignment 3 - Game of Life: File 5 of 15
*@version 1.0
*FileProcessor Class
*
*/

#include <fstream>
#include <string>
#include "FileProcessor.h"
using namespace std;

// Constructor
FileProcessor::FileProcessor(){}

// Destructor
FileProcessor::~FileProcessor(){}

/*
processes file
returns content from file input
*/
string FileProcessor::processFile(string inputFile){
    ifstream inFS;
    string line;
    string content;
    inFS.open(inputFile);

    while(!inFS.fail()){
        inFS >> line;
        content += line;

    }
    inFS.close();
    return content;

}

/*
sends content to output file
*/
void FileProcessor::sendToFile(string content)
{
    ofstream oFS;

    oFS.open("output.txt");
    oFS << content;

    oFS.close();

}
