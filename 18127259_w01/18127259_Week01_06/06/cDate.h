#ifndef _date_h_
#define _date_h_

#pragma warning(disable:4996)

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

#define MAX_YEAR 9999
#define MIN_YEAR 1900

class cDate
{
private:
	int Day;
	int Month;
	int Year;
	string Format;

public:
	cDate();
	~cDate();

	void input();
	void getCurrentDate();

	bool isValid() const;
	int getDelta() const;						// The distance from 1/1/yyyy to dd/mm/yyyy
	int getDistnace(const cDate& date) const;
	int getDaysOfThisYear() const;				// return 365 or 366

	int& getDay();
	int& getMonth();
	int& getYear();
	string& getFormat();
};

#endif