/*
 * Sequence.hpp
 * The structure of Sequence class
 */ 

#ifndef Sequence_hpp
#define Sequence_hpp

#include "stdio.h"
#include "algorithm"
#include "ostream"
#include "stdint.h"



using namespace std;

class Sequence {
    private:
        uint8_t* sq;
        int size;
    public:
        Sequence(int _size);
        uint8_t* &getSequence();
        void setSequence(uint8_t* sq);
        void setSize(int _size);
        int getSize();
        void updateSequence(Sequence seq);
        friend ostream& operator<<(ostream& os, Sequence& seq);
        friend Sequence& operator^(Sequence& a, Sequence& b);
};

#endif /* Sequence_hpp */
