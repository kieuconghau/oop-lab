#pragma once

#include <iostream>
#include <string>
using namespace std;

#include "cSalary.h"

class cEmployee
{
public:
	cEmployee();
	cEmployee(const cEmployee& employee);
	cEmployee(string id, string fullName, string doB, string address, float salaryUnit, cSalary::ecCurrencyUnit currencyUnit);
	cEmployee(string id, string fullName, string doB, float salaryUnit, cSalary::ecCurrencyUnit currencyUnit);
	cEmployee(string id, string fullName, float salaryUnit, cSalary::ecCurrencyUnit currencyUnit);
	~cEmployee();
	void input_info();
	void show_info();
	void calc_salary(unsigned int quantity);
private:

protected:
	string ID;
	string FullName;
	string DoB;
	string Address;
	cSalary Salary;
};

