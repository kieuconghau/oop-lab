#ifndef ctriangle_h
#define ctriangle_h

#include <iostream>
#include <fstream>
#include "cPoint2D.h"
using namespace std;

#define EPSILON 0.00001f

enum class cTypeOfTriangle
{
	INVALID,
	EQUILATERAL,
	RIGHT_ISOSCELES,
	OBTUSE_ISOSCELES,
	ACUTE_ISOSCELES,
	RIGHT,
	OBTUSE,
	ACUTE,
	
	Count
};


class cTriangle
{
private:
	cPoint2D A;
	cPoint2D B;
	cPoint2D C;
	cTypeOfTriangle Type;

public:
	void load(ifstream&);
	void identifyType();
	void showInfo();

	cTypeOfTriangle getType() const;
	string getType_str() const;
};

#endif