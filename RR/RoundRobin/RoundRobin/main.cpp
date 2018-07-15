//
//  main.cpp
//  RoundRobin
//
//  Created by Raul Muniz on 4/7/18.
//  Copyright © 2018 Raul Muniz. All rights reserved.
//  Raul.Muniz01@utrgv.edu

#include<iostream>
#include<iomanip>
#include <fstream>
using namespace std;

double arrivalTime[500];
double process[500];
double serviceTime[500];

int size = 0;

double quantum;
double dispatchTime = 0;


void data()
{
    
    
    ifstream in("test.txt");
   
    int i = 0;
    
    cout<<"Enter Number of Processes: ";
    cin>>size;
    
    
    //Processes
    while( !in.eof() || i < size)
    {
        in>>arrivalTime[i];
        in>>serviceTime[i];
        
        process[i] = i + 1;
        i++;
    }
    
    
    cout<<"Enter the Time Quantum: ";
    cin>>quantum;
    
    cout << "Enter dispatched time : ";
    cin>> dispatchTime;
    
}

void displayData()
{
    cout<<"Process ID || Execution Time || Arrival Time\n";
    
    for(int i = 0; i < size; i++)
    {
    
        cout<< "\t" << i + 1<<"\t\t\t"<<serviceTime[i]<<"\t\t\t"<<arrivalTime[i]<<endl;
        
    }
    
}

void calculate_wt_tt()
{
    
    
    double servicesTwo[500];
    
    bool flag = true;
    bool flag2 = false;
    
    double a_t = 0, wt = 0, tnt = 0;
    float avg = 0, avtnt = 0;
    
    //read data
    for (int i = 0; i<size; i++)
    {
        
        servicesTwo[i] = serviceTime[i];
        
    }
    
    
    a_t = arrivalTime[0];
    
    cout<<"Process ID || Wait Time || Turn around Time \n";
    
    while(flag)
    {
        
        for (int i = 0; i<size; i++)
            
        {
            
            if (a_t < arrivalTime[i] || process[i]<0)
                
            {
                
                continue;
                
            }
            
            
            
            flag2= true;
            
            a_t += quantum;
            
            serviceTime[i] -= quantum;
            
            
            if (serviceTime[i] <= 0)
            {
                
                a_t += serviceTime[i];
                
                wt = a_t - servicesTwo[i] - arrivalTime[i];
                
                tnt = a_t - arrivalTime[i];
                
                cout<<"\t"<< process[i] << "\t\t\t" << wt << "\t\t\t" << tnt<<endl;
                
                process[i] = -1;
                
                avg += wt;
                
                avtnt += tnt;
                
            }
            
            avg += wt;
            avtnt += tnt;
            
            serviceTime[i] += dispatchTime;
            
        }
        
        
        if (flag2 == false)
        {
            
            a_t++;
            
        }
        
        flag2 = flag = false;
        
        for (int k = 0; k < size; k++)
        {
            if (process[k] != -1)
            {
                
                flag = true;
                
            }
            
        }
        
    }
    
    avg += wt;
    avtnt += tnt;
    
    avg = avg / (float)size;
    avtnt /= (float)size;
    
    cout<<"Average Waiting Time: " << avg<<endl;
    cout<<"Average turn around time: " << avtnt<<endl;
    
}

int main()

{
    
    data();
    
    displayData();
    
    calculate_wt_tt();
    
    
    return 0;
}

