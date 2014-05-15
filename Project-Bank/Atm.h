
#ifndef ATM_H
#define ATM_H

class AtmSession;

#include <queue>
#include "AtmSession.h"
#include "DepositOperation.h"
#include "CustomersManagment.h"
#include "AccountsManagment.h"
#include "CreditCard.h"
#include "AtmCash.h"

class Atm
{
public:
	Atm(CustomersManagment& ,AccountsManagment&);
	~Atm();

	void RefillAtm();
	void ConfirmDepositsOperations();
	vector<Operation> GetDailyHistoryOperations() const;
	AtmSession GetSession(CreditCard, int);
	
private:
	CustomersManagment& customersManagment;
	AccountsManagment& accountsManagment;
	queue<DepositOperation> depositOperations;
	vector<Operation> dailyHistoryOperations;
	AtmCash atmCash;
};

#endif