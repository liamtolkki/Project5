#pragma once

class Node
{
public:
    Node();
    Node *getNext(int index); // This returns the pointer at the given index

private:
    Node *charList[27]; // will hold the pointers for the next char A-Z
};