
#ifndef ACCOUNT_REPORT_H
#define ACCOUNT_REPORT_H

#include "Report.h"
#include "AccountInfo.h"
#include <vector>

class AccountReport : public Report
{
public:
	AccountReport(vector<AccountInfo>);
	const vector<AccountInfo> accounts;	
};

#endif