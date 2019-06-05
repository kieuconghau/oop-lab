#include "cFractionArray.h"

cFractionArray::cFractionArray()
{
	this->Arr = nullptr;
	this->N = 0;
}

cFractionArray::cFractionArray(const cFractionArray& fracArr)
{
	this->N = fracArr.N;
	if (this->N != 0)
	{
		this->Arr = new cFraction[this->N];
		if (this->Arr == nullptr)
			throw;

		for (int i = 0; i < this->N; i++)
			this->Arr[i] = fracArr.Arr[i];
	}
	else
		this->Arr = nullptr;
}

cFractionArray::cFractionArray(cFraction* arr, int length)
{
	if (length > 0 && arr != nullptr)
	{
		this->N = length;
		this->Arr = new cFraction[length];
		if (this->Arr == nullptr)
			throw;

		for (int i = 0; i < this->N; i++)
			this->Arr[i] = arr[i];
	}
	else
	{
		this->Arr = nullptr;
		this->N = 0;
	}
}

cFractionArray::~cFractionArray()
{
	if (this->Arr != nullptr)
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
	if (this->Arr == nullptr)
		return false;

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
	cFraction* max = this->Arr;

	for (int i = 1; i < this->N; i++)
		if (this->Arr[i].getComparison(*max) == cComparison::GREATER)
			max = this->Arr + i;

	return max;
}

cFraction* cFractionArray::getMin()
{
	cFraction* min = this->Arr;

	for (int i = 1; i < this->N; i++)
		if (this->Arr[i].getComparison(*min) == cComparison::LESS)
			min = this->Arr + i;

	return min;
}

void cFractionArray::sortAscending()
{
	cFraction* max;

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