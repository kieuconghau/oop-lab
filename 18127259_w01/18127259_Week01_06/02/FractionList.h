#ifndef _fraction_list_h_
#define _fraction_list_h

#include <iostream>
#include <fstream>
#include "Fraction.h"

using namespace std;

class FractionList
{
private:
	Fraction* list;
	int n;

public:
	FractionList();
	~FractionList();

	bool load(const string file_name);

	Fraction* getList();
};

#endif