#include "block.h"

block::block(int blockNum, std::string data, size_t prevHash) : blockNum(blockNum), prevHash(prevHash), data(data)
{
    this->nonce = time(NULL);
    calculateHash();
    
}

void block::calculateHash()
{
    std::hash<std::string> hashStr;
    std::string hashString = std::to_string(blockNum) + std::to_string(nonce) + data + std::to_string(prevHash);
    currentHash = hashStr(hashString);
}

std::string block::getData()
{
    return data;
}

size_t block::getHash()
{
    return currentHash;
}

size_t block::getPrevHash()
{
    return prevHash;
}
size_t block::hash(std::string data) const
{
    std::hash<std::string> hashStr;
    std::string hashString = std::to_string(blockNum) + std::to_string(nonce) + data + std::to_string(prevHash);
    return hashStr(hashString);

}

bool block::validateBlock()
{
    bool valid = true;

    if(currentHash != hash(data))
    {
        valid = false;
    }

    return valid;

}

void block::hack(std::string newMessage)
{
    data = newMessage;
    
}
