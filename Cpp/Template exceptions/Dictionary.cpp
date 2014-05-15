
#include "Dictionary.h"
#include "DictionaryExceptions.h"
#include <string>

template class Dictionary<int,int>;
template class Dictionary<string,string>;
template class Dictionary<string,int>;
template class Dictionary<int,string>;

template <class Lang1, class Lang2>
Dictionary<Lang1,Lang2>::Dictionary()
{
		this->dictionarySize = 0;
};


template <class Lang1, class Lang2>
void Dictionary<Lang1, Lang2> :: AddWord(Lang1 const &word1, Lang2 const &word2)
{
	if (dictionarySize >= MAX_DICTIONARY_SIZE)
		throw DictionarySizeOverflow("Dictionary is full");

	words1[dictionarySize] = word1;
	words2[dictionarySize] = word2;

	dictionarySize++;
};



template <class Lang1, class Lang2>
Lang2 Dictionary<Lang1,Lang2>::Translate1to2(Lang1 const &word) const
{
	for(int index = 0; index < dictionarySize ; index++)
	{
		if (words1[index] == word)
			return words2[index];
	}

	throw WordNotFound("Word not found");
};

template <class Lang1, class Lang2>
Lang1 Dictionary<Lang1,Lang2>::Translate2to1(Lang2 const &word) const
{
	for(int index = 0; index < dictionarySize ; index++)
	{
		if (words2[index] == word)
			return words1[index];
	}

	throw WordNotFound("Word not found");
};


