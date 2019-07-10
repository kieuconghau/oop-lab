#include "cDailyWorker.h"

const float cDailyWorker::SALARY_UNIT = 20000.f;

cDailyWorker::cDailyWorker() {}

cDailyWorker::cDailyWorker(const cDailyWorker& productionEmployee)
	: cEmployee(productionEmployee) {}

cDailyWorker::cDailyWorker(string id, string fullName, string address, int day, int month, int year)
	: cEmployee(id, fullName, address, day, month, year) {}

cDailyWorker::cDailyWorker(string id, string fullName, string address)
	: cEmployee(id, fullName, address) {}

cDailyWorker::cDailyWorker(string id, string fullName)
	: cEmployee(id, fullName) {}

void cDailyWorker::input_info()
{
	cout << "~Production Employee~" << endl;
	cEmployee::input_info();
}

void cDailyWorker::show_info()
{
	cout << "~Daily Worker~" << endl;
	cEmployee::show_info();
}

void cDailyWorker::input_product_quantity()
{
	cout << "Input day quantity of this employee: ";
	cin >> this->DayQuantity;
}

void cDailyWorker::calc_salary()
{
	this->Salary = this->DayQuantity * cDailyWorker::SALARY_UNIT;
}
