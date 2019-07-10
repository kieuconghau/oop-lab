#pragma once

#include "cDate.h"
#include <iostream>
using namespace std;

enum class ecSex
{
	MALE,
	FEMALE,
	NONE
};

class cReader
{
public:
	cReader();
	cReader(const cReader& reader);
	cReader(string id, string fullName, int day, int month, int year, ecSex sex);
	cReader(string id, string fullName, int day, int month, int year);
	cReader(string id, string fullName);

	void input_info();
	void show_info();

private:

protected:
	string ID;
	string FullName;
	cDate ExpirationDate;
	ecSex Sex;
};

