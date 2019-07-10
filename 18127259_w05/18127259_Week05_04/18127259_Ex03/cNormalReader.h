#pragma once

#include "cReader.h"

class cNormalReader : public cReader
{
public:
	cNormalReader();
	cNormalReader(const cNormalReader& normalReader);
	cNormalReader(string id, string fullName, int day, int month, int year, ecSex sex);
	cNormalReader(string id, string fullName, int day, int month, int year);
	cNormalReader(string id, string fullName);

	void input_info();
	void show_info();
	float calc_fees();
	void input_book_quantity();

private:
	static const float FEES_PER_A_BOOK;
	int BookQuantity;
};


