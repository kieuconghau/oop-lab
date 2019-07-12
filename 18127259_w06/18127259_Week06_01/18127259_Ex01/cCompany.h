#pragma once

#include "cDailyWorker.h"
#include "cProductionEmployee.h"
#include <iostream>
#include <vector>
using namespace std;

class cCompany
{
public:
	cCompany();
	~cCompany();

	void input();
	void show();
	float calc_sum_salary();
	vector<cEmployee*> find_employees_having_the_highest_salary();
	int count_production_employees();
	int count_daily_workers();
	float calc_average_salary();
	vector<cEmployee*> find_all_employees_having_salary_less_than(float salary = 3000000);
	cEmployee* find_an_employee_with_id();
	vector<cEmployee*> find_all_employees_with_full_name();
	int count_all_employees_having_birthday_in_month(int month = 5);

private:
	vector<cEmployee*> Employees;
};