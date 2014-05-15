
#ifndef PERSONAL_INFO_H
#define PERSONAL_INFO_H

#include <string>
#include "Date.h"

using namespace std;

class PersonalInfo
{

public:
	PersonalInfo(Date&, int);
	PersonalInfo(const PersonalInfo &);

	void SetFirstName(string);
	string GetFirstName() const;

	void SetLastName(string);
	string GetLastName() const;

	int GetCustomerId() const;

	void SetPhoneNumber(string);
	string GetPhoneNumber() const;

	void SetAddress(string);
	string GetAddress() const;

	Date GetBirthDate() const;


private:
	string firstName;
	string lastName;
	
	const int customerId; //TEUDAT ZEHUT
	
	const Date birthDate;
	
	string address;
	
	string phoneNumber;
};



#endif