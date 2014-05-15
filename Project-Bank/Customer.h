#ifndef CUSTOMER_H
#define CUSTOMER_H


#include <string>
#include <iostream>
#include "Account.h"
#include <vector>
#include "PersonalInfo.h"
#include "CreditCard.h"

using namespace std;

//TODO: change customer to owner

class Customer  //abstruct
{
public:
	Customer(PersonalInfo &);

	PersonalInfo GetCopyOfInfo() const;

	virtual CUSTOMER_TYPE GetType() const = 0;

	Result AddAccount(int);
	Result RemoveAccount(int);
	
	
	PersonalInfo & GetInfo();

	vector<int> getAccounts() const;

	bool AccountExist(int) const;

private:
	CreditCard *card;
	PersonalInfo *info;   // used for editing personal info
	vector<int> accounts;
};

#endif