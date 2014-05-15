/*
Dictionary
translates words from Lang 1 to Lang 2 or vice versa
*/

#ifndef DICTIONARY_H
#define DICTIONARY_H
#define MAX_DICTIONARY_SIZE 100


template <class Lang1, class Lang2>
class Dictionary
{
public:
	// init an empty dictionary
	Dictionary();
	
	// add word and translation to the dictionary
	void AddWord(Lang1 const &word1, Lang2 const &word2);
	
	// Translate Words (by function)
	Lang1 Translate2to1(Lang2 const &word) const;
	Lang2 Translate1to2(Lang1 const &word) const;

private:
	Lang1 words1[MAX_DICTIONARY_SIZE];
	Lang2 words2[MAX_DICTIONARY_SIZE];
	
	// Current ammount of words
	unsigned int dictionarySize;
};


#endif
