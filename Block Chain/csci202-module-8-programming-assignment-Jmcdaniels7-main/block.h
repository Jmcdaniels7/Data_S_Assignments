#pragma once

#include <string>
#include <iostream>
#include <cmath>
#include <functional>

class block
{
    public:
        block(int, std::string, size_t = 0);
        std::string getData();
        size_t getHash();
        size_t getPrevHash();
        size_t hash(std::string data) const;
        bool validateBlock();
        void hack(std::string newMessage);
    private:
        std::string data;
        time_t nonce;
        size_t prevHash;
        size_t currentHash;
        int blockNum;
        void calculateHash();
        
};