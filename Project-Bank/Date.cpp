#include "Date.h"
#include "ctime"

Date::Date()
{
	time_t now = time(0); //now
	tm* parsedTime = localtime(&now);

	this->day = parsedTime->tm_mday;
	this->month = parsedTime->tm_mon;
	this->year = parsedTime->tm_year;
}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}