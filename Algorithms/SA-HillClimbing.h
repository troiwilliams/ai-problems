#ifndef ALGORITHM_SA_HILL_CLIMBING_H_
#define ALGORITHM_SA_HILL_CLIMBING_H_

#include "SearchAlgorithm.h"
#include <iostream>

namespace AI_Problems {

    //class MissCannNode;
    //class MissCannState;

    //template<typename NodeType, typename StateType>
    class SA_HillClimbing : public SearchAlgorithm {
    public:
        //! Constructor
        SA_HillClimbing(const std::string& problemType)
          : SearchAlgorithm("Steepest Ascent Hill Climbing", problemType)
        {
            std::cout << "creating steepest ascent hill climbing.\n";
        }

        //! Destructor
        ~SA_HillClimbing() {
            // no explicit implementation
        }

        //! Searches for a solution
        //template<typename NodeType, typename StateType>
        //NodeType* search(NodeType*);
        NodeBase* search(NodeBase*);
    };


    // ========================== SPECIALIZATIONS ========================== //
    /*
    template<>
    class SA_HillClimbing<MissCannNode, MissCannState> : public SearchAlgorithm {
    public:
        //! Constructor
        SA_HillClimbing<MissCannNode, MissCannState>
            (const std::string& problemType = "Missionaries and Cannibals")
          : SearchAlgorithm("Steepest Ascent Hill Climbing", problemType)
        { }

        //! Destructor
        ~SA_HillClimbing<MissCannNode, MissCannState>() {
            // no explicit implementation
        }

        //! Searches for a solution
        virtual NodeType* search(NodeType*);
    };
    */
}

#endif // end of ALGORITHM_SA_HILL_CLIMBING_H_