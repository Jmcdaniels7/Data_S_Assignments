#include <string>
#include <iostream>
#include <fstream>
#include "hashTable.h"

/* Program name: M07 PA 1
* Author: Jacob McDaniels
* Date last updated: 12/8/2024
* Purpose:  Create and Test two hash table classes for efficiency
*/

int main()
{
    int num; 
    int number;

    // initializing hashTables
    hashTable hashTableOne;
    hashTableTwo hashTableTwo;

    std::ifstream file;

    file.open("nums.txt");

    if (!file)
    {
        std::cout << "Unable to open file" << std::endl;
    }
    else
    {
        while(!file.eof())
        {
            file >> number;
            hashTableOne.insert(number);
            hashTableTwo.insertH(number);
            
        }

    }
    
    // output and input for number
    std::cout << "Enter a number: " << std::endl;
    std::cin >> num;

    while(!std::cin || num < 0)
    {
        std::cout << "Please choose a positive integer!" << std::endl;

        std::cout << "Enter a number: " << std::endl;
        std::cin >> num;

    }

    // searching for prompted number in hashTable 1
    if(hashTableOne.find(num))
    {
        std::cout << "Number found in first Hash Table!" << std::endl;
    }
    else
    {
        std::cout << "Number not found." << std::endl;
    }

    //searching for prompted number in hashTable 2
    if (hashTableTwo.find(num))
    {
        std::cout << "Number found in second Hash Table!" << std::endl;

    }
    else
    {
        std::cout << "Number not found." << std::endl;
    }
}