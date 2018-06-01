//
//  main.cpp
//  13Part1
//
//  Created by Raul Muniz on 4/26/18.
//  Copyright © 2018 Raul Muniz. All rights reserved.
//

#include "directedGraph.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include "doublyLL.h"
#include <sstream>
using namespace std;

int main()
{
    ifstream input;
    input.open("schedule.txt");
    directedGraph G;
    doublyLL items;
    doublyLL list;
    vector<string> classList;
    
    while (!input.eof())
    {
        string item;
        input >> item;
        //cout << item << endl;
        
        items.noRepeat(item);
    }
    
    //add verticies
    while (!items.empty())
    {
        G.addVertex(items.back());
    }
    
    //return to top of file
    input.clear();
    input.seekg(0, ios::beg);
    
    string item;
    while (getline(input, item))
    {
        stringstream ss(item);//thank you Dr. Schweller
        string take;
        string prereq;
        
        ss >> take;
        
        while (ss >> prereq)
        {
            G.addDirectedEdge(prereq, take);
        }
    }
    
    G.topoSort();
    
    return 0;
}
