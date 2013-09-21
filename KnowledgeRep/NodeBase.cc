#include "NodeBase.h"

namespace AI_Problems {
    
    void NodeBase::addChildNode(NodeBase* newNode) {
        childrenNodes.push_back(newNode);
    }

    NodeBase* NodeBase::getChild(unsigned int index) const {
        if (index < numbOfChildren())
            return childrenNodes[index];
        else
            return NULL;
    }

    const std::vector<NodeBase*>& NodeBase::getChildrenNodes() const {
        return childrenNodes;
    }

    int NodeBase::getHeuristicValue() const {
        return heuristicVal;
    }

    NodeBase* NodeBase::getParentNode() const {
        return parent;
    }

    StateBase* NodeBase::getState() const {
        return state;
    }

    unsigned int NodeBase::numbOfChildren() const {
        return childrenNodes.size();
    }

    std::ostream& operator<<(std::ostream& os, const NodeBase& kNode) {
        // print the state
        os << kNode.state << std::endl;
        // print the heuristic value
        os << "Heuristic value: " << kNode.heuristicVal << std::endl;
    }

}