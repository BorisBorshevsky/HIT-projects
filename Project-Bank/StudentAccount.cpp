

#include "StudentAccount.h"
#include "Account.h"

#define STUDENT_CREDIT 0
#define STUDENT_COMMITION 0

StudentAccount::StudentAccount()
	:Account(STUDENT_CREDIT,STUDENT_COMMITION)
{ };

ACCOUNT_TYPE StudentAccount::GetType() const
{
	return ACCOUNT_TYPE::Student_Account;
};


