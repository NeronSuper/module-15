#include "Trie.h"

Trie::Node::Node()
    : isEndOfWord(false)
{
    for (int i = 0; i < ALPHABIT_SIZE; i++)
    {
        children[i] = nullptr;
    }
}

Trie::Trie()
    : wordsCounter(0)
{
    root = new Node();
}

void Trie::insert(const std::string& str)
{
    Node* current = root;
    for (int i = 0; i < str.size(); i++)
    {
        int index = str[i] - 'a';
        if (!current->children[index])
            current->children[index] = new Node();

        current = current->children[index];
    }

    ++wordsCounter;
    current->isEndOfWord = true;
}

void Trie::getWords(string& res)
{
    char buf[255];

    getWords(root, buf, 0, res);
}

int Trie::getCountOfWords() const
{
    return wordsCounter;
}

Trie::Node* Trie::findLastNode(const string& word)
{
    Node* current = root;
    for (int i = 0; i < word.size(); i++)
    {
        int index = word[i] - 'a';
        if (!current->children[index])
            return nullptr;

        current = current->children[index];
    }

    return current;
}





void Trie::getWords(Node* root, char buf[], int ind, string& res)
{
    if (root->isEndOfWord)
    {
        buf[ind] = '\0';
        res += buf;
        res += ' ';
    }

    for (int i = 0; i < ALPHABIT_SIZE; i++)
    {
        if (root->children[i])
        {
            buf[ind] = i + 'a';
            getWords(root->children[i], buf, ind + 1, res);
        }
    }
}
