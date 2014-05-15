#ifndef CUSTOMERS_MANAGMENT_H
#define CUSTOMERS_MANAGMENT_H

#include "Customer.h"
#include "BankTypes.h"
#include <vector>

class CustomersManagment
{
public:
	CustomersManagment();

	void CreateCustomer(CUSTOMER_TYPE type, PersonalInfo & personalInfo);
	void RemoveCustomer(int customerId);
	Customer* GetCustomer(int customerId) const;
	bool IsCustomerExists(int customerId) const;
	vector<Customer*> GetCustomers() const;

private:
	vector<Customer *> customers;

};

#endif