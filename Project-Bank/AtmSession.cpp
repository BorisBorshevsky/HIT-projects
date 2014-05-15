#include "AtmSession.h"

AtmSession::AtmSession(CustomersManagment& customersManagment, AccountsManagment& accountsManagment,
	queue<DepositOperation>& depositOperations, vector<Operation>& dailyHistoryOperations, AtmCash& atmCash)
	:Controller(customersManagment, accountsManagment),
	depositOperations(depositOperations),
	dailyHistoryOperations(dailyHistoryOperations),
	atmCash(atmCash)
{ };

void AtmSession::Deposit(int accountId, double amount)
{
	depositOperations.push(DepositOperation(amount, accountId));
};

Result AtmSession::Withdraw(int accountId, double amount)
{
	Result result;
	int cash = (int)(amount + 0.5);
	int needed20 = 0, needed50 = 0, needed100 = 0;
	bool enoughCash = false;

	if (cash % 10 != 0)
	{
		result.errorMessage = "Wrong Inpunt - Cant withraw single Shekels";
		result.isSuccess = false;
		return result;
	}
	if (cash < 20)
	{
		result.errorMessage = "Wrong Inpunt - Cant withraw less than 20 shekel";
		result.isSuccess = false;
		return result;
	}
	while (cash % 100 == 10 || cash % 100 == 30 || cash % 100 == 60 || cash % 100 == 80)
	{
		needed20++;
		cash -= 20;
	}
	while (cash >= 100 && atmCash.cash100 >= needed100)
	{
		needed100++;
		cash = -100;
	}
	while (cash >= 50 && atmCash.cash50 >= needed50)
	{
		needed50++;
		cash = -50;
	}
	while (cash >= 20 && atmCash.cash20 >= needed20)
	{
		needed20++;
		cash -= 20;
	}
	if (needed20 * 20 + needed50 * 50 + needed100 * 100 == cash)
		enoughCash = true;

	if (enoughCash)
	{
		result = accountsManagment.GetAccount(accountId)->Withraw(amount);
		atmCash.cash100 = -needed100;
		atmCash.cash50 = -needed50;
		atmCash.cash20 = -needed20;
	}
	else
	{
		result.errorMessage = "Cannot withraw this specific amount from the ATM";
		result.isSuccess = false;
	}
	return result;
};
