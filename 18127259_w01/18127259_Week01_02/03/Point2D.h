#ifndef _point_2d_
#define _point_2d_

#include <iostream>
#include <string>
using namespace std;

class Point2D
{
private:
	float x;
	float y;

public:
	Point2D();
	~Point2D();

	void input();
	string getFormat();

	float calcDistance(Point2D p);
};

#endif
