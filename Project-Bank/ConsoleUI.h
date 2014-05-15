#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include "Bank.h"

class ConsoleUI
{
public:
	ConsoleUI(Bank& bank);

	void Run();

private:

	void PrintLogo();
	void ChooseController();
	void ManagerUI();
	void ClerkUI();
	void CustomerUI();
	void AtmUI();
	void ConsoleUI::PrintClerkMenu();
	void CreateNewCustomerUI(Clerk clerk);
	void ViewEditExistingCustomerUI();
	void RefillTheAtmUI();
	void GenerateTransactionReportAtmUI();
	void ConfirmDepositsAtmUI();
	void CreateNewAccountUI();
	void ViewInfoOfAccountUI();
	void UpdateInfoOfExistAccountUI();
	void LinkCustomerAccountUI();
	void DepositWithrowTransferUI();
	void DisableAccountUI();
	

	Bank * bank;

};

#endif // !CONSOLE_UI_H
