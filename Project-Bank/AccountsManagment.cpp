
#include "AccountsManagment.h"
#include "Account.h"
#include "Account.h"
#include <vector>

AccountsManagment::AccountsManagment()
{ };

void AccountsManagment::AddAccount(Account *account)
{
	accounts.push_back(account);

};

//TODO: TO FIX
Account* AccountsManagment::GetAccount(int accountId) const
{
	vector<Account *>::const_iterator iter;
	for (iter = accounts.begin(); iter != accounts.end(); ++iter)
	{
		if ((*iter)->GetInfo().accountId == accountId)
			return *iter;
	}
return NULL;
};

void AccountsManagment::RemoveAccount(int accountId)
{
	vector<Account *>::iterator iter;
	for(iter = accounts.begin(); iter != accounts.end(); ++iter )
	{
		if( (*iter)->GetInfo().accountId == accountId )
			accounts.erase(iter);
	}
};

bool AccountsManagment::IsAccountExists(int accountId) const
{
	bool isExist = false;
	for(unsigned int index = 0; index < accounts.size(); index++)
	{
		if (accounts[index]->GetInfo().accountId == accountId)
			isExist = true;
	}

	return isExist;
};

vector<Account *> AccountsManagment::GetAccounts() const
{
	return accounts;		
};

