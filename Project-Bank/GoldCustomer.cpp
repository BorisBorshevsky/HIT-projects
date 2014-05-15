
#include "GoldCustomer.h"

GoldCustomer::GoldCustomer(PersonalInfo & personalInfo)
:Customer(personalInfo)
{ }

CUSTOMER_TYPE GoldCustomer::GetType() const
{
	return CUSTOMER_TYPE::Gold_Customer;
};