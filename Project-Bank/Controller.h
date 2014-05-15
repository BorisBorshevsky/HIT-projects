
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "CustomersManagment.h"
#include "AccountsManagment.h"

class Controller 
{
public:
	Controller(CustomersManagment &, AccountsManagment &);
	double GetBalance(int accountId) const;
	virtual void Deposit(int accountId, double amount) = 0;
	virtual Result Withdraw(int accountId, double amount) = 0;
	Result Transfer(int sourceAccountId, int targetAccountId, double amount);

protected:
	CustomersManagment & customersManagment;
	AccountsManagment & accountsManagment;
};

#endif