Project5: Project5.o Trie.o
    g++ -g -ggdb Project5.o Trie.o -o Project5

Project5.o: Project5.cpp
    g++ -g -ggdb -c Project5.cpp

Trie.o: Trie.cpp
    g++ -g -ggdb -c Trie.cpp

clean:
    del /Q /F Project5.exe *.o