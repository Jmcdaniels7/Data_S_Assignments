#pragma once

/* Program name: M02 Programming assignment 2
* Author: Jacob McDaniels
* Date last updated: 11/1/2024
* Purpose: Use classes and insert method to be inserted into an ordered linked list
*/
#include "linkedList.h"

template <class Type>
class orderedLinkedList : public linkedList<Type>
{
    public:
        bool search(const Type &searchItem) const;
        void insert(const Type &newInfo);
        void insertFirst(const Type &newItem);
        void insertLast(const Type &newItem);
        void deleteNode(const Type &deleteItem);
};


template <class Type>
bool orderedLinkedList<Type>::search(const Type &searchItem) const
{
    // this function "traverses" the linked list to search for an item 
    node<Type> *current; 
    bool found = false;

    current = this->first; // we are starting at the head

    while(current != nullptr && !found)
    {
        if (*(current->info) >= searchItem) // still true if > than
        {
            found = true;
        }
        else
        {
            current = current->link; // traverse to the next node/link
        }
    }

    if (found)
    {
        found = (*(current->info) == searchItem); // this tests for equality

    }

    return found;
}

template <class Type>
void orderedLinkedList<Type>::insert(const Type &newInfo) 
{
    node<Type> *current; // current position traversing the list
    node<Type> *trailCurrent = nullptr; // pointer before the current position
    node<Type> *newNode; //pointer to create a new node

    bool found;

    newNode = new node<Type>; //new node created
    newNode->info =  new Type(newInfo); // we are storing are new node in the data
    newNode->link = nullptr; // we are setting the newNodes link to a null pointer

    // we are staring at the head so, if it is empty we want to put fill it with the new node

    if (this->isEmptyList()) // case 1
    {
        this->first = newNode;
        this->last = newNode;
        this->count++;
    }
    else
    {
        current = this->first;
        found = false;

        // not sure if we could use search function we just created in an if statement against found = false
        while (current != nullptr && !found)
        {
            if (*(current->info) >= newInfo)
            {
                found = true;
            }
            else 
            {
                trailCurrent = current;
                current = current->link;
            }
        } 
        // why wouldnt this be the case is we are assigned to the head?
        if (current == this->first) //case 2 if the current postion is head 
        //then we set the newNode link to the head, the head to newNode and increment by 1
        {
            newNode->link = this->first;
            this->first = newNode;
            this->count++;
        }
        else //case 3 
        // else if not current == head then we trail back behind current 
        // and set the link to New Node and the NewNode link to current
        // if that current is a null pointer then we set the tail to new node and increment by 1
        // if we are not at the head then why would we assign current to head? doesn't that mean we start at the head?
        {
            trailCurrent->link = newNode;
            newNode->link = current;

            if (current == nullptr)
            {
                this->last = newNode;
            }
            this->count++;
        }
    }
}

template <class Type>
void orderedLinkedList<Type>::insertFirst(const Type &newItem) 
{
    insert(newItem);

}

template <class Type>
void orderedLinkedList<Type>::insertLast(const Type &newItem) 
{
    insert(newItem);

}

template <class Type>
void orderedLinkedList<Type>::deleteNode(const Type &deleteItem) 
{
    node<Type> *current;
    node<Type> *trailCurrent;

    bool found;

    // head is a nullptr then nothing we can delete
    if (this->first == nullptr)
    {
        std::cout << "Can't delete from an empty list!" << std::endl;
    }
    else // if something is in head
    {
        current = this->first; // start at head
        found = false;

        //could we use the search function?
        while (current != nullptr && !found) 
        {
            if (*(current->info) >= deleteItem)
            {
                found = true;
            }
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        } 
        if (current == nullptr) 
        {
            std::cout << "The item to be deleted is not in the list." << std::endl;
        }
        else // loop found something so we start the process of deleting
        {
            if (*(current->info) == deleteItem) // if the item to be deleted is in the list based on the search
            {
                // if the head is current
                if (this->first == current)
                {
                    // set the head to the head link if that is a null pointer then we must be at the tail? and we delete current
                    this->first = this->first->link;

                    if (this->first == nullptr)
                    {
                        this->last = nullptr;
                    }
                    delete current;
                }
                else // if the head is not current then we traverse back see if current is the tail if so tail is trail and then we delete
                {
                    trailCurrent->link = current->link; // traversing back one

                    if (current == this->last)
                    {
                        this->last = trailCurrent;
                    }
                    delete current;
                }
                this->count--; // because we deleted an item
            }
            else // if not found in the search
            {
                std::cout << "The item is not in the list." << std::endl;
            }
        }
    }
}