//
//  main.cpp
//  Assignment #6
//
//  Created by Raul Muniz on 2/16/18.
//  Copyright © 2018 Raul Muniz. All rights reserved.
//
#include <iostream>
#include "myVector.h"
//#include <vector>
//using namespace std;

int main()
{
    vector<int> myvecA;
    vector<int> myvecB(10);
    vector<int> myvecC(5,-9);
    vector<std::string> myvecD(6,"Are we there yet?");
    
    //The size method should return how many items, abstractly,
    //the vector currently holds.
    std::cout << "vector A size: " << myvecA.size() << std::endl;
    std::cout << "vector B size: " << myvecB.size() << std::endl;
    std::cout << "vector C size: " << myvecC.size() << std::endl;
    std::cout << "vector D size: " << myvecD.size() << std::endl;
    
    //Capacity should report how large the array holding the items is.
    //This size will be at least that of 'size()', but could be larger.
    std::cout << "vector A capacity: " << myvecA.capacity() << std::endl;
    std::cout << "vector B capacity: " << myvecB.capacity() << std::endl;
    std::cout << "vector C capacity: " << myvecC.capacity() << std::endl;
    std::cout << "vector D capacity: " << myvecD.capacity() << std::endl;
    
    //You can access the items in the array
    //with the '[]' operator.
    std::cout << std::endl;
    std::cout << "vector B: " << std::endl;
    myvecB[3] = 43;
    myvecB[7] = 17;
    for(int i=0; i<myvecB.size(); i++)
        std::cout << myvecB[i] << std::endl;
    
    std::cout << std::endl;
    std::cout << "vector C: " << std::endl;
    myvecC[2] = 50;
    for(int i=0; i<myvecC.size(); i++)
        std::cout << myvecC[i] << std::endl;
    
    std::cout << std::endl;
    std::cout << "vector D: " << std::endl;
    myvecD[5] = "Shut up kids.";
    for(int i=0; i<myvecD.size(); i++)
        std::cout << myvecD[i] << std::endl;
    
    
    //An important ability of vectors is the ability to push items to the back
    //of the vector, which may require increasing the capacity behind the scenes.
    for(int i=0; i<16; i++)
        myvecA.push_back(2380 + i);
    std::cout << std::endl;
    std::cout << "vector A's size and capacity:" << std::endl;
    std::cout << "vector A size: " << myvecA.size() << std::endl;
    std::cout << "vector A capacity: " << myvecA.capacity() << std::endl;
    
    
    //vector's also have full stack functionality. Consider the "pop_back" method:
    for(int i=0; i<10; i++)
    {
        std::cout << "About to pop: " << myvecA.back() << std::endl;
        myvecA.pop_back();
    }
    
    std::cout << std::endl;
    std::cout << "vector A's size and capacity:" << std::endl;
    std::cout << "vector A size: " << myvecA.size() << std::endl;
    std::cout << "vector A capacity: " << myvecA.capacity() << std::endl;
    
    //Here is some addtional demo of the [] operator and how it works,
    //as well as the "push_back" method.
    std::cout << std::endl;
    for(int i=0; i<5; i++)
        myvecB[i] = i*10;
    
    myvecB.push_back(9990);
    myvecB.push_back(9991);
    myvecB.push_back(9992);
    myvecB.push_back(9993);
    myvecB.push_back(9994);
    
    for(int i=0; i<myvecB.size(); i++)
        std::cout << myvecB[i] << std::endl;
    
    
    //Now we will see, for a large example, how the vector adjusts its capacity:
    std::cout << std::endl;
    int max = 100;
    for(int i=0; i<max; i++)
    {
        int x = i*10000;
        myvecB.push_back(x);
        std::cout << "Pushing: " << x << ", size: " << myvecB.size() << ", capacity: " << myvecB.capacity() << std::endl;
    }
    return 0;
}
