#include "cTeacher.h"

const float cTeacher::DAY_OFF_PAY_RATE = 100000;

cTeacher::cTeacher()
{
	this->ID = "N/A";
	this->FullName = "N/A";
	this->PayRate = 0.f;
	this->BasicPay = 0.f;
	this->DayOff = 0;
}

cTeacher::cTeacher(const cTeacher& teacher)
{
	*this = teacher;
}

cTeacher::cTeacher(string id, string fullName, float payRate, float basicPay)
{
	this->ID = id;
	this->FullName = fullName;
	this->PayRate = payRate;
	this->BasicPay = basicPay;
	this->DayOff = 0;
}

cTeacher::cTeacher(string id, float payRate, float basicPay)
{
	this->ID = id;
	this->FullName = "N/A";
	this->PayRate = payRate;
	this->BasicPay = basicPay;
	this->DayOff = 0;
}

cTeacher::cTeacher(float payRate, float basicPay)
{
	this->ID = "N/A";
	this->FullName = "N/A";
	this->PayRate = payRate;
	this->BasicPay = basicPay;
	this->DayOff = 0;
}

void cTeacher::input_info()
{
	cout << "Input basic info:" << endl;
	cout << "  * ID        : ";
	getline(cin, this->ID);
	cout << "  * Full Name : ";
	getline(cin, this->FullName);
	cout << "  * Pay Rate  : ";
	cin >> this->PayRate;
	cout << "  * Basic Pay : ";
	cin >> this->BasicPay;
	cout << "  * Day-offs  : ";
	cin >> this->DayOff;
}

void cTeacher::show_info()
{
	cout << "Basic info:" << endl;
	cout << "  * ID        : " << this->ID << endl;
	cout << "  * Full Name : " << this->FullName << endl;
	cout << "  * Pay Rate  : " << this->PayRate << endl;
	cout << "  * Basic Pay : " << this->BasicPay << endl;
	cout << "  * Day-offs  : " << this->DayOff << endl;
}

float cTeacher::calc_salary()
{
	return this->PayRate * this->BasicPay - this->DayOff * cTeacher::DAY_OFF_PAY_RATE;
}

bool cTeacher::has_id(string id)
{
	return this->ID == id;
}

bool cTeacher::has_full_name(string fullName)
{
	return this->FullName == fullName;
}

bool cTeacher::has_dayoffs_more_than(int dayQuantity)
{
	return this->DayOff > dayQuantity;
}
