
#ifndef NORMAL_CUSTOMER
#define NORMAL_CUSTOMER


#include "Customer.h"
#include "PersonalInfo.h"

class NormalCustomer: public Customer
{
public:
	NormalCustomer(PersonalInfo &);
	virtual CUSTOMER_TYPE GetType() const;
};

#endif