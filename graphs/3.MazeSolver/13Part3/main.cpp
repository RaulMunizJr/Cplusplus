//
//  main.cpp
//  13Part3
//
//  Created by Raul Muniz on 4/29/18.
//  Copyright © 2018 Raul Muniz. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "graph.h"
using namespace std;

char ** myArray;

//displays the 2D array
void display(int numRows, int numColumns)
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numColumns; j++)
        {
            cout << myArray[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
//**********************************************************************
void loadMaze(ifstream& input, int row, int col)
{
    myArray = new char*[row];
    for (int x = 0; x < row; x++)
        myArray[x] = new char[col];
    
    for (int i = 0; i < row; i++)
    {
        for(int j = 0; j <= col; j++)
            myArray[i][j] = ' ';
    }
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j <= col; j++)
            input >> noskipws >> myArray[i][j];
    }
    
}
//**********************************************************************

int main()
{
    string fileToOpen;
    string fileSave;
    ifstream inputFile;
    ofstream outputFile;
    int numRows = 0;
    int numColumns = 0;
    string fileLine;
    directedGraph G;
    
    inputFile.open("maze1.txt");
    
    //Gets each line, gets the length, it stores longest in numColums
    while (getline(inputFile, fileLine))
    {
        if (fileLine.length() > numColumns)
        {
            numColumns = fileLine.length();
        }
        numRows++;
    }
    
    //go to top of file
    inputFile.clear();
    inputFile.seekg(0, ios::beg);
    
    loadMaze(inputFile, numRows, numColumns);
    display(numRows, numColumns);
    
    //create all the vertices
    G.createVertices(myArray, numRows, numColumns);
    
    point ab(numRows, numColumns);
    //attatch all edges
    G.edgeBuilder(myArray, ab);
    
    //Store the BFS array
    myArray = G.bfs(myArray);
    
    //display array
    display(numRows, numColumns);
    
    return 0;
}

