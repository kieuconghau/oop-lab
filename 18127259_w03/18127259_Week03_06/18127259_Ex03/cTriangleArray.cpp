#include "cTriangleArray.h"

cTriangleArray::cTriangleArray()
{
	this->Arr = nullptr;
	for (int i = 0; i < int(cTypeOfTriangle::Count); i++)
		this->CountType[i] = 0;
	this->N = 0;
}

cTriangleArray::cTriangleArray(cTriangle* arr, int length)
{
	if (length > 0 && arr != nullptr)
	{
		this->N = length;
		this->Arr = new cTriangle[this->N];
		if (this->Arr == nullptr)
			throw;

		for (int i = 0; i < this->N; i++)
			this->Arr[i] = arr[i];

		this->classify();
	}
	else
	{
		this->Arr = nullptr;
		for (int i = 0; i < int(cTypeOfTriangle::Count); i++)
			this->CountType[i] = 0;
		this->N = 0;
	}
}

cTriangleArray::cTriangleArray(const cTriangleArray& triArr)
{
	this->N = triArr.N;
	if (this->N != 0)
	{
		this->Arr = new cTriangle[this->N];
		if (this->Arr == nullptr)
			throw;

		for (int i = 0; i < this->N; i++)
			this->Arr[i] = triArr.Arr[i];

		this->classify();
	}
	else
	{
		this->Arr = nullptr;
		for (int i = 0; i < int(cTypeOfTriangle::Count); i++)
			this->CountType[i] = 0;
	}
}

cTriangleArray::~cTriangleArray()
{
	if (this->Arr != nullptr)
		delete[] this->Arr;
}

bool cTriangleArray::load(const string file_name)
{
	ifstream f(file_name);

	if (!f.is_open())
		return false;

	f >> this->N;
	this->Arr = new cTriangle[this->N];

	for (int i = 0; i < this->N; i++)
		this->Arr[i].load(f);

	f.close();
	return true;
}

void cTriangleArray::removeAllInvalidTriangles()
{
	cTriangle* temp_arr = new cTriangle[this->N];

	for (int i = 0; i < this->N; i++)
		temp_arr[i] = this->Arr[i];

	delete[] this->Arr;
	this->Arr = new cTriangle[this->N - this->CountType[int(cTypeOfTriangle::INVALID)]];

	int j = 0;
	for (int i = 0; i < this->N; i++)
		if (temp_arr[i].getType() != cTypeOfTriangle::INVALID)
			this->Arr[j++] = temp_arr[i];

	this->CountType[int(cTypeOfTriangle::INVALID)] = 0;

	this->N = j;

	delete[] temp_arr;
}

void cTriangleArray::classify()
{
	for (int i = 0; i < int(cTypeOfTriangle::Count); i++)
		this->CountType[i] = 0;

	for (int i = 0; i < this->N; i++)
	{
		this->Arr[i].identifyType();
		this->CountType[int(this->Arr[i].getType())]++;
	}
}

void cTriangleArray::showInfo()
{
	cout << "*************************************************************************************************" << endl;
	for (int i = 0; i < this->N; i++)
		this->Arr[i].showInfo();
	 
	cout << endl << "Classify:" << endl;
	cout << " * Invalid Triangle: " << this->CountType[int(cTypeOfTriangle::INVALID)] << endl;
	cout << " * Equilateral Triangle: " << this->CountType[int(cTypeOfTriangle::EQUILATERAL)] << endl;
	cout << " * Right Isosceles Triangle: " << this->CountType[int(cTypeOfTriangle::RIGHT_ISOSCELES)] << endl;
	cout << " * Obtuse Isosceles Triangle: " << this->CountType[int(cTypeOfTriangle::OBTUSE_ISOSCELES)] << endl;
	cout << " * Acute Isosceles Triangle: " << this->CountType[int(cTypeOfTriangle::ACUTE_ISOSCELES)] << endl;
	cout << " * Right Triangle: " << this->CountType[int(cTypeOfTriangle::RIGHT)] << endl;
	cout << " * Obtuse Triangle: " << this->CountType[int(cTypeOfTriangle::OBTUSE)] << endl;
	cout << " * Acute Triangle: " << this->CountType[int(cTypeOfTriangle::ACUTE)] << endl;
	cout << "*************************************************************************************************" << endl;
}
