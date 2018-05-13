//
//  DiceRollStats.cpp
//  Assignment #3
//
//  Created by Raul Muniz on 1/27/18.
//  Copyright © 2018 Raul Muniz. All rights reserved.
//

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<iomanip>

using namespace std;

void Roll(int numThrows, int maxRoll, int numdice, double *data)
{
    int roll;
    double temp;
    
    for (int i = 1; i <= numThrows; i++)
    {
        roll = rand() % (maxRoll - numdice + 1) + numdice;
        temp = data[roll - numdice];
        temp++;
        data[roll - numdice] = temp;
    }
}
//************************************************************************************
void stats(int numThrows, int numdice, int maxRoll, double *data)
{
    int index = maxRoll / 6, width, total = 0;
    cout << "ROLL STATISTICS:" << endl;
    cout << "------------------" << endl;
    for (int i = 0; i <= (maxRoll - numdice); i++)
    {
        if (index < 10)
            width = 14;
        else if (index >= 10 && index < 100)
            width = 13;
        else
            width = 12;
        
        cout << index << ":" << setw(width) << data[i]/numThrows << endl;
        index++;

        total += data[i];
    }

    if (total == numThrows)
        cout << "Successfully threw " << numdice << " dices " << total << " times!" << endl;
}
//************************************************************************************


int main()
{
    srand(time(NULL));
    int numThrows, numdice, maxRoll;
    
    cout << "How many dices do you want to throw?" << endl;
    cin >> numdice;
    maxRoll = 6 * numdice;
    cout << "How many times do you want to throw the six-sided dice(s)?" << endl;
    cin >> numThrows;
    double *data = new double[5 * numdice];
    

    for (int i = 0; i <= (5 * numdice); i++)
        data[i] = 0;

    Roll(numThrows, maxRoll, numdice, data);
    stats(numThrows, numdice, maxRoll, data);
    
    return 0;
}

/*********Practice with "set-precisions"*****************************
 void rolling(double storedThrows[], int num, int dice)
 {
 int roll;
 srand(time(0));
 
 for (int i = 0; i < num; i++)
 {
 roll = rand() % (dice * 6) + dice;
 storedThrows[roll] = storedThrows[roll] +1;
 }
 }
 
 int main()
 {
 int numDice;
 int numThrows;
 int size;
 
 cout << "How many six sided dice would you like to throw?" << endl;
 cin >> numDice;
 cout << endl;
 
 cout << "How many times would you like to throw the dice?" << endl;
 cin >> numThrows;
 cout << endl;
 
 size = numDice * 6;
 double * throws = new double[numDice * 6];
 
 for (int i = 0; i <= size; i++)
 {
 throws[i] = 0;
 }
 
 rolling(throws, numThrows, numDice);
 
 for (int i = numDice; i <= size; i++)
 {
 double results = (throws[i] / numThrows) * 100;
 cout << showpoint << setprecision(3);
 cout << setw(2) << i << ":" << setw(10) << right << results << endl;
 }
 
 return 0;
 }
 */
