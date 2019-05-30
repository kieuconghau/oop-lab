#include "cFractionArray.h"

cFractionArray::~cFractionArray()
{
	delete[] this->Arr;
}

bool cFractionArray::load(const string file_name)
{
	ifstream f(file_name);

	if (!f.is_open())
		return false;

	f >> this->N;
	if (this->N <= 0)
		return false;

	this->Arr = new cFraction[this->N];

	for (int i = 0; i < this->N; i++)
		this->Arr[i].load(f);

	f.close();
	return true;
}

void cFractionArray::show()
{
	for (int i = 0; i < this->N; i++)
		cout << "  " << this->Arr[i].getFormat();

	cout << endl;
}

void cFractionArray::standardize()
{
	for (int i = 0; i < this->N; i++)
		this->Arr[i].standardize();
}

cFraction cFractionArray::getSum()
{
	cFraction res = this->Arr[0];

	for (int i = 1; i < this->N; i++)
		res = res.add(this->Arr[i]);
	res.standardize();

	return res;
}

cFraction* cFractionArray::getMax()
{
	cFraction max = this->Arr[0];
	int pos = 0;

	for (int i = 1; i < this->N; i++)
		if (this->Arr[i].getComparison(max) == cComparison::GREATER)
		{
			max = this->Arr[i];
			pos = i;
		}

	return Arr + pos;
}

cFraction* cFractionArray::getMin()
{
	cFraction min = this->Arr[0];
	int pos = 0;

	for (int i = 1; i < this->N; i++)
		if (this->Arr[i].getComparison(min) == cComparison::LESS)
		{
			min = this->Arr[i];
			pos = i;
		}

	return this->Arr + pos;
}

void cFractionArray::sortAscending()
{
	cFraction* max = new cFraction;

	int i = this->N - 1;
	while (i != 0)
	{
		max = this->Arr;
		for (int j = 1; j <= i; j++)
		{
			if (this->Arr[j].getComparison(*max) == cComparison::GREATER)
				max = this->Arr + j;
		}

		cFraction temp = this->Arr[i];
		this->Arr[i] = *max;
		*max = temp;

		i--;
	}
}

cFraction* cFractionArray::getArr()
{
	return this->Arr;
}