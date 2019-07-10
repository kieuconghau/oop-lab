#include "cPoint2D.h"

cPoint2D::~cPoint2D()
{
}

float cPoint2D::getDistance(const cPoint2D& point) const
{
	return sqrtf(powf(this->X - point.X, 2) + powf(this->Y - point.Y, 2));
}

float cPoint2D::getX() const
{
	return this->X;
}

float cPoint2D::getY() const
{
	return this->Y;
}

void cPoint2D::setX(float x)
{
	this->X = x;
}

void cPoint2D::setY(float y)
{
	this->Y = y;
}
