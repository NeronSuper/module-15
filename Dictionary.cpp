#include "Dictionary.h"

Dictionary::Dictionary()
	: myDict()
{

}

void Dictionary::cliMain()
{
	while (1)
	{
		system("cls");
		cout << "1. Add words\n"
			<< "2. Autocomplete\n"
			<< "3. List of your words\n"
			<< "0. Exit\n";

		int input;
		cin >> input;

		switch (input)
		{
		case 0:
			return;

		case 1:
			addWord();

			break;

		case 2:
			autoComplete();

			break;
		case 3:
			ListOfWords();

			break;
		default:
			break;
		}
	}



}

void Dictionary::ListOfWords()
{
	system("cls");

	string words;
	myDict.getWords(words);

	stringstream ss;
	ss << words;

	string tmp;
	while (ss >> tmp)
	{
		cout << tmp << '\n';
	}

	system("pause");
}

void Dictionary::addWord()
{
	system("cls");

	cout << "Enter a word or several words separated by a space: ";

	string str;
	std::cin.ignore();
	getline(cin, str);

	stringstream ss;
	ss << str;

	string tmp;
	while (ss >> tmp)
	{
		myDict.insert(tmp);
	}
}

void Dictionary::autoComplete()
{
	while (1)
	{
		system("cls");
		cout << "Enter your word: ";

		string word;
		cin >> word;

		Trie::Node* lastNode = myDict.findLastNode(word);
		if (!lastNode)
		{
			cout << "nothing common\n";
			system("pause");

			continue;
		}
		char buf[255];
		string result;

		myDict.getWords(lastNode, buf, 0, result);


		stringstream ss;
		ss << result;

		string tmp;
		while (ss >> tmp)
		{
			cout << word + tmp << '\n';
		}

		break;
	}
	

	system("pause");
}
