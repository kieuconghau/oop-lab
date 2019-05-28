#ifndef cfractionarray_h
#define cfractionarray_h

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
	cFractionArray() = default;
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