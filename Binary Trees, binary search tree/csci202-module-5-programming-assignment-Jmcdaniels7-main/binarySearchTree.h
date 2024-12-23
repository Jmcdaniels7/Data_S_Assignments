#ifndef SEARCH_H
#define SEARCH_H
#include "binaryTree.h"

template <class elemType>
class binarySearchTree : public binaryTreeType<elemType>
{
    public:
        void insert(const elemType &insertItem);
        bool search(const elemType &searchItem) const;
        void deleteNode(const elemType &deleteItem);

    private:
        // the book uses p as a parameter for deleteFromTree and I think we covered in lecture 
        // that using current Node may give this more understanding of its use
        // the book also leaves the prototypes as I have written but I may go back and 
        // write the prototypes search and insert that are private
        void deleteFromTree(nodeType<elemType> *&currentNode);

};

template <class elemType>
void binarySearchTree<elemType>::insert(const elemType &insertItem)
{
    nodeType<elemType> *current;
    nodeType<elemType> *trailCurrent;
    nodeType<elemType> *newNode;

    newNode = new nodeType<elemType>;
    
    //I do not understand why this is causing a segmentation fault when the book says to do this
    newNode->info = new elemType(insertItem);
    newNode->lLink = nullptr;
    newNode->rLink = nullptr;

    if(this->root = nullptr)
    {
        this->root = newNode;
    }
    else
    {
        current = this->root;

        while (current != nullptr)
        {
            trailCurrent = current;

            if (*(current->info) == insertItem)
            {
                std::cout << "The item is already in the tree, duplicates are not allowed." << std::endl;
                return;
            }
            else if(*(current->info) > insertItem)
            {
                current = current->lLink;
            }

             if (*(trailCurrent->info) > insertItem)
            {
                trailCurrent->lLink = newNode;
            }
            else
            {
                trailCurrent->rLink = newNode;
            }
        }
    }
}

template <class elemType>
bool binarySearchTree<elemType>::search(const elemType &searchItem) const
{
    nodeType<elemType> *current;
    bool found = false;

    if (this->root == nullptr)
    {
        std::cout << "The tree is empty and cannot be searched." << std::endl;
    }
    else
    {
        current = this->root;

        while (current != nullptr && !found)
        {
            if (*(current->info) == searchItem)
            {
                found = true;
                std::cout << searchItem << std::endl;
            }
            else if (*(current->info) > searchItem)
            {
                current = current->lLink;
            }
            else
            {
                current = current->rLink;
            }
        }
    }
    return found;
}

template <class elemType>
void binarySearchTree<elemType>::deleteNode(const elemType &deleteItem)
{
    nodeType<elemType> *current;
    nodeType<elemType> *trailCurrent;

    bool found = false;

    if (this->root == nullptr)
    {
        std::cout << "This tree is empty and cannot be deleted from." << std::endl;
    }
    else
    {
        current = this->root;
        trailCurrent = this->root;

        while(current != nullptr && !found)
        {
            if (*(current->info) == deleteItem)
            {
                found = true;
            }
            else 
            {
                trailCurrent = current;

                if (*(current->info) > deleteItem)
                {
                    current = current->lLink;
                }
                else
                {
                    current = current->rLink;
                }
            }

            if (current == nullptr)
            {
                std::cout << "The item is not in the tree." << std::endl;
            }
            else if (found)
            {
                if (current == this->root)
                {
                    deleteFromTree(this->root);
                }
                else if(*(trailCurrent->info) > deleteItem)
                {
                    deleteFromTree(trailCurrent->lLink);

                }
                else
                {
                    deleteFromTree(trailCurrent->rLink);
                }
                
            }
            else
            {
                std::cout << "The item is not in the tree." << std::endl;
            }

        }
    }

        
}

template <class elemType>
void binarySearchTree<elemType>::deleteFromTree(nodeType<elemType> *&currentNode)
{
    nodeType<elemType> *current;
    nodeType<elemType> *trailCurrent;
    nodeType<elemType> *temp;

    if (currentNode == nullptr)
    {
        std::cout << "The node you are trying to delete does not exist." << std::endl;
    }
    else if (currentNode->lLink == nullptr && currentNode->rLink == nullptr)
    {
        temp = currentNode;
        currentNode = nullptr;
        delete temp;
    }
    else if(currentNode->lLink == nullptr)
    {
        temp = currentNode;
        currentNode = temp->rLink;
        delete temp;
    }
    else if(currentNode->rLink == nullptr)
    {
        temp = currentNode;
        currentNode = temp->lLink;
        delete temp;
    }
    else
    {
        current = currentNode->lLink;
        trailCurrent = nullptr;

        while(current->rLink != nullptr)
        {
            trailCurrent = current;
            current = current->rLink;
        }

        currentNode->info = current->info;

        if (trailCurrent == nullptr)
        {
            currentNode->lLink = current->lLink;
        }
        else
        {
            currentNode->rLink = current->rLink;
        }
        delete current;
    }
}

#endif