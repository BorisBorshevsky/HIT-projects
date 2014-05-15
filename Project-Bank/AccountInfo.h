#ifndef ACCOUNT_INFO_H
#define ACCOUNT_INFO_H

/*
AccountInfo.h
Used for reports as a copy of the info
not need for const, any change will be change "out of the bank"
*/

#include "BankTypes.h"
#include "Date.h"
#include <list>

using namespace std;

class AccountInfo
{
public:
	int accountId;		
	Date creationDate;

	double credit;		// misgeret ashrai
	double commition;	// Amla

	list<int> owners;	

	double balance;				//starts with 0
	bool isActive;
};

#endif