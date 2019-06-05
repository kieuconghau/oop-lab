#include "cDate.h"

cDate::cDate()
{
	this->Day = "01";
	this->Month = "01";
	this->Year = "1700";
	this->Format = this->Day + "/" + this->Month + "/" + this->Year;
}

cDate::cDate(const cDate& date)
{
	this->Day = date.Day;
	this->Month = date.Month;
	this->Year = date.Year;
	this->Format = date.Format;
}

cDate::cDate(string day, string month, string year)
{
	this->Day = day;
	this->Month = month;
	this->Year = year;
	this->Format = this->Day + "/" + this->Month + "/" + this->Year;

	if (!this->isValid())
		throw;
}

cDate::~cDate()
{
}

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

bool cDate::isValid()
{
	int year = stoi(this->Year);
	int month = stoi(this->Month);
	int day = stoi(this->Day);

	if (year < MIN_YEAR || year > MAX_YEAR)
		return false;

	if (day < 1)
		return false;

	if (month < 1 || month > 12)
		return false;
	else if (month == 2)
		return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0) ? day <= 29 : day <= 28;
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return day <= 31;
	else
		return day <= 30;
}