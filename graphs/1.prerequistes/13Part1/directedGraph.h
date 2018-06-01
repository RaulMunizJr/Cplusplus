//
//  directedGraph.h
//  13Part1
//
//  Created by Raul Muniz on 4/26/18.
//  Copyright © 2018 Raul Muniz. All rights reserved.
//

#ifndef directedGraph_h
#define directedGraph_h

#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class directedGraph
{
private:
    class vertex
    {
    public:
        string data;
        vector<vertex*> neighbors;
        bool mark;
        vertex * prior;
        
        vertex(string x)
        {
            data = x;
            mark = false;
        }
    };
    
    //declare vector for the vertexes
    //stack to arrange courses properly
    vector<vertex*> vertexList;
    stack<string> courseList;
    
    vertex * findVertex(string x)
    {
        for (int i = 0; i < vertexList.size(); i++)
        {
            if (vertexList[i]->data == x)
                return vertexList[i];
        }
        return NULL;
    }
    
    // Utility function to topoSort
    void topoUtil(vertex * s)
    {
        s->mark = true;
        
        //check neighbors to see if they're marked
        for (int i = 0; i < s->neighbors.size(); i++)
        {
            if (s->neighbors[i]->mark == false)
            {
                topoUtil(s->neighbors[i]);
            }
        }
        courseList.push(s->data);
    }
    
public:
    
    directedGraph()
    {
        
    }
    
    void addVertex(string x)
    {
        vertexList.push_back(new vertex(x));
    }
    
    void addDirectedEdge(string x, string y)
    {
        vertex * xVert = findVertex(x);
        vertex * yVert = findVertex(y);
        
        if (xVert != NULL && yVert != NULL)
        {
            xVert->neighbors.push_back(yVert);
        }
        else
        {
            cout << "Error" << endl;
        }
    }
    
    void topoSort()
    {
        //check each vertex to see if it's been visited
        for (int i = 0; i < vertexList.size(); i++)
        {
            if (vertexList[i]->mark == false)
            {
                topoUtil(vertexList[i]);
            }
        }
        
        //display courses
        while (!courseList.empty())
        {
            cout << courseList.top() << endl;
            courseList.pop();
        }
    }
};



#endif /* directedGraph_h */
