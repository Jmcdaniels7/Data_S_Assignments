#include <iostream>
#include <fstream>
#include "unorderedLinkedList.h"
#include "product.h"

/* Program name: M04 PA 2
* Author: Jacob McDaniels
* Date last updated: 11/20/2024
* Purpose: Use merge sort to sort 3 unorderedlinkedlists of products listed by price, desciption, and rating
*/

int compareDescription(product &item1, product &item2);
int comparePrice(product &item1, product &item2);
int compareRating(product &item1, product &item2);

int main()
{
    unorderedLinkedList<product> listByPrice;
    unorderedLinkedList<product> listByDescription;
    unorderedLinkedList<product> listByRating; 

    double price;
    std::string description;
    std::string prodNum;
    double rating;
    
    //reading the product information from the file
    std::ifstream inFile;

    inFile.open("products.txt");

    if (!inFile)
    {
        std::cout << "Unable to open file." << std::endl;
    }

    while (!inFile.eof())
    {
        inFile >> price;
        inFile >> std::ws;
        getline(inFile, description);
        getline(inFile, prodNum);
        inFile >> rating;

        product prod(price, description, prodNum, rating);

        listByPrice.insert(prod);
        listByDescription.insert(prod);
        listByRating.insert(prod);
    }

    std::cout << std::endl;
    std::cout << "original list for ordering by description: " << std::endl;
    listByDescription.print(std::cout, "\n"); // prints all of the items in the list and uses \n as the separator character.
    std::cout << std::endl
              << std::endl;
    std::cout << "original list for ordering by Price: " << std::endl;
    listByPrice.print(std::cout, "\n");
    std::cout << std::endl
              << std::endl;
    std::cout << "original list for ordering by rating" << std::endl;
    listByRating.print(std::cout, "\n");
    std::cout << std::endl
              << std::endl;

    //merge sort the 3 lists
    //Don't forget to modify unorderedLinkedList.h to add the merge sort functionality.
    
    listByPrice.mergeSort(comparePrice);
    listByDescription.mergeSort(compareDescription);
    listByRating.mergeSort(compareRating);

    std::cout << "mergeSorted by description product list: " << std::endl;
    listByDescription.print(std::cout, "\n");
    std::cout << std::endl
              << std::endl;
    std::cout << "mergeSorted by price product list: " << std::endl;
    listByPrice.print(std::cout, "\n");
    std::cout << std::endl
              << std::endl;

    std::cout << "mergeSorted by rating product list: " << std::endl;
    listByRating.print(std::cout, "\n");
    std::cout << std::endl
              << std::endl;

    return 0;
}

int compareDescription(product &item1, product &item2)
{
    if (item1.getDescription() < item2.getDescription())
    {
        return -1;

    }
    else if (item1.getDescription() == item2.getDescription())
    {
        return 0;
    }
    else if (item1.getDescription() > item2.getDescription())
    {
        return 1;
    }
    
    return 0;

}
int comparePrice(product &item1, product &item2)
{
    if (item1.getPrice() < item2.getPrice())
    {
        return -1;

    }
    else if (item1.getPrice() == item2.getPrice())
    {
        return 0;
    }
    else if (item1.getPrice() > item2.getPrice())
    {
        return 1;
    }

    return 0;

}
int compareRating(product &item1, product &item2)
{
    if (item1.getRating() < item2.getRating())
    {
        return -1;

    }
    else if (item1.getRating() == item2.getRating())
    {
        return 0;
    }
    else if (item1.getRating() > item2.getRating())
    {
        return 1;
    }

    return 0;

}
