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

	void input_info();
	void show_info();

private:

protected:
	string ID;
	string FullName;
	cDate DoB;
	string Address;
	float Salary;
};

