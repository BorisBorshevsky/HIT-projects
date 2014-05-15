//Screen.h
//Header File for Screen Class

#ifndef SCREEN_H
#define SCREEN_H

#include "Output_Device.h"

class Screen : public Output_Device
{
public:
	void Put_Char(const char) const;		//puts the char on the screen like this <CHAR>
};

#endif SCREEN_H