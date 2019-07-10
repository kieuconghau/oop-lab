#include "cProductionEmployee.h"

const float cProductionEmployee::SALARY_UNIT = 20000.f;

cProductionEmployee::cProductionEmployee() {}

cProductionEmployee::cProductionEmployee(const cProductionEmployee& productionEmployee)
	: cEmployee(productionEmployee) {}

cProductionEmployee::cProductionEmployee(string id, string fullName, string address, int day, int month, int year)
	: cEmployee(id, fullName, address, day, month, year) {}

cProductionEmployee::cProductionEmployee(string id, string fullName, string address)
	: cEmployee(id, fullName, address) {}

cProductionEmployee::cProductionEmployee(string id, string fullName)
	: cEmployee(id, fullName) {}

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

void cProductionEmployee::calc_salary()
{
	this->Salary = this->ProductQuantity * cProductionEmployee::SALARY_UNIT;
}
