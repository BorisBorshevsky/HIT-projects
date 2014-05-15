//Output_Device.h
//Output_Device Header File

#ifndef OUTPUT_H
#define OUTPUT_H

class Output_Device
{
public:
	virtual void Put_Char(const char) const = 0;		//pure virtual
};

#endif OUTPUT_H
