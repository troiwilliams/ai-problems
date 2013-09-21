#ifndef MISSIONARIES_CANNIBALS_PROBLEM_H_
#define MISSIONARIES_CANNIBALS_PROBLEM_H_

#include "../../KnowledgeRep/NodeBase.h"
#include "../../KnowledgeRep/StateBase.h"

namespace AI_Problems {

    class MissCannState : public StateBase {
    public:
        //! Constructor
        MissCannState(int numbMissionariesOnLeft = -1, int numbCannibalsOnLeft = 0,
            bool boatOnLeft = true)
          : StateBase(),
            missOnLeft(numbMissionariesOnLeft),
            cannOnLeft(numbCannibalsOnLeft),
            theBoatIsOnLeft(boatOnLeft)
        { }

        //! Destructor
        ~MissCannState() {
            // no explicit implementation
        }

        //! Copy constructor
        MissCannState(const MissCannState& kState)
          : StateBase(kState),
            missOnLeft(kState.missOnLeft),
            cannOnLeft(kState.cannOnLeft),
            theBoatIsOnLeft(kState.theBoatIsOnLeft)
        { }

        //! Assignment operator
        MissCannState& operator=(const MissCannState& kState) {
            if (this != &kState) {
                StateBase::operator=(kState);
                missOnLeft = kState.missOnLeft;
                cannOnLeft = kState.cannOnLeft;
                theBoatIsOnLeft = kState.theBoatIsOnLeft;
            }
            return *this;
        }

        //! Equals operator
        virtual bool operator==(const StateBase&);
        bool operator==(const MissCannState&);

        //! Calculates the state's heuristic value
        virtual int calcHeuristicValue();

        //! Generates children states for the missionaries and cannibals problem
        virtual std::vector<StateBase*> generateChildrenStates();

        //! Checks if the state is goal state
        virtual bool isGoal() const;

        //! Checks if the state is valid
        static bool isValidMove(MissCannState*, const int, const int);

        //! The total number of people in each group
        static const int kEachGroupSize;

        //! The maximum number of people that can fit in the boat at one time
        static const int kBoatCapacity;

        friend class MissCannNode;

    private:

        int missOnLeft;         //!< The count of missionaries on the left side
        int cannOnLeft;         //!< The count of cannibals on the left side
        bool theBoatIsOnLeft;   //!< States if the boat is on the left or right side
    };

    class MissCannNode : public NodeBase {
    public:
        //! Constructor
        MissCannNode(MissCannNode* parentNode, MissCannState* theState)
          : NodeBase(parentNode, theState)
        { }

        //! Destructor
        ~MissCannNode() {
            // no explicit implementation
        }

        //! Copy constructor
        MissCannNode(const MissCannNode& kNode)
          : NodeBase(kNode)
        { }

        //! Assignment operator
        MissCannNode& operator=(const MissCannNode& kNode) {
            if (this != &kNode) {
                NodeBase::operator=(kNode);
            }
            return *this;
        }

        //! Generates a new MissCannNode and returns it
        virtual NodeBase* generateChildNode(StateBase*);

        //! Accesses whether this node is better than its ancestor
        virtual bool isBetterThanItsAncestor();
    };
}

#endif // end of MISSIONARIES_CANNIBALS_PROBLEM_H_