#include "Customer.h"

using namespace std;


Customer::Customer(PersonalInfo & info)
{
	this->info = &info;
};

PersonalInfo & Customer::GetInfo()
{
	return *info;		
};

PersonalInfo Customer::GetCopyOfInfo() const
{
	PersonalInfo personalInfo(*info);
	return personalInfo;
}


Result Customer::AddAccount(int accountId)
{
	//TODO: check that the customer has not 2 overdraft accounts
	Result result;
	if (AccountExist(accountId))
	{
		result.errorMessage = "Account already exists";
		result.isSuccess = false;
	}
	else
	{
		result.isSuccess = true;
		accounts.push_back(accountId);
	}
	return result;
};

Result Customer::RemoveAccount(int accountId)
{
	Result result;
	vector<int>::iterator iter;
	for(iter = accounts.begin(); iter != accounts.end(); ++iter )
	{
		if( *iter == accountId )
		{
			result.isSuccess = true;
			accounts.erase( iter );
			return result;
		}	
	}
	result.errorMessage = "Account not found";
	result.isSuccess = false;
	return result;
};

vector<int> Customer::getAccounts() const
{
	return accounts;
}


bool Customer::AccountExist(int accountId) const
{
	unsigned int index;
	for(index=0; index < accounts.size(); index++)
	{
		if (accounts[index] == accountId)
			return true;
	}
	return false;
};