#include "ConsoleUI.h"

void ConsoleUI::ChooseController()
{
	PrintHomeScreen();
	cout << "Who are you??" << endl;
	cout << "1 - Im a Customer" << endl;
	cout << "2 - Im a Clerk" << endl;
	cout << "3 - Im a Manager" << endl;
	char c = getchar();
	switch (c)
	{
	case '1':
		CustomerUI();
		break;
	case '2':
		ClerkUI();
		break;
	case '3':
		ManagerUI();
		break;
	default:
		break;
	}

}

void ConsoleUI::PrintLogo()
{
	system("cls");
	cout << endl << "Welcome!" << endl;
}

void ConsoleUI::ManagerUI()
{
	system("cls");
	cout << "Hello manager, what would you like to do?" << endl;
	cout << "1 - Im a Customer" << endl;
	cout << "2 - Im a Clerk" << endl;
	cout << "3 - Im a Manager" << endl;
	char c = getchar();
	switch (c)
	{
	case '1':
		CustomerUI();
		break;
	case '2':
		ClerkUI();
		break;
	case '3':
		ManagerUI();
		break;
	default:
		break;
	}
}

void ConsoleUI::ClerkUI()
{
	system("cls");
	cout << "Hello clerk, what would you like to do?" << endl;
	
	char c = getchar();
	Clerk& clerk = bank->GetClerk();
	switch (c)
	{
	case 'A':	CreateNewCustomerUI(clerk);
		break;
	case 'B':	ViewEditExistingCustomerUI();
		break;
	case 'C':	RefillTheAtmUI();
		break;
	case 'D':	GenerateTransactionReportAtmUI();
		break;
	case 'E':	ConfirmDepositsAtmUI();
		break;
	case 'F':	CreateNewAccountUI();
		break;
	case 'G':	ViewInfoOfAccountUI();
		break;
	case 'H':	UpdateInfoOfExistAccountUI();
		break;
	case 'I':	LinkCustomerAccountUI();
		break;
	case 'J':	DepositWithrowTransferUI();
		break;
	case 'K':	DisableAccountUI();
		break;
	default:
		break;
	}
}

void ConsoleUI::CustomerUI() {}

void ConsoleUI::AtmUI() {}


void ConsoleUI::PrintClerkMenu()
{
	cout << "A - Create a new Customer" << endl;
	cout << "B - View/Edit Existing Customer" << endl;
	cout << "C - Refill the Atm" << endl;
	cout << "D - Generate transaction report from the ATM" << endl;
	cout << "E - Confirm Deposits from the atm" << endl;
	cout << "F - Create a new Account" << endl;
	cout << "G - View information of existing account" << endl;
	cout << "H - Update information of existing account" << endl;
	cout << "I - Link an existing Account to Existing Customer" << endl;
	cout << "J - Deposit / Withrow / Transfer" << endl;
	cout << "K - Disable Account" << endl;
}


void ConsoleUI::CreateNewCustomerUI(Clerk clerk){}
void ConsoleUI::ViewEditExistingCustomerUI(){}
void ConsoleUI::RefillTheAtmUI(){}
void ConsoleUI::GenerateTransactionReportAtmUI(){}
void ConsoleUI::ConfirmDepositsAtmUI(){}
void ConsoleUI::CreateNewAccountUI(){}
void ConsoleUI::ViewInfoOfAccountUI(){}
void ConsoleUI::UpdateInfoOfExistAccountUI(){}
void ConsoleUI::LinkCustomerAccountUI(){}
void ConsoleUI::DepositWithrowTransferUI(){}
void ConsoleUI::DisableAccountUI(){}
