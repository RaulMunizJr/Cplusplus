//
//  studentList.h
//  Assignment #8
//
//  Created by Raul Muniz on 3/2/18.
//  Copyright © 2018 Raul Muniz. All rights reserved.
//

#ifndef studentList_h
#define studentList_h

#include <iostream>
#include <string>
using namespace std;

/*
 Implement the "studentList" data structure with a doubly linked list implementation.
 
 You must implement all methods and they must work as described in the comments. You must also achieve the stated run times, and know the big-Oh run times for each of your methods.
 */


class student
{
public:
    string name;
    unsigned int id;
    double gpa;
    
    student()
    {
        name = "ghost";
        id = 0;
        gpa = 0;
    }
    student(string _name, unsigned int _id, double _gpa)
    {
        id = _id;
        gpa = _gpa;
        name = _name;
    }
};
class studentList
{
private:
    //Implement a doubly linked list of students
    
    class node
    {
    public:
        student data;
        node * next;
        node * prev;
        
        node(student x)
        {
            data = x;
            next = NULL;
            prev = NULL;
        }
    };
    
    node * head;
    node * tail;
    
public:
    studentList()
    {
        head = NULL;
        tail = NULL;
    }
    
    //add a student to the list.
    //Must run in O(1) time.
    void insert(student s)
    {
        node* n = new node(s);
        if(head == NULL)
            head = tail = n;
        else
        {
            n->prev = tail;
            tail->next = n;
            tail = n;
        }
    }
    
    //find the student with the given id number and return it
    //What is the worst case run time of this? -> it is of O(n) since it is sequential search and data is unsorted
    //What is the average case run time of this? -> it is of O(n) since it is sequential search and data is unsorted
    student retrieveStudent(unsigned int idnumber)
    {
        student s;
        node* curr = head;
        while(curr != NULL)
        {
            if(curr->data.id == idnumber)
            {
                s = curr->data;
                break;
            }
            curr = curr->next;
        }
        return s;
    }
    
    //Change the gpa of the student with given id number to newGPA
    //What is the run time? -> it is of O(n) since it is sequential search and data is unsorted
    void updateGPA(unsigned int idnumber, double newGPA)
    {
        node* curr = head;
        while(curr != NULL)
        {
            if(curr->data.id == idnumber)
            {
                curr->data.gpa = newGPA;
                break;
            }
            curr = curr->next;
        }
    }
    
    //Add all students from otherlist to this list.
    //otherlist should be empty after this operation.
    //Must run in O(1) time.
    void mergeList(studentList &otherlist)
    {
        if(head == NULL) //this list is empty
            head = tail = otherlist.head;
        else
        {
            tail->next = otherlist.head;
            tail = otherlist.tail;
        }
        
        //update the otherlist
        otherlist.head = otherlist.tail = NULL;
    }
    
    //create a list of students whose gpa is at least minGPA.
    //Return this list. The original list should
    //not be modified (do not remove the students from the original list).
    //Run time? -> O(n) since each item in the list should be examined
    studentList honorRoll(double minGPA)
    {
        studentList list;
        node* curr = head;
        while(curr != NULL)
        {
            if(curr->data.gpa >= minGPA)
            {
                list.insert(curr->data);
            }
            curr = curr->next;
            
        }
        return list;
    }
    
    //sort the list by the given field ("name", "id", or "gpa").
    //Run time? O(N^2)
    void sort(string field)
    {
        //selection sort
        node* min;
        for(node* i = head; i != NULL; i = i->next)
        {
            min = i;
            for(node* j = i->next; j != NULL; j= j->next)
            {
                if(field == "id" && j->data.id < min->data.id)
                    min = j;
                else if(field == "name" && j->data.name < min->data.name)
                    min = j;
                else if(field == "gpa" && j->data.gpa < min->data.gpa)
                    min = j;
            }
            
            if(min != i) //need to swap?
            {
                student temp = i->data;
                i->data = min->data;
                min->data = temp;
            }
        }
    }
    
    //Print out each student in the list. This is mainly for testing purposes.
    void printList()
    {
        node* curr = head;
        student s;
        while(curr != NULL)
        {
            s = curr->data;
            cout << s.id << "\t" << s.name << "\t" << s.gpa << endl;
            curr = curr->next;
        }
    }
};

#endif /* studentList_h */
