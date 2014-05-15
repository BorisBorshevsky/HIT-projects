#include "PlatinumCustomer.h"

PlatinumCustomer::PlatinumCustomer(PersonalInfo& personalInfo)
:Customer(personalInfo)
{ }

CUSTOMER_TYPE PlatinumCustomer::GetType() const
{
	return CUSTOMER_TYPE::Platinum_Customer;
};