#pragma once 

#include <iostream>
#include <list>
#include <algorithm>
#include <fstream>
#include <cmath>
#include "unorderedLinkedList.h"

// array based hash Table that using quadratic probing for collisions
class hashTable
{
    static const int h_size = 1000000;
    int hashTbl[h_size];

    public:
        hashTable();
        int hashFunction(int key);
        void insert(int &value);
        bool find(int &value);
        void erase(int &value);
};

// we need an array of linkedLists here and adds collisions to end of linked list
class hashTableTwo
{
    static const int hash_size = 1000000;
    unorderedLinkedList<int> *hashT[hash_size];

    public:
        hashTableTwo();
        int hashFunction(int key);
        void insertH(int &value);
        bool find(int &value);
        void erase(int &value);
};
