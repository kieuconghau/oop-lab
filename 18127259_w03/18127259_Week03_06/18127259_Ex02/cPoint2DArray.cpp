#include "cPoint2DArray.h"

cPoint2DArray::cPoint2DArray()
{
	this->Arr = nullptr;
	this->N = 0;
}

cPoint2DArray::cPoint2DArray(const cPoint2DArray& pointArr)
{
	this->N = pointArr.N;
	if (this->N != 0)
	{
		this->Arr = new cPoint2D[this->N];
		if (this->Arr == nullptr)
			throw;

		for (int i = 0; i < this->N; i++)
			this->Arr[i] = pointArr.Arr[i];
	}
	else
		this->Arr = nullptr;
}

cPoint2DArray::cPoint2DArray(cPoint2D* arr, int length)
{
	if (length > 0 && arr != nullptr)
	{
		this->N = length;
		this->Arr = new cPoint2D[this->N];
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

cPoint2DArray::~cPoint2DArray()
{
	if (this->Arr != nullptr)
		delete[] this->Arr;
}

void cPoint2DArray::showArr()
{
	for (int i = 0; i < this->N; i++)
		cout << this->Arr[i].getFormat() << endl;
}

bool cPoint2DArray::load(const string file_name)
{
	ifstream f(file_name);

	if (!f.is_open())
		return false;

	f >> this->N;
	if (this->N <= 0)
		return false;

	this->Arr = new cPoint2D[this->N];
	if (this->Arr == nullptr)
		return false;

	for (int i = 0; i < this->N; i++)
		this->Arr[i].load(f);

	f.close();
	return true;
}

cPoint2D* cPoint2DArray::findTheFarthestPoint(const cPoint2D& P)
{
	cPoint2D* max = this->Arr;
	
	for (int i = 1; i < this->N; i++)
		if (this->Arr[i].getDistance(P) > max->getDistance(P))
			max = Arr + i;

	return max;
}
