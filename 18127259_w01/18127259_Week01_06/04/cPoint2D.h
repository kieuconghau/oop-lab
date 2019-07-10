#ifndef _point_2d_h_
#define _point_2d_h_

#include <iostream>
using namespace std;

class cPoint2D
{
private:
	float X;
	float Y;

public:
	cPoint2D() = default;
	~cPoint2D();

	float getDistance(const cPoint2D& point) const;

	float getX() const;
	float getY() const;

	void setX(float x);
	void setY(float y);
};

#endif