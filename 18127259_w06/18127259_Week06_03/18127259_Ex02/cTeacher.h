#pragma once

#include <iostream>
#include <string>
using namespace std;

class cTeacher
{
public:
	enum class ecType
	{
		NORMAL_TEACHER,
		FORM_TEACHER
	};

	cTeacher(cTeacher::ecType type=cTeacher::ecType::NORMAL_TEACHER);
	cTeacher(const cTeacher& teacher);
	cTeacher(string id, string fullName, float payRate, float basicPay, cTeacher::ecType type = cTeacher::ecType::NORMAL_TEACHER);
	cTeacher(string id, float payRate, float basicPay, cTeacher::ecType type = cTeacher::ecType::NORMAL_TEACHER);
	cTeacher(float payRate, float basicPay, cTeacher::ecType type = cTeacher::ecType::NORMAL_TEACHER);

	virtual void input_info();
	virtual void show_info();
	virtual float calc_salary();

	bool has_id(string id);
	bool has_full_name(string fullName);
	bool has_dayoffs_more_than(int dayQuantity);
	bool has_type(cTeacher::ecType type);

private:
	static const float DAY_OFF_PAY_RATE;
	cTeacher::ecType Type;

protected:
	string ID;
	string FullName;
	float PayRate;
	float BasicPay;
	int DayOff;
};
