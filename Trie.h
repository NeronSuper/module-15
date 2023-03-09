#pragma once
#include <iostream>
#include <string>
using namespace std;

#define ALPHABIT_SIZE 26

class Trie
{
public:
    class Node
    {
    public:

        Node();

        Node* children[ALPHABIT_SIZE];

        bool isEndOfWord;
    };

    Trie();

    void insert(const std::string& str);

    void getWords(string& res);
    int getCountOfWords() const;

    Node* findLastNode(const string& word);

    void getWords(Node* root, char buf[], int ind, string& res);
private:

    Node* root;
    int wordsCounter;
};