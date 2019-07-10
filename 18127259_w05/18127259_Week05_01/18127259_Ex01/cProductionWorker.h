#pragma once

#include "cEmployee.h"
#include "cSalary.h"

class cProductionWorker : public cEmployee
{
public:
	cProductionWorker();
	cProductionWorker(const cProductionWorker& productionWoker);
	cProductionWorker(string id, string fullName, string doB, string address, unsigned int dayQuantity=0);
	cProductionWorker(string id, string fullName, string doB, unsigned int dayQuantity=0);
	cProductionWorker(string id, string fullName, unsigned int dayQuantity=0);
	~cProductionWorker();
	void input_info();
	void show_info();
	void calc_salary();
private:
	static float SALARY_UNIT;
	static cSalary::ecCurrencyUnit CURRENCY_UNIT;
	unsigned int DayQuantity;
};