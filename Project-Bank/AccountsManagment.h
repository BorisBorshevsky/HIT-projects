#ifndef ACCOUNT_MANAGMENTS_H
#define ACCOUNT_MANAGMENTS_H

using namespace std;

#include "Account.h"
#include "AccountInfo.h"
#include "BankTypes.h"
#include <vector>

class AccountsManagment
{
public:
	AccountsManagment();
	void AddAccount(Account *account);
	void RemoveAccount(int AccountId);
	Account* GetAccount(int AccountId) const;
	bool IsAccountExists(int AccountId) const;
	vector<Account *> GetAccounts() const;

private:

	static AccountsManagment *instance;
	vector<Account *> accounts;
};

#endif