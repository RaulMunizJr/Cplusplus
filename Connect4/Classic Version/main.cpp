//
//  main.cpp
//  Raul's Playground
//
//  Created by Raul Muniz on -/-/-.
//  Copyright © 2017 Raul Muniz. All rights reserved.
//

#include <iostream>
#include "playground.h"
using namespace std;

void header()
{

    cout << "\t\tConnect 4!" << endl;
    cout << "------------------------------" << endl;
}

int main()
{
    //declare variables
    int rows = 8;
    int columns = 10;
    char playAgain = 'y';
    char gameType;
    int play;
    
    header();
    cout << endl;
    
    while (playAgain == 'y' || playAgain == 'Y')
    {
        cout << "Will this be a standard board game? [Enter Y/N]" << endl;
        cin >> gameType;
        
        if (gameType == 'n' || gameType == 'N')
        {
            cout << "How many rows? " << endl;
            cin >> rows;
            cout << "How many columns" << endl;
            cin >> columns;
            
            cout << "Enter 1 for vs AI or 2 for PVP" << endl;
            cin >> play;
        }
        
        if (gameType == 'y' || gameType == 'Y')
        {
            cout << "Enter 1 for vs AI or 2 for PVP" << endl;
            cin >> play;
        }
        
        Connect4 G(rows, columns);
        Connect4 Game;
        
        
        if (gameType == 'n' || gameType == 'N')
        {
            G.players(play);
            G.play();
        }
        else
        {
            Game.players(play);
            Game.play();
        }
        
        cout << "play again?" << endl;
        cin >> playAgain;
    }
    
    return 0;
}
