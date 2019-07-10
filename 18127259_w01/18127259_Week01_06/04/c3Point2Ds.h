#ifndef _3point2ds_h_
#define _3point2ds_h_

#include <iostream>
#include <fstream>
#include "cPoint2D.h"
using namespace std;

#define EPSILON 0.00001f

class c3Point2Ds
{
private:
	cPoint2D Point[3];
	/*string Type;
	float Perimeter;
	float Area;*/

public:
	c3Point2Ds() = default;
	~c3Point2Ds();

	bool load(const string file_name);
	bool save(const string file_name);
	bool isTriangle();

	string getType() const;
	float getPerimeter() const;
	float getArea() const;
};

#endif