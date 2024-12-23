#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include "burger.h"
#include "set.h"

/* Program name: M06 PA 1
* Author: Jacob McDaniels
* Date last updated: 11/27/2024
* Purpose: Use a AVL tree in a set for toppings
*/

void resetStream();
int promptNumPatties();
const int maxToppings = 7;

void promptToppings(burger &Burger, int &count);

int main()
{
    int pat = promptNumPatties();

    burger myBurger(pat);

    int topCount = 0;
    promptToppings(myBurger, topCount);

    

    std::cout << myBurger.tostring() << std::endl;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int promptNumPatties()
{
    int pat = 0;
    std::cout << "How many patties do you want on your burger? ";
    std::cin >> pat;
    std::cout << std::endl;
    if (!std::cin && pat < 0)
    {
        resetStream();
        
    }
    else
    {
        return pat;
        
    }
    std::cout << "You entered an invalid amount of patties. Please try again." << std::endl;

    return promptNumPatties();
}

void promptToppings(burger &Burger, int &count)
{
    int topInt = 0;
    count = 0;
    
    for (int i = 0; i < maxToppings; i++)
    {
        std::cout << "Please choose a topping from the list. Enter -1 to stop adding toppings." << std::endl;
        for (int i = 0; i < TOP_NUM; i++)
        {
            //map could be used
            std::cout << i + 1 << ": " << toppingStr[i] << std::endl;
        }
        std::cin >> topInt;
        std::cout << std::endl;
        if (topInt == -1)
        {
            break;
        }
        while (!std::cin || topInt <= 0 || topInt > TOP_NUM)
        {
            if (!std::cin)
            {
                resetStream();
            }
            std::cout << "You did not choose a valid topping. Please try again." << std::endl;
            std::cin >> topInt;
            std::cout << std::endl;
        }

        Burger.addTopping(toppingList[topInt - 1]);
        count++;

        if (topInt > maxToppings)
        {
            break;
        }
    }
}
