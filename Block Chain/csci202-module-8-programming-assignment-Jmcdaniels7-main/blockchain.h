#pragma once
#include <string>
#include "block.h"
#include "linkedQueue.h"

// this needs to have a verify method that verifies the chain, 
//if the message is changed and prev hash does not match the previous block current hash
class blockChain
{
    public:
        blockChain();
        void insert(std::string message);
        void hack(std::string newMessage);
        void verifyChain();
        void chainMessages();

    private:
        linkedQueue<block> chain;
        int numBlocks;



};
