#include "cPoint2DArray.h"

cPoint2DArray::~cPoint2DArray()
{
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
	this->Arr = new cPoint2D[this->N];

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