
/*
BusinessAccount.h
Class for BusinessAccount
*/

#ifndef BUSINESS_ACCOUNT_H
#define BUSINESS_ACCOUNT_H


#include "Account.h"

class BusinessAccount : public Account
{
public:
	BusinessAccount();
	virtual ACCOUNT_TYPE GetType() const;
};


#endif