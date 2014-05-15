

#include "BusinessAccount.h"
#include "Account.h"
#include "BankTypes.h"

#define BUSINESS_CREDIT 10000
#define BUSINESS_COMMITION 6.5

BusinessAccount::BusinessAccount()
	:Account(BUSINESS_CREDIT,BUSINESS_COMMITION)
{ };

ACCOUNT_TYPE BusinessAccount::GetType() const
{
	return ACCOUNT_TYPE::Business_Account;
};



