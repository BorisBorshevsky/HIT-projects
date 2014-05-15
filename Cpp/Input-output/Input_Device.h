//Input_Device.h
//Input_device Header File

#ifndef INPUT_H
#define INPUT_H

class  Input_Device		//default constructor/destructor
{
public:
	virtual char GetChar() const = 0;						//pure virtual
	virtual bool End_Of_Input(const char &a) const = 0;		//pure virtual
};

#endif INPUT_H

