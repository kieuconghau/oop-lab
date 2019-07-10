#include "cFormTeacher.h"

const float cFormTeacher::FRINGE_BENEFITS = 500000;

cFormTeacher::cFormTeacher()
{
	this->ClassName = "N/A";
}

cFormTeacher::cFormTeacher(const cFormTeacher& formTeacher) : cTeacher(formTeacher)
{
	*this = formTeacher;
}

cFormTeacher::cFormTeacher(string className, string id, string fullName, float payRate, float basicPay)
	: cTeacher(id, fullName, payRate, basicPay)
{
	this->ClassName = className;
}

cFormTeacher::cFormTeacher(string className, string id, float payRate, float basicPay)
	: cTeacher(id, payRate, basicPay)
{
	this->ClassName = className;
}

cFormTeacher::cFormTeacher(string className, float payRate, float basicPay)
	: cTeacher(payRate, basicPay)
{
	this->ClassName = className;
}

void cFormTeacher::input_info()
{
	cTeacher::input_info();

	cout << "Input detail info:" << endl;
	cout << "  * Class Name: ";
	getline(cin, this->ClassName);
}

void cFormTeacher::show_info()
{
	cTeacher::show_info();
	
	cout << "Detail info:" << endl;
	cout << "  * Class Name: " << this->ClassName << endl;
}

float cFormTeacher::calc_salary()
{
	return cTeacher::calc_salary() + cFormTeacher::FRINGE_BENEFITS;
}
