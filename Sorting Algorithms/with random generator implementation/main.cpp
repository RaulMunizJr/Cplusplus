//
//  main.cpp
//  Homework #9
//
//  Created by Raul Muniz on 3/31/18.
//  Copyright © 2018 Raul Muniz. All rights reserved.
//

/**********************************
 For this homework assignment I used
 a random number generator instead
 of the numbers.txt file
 ***********************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void selectionSort(unsigned int arr[], int size)
{
    int i, j, temp;
    for(i=0; i<size; i++)
    {
        for(j=i+1; j<size; j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

void Merge(unsigned int *a, int low, int high, int mid)
{
    int i, j, k;
    unsigned int temp[high-low+1];
    i = low;
    k = 0;
    j = mid + 1;
    while (i <= mid && j <= high){
        if (a[i] < a[j]){
            temp[k] = a[i];
            k++;
            i++;
        }
        else{
            temp[k] = a[j];
            k++;
            j++;
        }
    }
    // Insert all the remaining values from i to mid unsigned into temp[].
    while (i <= mid){
        temp[k] = a[i];
        k++;
        i++;
    }
    // Insert all the remaining values from j to high unsigned into temp[].
    while (j <= high){
        temp[k] = a[j];
        k++;
        j++;
    }
    // Assign sorted data stored in temp[] to a[].
    for (i = low; i <= high; i++){
        a[i] = temp[i-low];
    }
}
// A function to split array unsigned into two parts.
void MergeSort(unsigned int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        // Split the data unsigned into two half.
        MergeSort(a, low, mid);
        MergeSort(a, mid+1, high);
        // Merge them to get sorted output.
        Merge(a, low, high, mid);
    }
}
void MaxHeapify(unsigned int a[], int i, int n)
{
    int j;
    unsigned int temp;
    temp = a[i];
    j = 2*i;
    while (j <= n)
    {
        if (j < n && a[j+1] > a[j])
            j = j+1;
        // Break if parent value is already greater than child value.
        if (temp > a[j])
            break;
        // Switching value with the parent node if temp < a[j].
        else if (temp <= a[j])
        {
            a[j/2] = a[j];
            j = 2*j;
        }
    }
    a[j/2] = temp;
    return;
}
void HeapSort(unsigned int a[], int n)
{
    int i;
    unsigned int temp;
    for (i = n; i >= 2; i--)
    {
        // Storing maximum value at the end.
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        // Building max heap of remaining element.
        MaxHeapify(a, 1, i - 1);
    }
}
void Build_MaxHeap(unsigned int a[], int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
        MaxHeapify(a, i, n);
}
unsigned int partitionQ(unsigned int a[],unsigned int l,unsigned int u)
{
    int i,j;
    unsigned int v, temp;
    v=a[l];
    i=l;
    j=u+1;
    do
    {
        do
            i++;
        while(a[i]<v&&i<=u);
        do
            j--;
        while(v<a[j]);
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);
    a[l]=a[j];
    a[j]=v;
    return(j);
}
void quick_sort(unsigned int a[], int l, int u)
{
    int j;
    if(l<u)
    {
        j=partitionQ(a,l,u);
        quick_sort(a,l,j-1);
        quick_sort(a,j+1,u);
    }
}
unsigned int getMax(unsigned int arr[], int n)
{
    unsigned int max = arr[0];
    for ( int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
void countSort(unsigned int arr[], unsigned int n, unsigned int exp)
{
    // Count[i] array will be counting the number of array values having that 'i' digit at their (exp)th place.
    unsigned int output[n];
    int i, count[10] = {0};
    // Count the number of times each digit occurred at (exp)th place in every input.
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    // Calculating their cumulative count.
    for (i = 1; i < 10; i++)
        count[i] += count[i-1];
    // Inserting values according to the digit '(arr[i] / exp) % 10' fetched unsigned into count[(arr[i] / exp) % 10].
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    // Assigning the result to the arr pounsigned inter of main().
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
// Sort arr[] of size n using Radix Sort.
void radixsort(unsigned int arr[], unsigned int n)
{
    unsigned int exp, m;
    m = getMax(arr, n);
    // Calling countSort() for digit at (exp)th place in every input.
    for (exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int main()
{
    unsigned int a[100000],b[100000];
    int i;
    for ( i = 0; i < 100000; ++i){
        a[i] = rand();
        b[i] = a[i];
    }
    clock_t tStart = clock();
    selectionSort(a,100000);
    cout << "Selection Sort Time Taken: " << (double)(clock()-tStart)/CLOCKS_PER_SEC*1000 << " ms." << endl;
    for ( i = 0; i < 100000; ++i){
        a[i] = b[i];
    }
    tStart = clock();
    MergeSort(a,0,100000);
    cout << "Merge Sort Time Taken: " << (double)(clock()-tStart)/CLOCKS_PER_SEC*1000 << " ms." << endl;
    for ( i = 0; i < 100000; ++i)
    {
        a[i] = b[i];
    }
    tStart = clock();
    HeapSort(a,100000);
    cout << "Heap Sort Time Taken: " << (double)(clock()-tStart)/CLOCKS_PER_SEC*1000 << " ms." << endl;
    for ( i = 0; i < 100000; ++i)
    {
        a[i] = b[i];
    }
    tStart = clock();
    quick_sort(a,0,100000);
        cout << "Quick Sort Time Taken: " << (double)(clock()-tStart)/CLOCKS_PER_SEC*1000 << " ms." << endl;
    for ( i = 0; i < 100000; ++i)
    {
        a[i] = b[i];
    }
    tStart = clock();
    radixsort(a,100000);
    cout << "Radix Sort Time Taken: " << (double)(clock()-tStart)/CLOCKS_PER_SEC*1000 << " ms." << endl;
    return 0;
}
