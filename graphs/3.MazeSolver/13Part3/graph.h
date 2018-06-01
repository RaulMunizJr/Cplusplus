//
//  graph.h
//  13Part3
//
//  Created by Raul Muniz on 4/29/18.
//  Copyright © 2018 Raul Muniz. All rights reserved.
//

#ifndef graph_h
#define graph_h

#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class point
{
public:
    int rows;
    int columns;
    
    point()
    {
        rows = 0;
        columns = 0;
    }
    
    point(int x, int y)
    {
        rows = x;
        columns = y;
    }
    
    bool operator==(point &compare)
    {
        if (this->rows == compare.rows && this->columns == compare.columns)
            return true;
        else
            return false;
    }
};

class directedGraph
{
private:
    
    class vertex
    {
    public:
        char data;
        vector<vertex*> neighbors;
        bool mark;
        vertex* prior;
        point xy;
        
        vertex(char x, point a)
        {
            data = x;
            mark = false;
            prior = NULL;
            xy = a;
        }
    };
    
    vector<vertex*> vertexList;
    
    void breadthFirstSearch(vertex * s)
    {
        queue<vertex*> Q;
        s->mark = true;
        Q.push(s);
        
        while (!Q.empty())
        {
            vertex * x = Q.front();
            Q.pop();
            
            for (int i = 0; i < x->neighbors.size(); i++)
            {
                vertex * y = x->neighbors[i];
                if (y->mark == false)
                {
                    //update previous
                    y->prior = x;
                    
                    //put y into Q
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
    
    //add a directed edge going
    void addDirectedEdge(point x1y1, point x2y2)
    {
        vertex * xVert = findVertex(x1y1);
        vertex * yVert = findVertex(x2y2);
        
        if (xVert != NULL && yVert != NULL)
            xVert->neighbors.push_back(yVert);
    }
    
    //add bi-directional edge
    void addEdge(point x1y1, point x2y2)
    {
        addDirectedEdge(x1y1, x2y2);
        addDirectedEdge(x2y2, x1y1);
    }
    
    //find vertex with x as data field.
    //return NULL if x is not present
    vertex * findVertex(char x)
    {
        for (int i = 0; i < vertexList.size(); i++)
        {
            if (vertexList[i]->data == x)
                return vertexList[i];
        }
        return NULL;
    }
    
    vertex * findVertex(point a)
    {
        for (int i = 0; i < vertexList.size(); i++)
        {
            if(vertexList[i]->xy == a)
                return vertexList[i];
        }
        return NULL;
    }
    
    void addVertex(char x, point ab)
    {
        vertexList.push_back(new vertex(x, ab));
        //cout << ab.columns << " " << ab.rows << endl;
    }
    
    void edgeBuilder(char ** maze, point xy)
    {
        point ab;
        point cd;
        
        for (int i = 0; i < xy.rows - 1; i++)
        {
            for (int j = 0; j < xy.columns; j++)
            {
                ab.rows = i;
                ab.columns = j;
                cd.rows = i + 1;
                cd.columns = j;
                addEdge(ab, cd);
            }
        }
        for (int i = 0; i < xy.rows; i++)
        {
            for (int j = 0; j < xy.columns - 1; j++)
            {
                ab.rows = i;
                ab.columns = j;
                cd.rows = i;
                cd.columns = j + 1;
                addEdge(ab, cd);
            }
        }
    }
    
    char** bfs(char** maze)
    {
        breadthFirstSearch(findVertex('s'));
        
        for (vertex * x = findVertex('e')->prior; x != findVertex('s'); x = x->prior)
        {
            maze[x->xy.rows][x->xy.columns] = '.';
            x->data = '.';
        }
        return maze;
    }
    
    void createVertices(char** maze, int rows, int columns)
    {
        point ab (0, 0);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                ab.rows = i;
                ab.columns = j;
                if (maze[i][j] != '#')
                {
                    addVertex(maze[i][j], ab);
                }
            }
        }
    }
};

#endif /* graph_h */
