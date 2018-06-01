//
//  doublyLL.h
//  13Part1
//
//  Created by Raul Muniz on 4/26/18.
//  Copyright © 2018 Raul Muniz. All rights reserved.
//

#ifndef doublyLL_h
#define doublyLL_h

#include <iostream>
using namespace std;

class node
{
public:
    string data;
    node *prev;
    node *next;
    
    node(string x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

class doublyLL
{
private:
    
    node *head;
    node *tail;
    
public:
    
    doublyLL()
    {
        head = NULL;
        tail = NULL;
    }
    
    void insert(string x)
    {
        node *N = new node(x);
        
        if (head == NULL)
        {
            head = N;
            tail = N;
        }
        else
        {
            tail->next = N;
            N->prev = tail;
            tail = N;
        }
    }
    
    void noRepeat(string x)
    {
        bool repeat = false;
        node *A = head;
        
        while (A != NULL)
        {
            if (x == A->data)
            {
                repeat = true;
            }
            A = A->next;
        }
        if (repeat == true)
        {
            
        }
        else
        {
            insert(x);
        }
    }
    
    void removeBack()
    {
        if (head == NULL)
        {
            //nothing
        }
        else
        {
            if (head == tail)
            {
                node *N = head;
                delete N;
                head = NULL;
                tail = NULL;
            }
            else
            {
                node *N = tail;
                tail = tail->prev;
                tail->next = NULL;
                delete N;
            }
        }
    }
    
    string back()
    {
        string output = tail->data;
        removeBack();
        return output;
    }
    
    bool empty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }
    
    string returnData()
    {
        node *N = tail;
        
        if (head == NULL)
        {
            //nothing
        }
        else
        {
            return tail->data;
        }
        return tail->data;
    }
    
    void display()
    {
        node *t = head;
        
        while(t != NULL)
        {
            cout << t->data << " " << endl;
            t = t->next;
        }
    }
};

#endif /* doublyLL_h */
