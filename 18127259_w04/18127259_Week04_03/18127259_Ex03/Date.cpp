#include "Date.h"

Date::Date()
{
	time_t now = time(0);
	tm* ltm = localtime(&now);

	this->Day = ltm->tm_mday;
	this->Month = ltm->tm_mon + 1;
	this->Year = ltm->tm_year + 1900;
}

Date::Date(const Date& date)
{
	this->Day = date.Day;
	this->Month = date.Month;
	this->Year = date.Year;
}

Date::Date(int year, int month, int day)
{
	this->Day = day;
	this->Month = month;
	this->Year = year;

	if (!this->isValid())
		throw;
}

Date::Date(int year, int month)
{
	this->Year = year;
	this->Month = month;
	this->Day = 1;

	if (!this->isValid())
		throw;
}

Date::Date(int year)
{
	this->Year = year;
	this->Month = 1;
	this->Day = 1;

	if (!this->isValid())
		throw;
}

bool Date::isValid()
{
	if (this->Year < MIN_YEAR)
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

Date Date::Tomorrow()
{
	Date tomorrow;

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

Date Date::Yesterday()
{
	Date yesterday;

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

int Date::getDayLimit_Month() const
{
	if (this->Month == 1 || this->Month == 3 || this->Month == 5 || this->Month == 7 || this->Month == 8 || this->Month == 10 || this->Month == 12)
		return 31;

	if (this->Month == 2)
		return this->Year % 400 == 0 || (this->Year % 4 == 0 && this->Year % 100 != 0) ? 29 : 28;

	return 30;
}

int Date::getDaysOfThisYear() const
{
	return this->Year % 400 == 0 || (this->Year % 4 == 0 && this->Year % 100 != 0) ? 366 : 365;
}

bool Date::operator==(const Date& date)
{
	return this->Year == date.Year && this->Month == date.Month && this->Day == date.Day;
}

bool Date::operator!=(const Date& date)
{
	return this->Year != date.Year || this->Month != date.Month || this->Day == date.Day;
}

bool Date::operator>=(const Date& date)
{
	if (this->Year < date.Year)
		return false;

	if (this->Year > date.Year)
		return true;

	if (this->Year == date.Year)
	{
		if (this->Month < date.Month)
			return false;
		if (this->Month > date.Month)
			return true;
		if (this->Month == date.Month)
			return this->Day >= date.Day;
	}
}

bool Date::operator<=(const Date& date)
{
	if (this->Year > date.Year)
		return false;

	if (this->Year < date.Year)
		return true;

	if (this->Year == date.Year)
	{
		if (this->Month > date.Month)
			return false;
		if (this->Month < date.Month)
			return true;
		if (this->Month == date.Month)
			return this->Day <= date.Day;
	}
}

bool Date::operator>(const Date& date)
{
	if (this->Year < date.Year)
		return false;

	if (this->Year > date.Year)
		return true;

	if (this->Year == date.Year)
	{
		if (this->Month < date.Month)
			return false;
		if (this->Month > date.Month)
			return true;
		if (this->Month == date.Month)
			return this->Day > date.Day;
	}
}

bool Date::operator<(const Date& date)
{
	if (this->Year > date.Year)
		return false;

	if (this->Year < date.Year)
		return true;

	if (this->Year == date.Year)
	{
		if (this->Month > date.Month)
			return false;
		if (this->Month < date.Month)
			return true;
		if (this->Month == date.Month)
			return this->Day < date.Day;
	}
}

istream& operator>>(istream& is, Date& date)
{
	while (true)
	{
		cout << "  * Input day: ";
		is >> date.Day;
		cout << "  * Input month: ";
		is >> date.Month;
		cout << "  * Input year: ";
		is >> date.Year;

		if (date.isValid())
			break;
		else
			cout << "\aInvalid date. Please input again." << endl;
	}

	return is;
}

ostream& operator<<(ostream& os, const Date& date)
{
	os << to_string(date.Day) + "/" + to_string(date.Month) + "/" + to_string(date.Year);

	return os;
}

Date::operator int() const
{
	int delta = 0;
	for (int month = 1; month < this->Month; month++) {
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			delta += 31;
		else if (month == 2) {
			if (this->Year % 400 == 0 || (this->Year % 4 == 0 && this->Year % 100 != 0))
				delta += 29;
			else
				delta += 28;
		}
		else
			delta += 30;
	}
	delta += this->Day;

	return delta;
}

Date::operator long() const
{
	Date date(1, 1, 1);
	return this->getDistance(date);
}

int Date::getDistance(const Date& date) const
{
	int res = 0;

	if (this->Year == date.Year) {
		res = abs((int)* this - (int)date);
	}
	else {
		Date min_date = this->Year < date.Year ? *this : date;
		Date max_date = this->Year > date.Year ? *this : date;

		res += min_date.getDaysOfThisYear() - (int)min_date;

		Date temp = min_date;
		temp.Year++;
		while (temp.Year < max_date.Year) {
			res += temp.getDaysOfThisYear();
			temp.Year++;
		}

		res += (int)max_date;
	}

	return res;
}

Date& Date::operator++()
{
	*this = this->Tomorrow();
	return *this;
}

Date Date::operator++(int)
{
	Date res = *this;
	*this = this->Tomorrow();
	return res;
}

Date& Date::operator--()
{
	*this = this->Yesterday();
	return *this;
}

Date Date::operator--(int)
{
	Date res(*this);
	*this = this->Yesterday();
	return res;
}

Date Date::operator+(const int d)
{
	Date temp(*this);

	if (d < 0)
		return temp - abs(d);

	int delta = (int)temp + d;
	while (delta > temp.getDaysOfThisYear())
	{
		delta -= temp.getDaysOfThisYear();
		temp.Year++;
	}

	temp.Month = 1;
	while (delta > temp.getDayLimit_Month())
	{
		delta -= temp.getDayLimit_Month();
		temp.Month++;
	}

	temp.Day = delta;

	return temp;
}

Date Date::operator-(const int d)
{
	Date temp(*this);

	if (d < 0)
		return temp + abs(d);

	int delta = temp.getDaysOfThisYear() - (int)temp + d;

	while (delta >= temp.getDaysOfThisYear())
	{
		delta -= temp.getDaysOfThisYear();
		temp.Year--;
	}

	delta = temp.getDaysOfThisYear() - delta;
	temp.Month = 1;
	while (delta > temp.getDayLimit_Month())
	{
		delta -= temp.getDayLimit_Month();
		temp.Month++;
	}

	temp.Day = delta;

	return temp;
}

Date& Date::operator+=(const int d)
{
	*this = *this + d;
	return *this;
}

Date& Date::operator-=(const int d)
{
	*this = *this - d;
	return *this;
}

Date& Date::operator=(const Date& date)
{
	this->Day = date.Day;
	this->Month = date.Month;
	this->Year = date.Year;

	return *this;
}
