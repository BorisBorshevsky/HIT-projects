#ifndef BANK_TEST_H
#define BANK_TEST_H

#include "Bank.h"
#include "BankTypes.h"
#include "PersonalInfo.h"
#include <iostream>
#include <typeinfo>

using namespace std;

class BankTest
{
public:
	BankTest();
	~BankTest();

	void TestLinkCustomers();

private:

};

BankTest::BankTest()
{
}

BankTest::~BankTest()
{
}

void BankTest::TestLinkCustomers()
{
	Result res;
	Bank bankZol("LO ZOL PO");

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

	accountId = bankZol.GetClerk().CreateAccount(ACCOUNT_TYPE::Private_Account);
	res = bankZol.GetClerk().LinkOwnerToAccount(101, accountId);
	cout << "link normal customer 101 to Private account " << accountId << " should be true, :" << res.isSuccess << endl;

	accountId = bankZol.GetClerk().CreateAccount(ACCOUNT_TYPE::Business_Account);
	res = bankZol.GetClerk().LinkOwnerToAccount(101, accountId);
	cout << "link normal customer 101 to business account " << accountId << " should be false :" << res.isSuccess << endl;

	accountId = bankZol.GetClerk().CreateAccount(ACCOUNT_TYPE::Student_Account);
	res = bankZol.GetClerk().LinkOwnerToAccount(102, accountId);
	cout << "link gold customer 102 to student account " << accountId << " should be flase :" << res.isSuccess << endl;

	accountId = bankZol.GetClerk().CreateAccount(ACCOUNT_TYPE::Private_Account);
	res = bankZol.GetClerk().LinkOwnerToAccount(102, accountId);
	cout << "link gold customer 102 to Private account " << accountId << " should be true, :" << res.isSuccess << endl;

	accountId = bankZol.GetClerk().CreateAccount(ACCOUNT_TYPE::Business_Account);
	res = bankZol.GetClerk().LinkOwnerToAccount(102, accountId);
	cout << "link gold customer 102 to business account " << accountId << " should be true, :" << res.isSuccess << endl;

	accountId = bankZol.GetClerk().CreateAccount(ACCOUNT_TYPE::Student_Account);
	res = bankZol.GetClerk().LinkOwnerToAccount(103, accountId);
	cout << "link paltinum customer 103 to student account " << accountId << " should be false :" << res.isSuccess << endl;

	accountId = bankZol.GetClerk().CreateAccount(ACCOUNT_TYPE::Private_Account);
	res = bankZol.GetClerk().LinkOwnerToAccount(103, accountId);
	cout << "link paltinum customer 103 to Private account " << accountId << " should be true, :" << res.isSuccess << endl;

	accountId = bankZol.GetClerk().CreateAccount(ACCOUNT_TYPE::Business_Account);
	res = bankZol.GetClerk().LinkOwnerToAccount(103, accountId);
	cout << "link paltinum customer 103 to business account " << accountId << " should be true, :" << res.isSuccess << endl;

	res = bankZol.GetClerk().LinkOwnerToAccount(103, 66);
	cout << "link paltinum customer 103 to business account " << accountId << " should be false :" << res.isSuccess << endl;

	res = bankZol.GetClerk().LinkOwnerToAccount(103111, accountId);
	cout << "link paltinum customer 103 to business account " << accountId << " should be false :" << res.isSuccess << endl;

	res = bankZol.GetManager().UnlinkOwnerToAccount(103, accountId);
	cout << "unlink paltinum customer 103 to business account " << accountId << " should be true :" << res.isSuccess << endl;

	res = bankZol.GetManager().UnlinkOwnerToAccount(107773, accountId);
	cout << "unlink paltinum customer 107773 to business account " << accountId << " should be false :" << res.isSuccess << endl;
}


#endif // !BANK_TEST_H
