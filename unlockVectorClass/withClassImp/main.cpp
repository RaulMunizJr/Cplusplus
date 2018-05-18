//
//  main.cpp
//  Raul's Playground
//
//  Created by Raul Muniz on -/-/-.
//  Copyright © 2017 Raul Muniz. All rights reserved.
//

#include <iostream>
#include "playground.h" //replace this with your own class when ready
//#include <vector>    //include this instead of the stl vector class when ready
//using namespace std;


//Part 1:  Run the test code using the stl vector class.  Make sure you understand the output
//           and how the vector class works.
//Part 2:  Create your own vector class (in the file "myVector.h").  To test your vector class,
//           Swap the #include statements above so that the test code uses your vector class instead of the stl vector class.
//
//           YOU MAY NOT CHANGE ANY PART OF THE TEST CODE other than swapping the included files.
//         Your vector class must yield the exact same results from the test code as the stl vector class,
//         with the following exceptions: The "capacity" method may return different values (ie, you may choose any resizing method you want,
//           but you should consider what is the smartest approach with respect to efficiency).  Additionally, for the 0-parameter constructor and
//           the 1-parameter, you do not need to initialize the values of the vector items (but you must for the 2-parameter constructor).
//         Beyond these items, your code must behave the same as for the stl vector.



int main()
{
    vector<int> myvecA;
    vector<int> myvecB(10);
    vector<int> myvecC(5, -9);
    vector<std::string> myvecD(6, "Are we there yet?");
    
    //The size method should return how many items, abstractly,
    //the vector currently holds.
    std::cout << "Vector A size: " << myvecA.size() << std::endl;
    std::cout << "Vector B size: " << myvecB.size() << std::endl;
    std::cout << "Vector C size: " << myvecC.size() << std::endl;
    std::cout << "Vector D size: " << myvecD.size() << std::endl;
    
    //Capacity should report how large the array holding the items is.
    //This size will be at least that of 'size()', but could be larger.
    std::cout << "Vector A capacity: " << myvecA.capacity() << std::endl;
    std::cout << "Vector B capacity: " << myvecB.capacity() << std::endl;
    std::cout << "Vector C capacity: " << myvecC.capacity() << std::endl;
    std::cout << "Vector D capacity: " << myvecD.capacity() << std::endl;
    
    //You can access the items in the array
    //with the '[]' operator.
    std::cout << std::endl;
    std::cout << "Vector B: " << std::endl;
    myvecB[3] = 43;
    myvecB[7] = 17;
    for (int i = 0; i<myvecB.size(); i++)
        std::cout << myvecB[i] << std::endl;
    
    std::cout << std::endl;
    std::cout << "Vector C: " << std::endl;
    myvecC[2] = 50;
    for (int i = 0; i<myvecC.size(); i++)
        std::cout << myvecC[i] << std::endl;
    
    std::cout << std::endl;
    std::cout << "Vector D: " << std::endl;
    myvecD[5] = "Shut up kids.";
    for (int i = 0; i<myvecD.size(); i++)
        std::cout << myvecD[i] << std::endl;
    
    
    //An important ability of vectors is the ability to push items to the back
    //of the vector, which may require increasing the capacity behind the scenes.
    for (int i = 0; i<16; i++)
        myvecA.push_back(2380 + i);
    std::cout << std::endl;
    std::cout << "Vector A's size and capacity:" << std::endl;
    std::cout << "Vector A size: " << myvecA.size() << std::endl;
    std::cout << "Vector A capacity: " << myvecA.capacity() << std::endl;
    
    
    //vector's also have full stack functionality.  Consider the "pop_back" method:
    for (int i = 0; i<10; i++)
    {
        std::cout << "About to pop: " << myvecA.back() << std::endl;
        myvecA.pop_back();
    }
    
    std::cout << std::endl;
    std::cout << "Vector A's size and capacity:" << std::endl;
    std::cout << "Vector A size: " << myvecA.size() << std::endl;
    std::cout << "Vector A capacity: " << myvecA.capacity() << std::endl;
    
    //Here is some addtional demo of the [] operator and how it works,
    //as well as the "push_back" method.
    std::cout << std::endl;
    for (int i = 0; i<5; i++)
        myvecB[i] = i * 10;
    
    myvecB.push_back(9990);
    myvecB.push_back(9991);
    myvecB.push_back(9992);
    myvecB.push_back(9993);
    myvecB.push_back(9994);
    
    for (int i = 0; i<myvecB.size(); i++)
        std::cout << myvecB[i] << std::endl;
    
    
    //Now we will see, for a large example, how the vector adjusts its capacity:
    std::cout << std::endl;
    int max = 100;
    for (int i = 0; i<max; i++)
    {
        int x = i * 10000;
        myvecB.push_back(x);
        std::cout << "Pushing: " << x << ", size: " << myvecB.size() << ", capacity: " << myvecB.capacity() << std::endl;
    }
    
    return 0;
}

