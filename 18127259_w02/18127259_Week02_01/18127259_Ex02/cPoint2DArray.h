#ifndef point2darray_h
#define point2darray_h

#include <iostream>
#include <fstream>
#include "cPoint2D.h"
using namespace std;

class cPoint2DArray
{
private:
	cPoint2D* Arr;
	int n;

public:
	cPoint2DArray() = default;
	~cPoint2DArray();

	void showArr();

	bool load(const string file_name);
	cPoint2D findTheFarthestPoint(const cPoint2D& P);
};

#endif