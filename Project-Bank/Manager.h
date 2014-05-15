#ifndef MANAGAR_H
#define MANAGER_H




#include "Clerk.h"
#include "AccountsReport.h"

class Manager : public Clerk
{
public:
	Manager(CustomersManagment &, AccountsManagment &);

	AccountReport GetAllOverdraftAccounts();

	Result UnlinkOwnerToAccount(int customerId, int accountId);
	
};



#endif // !MANAGAR_H