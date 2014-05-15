#include "Atm.h"

Atm::Atm(CustomersManagment& customersManagment, AccountsManagment& accountsManagment)
:customersManagment(customersManagment),
accountsManagment(accountsManagment)
{ };


Atm::~Atm()
{
	
};

void Atm::RefillAtm()
{
	/*atmCash.cash20 = 500;
	atmCash.cash50 = 500;
	atmCash.cash100 = 500;*/
};

vector<Operation> Atm::GetDailyHistoryOperations() const
{
	return this->dailyHistoryOperations;
};

void Atm::ConfirmDepositsOperations()
{
	while (depositOperations.empty() == false)
	{
		DepositOperation operation = depositOperations.front();
		Account *account = accountsManagment.GetAccount(operation.accountId);
		account->Deposit(operation.amount);

		depositOperations.pop();
	}
};

AtmSession Atm::GetSession(CreditCard creditCard, int pinCode)
{
	if (accountsManagment.IsAccountExists(creditCard.accountId) == false)
		throw new invalid_argument("the account does not exists");
	if (creditCard.pinCode != pinCode)
		throw new invalid_argument("the pinCode does not match to the credit card pinCode");

	return AtmSession(customersManagment, accountsManagment, depositOperations, dailyHistoryOperations, atmCash);
};
