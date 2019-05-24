#include "cPoint2DArray.h"

cPoint2DArray::~cPoint2DArray()
{
	delete[] this->Arr;
}

void cPoint2DArray::showArr()
{
	for (int i = 0; i < this->n; i++)
		cout << this->Arr[i].getFormat() << endl;
}

bool cPoint2DArray::load(const string file_name)
{
	ifstream f(file_name);

	if (!f.is_open())
		return false;

	f >> this->n;
	this->Arr = new cPoint2D[this->n];

	float temp;
	for (int i = 0; i < this->n; i++) {
		f >> temp;
		this->Arr[i].setX(temp);
		f >> temp;
		this->Arr[i].setY(temp);
	}

	f.close();
	return true;
}

cPoint2D cPoint2DArray::findTheFarthestPoint(const cPoint2D& P)
{
	float max_distance = P.getDistance(this->Arr[0]);
	cPoint2D res = this->Arr[0];
	
	for (int i = 1; i < this->n; i++)
	{
		float distance = P.getDistance(this->Arr[i]);
		if (distance > max_distance)
		{
			max_distance = distance;
			res = Arr[i];
		}
	}

	return res;
}