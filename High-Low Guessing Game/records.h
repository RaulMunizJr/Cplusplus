//
//  records.h
//  Assignment #1
//
//  Created by Raul Muniz on 1/20/18.
//  Copyright © 2018 Raul Muniz. All rights reserved.
//

#ifndef records_h
#define records_h

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class node
{
private:
public:
    node *prev, *next;
    string firstName, lastName;
    int numOfGuesses;
    
    node()
    {
        prev = NULL;
        next = NULL;
        numOfGuesses = 0;
        firstName = " ";
        lastName = " ";
    }
    
    node(string first, string last, int guesses)
    {
        numOfGuesses = guesses;
        firstName = first;
        lastName = last;
    }
    
};

class linkedlist
{
private:
public:
    node *head, *tail;
    
    linkedlist()
    {
        head = NULL;
        tail = NULL;
    }
    
    void initialize(string first, string last, int guess)
    {
        node * newNode = new node(first, last, guess);
        
        if (head == NULL && tail == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            node * index = head;
            
            while (guess >= index->numOfGuesses && index->next != NULL)
            {
                index = index->next;
            }
            
            if (index->next == NULL)
            {
                index->next = newNode;
                newNode->prev = index;
                tail = newNode;
            }
            else
            {
                newNode->prev = index->prev;
                newNode->next = index;
                node * temp = newNode->prev;
                temp->next = newNode;
            }
        }
        
        
    }
    
    void insertNode(string first, string last, int guess)
    {
        node * A = new node(first, last, guess);
        node * index = head;
        int trip = 0;
        
        if (head == NULL)
        {
            head = A;
            tail = A;
        }
        else if (guess <= index->numOfGuesses)
        {
            head->prev = A;
            A->next = head;
            head = A;
            
            node * doomed = tail;
            index = doomed->prev;
            index->next = NULL;
            tail = index;
            delete doomed;
        }
        else
        {
            while (guess > index->numOfGuesses)
            {
                if (head->firstName == tail->firstName && head->lastName == tail->lastName && head->numOfGuesses == tail->numOfGuesses)
                {
                    trip = 1;
                    break;
                }
                if (index->next != NULL)
                {
                    index = index->next;
                }
                else if (index == tail)
                {
                    trip = 1;
                    break;
                }
            }
            
            if (trip == 1) 
            {
                index->next = A;
                A->prev = index;
                tail = A;
            }
            else
            {
                node *temp = index->prev;
                temp->next = A;
                index->prev = A;
                A->prev = temp;
                A->next = index;
                
                node *doomed = tail;
                temp = doomed->prev;
                tail = temp;
                temp->next = NULL;
                delete doomed;
            }
        }
    }
    
    void save(ofstream &leaderboardInsert)
    {
        node * index = head;
        while (index != NULL)
        {
            leaderboardInsert << index->firstName << " " << index->lastName << " " << index->numOfGuesses << endl;
            index = index->next;
        }
    }
    
    bool checkTop10(int guess)
    {
        node * index = head;
        bool topCheck = false;
        
        for (int i = 0; i < 10 && index != NULL; i++)
        {
            if (guess <= index->numOfGuesses)
            {
                topCheck = true;
                break;
            }
            index = index->next;
        }
        
        return topCheck;
    }
};


#endif /* records_h */
