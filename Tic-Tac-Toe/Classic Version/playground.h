//
//  playground.h
//  Raul's Playground
//
//  Created by Raul Muniz on 1/22/18.
//  Copyright © 2018 Raul Muniz. All rights reserved.
//

#ifndef playground_h
#define playground_h

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Connect4
{
private:
    int rows;
    int columns;
    char** board;
    char currentPiece;
    bool over = false;
    int userColumn;
    int numPlayers;
    
    void DrawBoard()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cout << board[i][j];
            }
            cout << endl;
        }
    }
    
    void initilizeBorder()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                board[i][j] = ' ';
            }
        }
        char counter = '0';
        
        //set column counters
        for (int j = 2; j < columns - 1; j++)
        {
            board[0][j] = counter;
            counter = counter + 1;
        }
        
        counter = '0';
        
        //set row counters and dividers
        for (int i = 1; i < rows - 1; i++)
        {
            board[i][0] = counter;
            board[i][1] = '|';
            board[i][columns - 1] = '|';
            counter = counter + 1;
        }
        
        //set bottom dashes
        for (int j = 1; j < columns; j++)
        {
            board[rows - 1][j] = '-';
        }
    }
    
    bool makeMove(char piece, int column)
    {
        column = column + 2;
        //int ceiling = column - 2;
        
        //check to see if out of range
        if (column < 2)
        {
            return false;
        }
        
        if (column > columns -2)
        {
            return false;
        }
        
        //check to see if column is full
        if (board[1][column] != ' ')
        {
            return false;
        }
        
        //Drop piece
        int i = 1;
        while (board[i + 1][column] == ' ' && i < rows )
        {
            i++;
        }
        
        //set value
        board[i][column] = currentPiece;
        
        if (currentPiece == 'X')
        {
            currentPiece = 'O';
        }
        else
        {
            currentPiece = 'X';
        }
        
        return true;
    }
    
    int GetAIMove()
    {
        //bad playing, shame shame
        {
            srand(time(0));
            return rand() % (columns - 2) + 2;
        }
    }
    
    void move()
    {
        //if single player vs AI
        if (numPlayers == 1)
        {
            if (currentPiece == 'X')
            {
                cout << "Player " << currentPiece << " please choose a column." << endl;
                cin >> userColumn;
                
                while (makeMove(currentPiece, userColumn) == false)
                {
                    cout << "Invalid move, please choose another column." << endl;
                    cin >> userColumn;
                }
            }
            else
            {
                userColumn = GetAIMove();
                
                while (makeMove(currentPiece, userColumn) == false)
                {
                    userColumn = GetAIMove();
                }
            }
        }
        
        //If two players are playing
        else
        {
            cout << "Player " << currentPiece << " please choose a column." << endl;
            cin >> userColumn;
            
            while (makeMove(currentPiece, userColumn) == false)
            {
                cout << "Invalid move, please choose another column." << endl;
                cin >> userColumn;
            }
        }
    }
    
    //finds the index of the last piece placed
    int lastMove()
    {
        int index = 1;
        
        while (board[index][userColumn] == ' ')
        {
            index++;
        }
        
        return index;
    }
    
    bool GameOver()
    {
        for (int i = 1; i < rows - 1; i++)
        {
            for (int j = 2; j < columns - 2; j++)
            {
                if (board[i][j] == 'X' || board[i][j] == 'O')
                {
                    if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2]
                        && board[i][j + 2] == board[i][j + 3])
                    {
                        return true;
                    }
                }
            }
        }
        
        for (int i = 1; i < rows - 1; i++)
        {
            for (int j = 2; j < columns - 2; j++)
            {
                if (board[i][j] == 'X' || board[i][j] == 'O')
                {
                    if (board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j]
                        && board[i + 2][j] == board[i + 3][j])
                    {
                        return true;
                    }
                }
            }
        }
        
        for (int i = 1; i < rows - 1; i++)
        {
            for (int j = 2; j < columns - 2; j++)
            {
                if (board[i][j] == 'X' || board[i][j] == 'O')
                {
                    if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2]
                        && board[i + 2][j + 2] == board[i + 3][j + 3])
                    {
                        return true;
                    }
                }
            }
        }
        
        for (int i = 1; i < rows - 1; i++)
        {
            for (int j = 2; j < columns - 2; j++)
            {
                if (board[i][j] == 'X' || board[i][j] == 'O')
                {
                    if (board[i][j] == board[i + 1][j - 1] && board[i + 1][j - 1] == board[i + 2][j - 2]
                        && board[i + 2][j - 2] == board[i + 3][j - 3])
                    {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    char Winner()
    {
        if (GameOver() == true)
        {
            if (currentPiece == 'X')
            {
                return 'O';
            }
            else
            {
                return 'X';
            }
        }
        return 0;
    }
    
public:
    
    Connect4()
    {
        rows = 8;
        columns = 10;
        board = new char*[rows];
        
        for (int i = 0; i < rows; ++i)
        {
            board[i] = new char[columns];
        }
        currentPiece = 'X';
        initilizeBorder();
    }
    
    Connect4(int NumRows, int NumColumns)
    {
        rows = NumRows + 2;
        columns = NumColumns + 3;
        board = new char*[rows];
        
        for (int i = 0; i < rows; ++i)
        {
            board[i] = new char[columns];
        }
        currentPiece = 'X';
        initilizeBorder();
    }
    
    
    void play()
    {
        while (over == false)
        {
            DrawBoard();
            cout << endl;
            move();
            DrawBoard();
            over = GameOver();
        }
        
        if (numPlayers != 1)
        {
            cout << "Congratulations player " << Winner() << " you are the winner!" << endl;
        }
        else
        {
            if (Winner() == 'X')
            {
                cout << "Congratulations user, you are the winner!" << endl;
            }
            else
            {
                cout << "Sorry dude, better luck next time!" << endl;
            }
        }
    }
    
    void players(int x)
    {
        numPlayers = x;
    }
    
};


#endif /* playground_h */

