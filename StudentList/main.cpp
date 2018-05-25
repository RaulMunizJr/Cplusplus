//
//  main.cpp
//  Assignment #8
//
//  Created by Raul Muniz on 3/2/18.
//  Copyright © 2018 Raul Muniz. All rights reserved.
//

#include <iostream>
#include "studentList.h"

using namespace std;

int main()
{
    
    unsigned int id;
//*************************************************************************************
    studentList A;
    
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
    studentList B;
    
    B.insert(student("Dave Franco", 1033008, 2.6));
    B.insert(student("Spider Man", 1033000, 1.7));
    B.insert(student("Tony Stark", 1033001, 3.65));
    B.insert(student("Dr. Strange", 1033003, 1.6));
    B.insert(student("Scarlet Johanson", 1033004, 3.2));
    B.insert(student("Hawk Eye", 1033005, 4.1));
    
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
    
    A.mergeList(B);
    B.printList();
    
    //Printing list A
    cout << "Printing list A merged with B\n------------------------------" << endl;
    cout << endl;
    A.printList();
    cout << endl;
    
    studentList HonorRoll = A.honorRoll(3.5);
    
    //Printing list Honor ROll
    cout << "Printing list Honor Roll\n------------------------------" << endl;
    cout << endl;
    HonorRoll.printList();
    cout << endl;
    
    //Print list A sorted by name
    cout << "Printing list A sorted by Name:\n------------------------------" << endl;
    cout << endl;
    A.sort("name");
    A.printList();
    cout << endl;
    
    //Print list sorted by id
    cout << "Printing list A sorted by ID:\n------------------------------" << endl;
    cout << endl;
    A.sort("id");
    A.printList();
    cout << endl;
    
    //Print list sorted by gpa
    cout << "Printing list A sorted by GPA\n------------------------------" << endl;
    cout << endl;
    A.sort("gpa");
    A.printList();
    cout << endl;
    
    //Find and print a student
    cout << "Retrieving Student...\n------------------------------" << endl;
    cout << A.retrieveStudent(1044002).name << endl;
    cout << endl;

    return 0;
}
