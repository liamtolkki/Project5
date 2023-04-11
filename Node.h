#pragma once

class Node
{
public:
    Node();
    ~Node();                    // node destructor
    Node *&getIndex(int index); // returns the node at the proper index

private:
    Node *charList[27]; // will hold the pointers for the next char A-Z
};