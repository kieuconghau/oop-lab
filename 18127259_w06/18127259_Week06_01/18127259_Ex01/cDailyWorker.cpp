#include "cDailyWorker.h"

const float cDailyWorker::SALARY_UNIT = 300000;

cDailyWorker::cDailyWorker() : cEmployee(cEmployee::ecType::DAILY_WORKER)
{
	this->DayQuantity = 0;
}

cDailyWorker::cDailyWorker(const cDailyWorker& productionEmployee)
	: cEmployee(productionEmployee)
{
	this->DayQuantity = 0;
}

cDailyWorker::cDailyWorker(string id, string fullName, string address, int day, int month, int year)
	: cEmployee(id, fullName, address, day, month, year, cEmployee::ecType::DAILY_WORKER)
{
	this->DayQuantity = 0;
}

cDailyWorker::cDailyWorker(string id, string fullName, string address)
	: cEmployee(id, fullName, address, cEmployee::ecType::DAILY_WORKER)
{
	this->DayQuantity = 0;
}

cDailyWorker::cDailyWorker(string id, string fullName)
	: cEmployee(id, fullName, cEmployee::ecType::DAILY_WORKER)
{
	this->DayQuantity = 0;
}

void cDailyWorker::input_info()
{
	cout << "~Daily Worker~" << endl;
	cEmployee::input_info();
}

void cDailyWorker::show_info()
{
	cout << "~Daily Worker~" << endl;
	cEmployee::show_info();
}

void cDailyWorker::input_day_quantity()
{
	cout << "Input day quantity of this employee: ";
	cin >> this->DayQuantity;
}

float cDailyWorker::calc_salary()
{
	return this->DayQuantity * cDailyWorker::SALARY_UNIT;
}
