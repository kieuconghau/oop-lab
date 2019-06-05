#include "cDate.h"

cDate::cDate()
{
	this->Day = 1;
	this->Month = 1;
	this->Year = MIN_YEAR;
}

cDate::cDate(const cDate& date)
{
	this->Day = date.Day;
	this->Month = date.Month;
	this->Year = date.Year;
}

cDate::cDate(int day, int month, int year)
{
	this->Day = day;
	this->Month = month;
	this->Year = year;

	if (!this->isValid())
		throw;
}

cDate::~cDate()
{
}

bool cDate::isValid()
{
	if (this->Year < MIN_YEAR || this->Year > MAX_YEAR)
		return false;

	if (this->Day < 1)
		return false;

	if (this->Month < 1 || this->Month > 12)
		return false;
	else if (this->Month == 2)
		return this->Year % 400 == 0 || (this->Year % 4 == 0 && this->Year % 100 != 0) ? this->Day <= 29 : this->Day <= 28;
	else if (this->Month == 1 || this->Month == 3 || this->Month == 5 || this->Month == 7 || this->Month == 8 || this->Month == 10 || this->Month == 12)
		return this->Day <= 31;
	else
		return this->Day <= 30;
}

void cDate::input()
{
	while (true) {
		cout << "  * Day: ";
		cin >> this->Day;
		cout << "  * Month: ";
		cin >> this->Month;
		cout << "  * Year: ";
		cin >> this->Year;
		cout << endl;
		if (this->isValid())
			break;
		else
			cout << "\aTHE DATE IS NOT VALID. Please input again!" << endl;
	}
}

cDate cDate::getTomorrow()
{
	cDate tomorrow;

	if (this->Day == this->getDayLimit_Month())
	{
		tomorrow.Day = 1;
		tomorrow.Month = this->Month % 12 + 1;
		tomorrow.Year = this->Year + this->Month / 12;
	}
	else
	{
		tomorrow.Day = this->Day + 1;
		tomorrow.Month = this->Month;
		tomorrow.Year = this->Year;
	}

	return tomorrow;
}

cDate cDate::getYesterday()
{
	cDate yesterday;

	if (this->Day == 1)
	{
		yesterday.Month = (this->Month == 1) ? 12 : this->Month - 1;
		yesterday.Year = (this->Month == 1) ? this->Year - 1 : this->Year;
		yesterday.Day = yesterday.getDayLimit_Month();
	}
	else
	{
		yesterday.Day = this->Day - 1;
		yesterday.Month = this->Month;
		yesterday.Year = this->Year;
	}

	return yesterday;
}

string cDate::getFormat() const
{
	return to_string(this->Day) + "/" + to_string(this->Month) + "/" + to_string(this->Year);
}

int cDate::getDayLimit_Month() const
{
	if (this->Month == 1 || this->Month == 3 || this->Month == 5 || this->Month == 7 || this->Month == 8 || this->Month == 10 || this->Month == 12)
		return 31;
	
	if (this->Month == 2)
		return this->Year % 400 == 0 || (this->Year % 4 == 0 && this->Year % 100 != 0) ? 29 : 28;

	return 30;
}