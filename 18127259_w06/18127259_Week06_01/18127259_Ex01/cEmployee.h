#pragma once

#include "cDate.h"
#include <iostream>
using namespace std;

class cEmployee
{
public:
	enum class ecType
	{
		PRODUCTION_EMPLOYEE,
		DAILY_WORKER
	};

	cEmployee(cEmployee::ecType type);
	cEmployee(const cEmployee& employee);
	cEmployee(string id, string fullName, string address, int day, int month, int year, cEmployee::ecType type);
	cEmployee(string id, string fullName, string address, cEmployee::ecType type);
	cEmployee(string id, string fullName, cEmployee::ecType type);
	virtual ~cEmployee();
	
	virtual void input_info();
	virtual void show_info();
	virtual float calc_salary() = 0;
	
	bool has_id(string id);
	bool has_full_name(string fullName);
	bool has_birthday_in_month(int month);
	bool has_type(cEmployee::ecType type);

private:
	cEmployee::ecType Type;

protected:
	string ID;
	string FullName;
	cDate DoB;
	string Address;
};
