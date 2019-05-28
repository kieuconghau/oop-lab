#include "cPoint2D.h"

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