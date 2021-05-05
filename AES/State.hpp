/*
 * State.hpp
 * The structure of State class
 */

#ifndef State_hpp
#define State_hpp

#include "stdio.h"
#include "Sequence.hpp"



class State {
    private:
        uint8_t** s;
    public:
        State(Sequence* sq);
        ~State();
        uint8_t** getStateArray() const;
        Sequence toSequence() const;
        void setStateArray(uint8_t** newS);
        friend ostream& operator<<(ostream& os, const State& state);
        friend State& operator^(State& a, State& b);
};

#endif /* State_hpp */
