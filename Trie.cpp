#include "Node.h"
#include "Trie.h"
using namespace std;

Trie::Trie()
{ // make a new trie with a root node (Empty)
    Node *root = new Node();
}

bool Trie::insert(string str)
{                             // inserts a string
    Node *currentNode = root; // holds the starting node
    for (int i = 0; i < str.size(); i++)
    {                                              // this repeats for every character in the string
        char currentChar = str[i];                 // gets the current character in the string
        int arrIndex = (-1 * ('a' - currentChar)); // used for progressing the trie node index
        //-1 used to make it positive, since 'a' <= currentChar
        if (currentNode->getIndex(arrIndex) != nullptr)
        {
            currentNode = currentNode->getIndex(arrIndex);
        }
        else
        {
            // make a new node
            currentNode->getIndex(arrIndex) = new Node();
            currentNode = currentNode->getIndex(arrIndex);
        }
    }
}

int Trie::getCount()
{
    return wordCount;
}
int Trie::getSize()
{
    return size;
}