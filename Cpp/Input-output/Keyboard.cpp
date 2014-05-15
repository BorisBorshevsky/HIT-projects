//Keyboard.cpp

#include "Keyboard.h"
#include <conio.h>

char Keyboard::GetChar() const //gets a char from the keyboard
{
	return (getch());
}

bool Keyboard::End_Of_Input(const char &a) const //returns true if the char is ~
{
	return (a == '~');
}