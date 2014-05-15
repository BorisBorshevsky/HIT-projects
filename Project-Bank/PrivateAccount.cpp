

#include "PrivateAccount.h"
#include "Account.h"

#define PRIVATE_CREDIT 5000
#define PRIVATE_COMMITION 4.5

PrivateAccount::PrivateAccount()
	:Account(PRIVATE_CREDIT,PRIVATE_COMMITION)
{ };

ACCOUNT_TYPE PrivateAccount::GetType() const
{
	return ACCOUNT_TYPE::Private_Account;
};



