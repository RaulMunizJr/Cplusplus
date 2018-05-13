//
//  main.cpp
//  Assignment #4
//
//  Created by Raul Muniz on 1/31/18.
//  Copyright © 2018 Raul Muniz. All rights reserved.
//

#include <iostream>
#include <string>
#include<stdlib.h>
#include "stackQueue.h"
using namespace std;


int main() {

    stackQueue<int> obj;//************************************************for any data Type, in this case an 'int'

    obj.addBack(1);
    obj.addBack(2);
    obj.addBack(3);
    obj.addBack(4);
   
    cout << obj.removeBack() << endl; // 4
    cout << obj.removeBack() << endl; // 3
    cout << obj.removeBack() << endl; // 2
    cout << obj.removeBack() << endl; // 1
    
    
    
    

    return 0;
}
