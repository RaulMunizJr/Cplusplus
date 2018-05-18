// Homework 5.cpp : 
// Written by Charles Todd on 2/19/2018

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Connect4.h"
using namespace std;

void header()
{
	cout << "----------------------" << endl;
	cout << " Welcome to Connect 4!" << endl;
	cout << "----------------------" << endl;
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
		cout << "Will this be a standard board game? Enter y/n" << endl;
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

