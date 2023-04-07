#include "Node.h"
#include "Trie.h"
using namespace std;

Trie::Trie()
{ // make a new trie with a root node (Empty)
    root = new Node();
    wordCount = 0;
    size = 1; // this is including the root node
}

bool Trie::insert(string str)
{                             // inserts a string
    Node *currentNode = root; // holds the starting node
    for (int i = 0; i < str.size(); i++)
    {                                              // this repeats for every character in the string
        char currentChar = str[i];                 // gets the current character in the string
        int arrIndex = (-1 * ('a' - currentChar)); // used for progressing the trie node index
        //-1 used to make it positive, since 'a' <= currentChar
        if (currentNode->getIndex(arrIndex) == nullptr)
        {
            currentNode->getIndex(arrIndex) = new Node(); // make a new node if there isn't one
            size++;                                       // increments the size
        }

        currentNode = currentNode->getIndex(arrIndex); // update current
    }
    // once progressed to the right node, check if dupe...
    if (currentNode->getIndex(26) == nullptr)
    { // the last val of the array
        // this is reserved as the endOfWord placeholder
        // if empty, then the word is inserted for the first time
        currentNode->getIndex(26) = new Node();
        size++;
        wordCount++; // since new word is added
        return true; // sucessful insert
    }
    else
    {
        return false; // dupe word
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

bool Trie::find(string str)
{ // finds a string
    Node *currentNode = root;
    for (int i = 0; i < str.size(); i++)
    {
        char currentChar = str[i];
        int index = ((-1) * ('a' - currentChar)); // gets the index
        if (currentNode->getIndex(index) != nullptr)
        { // follows the traversal
            currentNode = currentNode->getIndex(index);
        }
        else // if the index is nullptr:
            return false;
    }
    // when the loop is done, look for an end of string (EOS) pointer:
    if (currentNode->getIndex(26) != nullptr)
    { // EOS position
        return true;
    }
    else
        return false; // if no EOS pointer, then the word DNE
}