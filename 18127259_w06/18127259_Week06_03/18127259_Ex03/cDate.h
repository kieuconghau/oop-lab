#pragma once

#include <iostream>
#include <string>
using namespace std;

class cDate
{
public:
	cDate();
	cDate(const cDate& date);
	cDate(int day, int month, int year);
	cDate(int month, int year);
	cDate(int year);

	bool isValid();
	void input();
	string getFormat();

	bool is_in_year(int year);

private:
	int Day;
	int Month;
	int Year;

	static const int MIN_YEAR = 1700;
	static const int MAX_YEAR = 9999;
};

