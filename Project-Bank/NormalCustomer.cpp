#include "NormalCustomer.h"

NormalCustomer::NormalCustomer(PersonalInfo& personalInfo)
:Customer(personalInfo)
{ }

CUSTOMER_TYPE NormalCustomer::GetType() const
{
	return CUSTOMER_TYPE::Normal_Customer;
};