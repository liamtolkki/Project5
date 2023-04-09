#include "Node.h"
#include "Trie.h"
#include <iostream>
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
    {                                       // this repeats for every character in the string
        char currentChar = str[i];          // gets the current character in the string
        int arrIndex = (currentChar - 'a'); // used for progressing the trie node index
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

string Trie::charsToString(vector<char> charVec)
{ // this turns the char vector into a string
    string concatenated;
    for (int i = 0; i < charVec.size(); i++)
    {
        // string builder
        concatenated += charVec[i];
    }
    return concatenated;
}

bool Trie::find(string str)
{ // finds a string
    Node *currentNode = root;
    for (int i = 0; i < str.size(); i++)
    {
        char currentChar = str[i];
        int index = (currentChar - 'a'); // gets the index
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

void Trie::completeHelper(Node *current, const string &str, vector<string> &words)
{

    if (current->getIndex(26) != nullptr)
    {
        words.push_back(str); // in this case, str will be the completed word
    }
    for (int i = 0; i < 26; i++)
    {
        if (current->getIndex(i) != nullptr)
        {
            char c = 'a' + i; // converts index to char
            completeHelper((current->getIndex(i)), (str + c), words);
        }
    }
}

vector<string> Trie::complete(string str)
{
    vector<string> wordVec;
    Node *current = root; // start with the root
    for (int i = 0; i < str.length(); i++)
    { // this gets the starting node for the complete() vector
        int index = (str[i] - 'a');
        if (current->getIndex(index) != nullptr) // progress the trie
        {
            current = current->getIndex(str[i] - 'a');
        }
        else
        { // if there is no word that starts with str
            return wordVec;
        }
    }
    completeHelper(current, str, wordVec); // this is a recursive function
    return wordVec;                        // return the list of words
}