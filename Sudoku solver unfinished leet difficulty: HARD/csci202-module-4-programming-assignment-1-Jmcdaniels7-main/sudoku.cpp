
/* Program name: M04 PA 1
* Author: Jacob McDaniels
* Date last updated: 11/15/2024
* Purpose: Sudoku load and solve using backtracking and recursion
*/

#include <string>
#include <iostream>
#include <fstream>
#include "sudoku.h"

//used from geeks for geeks
#define UNASSIGNED 0

void sudoku::loadGrid()
{
    std::ifstream file("sudoku.txt"); 

    if (file.is_open()) 
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                file >> arr[i][j];
            }
        }
    }
    else
    {
        std::cout << "Error opening the file!" << std::endl;
    }

}

bool sudoku::solveGrid(int arr[9][9], int row, int column)
{
    int row;
    int column;

    if (row == 8 && column == 9)
    {
        return true;

    }

    if (column == 9) {
        row++;
        column = 0;
    }

    if (arr[row][column] > 0)
    {
        return solveGrid(arr, row, column + 1);
    }
        
    if (!findEmpty(arr, row, column))
    {
        return true;
    }
    
    for (int i = 1; i <= 9; i++)
    {
        if (validNum(row, column, i))
        {
            arr[row][column] = i;

            if(solveGrid())
            {
                return true;
            }
        }
        arr[row][column] = UNASSIGNED;
    }
    return false;
}
std::ostream &operator<<(std::ostream &os, const sudoku &grid)
{
    //this will print the solved sudoku grid
   os << "+-----------+-----------+-----------+" << std::endl; 

    for (int i = 0; i < 9; i++)
    {
        
        os << "| ";

        for (int j = 0; j < 9; j++)
        {
            os << grid.arr[i][j];

            if ((j + 1) % 3 == 0)
            {
                os << " | ";
            }
            else
            {
                os << "   ";
            }
            
        }

        os << std::endl;

        if ((i + 1) % 3 == 0)
        {
            os << "+-----------+-----------+-----------+" << std::endl;
        }
        else
        {
            os << std::endl;
        }
    }

    return os;

}

bool sudoku::findEmpty(int &row, int &column)
{
    for (row = 0; row < 9; row++)
    {
        for(column = 0; column < 9; column++)
        {
            if(arr[row][column] == UNASSIGNED)
            {
                return true;
            }
        }
    }
    
    return false;
}

bool sudoku::validNum(int row, int column, int number)
{
    for (int i = 0; i <= 8; i++)
    {
        if (number == arr[i][column] || number == arr[row][i])
        {
            return false;
        }
    }


    int startRow = row - row & 3;
    int startColumn = column - column & 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(arr[i + startRow][j + startColumn] == number)
            {
                return false;
            }
        }
    }

    return true;
    

}
    
