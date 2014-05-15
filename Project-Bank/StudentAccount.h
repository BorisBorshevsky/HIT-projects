#ifndef STUDENT_ACCOUNT_H
#define STUDENT_ACCOUNT_H

#include "Account.h"

class StudentAccount : public Account
{
public:
	StudentAccount();

	virtual ACCOUNT_TYPE GetType() const;
};

#endif



