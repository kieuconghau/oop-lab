#ifndef cstudentarray_h
#define cstudentarray_h

#include <iostream>
#include <fstream>
#include "cStudent.h"
using namespace std;

class cStudentArray
{
private:
	cStudent* Arr;
	int N;

public:
	~cStudentArray();
	bool load_txt(const string);
	void sort();
	bool save_xml(const string);
};

#endif