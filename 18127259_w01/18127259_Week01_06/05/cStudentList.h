#ifndef _cstudentlist_h_
#define _cstudentlist_h_

#include <iostream>
#include <fstream>
#include "cStudent.h"
using namespace std;

class cStudentList
{
private:
	cStudent* List;
	int n;

public:
	cStudentList() = default;
	~cStudentList();

	bool saveToXML(const string file_name);
	void input();

	cStudent* getList();
};

#endif