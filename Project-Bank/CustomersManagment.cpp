

#include "CustomersManagment.h"
#include "Customer.h"
#include "NormalCustomer.h"
#include "GoldCustomer.h"
#include "PlatinumCustomer.h"
#include <vector>


CustomersManagment::CustomersManagment()
{ };

void CustomersManagment::CreateCustomer(CUSTOMER_TYPE type, PersonalInfo& personalInfo)
{
	Customer *customer;
	switch (type)
	{
	case Normal_Customer:
	{
							customer = new NormalCustomer(personalInfo);
							break;
	}
	case Gold_Customer:
	{
						  customer = new GoldCustomer(personalInfo);
						  break;
	}
	case Platinum_Customer:
	{
							  customer = new PlatinumCustomer(personalInfo);
							  break;
	}
	default:
		throw new exception("the customer type is not supported");
	}

	customers.push_back(customer);
};


Customer* CustomersManagment::GetCustomer(int customerId) const
{
	vector<Customer *>::const_iterator iter;
	for (iter = customers.begin(); iter != customers.end(); ++iter)
	{
		if ((*iter)->GetInfo().GetCustomerId() == customerId)
			return *iter;
	}
	return NULL;
};

void CustomersManagment::RemoveCustomer(int customerId)
{
	vector<Customer *>::iterator iter;
	for (iter = customers.begin(); iter != customers.end(); ++iter)
	{
		if ((*iter)->GetInfo().GetCustomerId() == customerId)
			customers.erase(iter);
	}
};

bool CustomersManagment::IsCustomerExists(int customerId) const
{
	vector<Customer *>::const_iterator iter;
	for (iter = customers.begin(); iter != customers.end(); ++iter)
	{
		if ((*iter)->GetInfo().GetCustomerId() == customerId)
			return true;
	}
	return false;
};


vector<Customer*> CustomersManagment::GetCustomers() const
{
	return customers;
};
