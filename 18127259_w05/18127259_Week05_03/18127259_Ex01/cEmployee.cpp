#include "cEmployee.h"

cEmployee::cEmployee()
{
	this->ID = "N/A";
	this->FullName = "N/A";
	this->Address = "N/A";
	this->Salary = 0.f;
}

cEmployee::cEmployee(const cEmployee& employee)
{
	*this = employee;
}

cEmployee::cEmployee(string id, string fullName, string address, int day, int month, int year) : DoB(day, month, year)
{
	this->ID = id;
	this->FullName = fullName;
	this->Address = address;
	this->Salary = 0.f;
}

cEmployee::cEmployee(string id, string fullName, string address)
{
	this->ID = id;
	this->FullName = fullName;
	this->Address = address;
	this->Salary = 0.f;
}

cEmployee::cEmployee(string id, string fullName)
{
	this->ID = id;
	this->FullName = fullName;
	this->Address = "N/A";
	this->Salary = 0.f;
}

void cEmployee::input_info()
{
	cout << "Input info: " << endl;
	cout << "  * ID            :";
	getline(cin, this->ID);
	cout << "  * Full Name     :";
	getline(cin, this->FullName);
	cout << "  * Date of Birth :";
	this->DoB.input();
	cout << "  * Address       :";
	getline(cin, this->Address);
}

void cEmployee::show_info()
{
	cout << "  * ID            : " << this->ID << endl;
	cout << "  * Full Name     : " << this->FullName << endl;
	cout << "  * Date of Birth : " << this->DoB.getFormat() << endl;
	cout << "  * Address       : " << this->ID << endl;
}
