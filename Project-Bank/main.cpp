#include "Bank.h"
#include "BankTypes.h"
#include "PersonalInfo.h"
#include "BankTest.h"
#include <iostream>
#include <typeinfo>

using namespace std;

void runRealEnv()
{
	Result res;
	Bank bankZol("Kesef Gadol");

	Date now;
	PersonalInfo p1(now, 101);
	PersonalInfo p2(now, 102);
	PersonalInfo p3(now, 103);

	bankZol.GetClerk().CreateCustomer(CUSTOMER_TYPE::Normal_Customer, p1);
	bankZol.GetClerk().CreateCustomer(CUSTOMER_TYPE::Gold_Customer, p2);
	bankZol.GetClerk().CreateCustomer(CUSTOMER_TYPE::Platinum_Customer, p3);

	int accountId = bankZol.GetClerk().CreateAccount(ACCOUNT_TYPE::Student_Account);
	res = bankZol.GetClerk().LinkOwnerToAccount(101, accountId);
	cout << "link normal customer 101 to student account " << accountId << " should be true, :" << res.isSuccess << endl;
}

int main()
{
	//Run bank tests
	BankTest bankTest;
	bankTest.TestLinkCustomers();
	Bank bank("hello");
	bank.GetAtm().GetSession(creditCard,pincode).Transfer(sourceAccID,targetAccID,double);
	
	
	//runRealEnv();
	getchar();
	return 0;
};



