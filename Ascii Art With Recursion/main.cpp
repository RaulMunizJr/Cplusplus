//
//  main.cpp
//  Assignment #10
//
//  Created by Raul Muniz on 3/26/18.
//  Copyright © 2018 Raul Muniz. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int rowAmt = 0, columnAmt = 0;

void printList(int rowAmt, int columnAmt, char **position)
{
    for (int i = 0; i < rowAmt; i++)
    {
        for (int j = 0; j < columnAmt; j++)
        {
            cout << position[i][j];
        }
        cout << endl;
    }
}

bool outOfRange(int currentRow, int currentCol)
{
    if (currentRow > rowAmt - 1 || currentRow < 0 || currentCol > columnAmt - 1 || currentCol < 0)
        return true;
    return false;
}

void fill(char **position, int row, int column, char symbol)
{
    //Base Case
    if (outOfRange(row, column) || position[row][column] != ' ')
        return;
    //Recursive Case
    else
    {
        fill(position, row - 1, column, symbol);
        fill(position, row, column - 1, symbol);
        position[row][column] = symbol;
        fill(position, row + 1, column, symbol);
        fill(position, row, column + 1, symbol);
    }
}

int main()
{
    char **position, choice, end, symbol;
    
    position = new char*[rowAmt];
    for (int i = 0; i < rowAmt; ++i)
        position[i] = new char[columnAmt];
    
    ifstream in;
    ofstream out;
    string name, line;
    int row, column;
    
BEGIN:
    do
    {
        
        cout << "Select from the options: (L)oad art. (F)ill. (S)ave art." << endl;
        cout << "Choice? ";
        cin >> choice;
        if (choice == 'L')
        {
            for (int i = 0; i < rowAmt; i++)
                delete[] position[i];
            delete[] position;
            cout << endl;
            cout << "Filename: ";
            cin >> name;
            in.open(name);
            
            if (!in)
            {
                cout << "File doesn't exist!" << endl;
                goto BEGIN;
            }
            
            while (getline(in, line))
            {
                if (line.length() > columnAmt)
                    columnAmt = line.length();
                
                rowAmt++;
            }
            in.close();
        
            position = new char*[rowAmt];
            for (int i = 0; i < rowAmt; ++i)
                position[i] = new char[columnAmt];

            in.open(name);
            for (int i = 0; getline(in, line); i++)
            {
                for (int j = 0; j < columnAmt; j++)
                {
                    if (line.length() < columnAmt && j >= line.length())
                    {
                        position[i][j] = ' ';
                    }
                    else
                    {
                        position[i][j] = line[j];
                    }
                }
            }
            
            printList(rowAmt, columnAmt, position);
            in.close();
            
            goto BEGIN;
        }
        else if (choice == 'F')
        {
            cout << "\nWelcome! Please begin drawing!" << endl;
            cout<< "------------------------------"<<endl;
            cout << "\tSelect cell Row: ";
            cin >> row;
            cout << "\tSelect cell Column: ";
            cin >> column;
            cout << "\tSymbol: ";
            cin >> symbol;
            //2) Fill
            cout << endl;
            cout << "Symbol Added" << endl;
            fill(position, row, column, symbol);
            printList(rowAmt, columnAmt, position);
        }
        else if (choice == 'S')
        {
            cout << "Drawing has been saved!" << endl;
            out.open(name);
            //2) Save onto file
            for (int i = 0; i < rowAmt; i++)
            {
                for (int j = 0; j < columnAmt; j++)
                {
                    out << position[i][j];
                }
                out << '\n';
            }
            out.close();
        }
        else
        {
            cout << "Please input 'L', 'F', or 'S'" << endl;
            goto BEGIN;
        }
        
        cout << "\tExit: (Y)es or (N)o? ";
        cin >> end;
        printList(rowAmt, columnAmt, position);
    } while (end != 'Y' && end != 'y');
    
    return 0;
}
