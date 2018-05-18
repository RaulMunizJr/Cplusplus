//
//  superQueue.h
//  Assignment #7
//
//  Created by Raul Muniz on 2/28/18.
//  Copyright © 2018 Raul Muniz. All rights reserved.
//

#ifndef superQueue_h
#define superQueue_h

#include <iostream>
#include <string>
using namespace std;

template <class N>//**********************************************************For any data type
class node
{
public:
    
    N data;
    node * prev;
    node * next;
    
    node()
    {
        prev = NULL;
        next = NULL;
    }
    
    node(N x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

//******************************************************************************

template <class T>//**********************************************************For any data type
class superQueue
{
private:
    node<T> *head;
    node<T> *tail;
    
    void removeNode(node<T> *doomed)
    {
        if (doomed == NULL)
        {
            //nothing
        }
        else if (doomed == head && doomed == tail)
        {
            delete doomed;
            head = NULL;
            tail = NULL;
        }
        else if (doomed == head)
        {
            head = doomed->next;
            head->prev = NULL;
            delete doomed;
        }
        else if (doomed == tail)
        {
            tail = doomed->prev;
            tail->next = NULL;
            delete doomed;
        }
        else
        {
            doomed->prev->next = doomed->next;
            doomed->next->prev = doomed->prev;
            delete doomed;
        }
    }
    
public:
    
    superQueue()
    {
        head = NULL;
        tail = NULL;
    }
    
    void push(T x)
    {
        node<T> *baby = new node<T>(x);
        
        if (head == NULL)
        {
            head = baby;
            tail = baby;
        }
        else
        {
            baby->prev = tail;
            tail = baby;
            baby->prev->next = baby;
        }
    }
    
    T pop()
    {
        if (head->next == NULL)
        {
            node<T> *doom = tail;
            T out = doom->data;
            head = NULL;
            tail = NULL;
            delete doom;
            return out;
        }
        else
        {
            node<T> *doomed = tail;
            T output = doomed->data;
            tail = doomed->prev;
            tail->next = NULL;
            delete doomed;
            return output;
        }
    }
    
    bool empty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
            return false;
    }
    
    T& operator[](int location)
    {
        node<T> *temp = head;
        
        for (int i = 0; i < location ; i++)
        {
            temp = temp->next;
        }
        
        return temp->data;
    }
    
    void enqueue(T x)
    {
        push(x);
    }
    
    T dequeue()
    {
        if (head->next == NULL)
        {
            node<T> *doom = head;
            T out = head->data;
            delete doom;
            head = NULL;
            tail = NULL;
            return out;
        }
        else
        {
            node<T> *doomed = head;
            T output = doomed->data;
            head = head->next;
            delete doomed;
            return output;
        }
    }
    
    void insert(T x)
    {
        push(x);
    }
    
    T extractMin()
    {
        node<T> *A = head;
        node<T> *min = head;
        
        while (A != NULL)
        {
            if (A->data < min->data)
            {
                min = A;
            }
            A = A->next;
        }
        
        T output = min->data;
        
        removeNode(min);
        
        return output;
    }
};



#endif /* superQueue_h */
