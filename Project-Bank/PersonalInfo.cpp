#include "PersonalInfo.h"

PersonalInfo::PersonalInfo(const PersonalInfo &personalInfo)
	:birthDate(personalInfo.birthDate),
	customerId(personalInfo.customerId)
{
	firstName =		personalInfo.firstName;
	lastName =		personalInfo.lastName;
	address =		personalInfo.address;
	phoneNumber =	personalInfo.phoneNumber;
};

PersonalInfo::PersonalInfo(Date& birthDate, int customerId)
	:birthDate(birthDate),
	customerId(customerId)
{ };

void PersonalInfo::SetFirstName(string firstName)
{
	this->firstName = firstName;

};
string PersonalInfo::GetFirstName() const
{
	return firstName;
};

void PersonalInfo::SetLastName(string lastName)
{
	this->lastName = lastName;
};

string PersonalInfo::GetLastName() const
{
	return lastName;
};

int PersonalInfo::GetCustomerId() const
{
	return customerId;
};

void PersonalInfo::SetPhoneNumber(string phoneNumber)
{
	this->phoneNumber = phoneNumber;
};
string PersonalInfo::GetPhoneNumber() const
{
	return phoneNumber;
};

void PersonalInfo::SetAddress(string address)
{
	this->address = address;
};
string PersonalInfo::GetAddress() const
{
	return this->address;
};

Date PersonalInfo::GetBirthDate() const
{
	return this->birthDate;
};