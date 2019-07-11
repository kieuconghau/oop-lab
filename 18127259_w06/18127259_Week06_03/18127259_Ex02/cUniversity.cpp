#include "cUniversity.h"

cUniversity::cUniversity()
{
	this->FTCount = 0;
	this->NTCount = 0;
}

cUniversity::~cUniversity()
{
	int n = this->Teachers.size();

	for (int i = 0; i < n; i++)
		delete this->Teachers[i];
}

void cUniversity::input()
{
	string opt;
	while (true)
	{
		cout << "Choose: 1. Normal Teacher, 2. Form Teacher, 0. <Exit> ";
		getline(cin, opt);

		if (opt != "1" && opt != "2")
			break;

		cTeacher* teacher;
		if (opt == "1")
		{
			teacher = new cTeacher;
			++this->NTCount;
		}
		else if (opt == "2")
		{
			teacher = new cFormTeacher;
			++this->FTCount;
		}
		else
			throw;

		teacher->input_info();

		this->Teachers.push_back(teacher);
	}
}

void cUniversity::show()
{
	int n = this->Teachers.size();

	for (int i = 0; i < n; i++)
	{
		cout << "#" << i + 1 << endl;
		this->Teachers[i]->show_info();
		cout << endl;
	}
}

float cUniversity::calc_sum_salary()
{
	int n = this->Teachers.size();
	float sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += this->Teachers[i]->calc_salary();
	}

	return sum;
}

vector<cTeacher*> cUniversity::find_all_teachers_having_the_highest_salary()
{
	int n = this->Teachers.size();

	float max = this->Teachers[0]->calc_salary();
	float cur;
	for (int i = 1; i < n; i++)
	{
		cur = this->Teachers[i]->calc_salary();
		if (cur > max)
			max = cur;
	}

	vector<cTeacher*> res;
	for (int i = 0; i < n; i++)
	{
		if (fabs(this->Teachers[i]->calc_salary() - max) <= 0.00001)
			res.push_back(this->Teachers[i]);
	}

	return res;
}

int cUniversity::count_normal_teacher()
{
	return this->NTCount;
}

int cUniversity::count_form_teacher()
{
	return this->FTCount;
}

float cUniversity::calc_average_salary()
{
	return this->calc_sum_salary() / this->Teachers.size();
}

vector<cTeacher*> cUniversity::find_all_teachers_having_salary_more_than(float salary)
{
	int n = this->Teachers.size();

	vector<cTeacher*> res;
	for (int i = 0; i < n; i++)
	{
		if (this->Teachers[i]->calc_salary() > salary)
			res.push_back(this->Teachers[i]);
	}

	return res;
}

cTeacher* cUniversity::find_a_teacher_with_id(string id)
{
	string id;
	cout << "Input ID:";
	getline(cin, id);

	int n = this->Teachers.size();

	for (int i = 0; i < n; i++)
	{
		if (this->Teachers[i]->has_id(id))
			return this->Teachers[i];
	}

	return nullptr;
}

vector<cTeacher*> cUniversity::find_all_teachers_with_name(string fullName)
{
	string fullName;
	cout << "Input full name: ";
	getline(cin, fullName);

	int n = this->Teachers.size();

	vector<cTeacher*> res;
	for (int i = 0; i < n; i++)
	{
		if (this->Teachers[i]->has_full_name(fullName))
			res.push_back(this->Teachers[i]);
	}

	return res;
}

int cUniversity::count_teachers_having_dayoffs_more_than(int dayQuantity)
{
	int n = this->Teachers.size();

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (this->Teachers[i]->has_dayoffs_more_than(dayQuantity))
			++count;
	}

	return count;
}