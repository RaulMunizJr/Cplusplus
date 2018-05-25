//
//  main.cpp
//  Homework #9
//
//  Created by Raul Muniz on 3/28/18.
//  Copyright © 2018 Raul Muniz. All rights reserved.
//

#include <iostream>
#include "studentList.h"
#include "hashTable.h"
using namespace std;

int main()
{
    
    unsigned int id;
    //*************************************************************************************
    hashTable A;
    
    A.insert(student("Eminem", 1044000, 3.2));
    A.insert(student("Dr. Dre", 1044001, 2.9));
    A.insert(student("Firulais", 1044002, 4.0));
    A.insert(student("Dr. Schweller", 1044003, 3.8));
    A.insert(student("G Eazy", 1044005, 1.9));
    A.insert(student("Will Smith", 1044006, 3.6));
    A.insert(student("Kevin Hart", 1044007, 2.7));
    
    //Printing list A
    cout << "Printing list A\n------------------------------" << endl;
    cout << endl;
    A.printList();
    
    //*************************************************************************************
    hashTable B;
    cout << "Hash table B size " << B.printTableSize() << endl;
    B.insert(student("Dave Franco", 1033008, 2.6));
    B.insert(student("Spider Man", 1033000, 1.7));
    B.insert(student("Tony Stark", 1033001, 3.65));
    B.insert(student("Dr. Strange", 1033003, 1.6));
    B.insert(student("Scarlet Johanson", 1033004, 3.2));
    B.insert(student("Hawk Eye", 1033005, 4.1));
    cout << "Hash table B size " << B.printTableSize() << endl;
    
    //Printing list B
    cout << endl;
    cout << "Printing list B\n------------------------------ " << endl;
    cout << endl;
    B.printList();
    cout << endl;
    
    //update eminem and dave franco gpa
    cout<< "-----------------------------------" << endl;
    cout << "Eminem and James Franco GPA updated" << endl;
    cout << "-----------------------------------\n"<< endl;
    
    A.updateGPA(1044000, 3.2);
    B.updateGPA(1033008, 2.0);
    
    //*********************************************************************************************
    
    cout << "Searching for Dr. Dre and Spider Man:\n------------------------------------\n";
    cout << A.getStudent(1044001).name << " " <<  A.getStudent(1044001).gpa << endl;
    cout << B.getStudent(1033000).name << " " << B.getStudent(1033000).gpa << endl;
    cout << endl;
    
    //Find and print a student
    cout << "Retrieving Student...\n-----------------------" << endl;
    cout << A.getStudent(1044002).name << endl;
    cout << endl;
    
    //Delete students from B
    B.remove(1033008);//Dave Franco
    B.remove(1033003);//Dr. Strange
    B.remove(1033005);//Hawk Eye

    cout << "Hash table B size " << B.printTableSize() << endl;
    
    //reprint B with removed names
    cout << "Reprinting B with removed names" << endl;
    B.printList();
    
    return 0;
}

