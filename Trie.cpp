#include "Trie.h"
#include "Node.h"
using namespace std;

Trie::Trie()
{ // make a new trie with a root node (Empty)
    Node *root = new Node();
}

bool Trie::insert(string str)
{                         // inserts a string
    Node *currentNode = root; // holds the starting node
    for (int i = 0; i < str.size(); i++)
    {                                   // this repeats for every character in the string
        char currentChar = str[i];          // gets the current character in the string
        int arrIndex = ('a' - currentChar); // used for progressing the trie node index
        if (currentNode->getNext(arrIndex) != nullptr)
        {
            currentNode = currentNode->getNext(arrIndex);
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