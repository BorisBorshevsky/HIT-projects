#ifndef DICTIONARYOVERFLOW_H
#define DICTIONARYOVERFLOW_H

#include <stdexcept>
using namespace std;

class DictionarySizeOverflow : public runtime_error 
{
public:
  DictionarySizeOverflow(string const & message)
      : runtime_error(message) {}
};


class WordNotFound : public runtime_error
{
public:
	WordNotFound(string const & message)
      : runtime_error(message) {}
};






#endif