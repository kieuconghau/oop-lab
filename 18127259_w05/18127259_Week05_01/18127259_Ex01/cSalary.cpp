#include "cSalary.h"

cSalary::cSalary()
{
	this->SalaryUnit = 1;
	this->CurrencyUnit = cSalary::ecCurrencyUnit::VND;
	this->SalarySum = 0.0;
}

cSalary::cSalary(float salaryUnit, cSalary::ecCurrencyUnit currencyUnit)
{
	this->SalaryUnit = salaryUnit;
	this->CurrencyUnit = currencyUnit;
	this->SalarySum = 0.0;
}

cSalary::~cSalary() {}

void cSalary::calc_salary(unsigned int quantity)
{
	this->SalarySum = quantity * this->SalaryUnit;
}
