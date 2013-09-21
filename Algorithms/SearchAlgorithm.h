#ifndef SEARCH_ALGORITHM_H_
#define SEARCH_ALGORITHM_H_

#include "../KnowledgeRep/NodeBase.h"
#include "../KnowledgeRep/StateBase.h"

#include <queue>
#include <set>
#include <string>
#include <iostream>

namespace AI_Problems {

    class SearchAlgorithm {
    public:
        //! Constructor
        SearchAlgorithm(const std::string& algorithmType, const std::string& problemType)
          : algorithmName(algorithmType),
            problemName(problemType),
            explored()
        {
            std::cout << "creating search algorithm\n";
        }

        //! Destructor
        virtual ~SearchAlgorithm() {
            // remove all the explored stuff
        }

        //! Tries to find the solution and return the end node
        //virtual NodeBase* search(NodeBase*) = 0;

        //! Checks if a state already exists
        bool stateExists(StateBase*);

    protected:
        std::string algorithmName;
        std::string problemName;
        std::set<StateBase*> explored;       //!< The set of nodes already explored
    };
}

#endif // end of SEARCH_ALGORITHM_H_