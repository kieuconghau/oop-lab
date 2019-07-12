#include "cNormalReader.h"

const float cNormalReader::FEES_PER_A_BOOK = 5000;

cNormalReader::cNormalReader()
	: cReader(cReader::ecType::NORMAL)
{
	this->BookQuantity = 0;
}

cNormalReader::cNormalReader(const cNormalReader& normalReader)
	: cReader(normalReader)
{
	this->BookQuantity = 0;
}

cNormalReader::cNormalReader(string id, string fullName, int day, int month, int year, ecSex sex)
	: cReader(id, fullName, day, month, year, sex, cReader::ecType::NORMAL)
{
	this->BookQuantity = 0;
}

cNormalReader::cNormalReader(string id, string fullName, int day, int month, int year)
	: cReader(id, fullName, day, month, year, cReader::ecType::NORMAL)
{
	this->BookQuantity = 0;
}

cNormalReader::cNormalReader(string id, string fullName)
	: cReader(id, fullName, cReader::ecType::NORMAL)
{
	this->BookQuantity = 0;
}

void cNormalReader::input_info()
{
	cout << "~NORMAL READER~" << endl;
	cReader::input_info();
}

void cNormalReader::show_info()
{
	cout << "~NORMAL READER~" << endl;
	cReader::show_info();
}

float cNormalReader::calc_fees()
{
	return this->BookQuantity * cNormalReader::FEES_PER_A_BOOK;
}

void cNormalReader::input_book_quantity()
{
	int n;
	cout << "Input quantity of book: ";
	cin >> n;
	this->BookQuantity = n;
}
