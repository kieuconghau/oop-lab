#ifndef ctrianglearray_h
#define ctrianglearray_h

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