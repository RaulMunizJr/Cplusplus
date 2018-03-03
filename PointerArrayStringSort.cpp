//
//  main.cpp
//  Raul's Playground
//
//  Created by Raul Muniz on -/-/-.
//  Copyright © 2017 Raul Muniz. All rights reserved.
//


#include <iostream>
using namespace std;

int findFirst(string *x, int start, int end)
{
    int first = start;
    for(int i=start; i <= end; i++)
    {
        if(x[i] < x[first])
        {
            first = i;
        }
    }
    return first;
}
/*
void swap(string &s1, string &s2) {
    string temp = s1;
    s1 = s2;
    s2 = temp;
}
*/
void sortArray(string *items, int start, int end)
{
    for(int i=start; i<=end; i++)
    {
        int min = findFirst(items,i, end);
        swap(items[i], items[min]);
    }
}


int main()
{
    cout<<"Welcome! How many Pokemon do you own?"<<endl;
    int num = 0;
    cin >> num;
    
    cout<< "Ok, enter the names!"<<endl;
    string *names = new string[num];
    for(int i=0; i<num; i++)
    {
        cin>>names[i];
    }
    sortArray(names, 0, num-1);
    cout<<"Thanks, here are the pokemon you entered: ";
    for(int i=0; i<num; i++)
    {
        cout << names[i] << " ";
    }
    cout << endl;
    
    
    return 0;
}
