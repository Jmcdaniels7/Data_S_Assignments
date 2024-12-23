/* Program name: M04 PA1
* Author: Jacob McDaniels
* Date last updated: 11/8/2024
* Purpose: Recursive backtracking for sudoku solutions
*/

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "sudoku.h"


int main()
{ 
    sudoku sudoku;

    sudoku.loadGrid();

    std::cout << sudoku << std::endl;

    if (sudoku.solveGrid())
    {
        std::cout << "Solved Sudoku:" << std::endl;

        std::cout << sudoku << std::endl;

    }
    else
    {
        std::cout << "Unsolved Sudoku" << std::endl;
    }

    
    
}
