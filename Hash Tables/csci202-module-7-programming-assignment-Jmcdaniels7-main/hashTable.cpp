#include "hashTable.h"

// hash table one
hashTable::hashTable()
{
    this->hashTbl[h_size] = hashTbl[h_size];

    for (int i = 0; i < h_size; i++)
    {
        hashTbl[i] = -1;
    }

}

int hashTable::hashFunction(int key)
{
    return key % h_size;
}

void hashTable::insert(int &value)
{
    int collisions = 0;
    int count = 0;
    int probeCount = 0;
    bool found = false;
    int x = 1;

    int hashValue = hashFunction(value);
    int hashValueOrigin = hashValue;

    for (int i = 0; i < h_size; i++)
    {
        if (hashTbl[hashValue] != -1)
        {
            hashTbl[hashValue] = value;
            count++;
        }
        else if(hashTbl[value] != value)
        {
            collisions++;

            while(hashTbl[hashValue] != -1 && !found)
            {
                if(hashTbl[hashValue] == value)
                {
                    found = true;
                }
                else
                {
                    hashValue = ((hashValueOrigin + static_cast<int>(pow(x,2))) % h_size) % h_size;
                    probeCount++;
                    x++;
                }
            }
        }
    }

    //std::cout << "There were " << collisions << " collisions." << std::endl;
    //std::cout << "There were " << count << " inserted." << std::endl;

}

bool hashTable::find(int &value)
{
    bool found = false;

    int hashValue = hashFunction(value);

    for (int i = 0; i < h_size; i++)
    {
        if (hashTbl[hashValue] == value)
        {
            found = true;
            break;
        }
    }

    return found;

}

void hashTable::erase(int &value)
{
    int hashValue = hashFunction(value);
    
    for (int i = 0; i < h_size; i++)
    {
        if (hashTbl[hashValue] == value)
        {
            hashTbl[hashValue] == -1;
        }
    }
}

// hash table two
hashTableTwo::hashTableTwo()
{

}
int hashTableTwo::hashFunction(int key)
{
    return key % hash_size;
}

void hashTableTwo::insertH(int &value)
{
    // this needs to insert into the end of the linked list
    int collisions = 0;
    int count = 0;
    int probeCount = 0;
    bool found = false;
    int n = hash_size;
    int hashValue = hashFunction(value);

    if(hashT[hashValue] != nullptr)
    {
        if (!hashT[hashValue]->search(value))
        {
            hashT[hashValue]->insert(value);
            count++;
        }
    }
    else
    {
        hashT[hashValue] = new unorderedLinkedList<int>();

        hashT[hashValue]->insert(value);
    }
    
    //std::cout << "There were " << collisions << " collisions." << std::endl;
    //std::cout << "There were " << count << " inserted." << std::endl;
}

bool hashTableTwo::find(int &value)
{
    // traverse array of linked lists
    bool found = false;
    int hashValue = hashFunction(value);
    
    if (hashT[hashValue]->search(value))
    {
        found = true;
    }

    return found;

}

void hashTableTwo::erase(int &value)
{
    int hashValue = hashFunction(value);
    // we need to traverse a array of linked lists
    if (hashT[hashValue]->search(value))
    {
        hashT[hashValue]->deleteNode(value);
    }
}