#ifndef point2d_h
#define point2d_h

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
	void load(ifstream&);
	float getDistance(const cPoint2D&) const;
	string getFormat() const;
};

#endif