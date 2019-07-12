#pragma once

#include "cNormalReader.h"
#include "cVipReader.h"
#include <iostream>
#include <vector>
using namespace std;

class cLibrary
{
public:
	cLibrary();
	~cLibrary();

	void input();
	void show();
	float calc_sum_fees();
	vector<cReader*> find_readers_having_the_highest_fees();
	int count_normal_readers();
	int count_vip_readers();
	float calc_average_salary();
	vector<cReader*> find_readers_having_fees_more_than(float fees = 30000);
	cReader* find_a_reader_with_id();
	vector<cReader*> find_readers_with_full_name();
	int count_readers_having_expiration_date_in_year(int year = 2017);

private:
	vector<cReader*> Readers;
};
