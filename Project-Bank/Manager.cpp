

#include "Manager.h"
#include "AccountsReport.h"
#include <vector>
#include "Account.h"

Manager::Manager(CustomersManagment & customersManagment, AccountsManagment & accountsManagment)
:Clerk(customersManagment, accountsManagment)
{
	
};

AccountReport Manager::GetAllOverdraftAccounts()
{
	vector<AccountInfo> overdraftAccount;	
	vector<Account *>::iterator iter , end;
	iter = accountsManagment.GetAccounts().begin();
	end = accountsManagment.GetAccounts().end();
	for (iter;iter != end; ++iter)
	{
		if ((*iter)->GetBalance() < 0)
			overdraftAccount.push_back((*iter)->GetInfo());
	}

	return AccountReport(overdraftAccount); 
};


Result Manager::UnlinkOwnerToAccount(int customerId, int accountId)
{
	Result result;
	result.isSuccess=false;
	
	vector<int>::iterator iter , end;
	Customer *customer = customersManagment.GetCustomer(customerId);
	if (customer == NULL)
	{
		result.errorMessage = "Customer not found";
		return result;
	}
	vector<int> accounts = customer->getAccounts();
	iter = accounts.begin();
	end = accounts.end();
	bool wasRemoved = false;
	while (wasRemoved == false && iter != accounts.end())
	{
		if (*iter == accountId)
		{
			accounts.erase(iter);
			result.isSuccess = true;
			wasRemoved = true;
		}
		else
			iter++;
	}
	if (wasRemoved == false)
	{
		result.errorMessage = "Account not found";
		return result;
	}

	wasRemoved = false;
	vector<int> owners = accountsManagment.GetAccount(accountId)->GetOwners();
	iter = owners.begin();
	end  = owners.end();
	while (wasRemoved == false && iter != owners.end())
	{
		if (*iter == customerId)
		{
			owners.erase(iter);
			result.isSuccess = true;
			wasRemoved = true;
		}
		else
			iter++;
	}

	if (wasRemoved == false)
	{
		result.errorMessage = "Customer not found";
		return result;
	}

	result.isSuccess = true;
	return result;
};

