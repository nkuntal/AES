/*
 * Block.hpp
 * The structure of Block class
 */ 

#ifndef Block_hpp
#define Block_hpp

#include "stdio.h"
#include "vector"
#include "string"
#include "iostream"
#include "Sequence.hpp"



using namespace std;

class Block {
    private:
        vector<Sequence> sequenceVct;
        void padding(vector<uint8_t>* input);
    public:
        Block(vector<uint8_t>* input, bool pad);
        ~Block();
        vector<Sequence>& getSequenceVector();
        vector<unsigned char> getInput() const;
        friend ostream& operator<<(ostream& os, const Block& block);
};

#endif /* Block_hpp */
