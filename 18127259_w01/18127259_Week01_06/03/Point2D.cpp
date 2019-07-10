#include "Point2D.h"

Point2D::Point2D()
{
	x = 0;
	y = 0;
}

Point2D::~Point2D()
{
}

void Point2D::input()
{
	cout << "Input info of a point 2D: " << endl;
	cout << "  * x: ";
	cin >> x;
	cout << "  * y: ";
	cin >> y;
	cout << endl;
}

string Point2D::getFormat() {
	return "(" + to_string(x) + " , " + to_string(y) + ")";
}

float Point2D::calcDistance(Point2D p)
{
	return sqrtf(powf(x - p.x, 2) + powf(y - p.y, 2));
}