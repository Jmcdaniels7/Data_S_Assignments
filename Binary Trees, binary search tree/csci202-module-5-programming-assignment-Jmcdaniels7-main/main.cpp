#include <iostream>
#include <fstream>
#include <limits>
#include "binarySearchTree.h"
#include "product.h"

/* Program name: M05 PA 1
* Author: Jacob McDaniels
* Date last updated: 11/25/2024
* Purpose: Insert objects into a binary tree and use binary serach to search and delete them.
*/

// we need to implement binary tree and search tree
// we need to insert, search, and delete from the the binary tree
int compare(product &item1, product &item2);

int main()
{
    int choice;
    double price;
    std::string description;
    std::string prodNum;
    double rating;

    binarySearchTree<product> tree;

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

        tree.insert(prod);
    }

    while(true)
    {
        std::cout << "What would you like to do: " << std::endl;

        std::cout << "1. Search for a product" << std::endl;
        std::cout << "2. Delete Product" << std::endl;
        std::cout << "3. Quit" << std::endl;

        std::cin >> choice;

        if(choice == 1)
        {
            std::string productNumber;

            std::cout << "Please enter the product number: " << std::endl;

            std::cin >> std::ws;
            getline(std::cin, productNumber);
            product prod1(19.99, " ", productNumber, 2.00);
            tree.search(prod1);

            if(!tree.search(prod1))
            {
                std::cout << "Item not found." << std::endl;
            }
        }
        else if (choice == 2)
        {
            int productID;

            std::cout << "Please enter the product ID: " << std::endl;
            std::cin >> productID;

            // still not sure how to find a productID based on product object only having 4 parameters
            product prod(0, "", "", 0);

            //tree.delete()

        }
        else if (choice == 3)
        {
            //inorder traversal from binarytree.h but should be inherited by binarySearchTree
            // cant use binaryTree class because it doesnt allow abstract instances of the class
            // these comments above are because binaryTree.h had a bug with the 
            // search method being implemented with a const before the declaration of pure virtual "= 0"
            tree.inorderTraversal();
            break;
        }

    }
}

int compare(product &item1, product &item2)
{
    if (item1.getProdNum() < item2.getProdNum())
    {
        return -1;

    }
    else if (item1.getProdNum() == item2.getProdNum())
    {
        return 0;
    }
    else if (item1.getProdNum() > item2.getProdNum())
    {
        return 1;
    }
    
    return 0;

}

