#include "SA-HillClimbing.h"

#include <iostream>
#include <climits>

namespace AI_Problems {

    NodeBase* SA_HillClimbing::search(NodeBase* rootNode) {
        NodeBase* currNode = NULL;
        StateBase* currState = NULL;
        // check if the root node is null, if so return null
        std::cout << "Is root node null? ";
        if ((currNode = rootNode) == NULL) {
            std::cout << "yes, terminating search\n";
            return NULL;
        }
        std::cout << "no\n";

        // check if the state of the root node is null, if so return null
        std::cout << "Is root state null? ";
        if ((currState = currNode->getState()) == NULL) {
            std::cout << "yes, terminating search\n";
            return NULL;
        }
        std::cout << "no\n";

        // check if the current state is the goal state, if so return it
        std::cout << "Is root node is goal? ";
        if (currState->isGoal()) {
            std::cout << "yes\n";
            return currNode;
        }
        std::cout << "no, continuing with search\n";

        // iteration counter
        int iterationCount = 0;

        // check if the current state is null
        std::cout << "Is root state null? ";
        if ((currState = currNode->getState()) == NULL) {
            std::cout << "yes, terminating search\n";
            return NULL;
        }
        std::cout << "no, continuing with search\n";
        // loop until:
        // 1) found goal state or
        // 2) stuck in local maximum
        do {
            std::cout << "\nsearch loop iteration[" << iterationCount << "] (search lvl = "
                      << (iterationCount + 1) << ")\n";
            // add the state to the already explored set
            std::cout << "adding current state to explored set\n";
            explored.insert(currState);

            // generate the current state's children states
            std::cout << "generating child(ren) state(s)\n";
            std::vector<StateBase*> childrenStates = currState->generateChildrenStates();

            // check the size of the children state vector
            std::size_t kNumbOfChildren = childrenStates.size();
            std::cout << "number of children states? " << kNumbOfChildren << std::endl;
            if (kNumbOfChildren == 0) {
                std::cout << "There are no more states to generate... (stuck in local maximum)\n";
                return currNode;
            }
            
            // get the SUCC comparison state (the first child)
            NodeBase* succNode = NULL;
            int succHvalue = INT_MIN;

            // evaluate each state in the vector
            std::cout << "iterating over all children states...\n";
            for (std::size_t i = 0; i < kNumbOfChildren; i++) {
                std::cout << "\tchild state[" << i << "]\n";
                StateBase* newState = childrenStates[i];
                
                // check if the state already exists
                std::cout << "\twas child state already explored? ";
                if (stateExists(newState)) {
                    std::cout << "yes, deleting it and continuing to next child\n";
                    delete newState;
                    childrenStates[i] = NULL;
                    continue;
                }
                std::cout << "no\n";

                // add the new state as a child of the current node
                std::cout << "\tgenerating new child node and adding it to the current node\n";
                NodeBase* newNode = currNode->generateChildNode(newState);
                currNode->addChildNode(newNode);

                // check if the new state is the goal state
                std::cout << "\tis child state[" << i << "] a goal state? ";
                if (newState->isGoal()) {
                    std::cout << "yes, returning it as answer\n";
                    return newNode;
                }
                std::cout << "no\n";

                // compare this new state to the SUCC
                std::cout << "\tis child state[" << i << "] > SUCC? ";
                int newStateHvalue = newState->calcHeuristicValue();
                if (newStateHvalue > succHvalue) {
                    std::cout << "yes (child hVal = " << newStateHvalue 
                              << " > SUCC hVal = " << succHvalue << "); SUCC = this child state\n";
                    succHvalue = newStateHvalue;
                    succNode = newNode;
                } else {
                    std::cout << "no (child hVal = " << newStateHvalue 
                              << " <= SUCC hVal = " << succHvalue << "); doing nothing\n";
                }

                // book keeping
                newNode = NULL;
                std::cout << "\n";
            }

            // check if the SUCC state is better than the current state
            std::cout << "is SUCC better than ancestor node? ";
            if (succNode->isBetterThanItsAncestor()) {
                std::cout << "yes; current node = SUCC node\n";
                currNode = succNode;
                currState = succNode->getState();
                succNode = NULL;
            }
            // else the search is stuck in a local maximum
            else {
                std::cout << "no, stuck in local maximum (terminating search)\n";
                succNode = NULL;
                return currNode;
            }

        } while (iterationCount++ < 6000);
        // book keeping
        currNode = NULL;
        currState = NULL;
        return NULL;
    }
}