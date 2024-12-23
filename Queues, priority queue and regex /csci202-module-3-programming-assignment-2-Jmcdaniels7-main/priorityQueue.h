#pragma once

/* Program name: M03 PA 2
* Author: Jacob McDaniels
* Date last updated: 11/9/2024
* Purpose: Bug report system with priority queue
*/

#include "linkedQueue.h"

template <class Type>
class priorityQueue : public linkedQueueType<Type>
{
public:
    void enqueue(const Type &queueElement);
};

template <class Type>
void priorityQueue<Type>::enqueue(const Type &queueElement)
{
    node<Type> *current;
    node<Type> *trailCurrent;
    node<Type> *newNode;
    newNode = new node<Type>;
    newNode->info = new Type(queueElement);
    newNode->link = nullptr;
    
    if (this->isEmptyQueue())
    {
        this->queueFront = newNode;
        this->queueRear = newNode;
    }
    else
    {
        current = this->queueFront;
        bool found = false;

        if (*(this->queueRear->info) >= queueElement)
        {
            //newNode goes to the rear and the current rear goes infront of newNode
            this->queueRear->link = newNode;
            this->queueRear = newNode;
            found = true;
        }
        else
        {
            // we go to the next position until we find a equal or greater priority element
            while(!found)
            {
                if (*(current->info) < queueElement)
                {
                    found = true;
                }
                else
                {
                    trailCurrent = current;
                    current = current->link;
                }
            }
            if (current == this->queueFront) 
            {
                newNode->link = this->queueFront;
                this->queueFront = newNode;
            }
            else
            {
                trailCurrent->link = newNode;
                newNode->link = current;
            }
        }
    }
}
