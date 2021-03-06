#ifndef AI_NODE_BASE_H_
#define AI_NODE_BASE_H_

#include "StateBase.h"

#include <vector>
#include <climits>

namespace AI_Problems {

    class NodeBase {
    public:
        //! Constructor
        NodeBase(NodeBase* parentNode, StateBase* newState)
          : parent(parentNode),
            state(newState),
            childrenNodes(),
            heuristicVal(0)
        {
            if (newState != NULL)
                heuristicVal = newState->calcHeuristicValue();
            else
                heuristicVal = INT_MIN;
        }

        //! Destructor
        ~NodeBase() {
            // untested
            /*
            delete parent;
            parent = NULL;
            delete state;
            state = NULL;
            while(!childrenNodes.empty()) {
                delete childrenNodes[0];
                childrenNodes.erase(childrenNodes.begin());
            }
            */
        }

        //! Copy constructor
        NodeBase(const NodeBase& kNode)
          : parent(kNode.parent),
            state(kNode.state),
            childrenNodes(kNode.childrenNodes),
            heuristicVal(kNode.heuristicVal)
        { }

        //! Assignment operator
        NodeBase& operator=(const NodeBase& kNode) {
            if (this != &kNode) {
                parent = kNode.parent;
                state = kNode.state;
                childrenNodes = kNode.childrenNodes;
                heuristicVal = kNode.heuristicVal;
            }
            return *this;
        }

        //! Adds a node to the vetor of children nodes
        void addChildNode(NodeBase*);

        //! Generates a new *Node and returns it (meant to be implemented in derived classes)
        virtual NodeBase* generateChildNode(StateBase*) = 0;

        //! Returns a child node specified by index
        NodeBase* getChild(unsigned int) const;

        //! Returns the children nodes
        const std::vector<NodeBase*>& getChildrenNodes() const;

        //! Returns the state's heuristic value
        int getHeuristicValue() const;

        //! Returns the parent node
        NodeBase* getParentNode() const;

        //! Returns the state contained in the node
        StateBase* getState() const;

        //! Accesses whether this node is better than its ancestor (not always the direct parent of a node)
        virtual bool isBetterThanItsAncestor() = 0;

        //! Returns the number of children for a particular node
        unsigned int numbOfChildren() const;

        //! Prints a node's data
        friend std::ostream& operator<<(std::ostream&, const NodeBase&);

    protected:
        NodeBase* parent;       //!< The node that generate this node (state that generate this state)
        StateBase* state;       //!< The state contained in this node
        std::vector<NodeBase*> childrenNodes; //!< The states generated by this state
        int heuristicVal;       //!< The state's heuristic value
    };
}

#endif // end of AI_NODE_BASE_H_