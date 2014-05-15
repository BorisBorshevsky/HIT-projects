#ifndef PRIVATE_ACCOUNT_H
#define PRIVATE_ACCOUNT_H

#include "Account.h"

class PrivateAccount : public Account
{
public:
	PrivateAccount();

	virtual ACCOUNT_TYPE GetType() const;
};



#endif