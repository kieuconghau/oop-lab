#include "cDate.h"

cDate::cDate()
{
	this->Year = 0;
	this->Month = 0;
	this->Day = 0;
	this->Format = "N/A";
}

cDate::~cDate()
{
}

void cDate::input()
{
	while (true) {
		cout << "Input a date: " << endl;
		cout << "  * Year: ";
		cin >> this->Year;
		cout << "  * Month: ";
		cin >> this->Month;
		cout << "  * Day: ";
		cin >> this->Day;
		cout << endl;
		if (this->isValid())
			break;
		else
			cout << "\aTHE DATE IS NOT VALID. Please input again!" << endl;
	}
}

void cDate::getCurrentDate()
{
	time_t now = time(0);
	tm* ltm = localtime(&now);

	this->Year = MIN_YEAR + ltm->tm_year;
	this->Month = 1 + ltm->tm_mon;
	this->Day = ltm->tm_mday;
}

bool cDate::isValid() const
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

int cDate::getDelta() const
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

int cDate::getDistnace(const cDate& date) const
{
	int res = 0;

	if (this->Year == date.Year) {
		res = abs(this->getDelta() - date.getDelta());
	}
	else {
		cDate min_date = this->Year < date.Year ? *this : date;
		cDate max_date = this->Year > date.Year ? *this : date;

		res += min_date.getDaysOfThisYear() - min_date.getDelta();
		
		cDate temp = min_date;
		temp.getYear()++;
		while (temp.Year < max_date.Year) {
			res += temp.getDaysOfThisYear();
			temp.getYear()++;
		}

		res += max_date.getDelta();
	}

	return res;
}

int cDate::getDaysOfThisYear() const
{
	return this->Year % 400 == 0 || (this->Year % 4 == 0 && this->Year % 100 != 0) ? 366 : 365;
}

int& cDate::getDay()
{
	return this->Day;
}

int& cDate::getMonth()
{
	return this->Month;
}

int& cDate::getYear()
{
	return this->Year;
}

string& cDate::getFormat()
{
	this->Format = to_string(this->Day) + "/" + to_string(this->Month) + "/" + to_string(this->Year);

	return this->Format;
}