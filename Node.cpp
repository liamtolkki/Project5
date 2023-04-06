#include "Node.h"

Node::Node() // default node constructor
{
    for (Node *charNode : charList)
    { // upon creation, all branches will be
        // initialized to null pointers
        charNode = nullptr;
    }
}
Node *&Node::getIndex(int index)
{
    return charList[index];
}