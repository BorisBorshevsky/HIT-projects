//main.cpp
//Input Output - Program 3
//By Boris Borshevsky
//ID: 311898746

#include <iostream>

#include "Input_Device.h"
#include "Output_Device.h"
#include "Keyboard.h"
#include "Screen.h"


//Copy function
//input: input device reference, output device reference
//output: none
//display: all chars from input device printed to screen with < >
void Copy(const Input_Device *in, const Output_Device *out) 
{
	char a = in->GetChar();
	while (!(in->End_Of_Input(a)))
	{
		out->Put_Char(a);
		a = in->GetChar();
	}
};


int main()
{
	Keyboard key;
	Screen scr;

	std::cout << "Type anything until '~' :" << std::endl;

	Copy(&key,&scr);

	return 0;
}