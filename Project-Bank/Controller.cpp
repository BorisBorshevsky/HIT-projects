
#include "Controller.h"
#include "CustomersManagment.h"
#include "AccountsManagment.h"

using namespace std;


Controller::Controller(CustomersManagment & customersManagment, AccountsManagment & accountsManagment)
	:customersManagment(customersManagment),
	accountsManagment(accountsManagment)
{ };


double Controller::GetBalance(int accountId) const
{
	return accountsManagment.GetAccount(accountId)->GetBalance();
};

Result Controller::Transfer(int sourceAccountId, int targetAccountId, double amount)
{
	Result result;
	result = accountsManagment.GetAccount(sourceAccountId)->Withraw(amount);
	if (result.isSuccess)
		result = accountsManagment.GetAccount(sourceAccountId)->Deposit(amount);
	return result;
};


