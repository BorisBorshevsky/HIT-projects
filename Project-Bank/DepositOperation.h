#ifndef DEPOSIT_OPERATION_H
#define DEPOSIT_OPERATION_H

#include "Operation.h"

class DepositOperation : public Operation
{
public:
	DepositOperation(double amount, int accountId);
};

#endif