
#ifndef BANK_H
#define BANK_H

#include <string>
#include "AccountsManagment.h"
#include "CustomersManagment.h"
#include "Controller.h"
#include "Atm.h"
#include "Clerk.h"
#include "Manager.h"

using namespace std;

class Bank
{
public:
	Bank(string); //Bank "BIG MONEY"

	string GetName();
	Atm& GetAtm();
	Clerk& GetClerk();
	Manager& GetManager();
	
private:
	const string name;
	AccountsManagment accountManagment;
	CustomersManagment customerManagment;
	Atm atm;
	Clerk clerk;
	Manager manager;
};

#endif