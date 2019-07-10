#include "cEmployee.h"

cEmployee::cEmployee()
{
	this->ID = "N/A";
	this->FullName = "N/A";
	this->DoB = "N/A";
	this->Address = "N/A";
}

cEmployee::cEmployee(const cEmployee& employee)
{
	*this = employee;
}

cEmployee::cEmployee(string id, string fullName, string doB, string address, float salaryUnit, cSalary::ecCurrencyUnit currencyUnit) : Salary(salaryUnit, currencyUnit)
{
	this->ID = id;
	this->FullName = fullName;
	this->DoB = doB;
	this->Address = address;
}

cEmployee::cEmployee(string id, string fullName, string doB, float salaryUnit, cSalary::ecCurrencyUnit currencyUnit) : Salary(salaryUnit, currencyUnit)
{
	this->ID = id;
	this->FullName = fullName;
	this->DoB = doB;
	this->Address = "N/A";
}

cEmployee::cEmployee(string id, string fullName, float salaryUnit, cSalary::ecCurrencyUnit currencyUnit) : Salary(salaryUnit, currencyUnit)
{
	this->ID = id;
	this->FullName = fullName;
	this->DoB = "N/A";
	this->Address = "N/A";
}

cEmployee::~cEmployee() {}

void cEmployee::input_info()
{
	cout << "  * ID: ";
	getline(cin, this->ID);
	cout << "  * Full name: ";
	getline(cin, this->FullName);
	cout << "  * Date of birth: ";
	getline(cin, this->DoB);
	cout << "  * Address: ";
	getline(cin, this->Address);
}

void cEmployee::show_info()
{
	cout << "  * ID: " << this->ID << endl;
	cout << "  * Full name: " << this->FullName << endl;
	cout << "  * Date of birth: " << this->DoB << endl;
	cout << "  * Address: " << this->Address << endl;
}

void cEmployee::calc_salary(unsigned int quantity)
{
	this->Salary.calc_salary(quantity);
}
