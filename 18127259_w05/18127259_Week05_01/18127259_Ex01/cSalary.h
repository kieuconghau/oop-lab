#pragma once

class cSalary
{
public:
	enum class ecCurrencyUnit
	{
		VND,
		USD
	};
	cSalary();
	cSalary(float salaryUnit, cSalary::ecCurrencyUnit currencyUnit);
	~cSalary();
	void calc_salary(unsigned int quantity);

private:
	float SalaryUnit;
	cSalary::ecCurrencyUnit CurrencyUnit;
	float SalarySum;
};

