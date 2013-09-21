#ifndef AI_STATE_BASE_H_
#define AI_STATE_BASE_H_

#include <iostream>
#include <vector>

namespace AI_Problems {

    class StateBase {
    public:
        //! Constructor
        StateBase() {
            // no explicit implementation
        }

        //! Destructor
        virtual ~StateBase() {
            // no explicit implementation
        }

        //! Copy constructor
        StateBase(const StateBase& kState)
        { }

        //! Assignment operator
        StateBase& operator=(const StateBase& kState) {
            return *this;
        }

        //! Equals operator
        virtual bool operator==(const StateBase&) = 0;

        //! Calculates the state's heuristic value
        virtual int calcHeuristicValue() = 0;

        //! Generates children states of the current state
        virtual std::vector<StateBase*> generateChildrenStates() = 0;

        //! Checks if this state is the goal state
        virtual bool isGoal() const = 0;

        //! Prints a state's data
        friend std::ostream& operator<<(std::ostream&, const StateBase&);

        friend class NodeBase;
    };
}

#endif // end of AI_STATE_BASE_H_