#include "cStudentList.h"

cStudentList::~cStudentList()
{
	delete[] this->List;
}

bool cStudentList::saveToXML(const string file_name)
{
	ofstream f(file_name);

	if (!f.is_open())
		return false;

	f << "<List>" << endl;
	for (int i = 0; i < this->n; i++) {
		f << "<Student" << i + 1 << ">" << endl;
		this->List[i].printInfo(f);
		f << "</Student" << i + 1 << ">" << endl;
	}
	f << "</List>" << endl;

	f.close();
	return true;
}

void cStudentList::input()
{
	cout << "Input the number of students in this list (should be 2): ";
	cin >> this->n;
	cin.ignore();

	this->List = new cStudent[n];

	for (int i = 0; i < n; i++) {
		cout << "Input info of the #" << i + 1 <<" student:" << endl;
		this->List[i].input();
	}
}

cStudent* cStudentList::getList()
{
	return this->List;
}
