#ifndef ATM_SESSION_H
#define ATM_SESSION_H

#include "Atm.h"
#include "AtmCash.h"
#include "CustomersManagment.h"
#include "AccountsManagment.h"
#include "Controller.h"
#include "DepositOperation.h"
#include <vector>
#include <queue>

class AtmSession : public Controller
{
public:
	AtmSession(CustomersManagment& ,AccountsManagment&, queue<DepositOperation>&, vector<Operation>&, AtmCash&);
	virtual void Deposit(int accountId, double amount);
	virtual Result Withdraw(int accountId, double amount);

private:
	queue<DepositOperation> & depositOperations;
	vector<Operation> & dailyHistoryOperations;
	AtmCash& atmCash;
};



#endif // !ATM_SESSION_H
