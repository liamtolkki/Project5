#include "Node.h"

Node::Node() // default node constructor
{
    for (Node *charNode : charList)
    { // upon creation, all branches will be
        // initialized to null pointers
        charNode = nullptr;
    }
}
Node *Node::getNext(int index)
{

    if (charList[index] == nullptr)
    {
        return nullptr;
    }
    else
    {
        return charList[index];
    }
}