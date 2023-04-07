/*
Liam Tolkkinen
Project 5 (Alphabet trie)
Data Structures and Algorithms
3/29/2023
*/
#include "Trie.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main()
{

    ifstream fileIn("wordlist_windows.txt"); // gets the word file
    vector<string> wordBank;
    Trie wordTrie; // the trie
    cout << "Opening file..." << endl;
    // make sure there is no error:
    if (fileIn.good())
    {
        string word;
        cout << "File opened sucessfully!" << endl;
        while (!fileIn.eof())
        {
            fileIn >> word;
            bool inserted;
            inserted = wordTrie.insert(word);
        }
    }
    else
    {
        cerr << "Couldn't open file!" << endl;
    }

    return 0;
}