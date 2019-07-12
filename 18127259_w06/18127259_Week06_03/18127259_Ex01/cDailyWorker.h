#pragma once

#include "cEmployee.h"

class cDailyWorker : public cEmployee
{
public:
	cDailyWorker();
	cDailyWorker(const cDailyWorker& productionEmployee);
	cDailyWorker(string id, string fullName, string address, int day, int month, int year);
	cDailyWorker(string id, string fullName, string address);
	cDailyWorker(string id, string fullName);

	void input_info();
	void show_info();

	void input_day_quantity();
	float calc_salary();

private:
	static const float SALARY_UNIT;
	int DayQuantity;
};

