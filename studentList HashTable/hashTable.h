//
//  hashTable.h
//  Homework #9
//
//  Created by Raul Muniz on 3/28/18.
//  Copyright © 2018 Raul Muniz. All rights reserved.
//

#ifndef hashTable_h
#define hashTable_h

#include <iostream>
#include "studentList.h"
using namespace std;

class hashTable
{
private:
    //an array of linked lists (use your linked list class from homework 8)
    studentList * table;
    
    //size of table
    unsigned int tableSize;
    
    //number of students in data stucture
    unsigned int numStudents;
    
public:
    //create a table of some hard coded size of your choice
    hashTable()
    {
        tableSize = 10;
        table = new studentList[tableSize];
        numStudents = 0;
    }
    
    //create a table of a given size
    hashTable(unsigned int size)
    {
        tableSize = size;
        table = new studentList[tableSize];
        numStudents = 0;
    }
    
    //insert s into hash table.  Store by hashing the student's id number.
    //Run time must be: O(1)
    void insert(student s)
    {
        int key = s.id % tableSize;
        table[key].insert(s);
        numStudents++;
        
        if (numStudents == tableSize)
        {
            optimalResize();
        }
    }
    
    //remove student with given id from table
    //Run time:  Average case O(1 + numStudents/tableSize)
    void remove(unsigned int id)
    {
        int key = id % tableSize;
        
        table[key].deleteStudent(id);
        numStudents--;
        
        if (numStudents / tableSize <= 0.25)
        {
            optimalResize();
        }
    }
    
    //Change the gpa of the student with given id number to newGPA
    //Run time:  Average case O(1 + numStudents/tableSize)
    void updateGPA(unsigned int idnumber, double newGPA)
    {
        int key = idnumber % tableSize;
        
        table[key].updateGPA(idnumber, newGPA);
    }
    
    //lookup up and return copy of student with given id.
    //Run time: Average case O(1 + numStudents/tableSize)
    student getStudent(unsigned int id)
    {
        int key = id % tableSize;
        
        return table[key].retrieveStudent(id);
    }
    
    //Change the size of your table!  newSize may be bigger or smaller that the current size.
    //Run time?O(n)
    void resize(unsigned int newSize)
    {
        hashTable temp(newSize);
        
        for (unsigned int i = 0; i < tableSize; i++)
        {
            studentList index = table[i];
            while (!table[i].empty())
            {
                temp.insert(table[i].returnStudent());
                table[i].removeBack();
            }
        }
        delete[] table;
        table = temp.table;
        tableSize = temp.tableSize;
        numStudents = temp.numStudents;
    }
    
    //Resize your table to an "optimal" choice based on the
    //current number of entries.  If you make it too large, you waste space.
    //If you make it too small, your searches are slow.  Pick a value
    //that is perfect.  Include in comments the reasoning for your
    //resizing choice.
    void optimalResize()
    {
        //maintains a 50% load balance which will maintain the 0(1) insertion and deletion.
        resize(numStudents * 2);
    }
    
    void printList()
    {
        for (int i = 0; i < tableSize; i++)
        {
            cout << "Printing Hash Table index " << i << " student list" << endl;
            table[i].printList();
            cout << endl;
        }
    }
    
    int printTableSize()
    {
        return tableSize;
    }
};


#endif /* hashTable_h */
