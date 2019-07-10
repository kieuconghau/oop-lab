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

	void input_info();
	void show_info();
	float calc_salary();

private:
	static const float DAY_OFF_PAY_RATE;

protected:
	string ID;
	string FullName;
	float PayRate;
	float BasicPay;
	int DayOff;
};
