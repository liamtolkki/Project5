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

    string input1;
    string input2;

    do
    {
        cout << "Please enter a word prefix or press enter to exit: ";

        getline(cin, input1);
        if (!input1.empty())
        {
            vector<string> completed = wordTrie.complete(input1);
            if (!completed.empty())
            {
                cout << "there are " << completed.size() << " completions starting with: '" << input1 << "'. Show completions (y/n)? ";
                getline(cin, input2);
                if (input2 == "y" || input2 == "yes")
                {
                    for (int i = 0; i < completed.size(); i++)
                    {
                        cout << completed[i] << endl;
                    }
                }
            }
        }

    } while (!input1.empty());
    return 0;
}