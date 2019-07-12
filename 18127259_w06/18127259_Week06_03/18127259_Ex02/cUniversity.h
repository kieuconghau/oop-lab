#pragma once

#include "cFormTeacher.h"
#include <iostream>
#include <vector>
using namespace std;

class cUniversity
{
public:
	cUniversity();
	~cUniversity();

	void input();
	void show();
	float calc_sum_salary();
	vector<cTeacher*> find_all_teachers_having_the_highest_salary();
	int count_normal_teacher();
	int count_form_teacher();
	float calc_average_salary();
	vector<cTeacher*> find_all_teachers_having_salary_more_than(float salary = 10000000);
	cTeacher* find_a_teacher_with_id();
	vector<cTeacher*> find_all_teachers_with_name();
	int count_teachers_having_dayoffs_more_than(int dayQuantity = 4);

private:
	vector<cTeacher*> Teachers;
};
