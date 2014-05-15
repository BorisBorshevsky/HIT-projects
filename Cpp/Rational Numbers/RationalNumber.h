//RationalNumber.h
//cpp file for RationalNumber Class
//BY Boris Borshevsky
//ID 311898746

#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <iostream>
using namespace std;


class RationalNumber 
{

public:
	//IOSTREAM Friend
	friend ostream& operator<<(ostream& out, const RationalNumber & other);
	friend istream& operator>>(istream& in , RationalNumber & other);

	//constructors
	RationalNumber();
	RationalNumber(int numerator,int denominator);
	RationalNumber(const RationalNumber & other);

	//destructor
	~RationalNumber();

	//onar operations
	RationalNumber operator-();

	//banary operations
	RationalNumber operator+(const RationalNumber& other);
	RationalNumber operator-(const RationalNumber& other);
	RationalNumber operator*(const RationalNumber& other);
	RationalNumber operator/(const RationalNumber& other);

	//Binary bool compare operations
	bool operator<(const RationalNumber& other);
	bool operator>(const RationalNumber& other);

	//getters
	int GetNumerator() const;
	int GetDenumerator() const;

	//Setters
	void SetDenumerator(int newDenum);
	void SetNumerator(int newNum);

	//display functions - not needed
	void Display() const;

private:
	// GCD function.
	int Gcd(int a, int b) const;

	//Reduction of fruction function
	void Reduction();

	int numerator;  //MONE
	int denominator;  //MEHANE
};


#endif RATIONALNUMBER_H
