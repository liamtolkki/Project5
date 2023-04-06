#include "Trie.h"
using namespace std;

Trie::Trie()
{ // make a new trie with a root node (Empty)
    Node *root = new Node();
}

bool Trie::insert(string str)
{                         // inserts a string
    Node *current = root; // holds the starting node
    for (int i = 0; i < str.size(); i++)
    {                                   // this repeats for every character in the string
        char current = str[i];          // gets the current character in the string
        int arrIndex = ('a' - current); // used for progressing the trie node index
        if (current->getNext(arrIndex) != nullptr)
        {
            current = current->getNext(arrIndex);
        }
    }
}

int Trie::getCount()
{
    return count;
}
int Trie::getSize()
{
    return size;
}