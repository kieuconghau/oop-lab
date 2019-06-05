#ifndef point2d_h_ex03
#define point2d_h_ex03

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class cPoint2D
{
private:
	float X;
	float Y;

public:
	cPoint2D();
	cPoint2D(float x, float y);
	cPoint2D(const cPoint2D&);
	~cPoint2D();
	void load(ifstream&);
	float getDistance(const cPoint2D&) const;
	string getFormat() const;
};

#endif