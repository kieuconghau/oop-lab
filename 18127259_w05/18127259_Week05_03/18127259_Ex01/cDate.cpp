#include "cDate.h"

cDate::cDate()
{
	this->Day = 1;
	this->Month = 1;
	this->Year = cDate::MIN_YEAR;
}

cDate::cDate(const cDate& date)
{
	*this = date;
}

cDate::cDate(int day, int month, int year)
{
	this->Day = day;
	this->Month = month;
	this->Year = year;
}

cDate::cDate(int month, int year)
{
	this->Day = 1;
	this->Month = month;
	this->Year = year;
}

cDate::cDate(int year)
{
	this->Day = 1;
	this->Month = 1;
	this->Year = year;
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
		cout << "    - Day: ";
		cin >> this->Day;
		cout << "    - Month: ";
		cin >> this->Month;
		cout << "    - Year: ";
		cin >> this->Year;
		cout << endl;
		if (this->isValid())
			break;
		else
			cout << "\aTHE DATE IS NOT VALID. Please input again!" << endl;
	}
}

string cDate::getFormat()
{
	return to_string(this->Day) + "/" + to_string(this->Month) + "/" + to_string(this->Year);
}
