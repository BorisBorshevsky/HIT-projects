
#include <iostream>
#include <string>
#include "Dictionary.h"
#include "DictionaryExceptions.h"
using namespace std;


// an example of using Dictionary class
int main()
{
	
	Dictionary<string, int> dic;
	try 
	{
		dic.AddWord("Bob",3);	
		dic.AddWord("Eve",7);
		dic.AddWord("Dan",12);
		dic.AddWord("Shawn",14);
	}
	catch (DictionarySizeOverflow e)
	{
		cout << e.what() << endl;
	};
	string word2 = "Bsob";
	string word1 = "Bob";
	cout << "Lang1 word: " << word1 << endl;
	try 
	{
	cout << "Translated to: " << dic.Translate1to2(word1) << endl;
	}
	catch (WordNotFound e)
	{
		cout << e.what() << endl;
	};

	flushall();
	getchar();



};
