#pragma once

#include "cReader.h"

class cVipReader : public cReader
{
public:
	cVipReader();
	cVipReader(const cVipReader& vipReader);
	cVipReader(string id, string fullName, int day, int month, int year, ecSex sex);
	cVipReader(string id, string fullName, int day, int month, int year);
	cVipReader(string id, string fullName);

	void input_info();
	void show_info();
	float calc_fees();

private:
	static const float FEES;
};
