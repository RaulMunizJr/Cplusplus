//
//  main.cpp
//  13Part4
//
//  Created by Raul Muniz on 4/30/18.
//  Copyright © 2018 Raul Muniz. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include "graph.h"
using namespace std;

int main()
{
    ifstream inputFile;
    string first, second, item;
    int wordLength;
    
    cout << "Choose Two Words: " << endl;
    cin >> first >> second;
    cout << endl;
    
    wordLength = first.length();
    inputFile.open("dictionary.txt");
    
    //Make graph
    directedGraph G;
    while (inputFile >> item)
    {
        if (item.length() == wordLength)
        {
            G.addVertex(item);
        }
    }
    G.makeEdges();
    cout << "The following is a valid path from " << first << " to " << second << ":"<< endl;
    
    //shortest route between words
    G.search(second, first);
    
    return 0;
}

