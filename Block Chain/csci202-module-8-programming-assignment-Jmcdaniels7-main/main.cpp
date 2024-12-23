#include <iostream>
#include <string>
#include <limits>
#include "block.h"
#include "blockchain.h"

/* Program name: M08 PA 1
* Author: Jacob McDaniels
* Date last updated: 12/11/2024
* Purpose: Build a BlockChain and attempt to hack it
*/

int menuChoice(int count);
void orbit(int choice, int &count);
void resetStream();

int main()
{
    int choice = 0;
    int count = 0;

    while(choice != 3)
    {
        choice = menuChoice(count);
        orbit(choice, count);
    }

}

int menuChoice(int count)
{
    int choice;

    std::cout << "Welcome to Orbit, what would you like to do?" << std::endl;
    
    if(count >= 1)
    {
        std::cout << "1. Create a new block" << std::endl;
        std::cout << "2. Hack a block" << std::endl;
        std::cout << "3. Exit" << std::endl;
    }
    else
    {
        std::cout << "1. Create a new blockChain" << std::endl;
        std::cout << "2. Exit" << std::endl;

    }

    std::cin >> choice;

    while(!std::cin || (choice < 1 || choice > 3))
    {
        std::cout << "Please choose an option 1-3." << std::endl;
        
        if(count >= 1)
        {
            std::cout << "1. Create a new block" << std::endl;
            std::cout << "2. Hack a block" << std::endl;
            std::cout << "3. Exit" << std::endl;
           
        }
        else
        {
            std::cout << "1. Create a new blockChain" << std::endl;
            std::cout << "2. Exit" << std::endl;
        }
        
        resetStream();
        std::cin >> choice;
    }

    return choice;

}

void orbit(int choice, int &count)
{
    static blockChain blockChain;
    if (choice == 1 && count == 0)
    {
        count++;

    }
    else if(choice == 1 && count > 0)
    {
        std::string message;

        std::cout << "What is your message?" << std::endl;
        std::cin >> std::ws;
        getline(std::cin, message);

        blockChain.insert(message);
    }
    else if (choice == 2 && count > 0)
    {
        std::string hMessage;
        std::cout << "What is your new message?" << std::endl;
        std::cin >> std::ws;

        getline(std::cin, hMessage);

        try
        {
            blockChain.verifyChain();
            std::cout << "Chain is valid" << std::endl;

            blockChain.hack(hMessage);
            blockChain.verifyChain();
            
        }
        catch(const std::exception& e)
        {
            std::cout << "A security breach occured!" << std::endl;
            std::cerr << e.what() << std::endl;
            blockChain.chainMessages();
        }

    }
    else if ((choice == 3 && count >= 1) || (choice == 2 && count < 0))
    {
        blockChain.chainMessages();

        std::cout << "Thank you for choosing Orbit!" << std::endl;
        exit(0);

    }
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}