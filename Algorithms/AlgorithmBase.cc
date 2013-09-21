#include "AlgorithmBase.h"

namespace AI_Problems {
    
    bool AlgorithmBase::stateExists(StateBase* state) {
        for (std::set<StateBase*>::iterator it = explored.begin(); it != explored.end(); ++it) {
            if (**it == *state)
                return true;
        }
        return false;
    }
}