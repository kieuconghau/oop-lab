#ifndef cfractionarray_h_ex1
#define cfractionarray_h_ex01

#include <iostream>
#include <fstream>
#include "cFraction.h"

using namespace std;

class cFractionArray
{
private:
	cFraction* Arr;
	int N;

public:
	cFractionArray();
	cFractionArray(const cFractionArray&);
	cFractionArray(cFraction*, int);
	~cFractionArray();

	bool load(const string file_name);
	void show();
	void standardize();
	
	cFraction getSum();
	cFraction* getMax();
	cFraction* getMin();
	void sortAscending();

	cFraction* getArr();
};

#endif