#pragma once

/* Program name: M04 PA 1
* Author: Jacob McDaniels
* Date last updated: 11/15/2024
* Purpose: Sudoku load and solve using backtracking and recursion
*/

#include <string>
#include <iostream>


class sudoku 
{
    private:
        int sudokuNum;
        int arr[9][9];

    public:

        void loadGrid();
        bool solveGrid(int arr[9][9], int row, int column);
        //finds empty slot in sudoku
        bool findEmpty(int arr[9][9], int &row, int &column);

        //checks for a valid number to place in row, column, or 3x3 subgrid
        bool validNum(int row, int column, int number);

        friend std::ostream &operator<<(std::ostream &os, const sudoku &sudokuSolve);
        
};