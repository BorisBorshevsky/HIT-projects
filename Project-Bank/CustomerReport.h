
#ifndef CUSTOMER_REPORT_H
#define CUSTOMER_REPORT_H

#include "PersonalInfo.h"
#include "Report.h"
#include <vector>
#include "AccountInfo.h"

class CustomerReport : public Report
{
public:
	CustomerReport(PersonalInfo, vector<AccountInfo>, double);
	const PersonalInfo personalInfo;
	const vector<AccountInfo> accountsInfo;
	const double totalBalance;
};



#endif