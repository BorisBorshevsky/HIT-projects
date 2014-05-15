#include "Bank.h"
#include "Controller.h"

Bank::Bank(string name)
	:name(name),
	atm(customerManagment, accountManagment),
	clerk(customerManagment, accountManagment),
	manager(customerManagment, accountManagment)
{ };

Clerk& Bank::GetClerk()
{
	return clerk;
};

Atm& Bank::GetAtm()
{
	return atm;
};

Manager& Bank::GetManager()
{
	return manager;
};


