//
//  main.cpp
//  Assignment #1
//
//  Created by Raul Muniz on 1/16/18.
//  Copyright © 2018 Raul Muniz. All rights reserved.
//
/*
#include <iostream>
#include <stdlib.h>
//#include "records.h"
using namespace std;
                                  PART 1
 
int main() {
    cout<<"Let's play a Number Guessing Game! What is Your Name?"<<endl;
    string name;
    getline(cin,name);
    
    int num_tries=0;
    int guessedNumber;
    srand (time(NULL));
    int randomNumber=rand() % 100 + 1;
    
    do
        {
            cout << "Guess a Number between 1 and 100: "<<endl;
            cin >> guessedNumber;
            num_tries++;
            if (guessedNumber > randomNumber)
            {
                cout << "Too high!!\n";
            }
            else if (guessedNumber < randomNumber)
            {
                cout << "Too low!!\n";
            }
            else
            {
                cout << "\nYou Win!!"<<endl;
            cout<<"It took you " << num_tries << " guesses "<<name<<"!"<<endl;
            }
        }while(guessedNumber != randomNumber);
    
    if (-1<num_tries && num_tries < 5)
    {
        cout<<"Amazing! Or was it luck?"<<endl;
    }
    else if(4<num_tries && num_tries < 7)
    {
        cout<<"That's a very good score..."<<endl;
    }
    else if(6<num_tries && num_tries < 9)
    {
        cout<<"That's pretty good but you can do better..."<<endl;
    }
    else if(8<num_tries && num_tries < 11)
    {
        cout<<"Not too shabby, but not too good either..."<<endl;
    }
    else{
        cout<<"What a terrible score!..."<<endl;
    }
    return 0;
}
*/

    /*
    cout<<"Think you’ve got what it takes to make the top ten?  Let’s find out!"<<endl;
    cout<<"What is your name?"<<endl;
    string name;
    getline(cin,name);
    
    int num_tries=0;
    int guessedNumber;
    srand (time(NULL));
    int randomNumber=rand() % 100 + 1;
    
    do
    {
        cout << "Guess a Number between 1 and 100: "<<endl;
        cin >> guessedNumber;
        num_tries++;
        if (guessedNumber > randomNumber)
        {
            cout << "Too high!!\n";
        }
        else if (guessedNumber < randomNumber)
        {
            cout << "Too low!!\n";
        }
        else
        {
            cout << "\nYou Win!!"<<endl;
            cout<<"It took you " << num_tries << " guesses "<<name<<"!"<<endl;
        }
    }while(guessedNumber != randomNumber);
    
    if (-1<num_tries && num_tries < 5)
    {
        cout<<"Amazing! Or was it luck?"<<endl;
    }
    else if(4<num_tries && num_tries < 7)
    {
        cout<<"That's a very good score..."<<endl;
    }
    else if(6<num_tries && num_tries < 9)
    {
        cout<<"That's pretty good but you can do better..."<<endl;
    }
    else if(8<num_tries && num_tries < 11)
    {
        cout<<"Not too shabby, but not too good either..."<<endl;
    }
    else{
        cout<<"What a terrible score!..."<<endl;
    }*/
 //                 PART 2

#include <stdlib.h>
#include <iostream>
#include <fstream>//Read file
#include <ctime>//Rand
#include "records.h"
using namespace std;

void theGame(int &numGuess)
{
    numGuess = 0;
    int guess;
    int randNum = (rand() % 100) + 1; //plus one to get the number wanted.
    do{
        cout << "Guess the number from 1 to 100" << endl;
        cin >> guess;
        numGuess++;
        if (guess > 100 || guess < 0)
        {
            cout << "Remember to make a good guess..." << endl;
        }
        else if (guess > randNum)
        {
            cout << "Too high!!" << endl;
        }
        else if (guess < randNum)
        {
            cout << "Too low!!" << endl;
        }
    } while (guess != randNum);
}
void text(int numGuess)
{
    if (numGuess <= 4 && numGuess > 0)
    {
        cout << "Amazing! Or was it luck?\n" << endl;
    }
    else if (numGuess == 5 || numGuess == 6)
    {
        cout << "That's a very good score...\n" << endl;
    }
    else if (numGuess == 7 || numGuess == 8)
    {
        cout << "That's pretty good but you can do better...\n" << endl;
    }
    else if (numGuess == 9 || numGuess == 10)
    {
        cout << "Not too shabby, but not too good either...\n" << endl;
    }
    else
    {
        cout << "What a terrible score!...\n" << endl;
    }
    
    cout << "It took you " << numGuess << " tries to accurately guess the number!" << endl;
}

void showLeaderboard()
{
    ifstream Records;
    string line; //Used for getting linefeed.
    int scores = 1; //Initialized to 1 to print out 10 scores.
    Records.open("Records.txt");
    
    cout << "\tThe top 10 High Scores are:" << endl;
    cout<<"--------------------------------------"<<endl;
    
    if (Records.is_open())
    {
        while (getline(Records, line) && scores <= 10)
        {
            cout << line << endl;
            scores++;
        }
        cout << endl;
    }
    else
    {
        cout << "File does not exist." << endl;
    }
    Records.close();
}

//**************************************************************************

int main()
{
    srand(time(NULL));
    
    int leaderboardGuess, playerGuess = 0;
    string firstName, lastName, word;
    
    linkedlist list;
    
    ifstream leaderboard;
    ofstream leaderboardOut;
    
    cout << "Welcome to the Number Guessing Game!" << endl;
    showLeaderboard();
    
    leaderboard.open("Records.txt");
    
    leaderboard >> firstName;
    leaderboard >> lastName;
    leaderboard >> leaderboardGuess;
    
    list.initialize(firstName, lastName, leaderboardGuess);
    
    while (getline(leaderboard, word))
    {
        leaderboard >> firstName;
        leaderboard >> lastName;
        leaderboard >> leaderboardGuess;
        
        list.initialize(firstName, lastName, leaderboardGuess);
    }
    leaderboard.close();

//***********************************************************************
    cout << "What is your name?" << endl;
    cin >> firstName >> lastName;
    
    theGame(playerGuess);
    text(playerGuess);
    
    list.insertNode(firstName, lastName, playerGuess);
    
    leaderboardOut.open("Records.txt");
    list.save(leaderboardOut);
    leaderboardOut.close();
    
//************************************************************************
    if (list.checkTop10(playerGuess) == true)
    {
        cout << "Congratulations, you made it to the top 10!" << endl;
    }
    
    return 0;
}
