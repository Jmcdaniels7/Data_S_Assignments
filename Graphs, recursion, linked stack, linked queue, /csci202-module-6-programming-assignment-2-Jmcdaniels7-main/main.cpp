#include <string>
#include <iostream>
#include <regex>
#include <iomanip>
#include <vector>
#include <fstream>
#include "graph.h"

/* Program name: M06 PA 2
* Author: Jacob McDaniels
* Date last updated: 11/29/2024
* Purpose: Search for paths between prompted IP addresses
*/

int main()
{
    graphType Graph;
    std::string startIP;
    std::string endIP;

    //vector loaded and graph created per adjanency list from routes.txt
    Graph.createGraph("routes.txt");

    std::cout << "Enter the starting ip: " << std::endl;
    std::cin >> std::ws;

    getline(std::cin, startIP);

    std::cout << "Enter the goal ip: " << std::endl;
    std::cin >> std::ws;

    getline(std::cin, endIP);
    
    std::cout << Graph.findPath(startIP, endIP) << std::endl;
}

