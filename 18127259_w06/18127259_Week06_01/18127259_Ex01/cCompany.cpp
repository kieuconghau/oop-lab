#include "cCompany.h"

cCompany::cCompany() {}

cCompany::~cCompany()
{
	int n = this->Employees.size();

	for (int i = 0; i < n; i++)
		delete this->Employees[i];
}

void cCompany::input()
{
	string opt;
	while (true)
	{
		cout << "Choose: 1. Production Employee, 2. Daily Woker, 0. <Exit> ";
		getline(cin, opt);

		if (opt != "1" && opt != "2")
			break;

		cEmployee* employee;
		if (opt == "1")
		{
			employee = new cProductionEmployee;
		}
		else if (opt == "2")
		{
			employee = new cDailyWorker;
		}
		else
			throw;

		employee->input_info();

		this->Employees.push_back(employee);
	}
}

void cCompany::show()
{
	int n = this->Employees.size();

	for (int i = 0; i < n; i++)
	{
		cout << "#" << i + 1 << endl;
		this->Employees[i]->show_info();
		cout << endl;
	}
}

float cCompany::calc_sum_salary()
{
	int n = this->Employees.size();
	float sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += this->Employees[i]->calc_salary();
	}

	return sum;
}

vector<cEmployee*> cCompany::find_employees_having_the_highest_salary()
{
	int n = this->Employees.size();
	
	float max = this->Employees[0]->calc_salary();
	float cur;
	for (int i = 1; i < n; i++)
	{
		cur = this->Employees[i]->calc_salary();
		if (cur > max)
			max = cur;
	}

	vector<cEmployee*> res;
	for (int i = 0; i < n; i++)
	{
		if (fabs(this->Employees[i]->calc_salary() - max) <= 0.00001)
			res.push_back(this->Employees[i]);
	}

	return res;
}

int cCompany::count_production_employees()
{
	int n = this->Employees.size();

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (this->Employees[i]->has_type(cEmployee::ecType::PRODUCTION_EMPLOYEE))
			++count;
	}

	return count;
}

int cCompany::count_daily_workers()
{
	int n = this->Employees.size();

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (this->Employees[i]->has_type(cEmployee::ecType::DAILY_WORKER))
			++count;
	}

	return count;
}

float cCompany::calc_average_salary()
{
	return this->calc_sum_salary() / this->Employees.size();
}

vector<cEmployee*> cCompany::find_all_employees_having_salary_less_than(float salary)
{
	int n = this->Employees.size();

	vector<cEmployee*> res;
	for (int i = 0; i < n; i++)
	{
		if (this->Employees[i]->calc_salary() < salary)
			res.push_back(this->Employees[i]);
	}

	return res;
}

cEmployee* cCompany::find_an_employee_with_id()
{
	string id;
	cout << "Input ID:";
	getline(cin, id);

	int n = this->Employees.size();

	for (int i = 0; i < n; i++)
	{
		if (this->Employees[i]->has_id(id))
			return this->Employees[i];
	}

	return nullptr;
}

vector<cEmployee*> cCompany::find_all_employees_with_full_name()
{
	string fullName;
	cout << "Input full name: ";
	getline(cin, fullName);

	int n = this->Employees.size();

	vector<cEmployee*> res;
	for (int i = 0; i < n; i++)
	{
		if (this->Employees[i]->has_full_name(fullName))
			res.push_back(this->Employees[i]);
	}

	return res;
}

int cCompany::count_all_employees_having_birthday_in_month(int month)
{
	int n = this->Employees.size();

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (this->Employees[i]->has_birthday_in_month(month))
			count++;
	}

	return count;
}
