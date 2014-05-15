//RationalNumber.cpp
//cpp file for RationalNumber Class
//BY Boris Borshevsky
//ID 311898746


#include <iostream>
#include "RationalNumber.h"
using namespace std;

//************
//constructors
//************
//default constructor - sets 1
RationalNumber::RationalNumber()		
{
	numerator = 1;
	denominator = 1;
};
//************************************************
//Basic constructor - sets ,num ,denum, reduces. 
//************************************************
RationalNumber::RationalNumber(int numerator,int denominator)		
{
	this->numerator = numerator;
	this->denominator = denominator;
	Reduction();
};
//copy constructor
RationalNumber::RationalNumber(const RationalNumber & other )		
{
	this->numerator = other.numerator;
	this->denominator = other.denominator;
};


//Distructor
RationalNumber::~RationalNumber()		//destructor
{ }
//*****************
//onar operations
//*****************
RationalNumber RationalNumber::operator-() 			// - onar
{
	return RationalNumber (numerator * (-1), denominator);
};


//***************************************************************
//Binary oprations - all operation use reduction in the end
//***************************************************************
RationalNumber  RationalNumber::operator+(const RationalNumber& other)  //add oper
{
	return RationalNumber (numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
};
RationalNumber RationalNumber::operator-(const RationalNumber& other)  //sub oper
{
	return RationalNumber (numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
};
RationalNumber RationalNumber::operator*(const RationalNumber& other)  //multi oper
{
	return RationalNumber (numerator * other.numerator , denominator * other.denominator);
};
RationalNumber RationalNumber::operator/(const RationalNumber& other)  //devide oper
{
	return RationalNumber ( numerator * other.denominator, denominator * other.numerator);
};


//*****************************************************************************************
//Compare oprations - return true \ false values for comprisons between rational numbers
//****************************************************************************************
bool RationalNumber::operator<(const RationalNumber& other) 
{
	return (numerator * other.denominator < other.numerator * denominator);
};
bool RationalNumber::operator>(const RationalNumber& other) 
{
	return (numerator * other.denominator > other.numerator * denominator);
};

//*******************************
// Getters - returns the values
//*******************************
int RationalNumber::GetDenumerator() const
{
	return this->denominator;
};
int RationalNumber::GetNumerator() const		
{
	return this->numerator;
};

//************************************************
// Setters - all sertters do reduction in the end
//************************************************
void RationalNumber::SetDenumerator(int newDenum)
{
	denominator = newDenum;
	Reduction();	
};
void RationalNumber::SetNumerator(int newNum)
{
	numerator = newNum;
	Reduction();
};

//GCD function - returns greatest common delimitor
int RationalNumber::Gcd(int num1, int num2) const	
{													
	num1=abs(num1);
	num2=abs(num2);
	int mod;										 	
	while (num2 != 0) {								
		mod = num1 % num2;						  	
		num1 = num2;									
		num2 = mod;
	}                      							
	return num1;										
};

//help function for display
void RationalNumber::Display() const
{
	cout << numerator << "/" << denominator << " " ; 
}


//Reduction 
//Reduces the fruction, sets 1/1 if the denumerator is 0
//using gcd function
void RationalNumber::Reduction()
{
	if (denominator == 0) 
	{
		this->numerator = 1;
		this->denominator = 1;
	}
	else
	{
		int gcd = Gcd(numerator,denominator);
		if (denominator < 0)	//used to keep the denominator positive 
			gcd=gcd * (-1);	
		this->numerator = numerator/gcd;
		this->denominator = denominator/gcd;
	}
};
//osterm function for Rational Number
//displays numerator/denumerator on the screen
ostream& operator<<(ostream& out, const RationalNumber& other)
{
	out << other.numerator << '/' << other.denominator;
	return out;
};
//istream function
//sets first entered value at numerator, second in denumerator, reduction in the end
istream &operator>>( istream & in, RationalNumber & other )
{ 
	in >> other.numerator >> other.denominator;
	other.Reduction();
	return in;            
};