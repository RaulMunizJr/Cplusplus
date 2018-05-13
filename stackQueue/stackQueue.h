//
//  stackQueue.h
//  Assignment #4
//
//  Created by Raul Muniz on 1/31/18.
//  Copyright © 2018 Raul Muniz. All rights reserved.
//

#ifndef stackQueue_h
#define stackQueue_h
#include<iostream>

using namespace std;

template <class T>//************************************************for any data Type
class stackQueue
{
private:
    //declare your array variable and
    //any additional variables you need
    //to solve the problem
    
    T *items;//******************************************************for any data Type
    int front;
    int back;
    int capacity;
    
public:
    stackQueue()
    {
        capacity = 5;
        items = new T[capacity];
        front = -1;
        back = -1;
    }
    
    //Insert x to the "back" of the list of items.
    void addBack(T x)//************************************************for any data Type
    {
        if (front == -1)
        {
            front = 0;
            back = 0;
            items[back] = x;
        }
        else if (back == capacity - 1)
        {
            back = 0;
        
            if (back == front)
            {
                back = capacity - 1;
                resize();
            }
        }
        else if (back + 1 == front)
        {
            resize();
        }
        else
        {
            back++;
            items[back] = x;
        }
    }
    
    //Add x to the "front" of the list of items.
    void addFront(T x)//*******************************************for any data Type
    {
        if (front == -1)
        {
            front = 0;
            back = 0;
            items[front] = x;
        }
        else if (front == 0)
        {
            if (back == capacity - 1)
            {
                resize();
            }
            
            front = capacity - 1;
            items[front] = x;
        }
        else if (front - 1 == back)
        {
            resize();
            front = capacity - 1;
            items[front] = x;
        }
        else
        {
            front--;
            items[front] = x;
        }
    }
    
    //Remove and return the item currently at the "back" of the list
    T removeBack()//***************************************************for any data Type
    {
        int index = back;
        
        if (front == -1)
        {
            cout << "Empty.." << endl;
            return 0;
        }
        else if (back == front)
        {
            front = -1;
            back = -1;
            return items[index];
        }
        else if (back == 0)
        {
            back = capacity - 1;
            return items[index];
        }
        else
        {
            back--;
            return items[index];
        }
    }
    
    //Remove and return the item currently at the "front" of the list
    T removeFront()//*****************************************************for any data Type
    {
        int index = front;
        
        if (front == -1)
        {
            cout << "Empty.." << endl;
            return 0;
        }
        else if (front == back)
        {
            front = -1;
            back = -1;
            return items[index];
        }
        else if (front == capacity - 1)
        {
            front = 0;
            return items[index];
        }
        else
        {
            front++;
            return items[index];
        }
    }
    
    //Is the stackQueue empty?
    bool empty()
    {
        if (front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    void resize()
    {
        int index = 0;
        int i = front;
        
        T *temp = new T[capacity * 2];//**********************************************for any data Type
        
        while (i != back)
        {
            temp[index] = items[i];
            index++;
            
            if (i == capacity - 1)
            {
                i = 0;
            }
            else
            {
                i++;
            }
        }
        
        temp[index] = items[back];
        delete[] items;
        items = temp;
        capacity = capacity * 2;
        front = 0;
        back = index;
    }
};

#endif /* stackQueue_h */
