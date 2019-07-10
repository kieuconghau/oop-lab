#include "FractionList.h"

FractionList::FractionList()
{
	this->list = nullptr;
	this->n = 0;
}

FractionList::~FractionList()
{
	delete[] this->list;
}

bool FractionList::load(const string file_name)
{
	ifstream f(file_name);

	if (!f.is_open())
		return false;

	f >> this->n;
	if (this->n <= 0)
		return false;

	this->list = new Fraction[this->n];
	
	int temp;
	for (int i = 0; i < this->n; i++) {
		f >> temp;
		this->list[i].setNu(temp);

		f >> temp;
		if (temp == 0)
			return false;
		this->list[i].setDe(temp);
	}

	f.close();
	return true;
}

Fraction* FractionList::getList()
{
	return this->list;
}