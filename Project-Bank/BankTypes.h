#ifndef BANK_TYPES_H
#define BANK_TYPES_H

#include <string>

enum CUSTOMER_TYPE
{
	Normal_Customer,
	Gold_Customer,
	Platinum_Customer
};

enum ACCOUNT_TYPE
{
	Student_Account,
	Private_Account,
	Business_Account
};

struct Result
{
	bool isSuccess;
	std::string errorMessage;
};


#endif