#ifndef ctrianglearray_h_ex03
#define ctrianglearray_h_ex03

#include <iostream>
#include <fstream>
#include "cTriangle.h"
using namespace std;

class cTriangleArray
{
private:
	cTriangle* Arr;
	int CountType[int(cTypeOfTriangle::Count)];
	int N;

public:
	~cTriangleArray();
	bool load(const string);
	void removeAllInvalidTriangles();
	void classify();
	void showInfo();
};

#endif