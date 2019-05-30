#ifndef cdate_h_ex04
#define cdate_h_ex04

#include <iostream>
#include <string>
using namespace std;

#define MIN_YEAR 1700
#define MAX_YEAR 9998

class cDate
{
private:
	int Day;
	int Month;
	int Year;

public:
	bool isValid();
	void input();

	cDate getTomorrow();
	cDate getYesterday();
	string getFormat() const;
	
	int getDayLimit_Month() const;
};

#endif