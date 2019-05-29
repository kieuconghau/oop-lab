#include "cStudentArray.h"

cStudentArray::~cStudentArray()
{
	delete[] this->Arr;
}

bool cStudentArray::load_txt(const string file_name)
{
	ifstream f(file_name);

	if (!f.is_open())
		return false;

	f >> this->N;
	this->Arr = new cStudent[this->N];
	
	if (this->Arr == nullptr)
		return false;

	f.seekg(2, ios::cur);
	for (int i = 0; i < this->N; i++)
	{
		this->Arr[i].setNo(i + 1);
		this->Arr[i].load_txt(f);
	}

	f.close();
	return true;
}

void cStudentArray::sort()
{
	cStudent* max;

	int i = this->N - 1;
	while (i >= 1)
	{
		max = this->Arr;
		for (int j = 1; j <= i; j++)
			if (max->compare(this->Arr[j]) < 0)
				max = this->Arr + j;

		max->swap(this->Arr[i--]);
	}
}

bool cStudentArray::save_xml(const string file_name)
{
	ofstream f(file_name);

	if (!f.is_open())
		return false;

	f << "<List>" << endl;
	for (int i = 0; i < this->N; i++)
		this->Arr[i].save_xml(f);
	f << "</List>" << endl;

	f.close();
	return true;
}