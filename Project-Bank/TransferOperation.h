#ifndef DEPOSIT_OPERATION_H
#define DEPOSIT_OPERATION_H

#include "Operation.h"

class TransferOperation : public Operation
{
public:
	TransferOperation(double amount, int sourceAccountId, int targetAccountId);

	const int targetAccountId;
};

#endif