#include "CustomerReport.h"
#include "CustomersManagment.h"



CustomerReport::CustomerReport(PersonalInfo info, vector<AccountInfo> accountsInfo, double totalBalance)
	:personalInfo(info),
	accountsInfo(accountsInfo),
	totalBalance(totalBalance)
{ };