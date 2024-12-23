#include "blockchain.h"

blockChain::blockChain()
{
    numBlocks = 0;

    block genesis(numBlocks++, "Genesis Block", 0);
    chain.enqueue(genesis);

}

void blockChain::insert(std::string message)
{
    block newBlock(numBlocks++, message, chain.back().getHash());

    chain.enqueue(newBlock);
}

void blockChain::hack(std::string newMessage)
{
    linkedQueue<block> newChain;
    int count = 0;

    while(!chain.isEmptyQueue())
    {
        newChain.enqueue(chain.dequeue());
        count++;

        if(count == 2)
        {
            block hackBlock(chain.dequeue());

            hackBlock.hack(newMessage);

            newChain.enqueue(hackBlock);
        
        }
    }

    while(!newChain.isEmptyQueue())
    {
        chain.enqueue(newChain.dequeue());
    }
}

void blockChain::verifyChain()
{
    linkedQueue<block> cpy(chain);

    size_t currentHash;
    size_t recalculatedHash;
    size_t prevHash = 0;

    while(!cpy.isEmptyQueue())
    {
        block current(cpy.dequeue());

        // since we are suppose to hack, then the block down the chain would need to be verified
        if(!current.validateBlock())
        {
            // we could here set current Hash to recalculated and at the end let prevHash alter the blocks 
            // down the chain like in the video we watched with changing block data.
            // possibly in this case we would verify the block to change its current hash to the recalculated
            throw std::runtime_error("Block has been changed.");
            
        }

        if(prevHash != current.getPrevHash())
        {
            //same thing here we just adjust down the chain or we dont allow changes
            throw std::runtime_error("Block has been changed.");
        }
        prevHash = current.getHash();
    }
}

void blockChain::chainMessages()
{
    linkedQueue<block> cpy(chain);

    while(!cpy.isEmptyQueue())
    {
        block current(cpy.dequeue());

        std::cout << current.getData() << std::endl;
    }
}