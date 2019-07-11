#pragma once

#include "cDate.h"
#include <iostream>
using namespace std;

class cEmployee
{
public:
	cEmployee();
	cEmployee(const cEmployee& employee);
	cEmployee(string id, string fullName, string address, int day, int month, int year);
	cEmployee(string id, string fullName, string address);
	cEmployee(string id, string fullName);
	virtual ~cEmployee();

	virtual void input_info();
	virtual void show_info();
	virtual float calc_salary() = 0;
	
	bool has_id(string id);
	bool has_full_name(string fullName);
	bool has_birthday_in_month(int month);

private:

protected:
	string ID;
	string FullName;
	cDate DoB;
	string Address;
};
