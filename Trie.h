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
    bool insert(string str);

private:
    int wordCount, size; // int vars

    Node *root;
};