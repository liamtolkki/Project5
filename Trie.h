#pragma once

#include "Node.h"
#include <string>
using namespace std;

class Trie
{
public:
    Trie(); // default constructor
    int getCount();
    int getSize();

private:
    int wordCount, size; // int vars
    bool insert(string str);
    Node *root;
};