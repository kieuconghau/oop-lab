#include "IntArray.h"

IntArray::IntArray()
{
	this->Arr = nullptr;
	this->N = 0;
}

IntArray::IntArray(int length)
{
	if (length < 0)
		throw;

	else if (length == 0)
		IntArray();

	else
	{
		this->Arr = new int[length];
		if (this->Arr == nullptr)
			throw;
		this->N = length;
		for (int i = 0; i < this->N; i++)
			this->Arr[i] = 0;
	}
}

IntArray::IntArray(int* array, int length)
{
	if (array == nullptr && length == 0)
		IntArray();

	else if (array != nullptr && length > 0)
	{
		this->Arr = new int[length];
		if (this->Arr == nullptr)
			throw;
		this->N = length;
		for (int i = 0; i < this->N; i++)
			this->Arr[i] = array[i];
	}

	else throw;
}

IntArray::IntArray(const IntArray& ia)
{
	if (ia.Arr == nullptr && ia.N == 0)
		IntArray();

	else if (ia.Arr != nullptr && ia.N > 0)
	{
		this->Arr = new int[ia.N];
		if (this->Arr == nullptr)
			throw;
		this->N = ia.N;
		for (int i = 0; i < this->N; i++)
			this->Arr[i] = ia.Arr[i];
	}

	else throw;
}

IntArray::~IntArray()
{
	if (this->Arr != nullptr)
		delete[] this->Arr;
}

IntArray& IntArray::operator=(const IntArray& ia)
{
	if (this == &ia)
		return *this;

	if (this->Arr != nullptr)
		delete[] this->Arr;

	if (ia.Arr == nullptr && ia.N == 0)
	{
		IntArray();
		return *this;
	}

	if (ia.Arr != nullptr && ia.N > 0)
	{
		this->Arr = new int[ia.N];
		if (this->Arr == nullptr)
			throw;
		this->N = ia.N;
		for (int i = 0; i < this->N; i++)
			this->Arr[i] = ia.Arr[i];
		return *this;
	}

	else throw;
}

int& IntArray::operator[](int index)
{
	return this->Arr[index];
}

IntArray::operator int() const
{
	return this->N;
}

istream& operator>>(istream& is, IntArray& ia)
{
	while (true)
	{
		cout << "Input number of elements in this array: ";
		is >> ia.N;
		if (ia.N <= 0)
			cout << "\aInvalid input! The number of elements in this array must > 0." << endl;
		else break;
	}

	if (ia.Arr != nullptr)
		delete[] ia.Arr;

	ia.Arr = new int[ia.N];
	for (int i = 0; i < ia.N; i++)
	{
		cout << "  * Input element #" << i + 1 << ": ";
		is >> ia.Arr[i];
	}

	return is;
}

ostream& operator<<(ostream& os, const IntArray& ia)
{
	if (ia.Arr == nullptr && ia.N == 0)
		os << "Nothing";

	else if (ia.Arr != nullptr && ia.N > 0)
		for (int i = 0; i < ia.N; i++)
			os << "  " << ia.Arr[i];

	else throw;

	return os;
}
