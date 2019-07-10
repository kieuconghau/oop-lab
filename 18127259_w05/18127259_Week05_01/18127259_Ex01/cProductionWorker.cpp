#include "cProductionWorker.h"

float cProductionWorker::SALARY_UNIT = 20000;
cSalary::ecCurrencyUnit cProductionWorker::CURRENCY_UNIT = cSalary::ecCurrencyUnit::VND;

cProductionWorker::cProductionWorker()
{
	this->DayQuantity = 0;
}

cProductionWorker::cProductionWorker(const cProductionWorker& productionWoker)
{
	*this = productionWoker;
}

cProductionWorker::cProductionWorker(string id, string fullName, string doB, string address, unsigned int dayQuantity) : cEmployee(id, fullName, doB, address, cProductionWorker::SALARY_UNIT, cProductionWorker::CURRENCY_UNIT)
{
	this->DayQuantity = dayQuantity;
}

cProductionWorker::cProductionWorker(string id, string fullName, string doB, unsigned int dayQuantity) : cEmployee(id, fullName, doB, cProductionWorker::SALARY_UNIT, cProductionWorker::CURRENCY_UNIT)
{
	this->DayQuantity = dayQuantity;
}

cProductionWorker::cProductionWorker(string id, string fullName, unsigned int dayQuantity) : cEmployee(id, fullName, cProductionWorker::SALARY_UNIT, cProductionWorker::CURRENCY_UNIT)
{
	this->DayQuantity = dayQuantity;
}

cProductionWorker::~cProductionWorker() {}

void cProductionWorker::input_info()
{
	cout << "Input info for this production worker:" << endl;
	cEmployee::input_info();
}

void cProductionWorker::show_info()
{
	cout << "Information of this production woker:" << endl;
	cEmployee::show_info();
}

void cProductionWorker::calc_salary()
{
	cEmployee::calc_salary(this->DayQuantity);
}

