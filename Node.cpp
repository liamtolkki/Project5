#include "Node.h"

Node::Node() // default node constructor
{
    for (int i = 0; i < 27; i++)
    { // upon creation, all branches will be
        // initialized to null pointers
        charList[i] = nullptr;
    }
}
Node::~Node()
{
    for (int i = 0; i < 27; i++)
    {
        delete charList[i]; // this acts recursively
        // it calls the destructor for every child node (even the EOS pointer)
    }
}
Node *&Node::getIndex(int index)
{
    return charList[index];
}