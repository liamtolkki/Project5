#pragma once

#include "Node.h"
#include <string>
#include <vector>
using namespace std;

class Trie
{
public:
    Trie();  // default constructor
    ~Trie(); // destructor
    int getCount();
    int getSize();
    bool insert(string str);
    bool find(string str);
    int completeCount(string str);
    vector<string> complete(string str);
    Trie &operator=(const Trie &);
    void copyHelper(Node *&current1, Node *&current2);

private:
    int wordCount, size; // int vars

    void completeHelper(Node *current, const string &str, vector<string> &words); // recursive function

    string charsToString(vector<char> charVec);

    Node *root;
};