//
//  main.cpp
//  13Part2
//
//  Created by Raul Muniz on 4/25/18.
//  Copyright © 2018 Raul Muniz. All rights reserved.
//

#include <iostream>
#include "directedGraph.h"
using namespace std;

int main()
{
    int numberOfComputers;
    int infected = '0';
    int one;
    int two = 0;
    directedGraph G;
    
    cout << "Enter the number of computers: (-1 when done)" << endl;
    cin >> numberOfComputers;
    
    for (int i = 0; i < numberOfComputers; i++)
    {
        G.addVertex(i);
    }
    
    while (two != -1)
    {
        cin >> one;
        cin >> two;
        
        if (two != -1)
        {
            G.addEdge(one, two);
        }
        else
        {
            infected = one;
        }
    }
    
    G.infected(one);
    
    /*
     10         //number of computers
     3 2        //
     7 8        //
     1 2        //
     3 9        //Connected
     9 1        //Pairs...
     0 1        //
     6 7        //
     8 6        //
     1          //The one infected.
     */
    
    return 0;
}
