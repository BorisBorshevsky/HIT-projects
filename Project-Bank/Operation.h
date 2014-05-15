#ifndef OPERATION_H
#define OPERATION_H

#include <string>

using namespace std;

class Operation
{
public:
	Operation(double, int);

	const double amount;
	const int accountId;
};


#endif
