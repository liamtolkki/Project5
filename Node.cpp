#include "Node.h"

Node::Node() // default node constructor
{
    for (int i = 0; i < 27; i++)
    { // upon creation, all branches will be
        // initialized to null pointers
        charList[i] = nullptr;
    }
}
Node *&Node::getIndex(int index)
{
    return charList[index];
}