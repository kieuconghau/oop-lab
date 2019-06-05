#include "cPoint2D.h"

cPoint2D::cPoint2D()
{
	this->X = 0;
	this->Y = 0;
}

cPoint2D::cPoint2D(const cPoint2D& point)
{
	this->X = point.X;
	this->Y = point.Y;
}

cPoint2D::cPoint2D(float x_cor, float y_cor)
{
	this->X = x_cor;
	this->Y = y_cor;
}

cPoint2D::~cPoint2D()
{
}

void cPoint2D::input()
{
	cout << "  * Input X coordinate: ";
	cin >> this->X;
	cout << "  * Input Y coordinate: ";
	cin >> this->Y;
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

float cPoint2D::getX() const
{
	return this->X;
}

float cPoint2D::getY() const
{
	return this->Y;
}

void cPoint2D::setX(const float x)
{
	this->X = x;
}

void cPoint2D::setY(const float y)
{
	this->Y = y;
}