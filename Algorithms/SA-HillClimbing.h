#ifndef ALGORITHM_SA_HILL_CLIMBING_H_
#define ALGORITHM_SA_HILL_CLIMBING_H_

#include "AlgorithmBase.h"
#include <iostream>

namespace AI_Problems {

    class SA_HillClimbing : public AlgorithmBase {
    public:
        //! Constructor
        SA_HillClimbing(const std::string& problemType)
          : AlgorithmBase("Steepest Ascent Hill Climbing", problemType)
        { }

        //! Destructor
        ~SA_HillClimbing() {
            // no explicit implementation
        }

        //! Searches for a solution using the Steepest Ascent Hill Climbing algorithm
        NodeBase* search(NodeBase*);
    };
}

#endif // end of ALGORITHM_SA_HILL_CLIMBING_H_