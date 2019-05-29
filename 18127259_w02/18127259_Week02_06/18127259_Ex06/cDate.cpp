#include "cDate.h"

void cDate::setDate(const string date)
{
	this->Format = date;
}

void cDate::init()
{
	this->Day = this->Format.substr(0, 2);
	this->Month = this->Format.substr(3, 2);
	this->Year = this->Format.substr(6, 4);
}

string cDate::getFormat() const
{
	return this->Format;
}
