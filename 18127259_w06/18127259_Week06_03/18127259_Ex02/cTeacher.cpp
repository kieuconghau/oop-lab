#include "cTeacher.h"

const float cTeacher::DAY_OFF_PAY_RATE = 100000;

cTeacher::cTeacher(cTeacher::ecType type)
{
	this->ID = "N/A";
	this->FullName = "N/A";
	this->PayRate = 0.f;
	this->BasicPay = 0.f;
	this->DayOff = 0;
	this->Type = type;
}

cTeacher::cTeacher(const cTeacher& teacher)
{
	*this = teacher;
}

cTeacher::cTeacher(string id, string fullName, float payRate, float basicPay, cTeacher::ecType type)
{
	this->ID = id;
	this->FullName = fullName;
	this->PayRate = payRate;
	this->BasicPay = basicPay;
	this->DayOff = 0;
	this->Type = type;
}

cTeacher::cTeacher(string id, float payRate, float basicPay, cTeacher::ecType type)
{
	this->ID = id;
	this->FullName = "N/A";
	this->PayRate = payRate;
	this->BasicPay = basicPay;
	this->DayOff = 0;
	this->Type = type;
}

cTeacher::cTeacher(float payRate, float basicPay, cTeacher::ecType type)
{
	this->ID = "N/A";
	this->FullName = "N/A";
	this->PayRate = payRate;
	this->BasicPay = basicPay;
	this->DayOff = 0;
	this->Type = type;
}

void cTeacher::input_info()
{
	cout << "Input basic info:" << endl;
	cout << "  * ID        : ";
	getline(cin, this->ID);

	cout << "  * Full Name : ";
	getline(cin, this->FullName);

	string temp;
	cout << "  * Pay Rate  : ";
	getline(cin, temp);
	this->PayRate = atoi(temp.c_str());

	cout << "  * Basic Pay : ";
	getline(cin, temp);
	this->BasicPay = atoi(temp.c_str());

	cout << "  * Day-offs  : ";
	getline(cin, temp);
	this->DayOff = atoi(temp.c_str());
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

bool cTeacher::has_type(cTeacher::ecType type)
{
	return this->Type == type;
}
