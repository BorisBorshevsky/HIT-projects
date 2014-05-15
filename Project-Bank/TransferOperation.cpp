#include "TransferOperation.h"

TransferOperation::TransferOperation(double amount, int sourceAccountId, int targetAccountId)
:Operation(amount, sourceAccountId),
targetAccountId(targetAccountId)
{ }