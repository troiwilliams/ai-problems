#include "MissionariesCannibalsProblem.h"
#include "../../Algorithms/SA-HillClimbing.h"
#include "../../KnowledgeRep/NodeBase.h"

#include <iostream>
using namespace AI_Problems;

int main() {
    std::cout << "Missionaries and Cannibals problem.\n";
    std::cout << "Root node created? ";
    NodeBase* rootNode = new MissCannNode(NULL,
        new MissCannState(MissCannState::kEachGroupSize, MissCannState::kEachGroupSize, true));
    if (rootNode == NULL) {
        std::cout << "no\nTerminating.\n";
        return 1;
    } else {
        std::cout << "yes\n";
    }

    std::cout << "Starting search.\n";
    std::cout << "Algorithm created? ";
    SA_HillClimbing* algo = new SA_HillClimbing("Missionaries and Cannibals");
    if (algo == NULL) {
        std::cout << "no\nTerminating.\n";
        return 1;
    } else {
        std::cout << "yes\n";
    }

    NodeBase* finish = algo->search(rootNode);
    std::cout << "Search complete.\n";

    if (finish == NULL) {
        std::cout << "There was a problem during runtime.\n";
    } else if (finish->getState()->isGoal()) {
        std::cout << "Found the GOAL!\n";
    } else {
        std::cout << "Got stuck in a local maximum.\n";
    }
    return 0;
}