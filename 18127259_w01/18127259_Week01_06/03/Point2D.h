#include <iostream>
#include <string>
using namespace std;

#ifndef _point_2d_
#define _point_2d_

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
