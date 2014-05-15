
#include "Clerk.h"
#include "StudentAccount.h"
#include "PrivateAccount.h"
#include "BusinessAccount.h"
#include <vector>
#include <typeinfo>

Clerk::Clerk(CustomersManagment & customersManagment, AccountsManagment & accountsManagment)
	:Controller(customersManagment,accountsManagment)
{ 
	atm = NULL;
};

Result Clerk::Withdraw(int accountId, double amount)
{
	Result res = accountsManagment.GetAccount(accountId)->Withraw(amount);
	return res;
};

void Clerk::Deposit(int accountId, double amount)
{
	accountsManagment.GetAccount(accountId)->Deposit(amount);
};

Result Clerk::CreateCustomer(CUSTOMER_TYPE type, PersonalInfo& personalInfo)
{
	Result result;
	bool isCustomerExists = customersManagment.IsCustomerExists(personalInfo.GetCustomerId());
	if (isCustomerExists == false)
	{
		result.isSuccess = true;
		customersManagment.CreateCustomer(type, personalInfo);
	}
	else
	{
		result.isSuccess = false;
		result.errorMessage = "The customer already exist";
	}
	return result;

};

bool Clerk::CheckAccountToCustomer(ACCOUNT_TYPE accountType, CUSTOMER_TYPE customerType)
{
	if (accountType == ACCOUNT_TYPE::Student_Account && customerType != CUSTOMER_TYPE::Normal_Customer)
		return false;
	if (accountType == ACCOUNT_TYPE::Business_Account && customerType == CUSTOMER_TYPE::Normal_Customer)
		return false;
	return true;
}

// TODO: cehck typeof account to type of customer
Result Clerk::LinkOwnerToAccount(int customerId, int accountId)
{
	Result result;
	result.isSuccess = false;
	Customer *customer = customersManagment.GetCustomer(customerId);
	if (customer == NULL)
	{
		result.errorMessage = "Customer not found";
		return result;
	}
	Account * account = accountsManagment.GetAccount(accountId);
	if (account == NULL)
	{
		result.errorMessage = "Account not found";
		return result;
	}
	if (CheckAccountToCustomer(account->GetType(), customer->GetType()) == false)
	{
		result.errorMessage = "The account type can not be belong to customer type";
		return result;
	}
	
	int overDraft = 0;
	vector<int>::const_iterator iter , end;
	vector<int> accounts = customer->getAccounts();
	iter = accounts.begin();
	end = accounts.end();
	for (iter; iter != end; ++iter)
	{
		if (accountsManagment.GetAccount(*iter)->GetBalance() < 0) 
			overDraft++;
	}
	if (overDraft > 2) 
	{
		result.errorMessage = "Too many accounts in overdraft";
		result.isSuccess = false;
		return result;
	}
	result.isSuccess=true;
	account->AddOwner(customerId);
	customer->AddAccount(accountId);

	return result;
};

AccountInfo Clerk::GetAccountInfo(int accountId)
{
	return accountsManagment.GetAccount(accountId)->GetInfo();
};

Result Clerk::CloseAccount(int accountId)
{
	Result result;
	result.isSuccess = true;
	if (accountsManagment.GetAccount(accountId)->GetBalance() == 0)
		accountsManagment.GetAccount(accountId)->Disable();
	else
	{
		result.isSuccess = false;
		result.errorMessage = "Account balance is not 0";
	}
	return result;
};

double Clerk::GetTotalAccountsBalance(int customerId)
{
	unsigned int index;
	double sum = 0;
	vector<int> accounts = customersManagment.GetCustomer(customerId)->getAccounts();
	for(index=0; index < accounts.size(); index++)
		sum += accountsManagment.GetAccount(accounts[index])->GetBalance();

	return sum;	
};

Customer & Clerk::GetCustomer(int customerId)
{
	return *customersManagment.GetCustomer(customerId);		
};

void Clerk::RefillAtm()
{
	if (atm != NULL)
		atm->RefillAtm();
};

void Clerk::ConfirmAtmDeposits()
{
	atm->ConfirmDepositsOperations();
};

int Clerk::CreateAccount(ACCOUNT_TYPE type)
{
	Account *account;
	switch (type)
	{
	case Student_Account:
	{
							account = new StudentAccount();
							break;
	}
	case Private_Account:
	{
							account = new PrivateAccount();
							break;
	}
	case Business_Account:
	{
							 account = new BusinessAccount();
							 break;
	}
	default:
		throw new exception("Unkown account type");
		break;
	}

	accountsManagment.AddAccount(account);

	return account->GetInfo().accountId;
}

CustomerReport Clerk::GetCustomerReport(int customerId)
{
	vector<AccountInfo> accountsInfo;
	vector<int>::iterator iter , end;
	iter = customersManagment.GetCustomer(customerId)->getAccounts().begin();
	end = customersManagment.GetCustomer(customerId)->getAccounts().end();
	for (iter;iter != end; ++iter)
	{
		AccountInfo accountInfo = accountsManagment.GetAccount(*iter)->GetInfo();
		accountsInfo.push_back(accountInfo); 
	}
	PersonalInfo personalInfo = customersManagment.GetCustomer(customerId)->GetCopyOfInfo();
	return CustomerReport(personalInfo, accountsInfo,GetTotalAccountsBalance(customerId));	
};

DailyAtmActionsReport Clerk::GetDailyAtmActionsReport()
{
	return DailyAtmActionsReport(atm->GetDailyHistoryOperations());
};

