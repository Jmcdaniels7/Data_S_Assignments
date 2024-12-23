/* Program name: M02 Programming assignment 2
* Author: Jacob McDaniels
* Date last updated: 11/6/2024
* Purpose: Use classes and insert method to be inserted into an ordered linked list
*/
#include "person.h"
#include "orderedLinkedList.h"
#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <map>

void resetStream();

int main()
{
    orderedLinkedList<Person> list;
    Person** persons;

    std::string name;
    int age;
    int numPeople = 5;

    persons = new Person*[numPeople];

    for (int i = 0; i < numPeople; i++)
    {
        

        std::cout << "What is your name?" << std::endl;
        std::cin >> std::ws;
        getline(std::cin, name);
        

        std::cout << "What is your age?" << std::endl;
        std::cin >> age;

        if (age <= 0)
        {
            resetStream();
            std::cin >> age;
        }
        
        persons[i] = new Person(name, age);
    }

    for (int i = 0; i < numPeople; i++)
    {
        list.insertFirst(*(persons[i]));
        delete persons[i];
    }
    delete[] persons;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Please enter a valid age!" << std::endl;
}