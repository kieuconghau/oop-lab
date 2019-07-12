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
	enum class ecType
	{
		NORMAL,
		VIP
	};

	cReader(cReader::ecType type);
	cReader(const cReader& reader);
	cReader(string id, string fullName, int day, int month, int year, ecSex sex, cReader::ecType type);
	cReader(string id, string fullName, int day, int month, int year, cReader::ecType type);
	cReader(string id, string fullName, cReader::ecType type);

	virtual void input_info();
	virtual void show_info();
	virtual float calc_fees() = 0;

	bool has_id(string id);
	bool has_full_name(string fullName);
	bool has_type(cReader::ecType type);
	bool has_expiration_date_in_year(int year);

private:
	cReader::ecType Type;

protected:
	string ID;
	string FullName;
	cDate ExpirationDate;
	ecSex Sex;
};
