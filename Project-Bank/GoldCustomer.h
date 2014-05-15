#ifndef GOLD_CUSTOMER_H
#define GOLD_CUSTOMER_H

#include "Customer.h"

class GoldCustomer : public Customer
{
public:
	GoldCustomer(PersonalInfo &);
	virtual CUSTOMER_TYPE GetType() const;
};


#endif // !GOLD_CUSTOMER_H