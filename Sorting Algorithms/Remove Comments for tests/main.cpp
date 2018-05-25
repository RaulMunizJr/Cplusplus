//
//  main.cpp
//  SortingAlgorithms
//
//  Created by Raul Muniz on 5/24/18.
//  Copyright © 2018 Raul Muniz. All rights reserved.
//

#include <iostream>

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "mergeSort.h"
#include "minHeap.h"
#include "quickSort.h"
#include "radixSort.h"
#include "selectionSort.h"
using namespace std;

int main()
{
    cout << "Sorting Beginning....\n" << endl;
    ifstream input;
    input.open("numbers.txt");
    ofstream output;
    output.open("sortedNumbers.txt");
    
    int size = 10000000;
    unsigned int * nums = new unsigned int[size];
    
    int index = 0;
    
    while (index < size)
    {
        input >> nums[index];
        index++;
    }
    
    clock_t startTime, endTime;

    //******************* Remove comments to test sorting algorithms *********************//
    startTime = clock();
    heapSort(nums, 0, size - 1);
    //mergeSort(nums, 0, size - 1);
    //selectionSort(nums, size);
    //quicksort(nums, 0, size-1);
    //radixSort(nums, 0, size - 1);
    endTime = clock();
    
    cout << "Sort took: " << endTime - startTime << " milliseconds" << endl;
    
    
    for (int i = 0; i < size; i++)
    {
        output << nums[i] << endl;
    }
    
    return 0;
}
