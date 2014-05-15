
#ifndef CLERK_H
#define CLERK_H

#include "Controller.h"
#include "DailyAtmActionsReport.h"
#include "CustomerReport.h"
#include "BankTypes.h"
#include "Atm.h"

class Clerk : public Controller
{
public:

	Clerk(CustomersManagment &, AccountsManagment &);

	void AddAtm(Atm&);
	Result CreateCustomer(CUSTOMER_TYPE, PersonalInfo&);
	Customer & GetCustomer(int customerId);
	
	void RefillAtm();
	DailyAtmActionsReport GetDailyAtmActionsReport();
	void ConfirmAtmDeposits();

	int CreateAccount(ACCOUNT_TYPE type);

	AccountInfo GetAccountInfo(int accountId);		//Returns Copy of Account Info
	Result LinkOwnerToAccount(int customerId, int accountId);
	Result CloseAccount(int accountId);
	CustomerReport GetCustomerReport(int customerId);

	double GetTotalAccountsBalance(int);
	virtual void Deposit(int accountId, double amount);
	virtual Result Withdraw(int accountId, double amount);
private:
	bool CheckAccountToCustomer(ACCOUNT_TYPE, CUSTOMER_TYPE);

	Atm *atm;

};

#endif