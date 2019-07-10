#pragma once

#include "cTeacher.h"

class cFormTeacher : public cTeacher
{
public:
	cFormTeacher();
	cFormTeacher(const cFormTeacher& formTeacher);
	cFormTeacher(string className, string id, string fullName, float payRate, float basicPay);
	cFormTeacher(string className, string id, float payRate, float basicPay);
	cFormTeacher(string className, float payRate, float basicPay);

	void input_info();
	void show_info();
	float calc_salary();

private:
	static const float FRINGE_BENEFITS;
	string ClassName;
};