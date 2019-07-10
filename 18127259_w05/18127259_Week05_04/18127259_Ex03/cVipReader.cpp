#include "cVipReader.h"

const float cVipReader::FEES = 50000;

cVipReader::cVipReader() {}

cVipReader::cVipReader(const cVipReader& vipReader)
	: cReader(vipReader) {}

cVipReader::cVipReader(string id, string fullName, int day, int month, int year, ecSex sex)
	: cReader(id, fullName, day, month, year, sex) {}

cVipReader::cVipReader(string id, string fullName, int day, int month, int year)
	: cReader(id, fullName, day, month, year) {}

cVipReader::cVipReader(string id, string fullName)
	: cReader(id, fullName) {}

void cVipReader::input_info()
{
	cout << "~VIP READER~" << endl;
	cReader::input_info();
}

void cVipReader::show_info()
{
	cout << "~VIP READER~" << endl;
	cReader::show_info();
}

float cVipReader::calc_fees()
{
	return cVipReader::FEES;
}
