//Keyboard.h 
//Keyboard Header File

#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "Input_Device.h"

class Keyboard : public Input_Device
{
public:
	virtual char GetChar() const;					//gets one char from keyborad
	virtual bool End_Of_Input(const char &a) const;	//returns true if the char is ~
};

#endif KEYBOARD_H