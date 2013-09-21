#include "MissionariesCannibalsProblem.h"

namespace AI_Problems {

    const int MissCannState::kEachGroupSize = 3;
    const int MissCannState::kBoatCapacity = 2;

    bool MissCannState::operator==(const StateBase& kState) {
        return (*this == static_cast<const MissCannState&>(kState));
    }

    bool MissCannState::operator==(const MissCannState& kState) {
        // compares two states to see if they are the same
        return (missOnLeft == kState.missOnLeft && cannOnLeft == kState.cannOnLeft
                && theBoatIsOnLeft == kState.theBoatIsOnLeft);
    }

    int MissCannState::calcHeuristicValue() {
        // calculate the heuristic value
        // count how many missionaries and cannibals are on the left side
        int numbOnLeftSide = missOnLeft + cannOnLeft;
        // check the distribution between missionaries and cannibals
        int distrubOnLeft = missOnLeft - cannOnLeft;
        // square the count and add the "distribution" (the count is very weighed in this heurisitic)
        int heuristicVal = (numbOnLeftSide * numbOnLeftSide) + distrubOnLeft;
        // mulitply the value by -1 (for use with steepest acsent hill climbing)
        heuristicVal *= -1;
        return heuristicVal;
    }

    std::vector<StateBase*> MissCannState::generateChildrenStates() {
        std::vector<StateBase*> children;
        bool opposSide = (!theBoatIsOnLeft);
        // loop the moves
        int k = 0;
        for (int i = 0; i < MissCannState::kBoatCapacity + 1; i++) {
            for (int j = 0; j < MissCannState::kBoatCapacity; j++) {
                k = j - i + 1;
                // check if K is non-negative
                if ((k >= 0) && isValidMove(this, i, k)) {
                    if (theBoatIsOnLeft)
                        children.push_back(new MissCannState(missOnLeft - i, cannOnLeft - k, opposSide));
                    else
                        children.push_back(new MissCannState(missOnLeft + i, cannOnLeft + k, opposSide));
                }
            }
        }
        // return the children states
        return children;
    }

    bool MissCannState::isGoal() const {
        // the goal is all missionaries and cannibals are on the right side
        return ((missOnLeft == 0) && (cannOnLeft == 0) && (theBoatIsOnLeft == false));
    }

    bool MissCannState::isValidMove(MissCannState* state, const int nMissToMove, const int nCannToMove) {
        int nMissLeftAfterMove = 0;
        int nCannLeftAfterMove = 0;
        // moving from left to right
        if (state->theBoatIsOnLeft) {
            nMissLeftAfterMove = state->missOnLeft - nMissToMove;
            nCannLeftAfterMove = state->cannOnLeft - nCannToMove;
        } 
        // else moving from right to left
        else {
            nMissLeftAfterMove = state->missOnLeft + nMissToMove;
            nCannLeftAfterMove = state->cannOnLeft + nCannToMove;
        }
        int nMissRightAfterMove = MissCannState::kEachGroupSize - nMissLeftAfterMove;
        int nCannRightAfterMove = MissCannState::kEachGroupSize - nCannLeftAfterMove;

        // test if the total number of missionaries == the group size (the same thing for total cannibals)
        return (((nMissLeftAfterMove + nMissRightAfterMove) == MissCannState::kEachGroupSize)
        && ((nCannLeftAfterMove + nCannRightAfterMove) == MissCannState::kEachGroupSize)
        // test if #missOnLeft >= #cannOnLeft OR #missOnLeft == 0
        && ((nMissLeftAfterMove > 0 && nMissLeftAfterMove >= nCannLeftAfterMove) 
            || nMissLeftAfterMove == 0)
        // test if #cannOnLeft >= 0
        && (nCannLeftAfterMove >= 0)
        // test if #missOnRight >= #cannOnRight OR #missOnRight == 0
        && ((nMissRightAfterMove > 0 && nMissRightAfterMove >= nCannRightAfterMove) 
            || nMissRightAfterMove == 0)
        // test if #cannOnRight >= 0
        && (nCannRightAfterMove >= 0));
    }

    NodeBase* MissCannNode::generateChildNode(StateBase* newState) {
        return new MissCannNode(this, static_cast<MissCannState*>(newState));
    }

    bool MissCannNode::isBetterThanItsAncestor() {
        // get the ancestor of this node
        NodeBase* genericGrandpa = this->getParentNode()->getParentNode();
        MissCannNode* grandpa = NULL;
        if ((genericGrandpa != NULL) && (grandpa = static_cast<MissCannNode*>(genericGrandpa)) != NULL) {
            // return the result the following statement
            return (heuristicVal > grandpa->heuristicVal);
        }
        // return true because there is nothing to compare this node to.
        // this node must be a child of the root node.
        else {
            return true;
        }
    }
}