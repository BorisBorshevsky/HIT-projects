#ifndef DAILY_ATM_ACTIONS_REPORT_H
#define DAILY_ATM_ACTIONS_REPORT_H

#include "Report.h"
#include "Operation.h"
#include <vector>

class DailyAtmActionsReport : public Report
{
public:
	DailyAtmActionsReport(vector<Operation>);
	const vector<Operation> operations;

};

#endif