#pragma once

#include "cEmployee.h"

class cProductionEmployee : public cEmployee
{
public:
	cProductionEmployee();
	cProductionEmployee(const cProductionEmployee& productionEmployee);
	cProductionEmployee(string id, string fullName, string address, int day, int month, int year);
	cProductionEmployee(string id, string fullName, string address);
	cProductionEmployee(string id, string fullName);

	void input_info();
	void show_info();

	void input_product_quantity();
	void calc_salary();

private:
	static const float SALARY_UNIT;
	int ProductQuantity;
};

