#include "cPoint2D.h"

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
	float temp;

	stream >> temp;
	this->setX(temp);
	
	stream >> temp;
	this->setY(temp);
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