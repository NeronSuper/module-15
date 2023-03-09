#pragma once

#include "Trie.h"

#include <sstream>

class Dictionary
{
public:
	Dictionary();

	void cliMain();

private:

	void ListOfWords();
	void addWord();
	void autoComplete();

private:
	Trie myDict;

};

