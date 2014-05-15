/*
Acccount.h
class to host accounts in the bank
*/

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>
#include <vector>
#include "AccountInfo.h"
#include "BankTypes.h"
#include "Operation.h"
#include "Date.h"

using namespace std;

class Account //abstruct
{
public:
	Account(double credit, double commition); //constructor

	Result Deposit(const double cash);			//deposit Cash to Account (with commition)
	Result Withraw(const double cash);			//Withrow Cash to Account (with commition)
	
	AccountInfo GetInfo() const;			//returns copy of account info

	void AddOwner(int id);					//add owner to the account (Murshe Hatima)
	void RemoveOwner(int id);				//Removes owner from the account (Murshe Hatima)
	vector<int> GetOwners() const;				//returns a list of account owners

	Date GetCreationDate() const;			//returns account creation time
	
	void Disable();							//disables account
	void Enable();							//enables the account
	
	double GetBalance() const;					//returns account current balance

	virtual ACCOUNT_TYPE GetType() const = 0;
	
	vector<Operation *> GetHistoryOperations() const; //returns history of operations

private:
	
	vector<Operation *> history;					//list of transactions
	
	const int accountId;					//accountID
	const Date creationDate;				//Creation Date

	const double credit;					// misgeret ashrai
	const double commition;					// Amla

	vector<int> owners;						//list of owners

	bool IsOwnerExists(const int id) ;		//check if owner exists for specific account

	double balance;							//starts with 0
	bool isActive;							//starts with true
	
	static int GenerateId();				//function to generate account ID
	static int lastAccontId;				//last "running" account ID

};

#endif


