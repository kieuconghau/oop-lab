#pragma once

#include <iostream>
#include <string>
using namespace std;

class cTeacher
{
public:
	cTeacher();
	cTeacher(const cTeacher& teacher);
	cTeacher(string id, string fullName, float payRate, float basicPay);
	cTeacher(string id, float payRate, float basicPay);
	cTeacher(float payRate, float basicPay);

	virtual void input_info();
	virtual void show_info();
	virtual float calc_salary();

	bool has_id(string id);
	bool has_full_name(string fullName);
	bool has_dayoffs_more_than(int dayQuantity);

private:
	static const float DAY_OFF_PAY_RATE;

protected:
	string ID;
	string FullName;
	float PayRate;
	float BasicPay;
	int DayOff;
};
