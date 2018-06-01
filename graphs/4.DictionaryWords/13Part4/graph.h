//
//  graph.h
//  13Part4
//
//  Created by Raul Muniz on 4/30/18.
//  Copyright © 2018 Raul Muniz. All rights reserved.
//

#ifndef graph_h
#define graph_h

#include <vector>
#include <string>
#include <iostream>
#include <queue>
using namespace std;

class directedGraph
{
private:
    class vertex
    {
    public:
        string data;
        vector< vertex* > neighbors;
        vertex* prior;
        bool mark;
        
        vertex(string x)
        {
            data = x;
            prior = NULL;
            mark = false;
        }
    };
    
    vector<vertex*> vertexList;
    
    //find vertex with x as data field.
    //return NULL if x is not present
    vertex * findVertex(string x)
    {
        for (int i = 0; i < vertexList.size(); i++)
        {
            if (vertexList[i]->data == x)
                return vertexList[i];
        }
        return NULL;
    }
    
    void breadthFirstSearch(vertex * s)
    {
        //step 1: set up Q, put s in Q
        queue<vertex*> Q;
        s->mark = true;
        Q.push(s);
        
        //step 3:  The bfs loop!
        while (!Q.empty())
        {
            vertex * x = Q.front();
            Q.pop();
            
            //to print items in bfs order, add cout HERE!
            //cout << x->data;
            
            for (int i = 0; i < x->neighbors.size(); i++)
            {
                vertex * y = x->neighbors[i];
                if (y->mark == false)
                {
                    y->prior = x;
                    y->mark = true;
                    Q.push(y);
                }
            }
        }
        
    }
    
public:
    
    directedGraph()
    {
        
    }
    
    void addVertex(string x)
    {
        vertexList.push_back(new vertex(x));
    }
    
    //add a directed edge going from
    //x to y
    void addDirectedEdge(string x, string y)
    {
        vertex * xVert = findVertex(x);
        vertex * yVert = findVertex(y);
        
        if (xVert != NULL && yVert != NULL)
            xVert->neighbors.push_back(yVert);
        else
            cout << "You misspelled something..." << endl;
    }
    
    //add bi-directional edge
    void addEdge(string x, string y)
    {
        addDirectedEdge(x, y);
        addDirectedEdge(y, x);
    }
    
    void makeEdges()
    {
        for (int i = 0; i < vertexList.size(); i++)
        {
            for (int j = i + 1; j < vertexList.size(); j++)
            {
                if (isAdjacent(vertexList[i]->data, vertexList[j]->data))
                {
                    addEdge(vertexList[i]->data, vertexList[j]->data);
                }
            }
        }
    }
    
    void search(string x, string y)
    {
        vertex* xV = findVertex(x);
        breadthFirstSearch(xV);
        
        for (vertex* yV = findVertex(y); yV != NULL; yV = yV->prior)
        {
            cout << yV->data << endl;
        }
    }
    
    bool isAdjacent(string& a, string& b)
    {
        int count = 0;
        int n = a.length();
        
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i]) count++;
            if (count > 1) return false;
        }
        if (count == 0)
            return false;
        else
            return true;
    }
};


#endif /* graph_h */
