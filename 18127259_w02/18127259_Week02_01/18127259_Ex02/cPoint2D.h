#ifndef point2d_h
#define point2d_h

#include <iostream>
#include <string>
using namespace std;

class cPoint2D
{
private:
	float X;
	float Y;

public:
	cPoint2D() = default;
	~cPoint2D();

	void input();

	float getDistance(const cPoint2D& point) const;
	string getFormat() const;

	float getX() const;
	float getY() const;

	void setX(const float x);
	void setY(const float y);
};

#endif