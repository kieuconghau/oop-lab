#include "cProductionEmployee.h"

const float cProductionEmployee::SALARY_UNIT = 20000.f;

cProductionEmployee::cProductionEmployee()
{
	this->ProductQuantity = 0;
}

cProductionEmployee::cProductionEmployee(const cProductionEmployee& productionEmployee)
	: cEmployee(productionEmployee)
{
	this->ProductQuantity = 0;
}

cProductionEmployee::cProductionEmployee(string id, string fullName, string address, int day, int month, int year)
	: cEmployee(id, fullName, address, day, month, year)
{
	this->ProductQuantity = 0;
}

cProductionEmployee::cProductionEmployee(string id, string fullName, string address)
	: cEmployee(id, fullName, address)
{
	this->ProductQuantity = 0;
}

cProductionEmployee::cProductionEmployee(string id, string fullName)
	: cEmployee(id, fullName)
{
	this->ProductQuantity = 0;
}

void cProductionEmployee::input_info()
{
	cout << "~Production Employee~" << endl;
	cEmployee::input_info();
}

void cProductionEmployee::show_info()
{
	cout << "~Production Employee~" << endl;
	cEmployee::show_info();
}

void cProductionEmployee::input_product_quantity()
{
	cout << "Input product quantity of this employee: ";
	cin >> this->ProductQuantity;
}

float cProductionEmployee::calc_salary()
{
	return this->ProductQuantity * cProductionEmployee::SALARY_UNIT;
}
