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

    cout << "Testing find()..." << endl;
    cout << "Word: 'hello', Should be: 1. Result:   " << wordTrie.find("hello") << endl;
    cout << "Word: 'coffee', Should be: 1. Result:   " << wordTrie.find("coffee") << endl;
    cout << "Word: 'jjjjo', Should be: 0. Result:   " << wordTrie.find("jjjjo") << endl;
    cout << "Word: 'capacitance', Should be: 1. Result:   " << wordTrie.find("capacitance") << endl;
    string input;
    do
    {
        cout << "Please enter a word prefix or press enter to exit: ";

        getline(cin, input);
        if (!input.empty())
        {
            vector<string> completed = wordTrie.complete(input);
            for (int i = 0; i < completed.size(); i++)
            {
                cout << completed[i] << endl;
            }
        }
    } while (!input.empty());

    return 0;
}