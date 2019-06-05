#include "cPoint2D.h"

cPoint2D::cPoint2D()
{
	this->X = 0;
	this->Y = 0;
}

cPoint2D::cPoint2D(float x, float y)
{
	this->X = x;
	this->Y = y;
}

cPoint2D::cPoint2D(const cPoint2D& p)
{
	this->X = p.X;
	this->Y = p.Y;
}

cPoint2D::~cPoint2D()
{
}

void cPoint2D::load(ifstream& stream)
{
	stream >> this->X >> this->Y;
}

float cPoint2D::getDistance(const cPoint2D& point) const
{
	return sqrtf(powf(this->X - point.X, 2) + powf(this->Y - point.Y, 2));
}

string cPoint2D::getFormat() const
{
	return "(" + to_string(this->X) + " , " + to_string(this->Y) + ")";
}