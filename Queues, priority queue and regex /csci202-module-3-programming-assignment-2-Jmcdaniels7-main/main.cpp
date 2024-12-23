/* Program name: M03 PA 2
* Author: Jacob McDaniels
* Date last updated: 11/9/2024
* Purpose: Bug report system with priority queue
*/
#include <iostream>
#include <string>
#include <regex>
#include "priorityQueue.h"
#include "linkedQueue.h"
#include "BugReport.h"
#include "unorderedLinkedList.h"
#include "linkedList.h"

int menu();

int main() 
{

    std::string date; 
    std::string reporter;
    std::string bugDescript;
    std::string status;
    int id = 0;
    int priority;

    priorityQueue<BugReport> bugQueue;
    unorderedLinkedList<BugReport> finishedReports;

    while(true)
    {
        int menuChoice = menu();

        if(menuChoice < 1 || menuChoice > 3)
        {
            std::cout << ("Please choose valid choices between 1 and 3.") << std::endl;
            menuChoice = menu();
        }

        // system for reporting bug reports
        if (menuChoice == 1)
        {
            std::cout << "Enter the date of the report (yyyy-mm-dd):" << std::endl;

            std::cin >> std::ws;
            getline(std::cin, date);

            std::regex dateStr{"([0-9]{4})-(0?[1-9]|1[0-2])-([1-2][0-9]|3[0-1]|0?[1-9])"};

            std::smatch parts;

            if(std::regex_match(date, parts, dateStr))
            {
                int day = std::stoi(parts[3]);
                int month = std::stoi(parts[2]);
                int year = std::stoi(parts[1]);
            }
            else
            {
                std::cout << "The date entered is not valid. Please check that the date entered is in the correct format." << std::endl;
                std::cin >> std::ws;
                getline(std::cin, date);
            }

            std::cout << "Enter the name of the reporter: " << std::endl;

            std::cin >> std::ws;
            getline(std::cin, reporter);

            std::cout << "Describe the bug: " << std::endl;

            std::cin >> std::ws;
            getline(std::cin, bugDescript);

            std::cout << "What is the priority 1 - 10 (1 is low, 10 is high):" << std::endl;

            std::cin >> priority;
            id++;

            status = "new";

            // although enqueue should only evaluate the priority variable
            BugReport report(id, bugDescript, reporter, status, priority, date);
            bugQueue.enqueue(report);
        }
        else if (menuChoice == 2)
        {
            // grab first bug report of priority queue and insert it into finished bug reports linked list.
            BugReport newStatus = bugQueue.front();
            newStatus.setStatus("In Progress");

            std::cout << newStatus << std::endl;

            newStatus.setStatus("Finished");

            finishedReports.insert(newStatus);

            bugQueue.dequeue();

        }
        else if (menuChoice == 3)
        {
            std::cout << "Quitting:" << std::endl;

            // first print out finished bug reports
            std::cout << "List of Finished Bug Reports: " << std::endl;
            std::cout << finishedReports.print() << std::endl;

            // print uncompleted bug reports
            //clear the queue of bug reports
            std::cout << "List of Unfinished Bug Reports:" << std::endl;
            std::cout << std::endl;
            
            while(!bugQueue.isEmptyQueue())
            {
                std::cout << bugQueue.front() << std::endl;

                bugQueue.dequeue();
            }
            finishedReports.initializeList();
            
            break;
        }
    }
}

int menu()
{
    int menuChoice;

    std::cout << "Please choose from the following menu:" << std::endl;
    std::cout << "1. Enter Bug Report" << std::endl;
    std::cout << "2. Distribute Bug Report" << std::endl;
    std::cout << "3. Quit" << std::endl;

    std::cin >> menuChoice;

    return menuChoice;
}

