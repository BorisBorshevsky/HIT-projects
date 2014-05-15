//main.c
//test function for RationalNumber class
//BY Boris Borshevsky
//ID 311898746

#include <iostream>
#include "RationalNumber.h"
using namespace std;


int main()
{
	RationalNumber a,b;
	RationalNumber c(10,20);

	cout << "Enter Numerator and Denumerator for Num1:" << endl; 
	cin >> a;
	cout << "Enter Numerator and Denumerator for Num2:" << endl; 
	cin >> b;

	cout << "a     " << a << endl;
	cout << "b     " << b << endl;

	cout << "(a+b) " << (a+b) << endl;
	cout << "(a-b) " << (a-b) << endl;
	cout << "(a*b) " << (a*b) << endl;
	cout << "(a/b) " << (a/b) << endl;
	cout << "(a>b) " << (a>b) << endl;
	cout << "(a<b) " << (a<b) << endl;
	cout << "(-a)  "  << (-a) << endl;

	cout << c << endl;
	c.SetNumerator(4);
	cout << c << endl;
	c.SetDenumerator(6);
	cout << c << endl;
	c.SetDenumerator(0);
	cout << c << endl;

	flushall();
	getchar();
}