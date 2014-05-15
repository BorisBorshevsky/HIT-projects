#include "Account.h"
#include <algorithm>
#include "DepositOperation.h"
#include "WithrawOperation.h"

int Account::lastAccontId = 0;

Account::Account(double credit, double commition)
	:accountId(GenerateId())  , 
	creationDate(Date()) ,
	credit(credit) ,
	commition(commition)
{
	isActive = true;
	balance = 0;
};

vector<Operation *> Account::GetHistoryOperations() const
{
	return history;
};

vector<int> Account::GetOwners() const
{
	return owners;		
};

int Account::GenerateId()
{
	return ++lastAccontId;
};

double Account::GetBalance() const
{
	return balance;		
};


Result Account::Withraw(const double cash)
{
	Result res;
	if ((balance + credit) >= (cash + commition))
	{
		balance -= cash + commition;
		history.push_back(&DepositOperation(cash,accountId));
		res.isSuccess = true;
	}
	else
	{
		res.errorMessage = "No money";
		res.isSuccess = false;
	}
	return res;
};

Result Account::Deposit(const double cash)
{
	Result res;
	res.isSuccess = true;
	
	balance += cash - commition;
	
	history.push_back( &DepositOperation(cash,accountId) );

	return res;
};

AccountInfo Account::GetInfo() const
{
	AccountInfo info;

	info.accountId = accountId;
	info.balance = balance;
	info.creationDate = creationDate;
	info.credit = credit;
	info.isActive = isActive;
	//info.owners = owners;
	info.commition = commition;

	return info;
};

Date Account::GetCreationDate() const
{
	return creationDate;
};

void Account::Disable()
{
	isActive = false;
};

void Account::Enable()
{
	isActive = true;
};

void Account::AddOwner(int id)
{
	owners.push_back(id);
};
	
void Account::RemoveOwner(int id)
{
	vector<int>::iterator iter;
	for (iter = owners.begin();iter != owners.end();++iter)
	{
		if (*iter == id)
			owners.erase(iter);
	}
};

bool Account::IsOwnerExists(const int id) 
{
	vector<int>::iterator end = owners.end();
	vector<int>::iterator start = owners.begin();
	vector<int>::iterator found = find( start, end, id );
	
	return (found !=  end);
};
	








