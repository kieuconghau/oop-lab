#include "cEmployee.h"

cEmployee::cEmployee(cEmployee::ecType type)
{
	this->ID = "N/A";
	this->FullName = "N/A";
	this->Address = "N/A";
	this->Type = type;
}

cEmployee::cEmployee(const cEmployee& employee)
{
	*this = employee;
}

cEmployee::cEmployee(string id, string fullName, string address, int day, int month, int year, cEmployee::ecType type) : DoB(day, month, year)
{
	this->ID = id;
	this->FullName = fullName;
	this->Address = address;
	this->Type = type;
}

cEmployee::cEmployee(string id, string fullName, string address, cEmployee::ecType type)
{
	this->ID = id;
	this->FullName = fullName;
	this->Address = address;
	this->Type = type;
}

cEmployee::cEmployee(string id, string fullName, cEmployee::ecType type)
{
	this->ID = id;
	this->FullName = fullName;
	this->Address = "N/A";
	this->Type = type;
}

cEmployee::~cEmployee() {}

void cEmployee::input_info()
{
	cout << "Input basic info: " << endl;
	cout << "  * ID            : ";
	getline(cin, this->ID);
	cout << "  * Full Name     : ";
	getline(cin, this->FullName);
	cout << "  * Date of Birth : " << endl;
	this->DoB.input();
	cout << "  * Address       : ";
	getline(cin, this->Address);
}

void cEmployee::show_info()
{
	cout << "Basic info:" << endl;
	cout << "  * ID            : " << this->ID << endl;
	cout << "  * Full Name     : " << this->FullName << endl;
	cout << "  * Date of Birth : " << this->DoB.getFormat() << endl;
	cout << "  * Address       : " << this->ID << endl;
}

bool cEmployee::has_id(string id)
{
	return this->ID == id;
}

bool cEmployee::has_full_name(string fullName)
{
	return this->FullName == fullName;
}

bool cEmployee::has_birthday_in_month(int month)
{
	return this->DoB.is_in_month(month);
}

bool cEmployee::has_type(cEmployee::ecType type)
{
	return this->Type == type;
}
