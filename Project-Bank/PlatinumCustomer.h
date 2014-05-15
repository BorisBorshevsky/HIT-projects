#ifndef PLATINUM_CUSTOMER
#define PLATINUM_CUSTOMER

#include "Customer.h"

class PlatinumCustomer: public Customer
{
public:
	PlatinumCustomer(PersonalInfo &);
	virtual CUSTOMER_TYPE GetType() const;
};


#endif