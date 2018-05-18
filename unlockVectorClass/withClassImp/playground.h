//
//  playground.h
//  Raul's Playground
//
//  Created by Raul Muniz on 1/22/18.
//  Copyright © 2018 Raul Muniz. All rights reserved.
//

#ifndef playground_h
#define playground_h

#include <iostream>
#include <string>
//using namespace std;

template <class T>
class vector
{
private:
    T * items;
    int cap;
    int numItems;
    int end;
    
    void resize(int newSize)
    {
        T * temp = new T[newSize];
        
        for (int i = 0; i < numItems; i++)
        {
            {
                temp[i] = items[i];
            }
        }
        
        delete[] items;
        items = temp;
        cap = (cap + (cap/2));
    }
    
public:
    
    vector()
    {
        cap = 0;
        numItems = 0;
        items = new T[cap];
    }
    
    vector(int x)
    {
        cap = x;
        items = new T[x];
        numItems = 0;
        
        for (int i = 0; i < x; i++)
        {
            items[i] = 0;
            numItems++;
        }
    }
    
    vector(int x, T input)
    {
        cap = x;
        items = new T[x];
        numItems = 0;
        
        for (int i = 0; i < x; i++)
        {
            items[i] = input;
            numItems++;
        }
    }
    
    int size()
    {
        return numItems;
    }
    
    int capacity()
    {
        return cap;
    }
    
    T& operator[](int location)
    {
        return items[location];
    }
    
    void push_back(int x)
    {
        if (numItems == cap)
        {
            if (cap == 0)
            {
                cap = 6;
            }
            resize(cap + (cap/2));
            items[numItems] = x;
            numItems++;
        }
        else
        {
            items[numItems] = x;
            numItems++;
        }
    }
    
    int back()
    {
        numItems--;
        return items[numItems];
    }
    
    void pop_back()
    {
        if (numItems == 0)
        {
            std::cout << "The array is empty" << std::endl;
        }
        else
        {
            //numItems--;
        }
    }
    
    bool empty()
    {
        if (numItems == 0)
            return true;
        else
            return false;
    }
};



#endif /* playground_h */

