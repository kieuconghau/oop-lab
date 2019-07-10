#include "c3Point2Ds.h"

c3Point2Ds::~c3Point2Ds()
{
}

bool c3Point2Ds::load(const string file_name)
{
	ifstream f(file_name);
	
	if (!f.is_open())
		return false;

	float temp;
	for (int i = 0; i < 3; i++) {
		f >> temp;
		this->Point[i].setX(temp);
		f >> temp;
		this->Point[i].setY(temp);
	}

	f.close();
	return true;
}

bool c3Point2Ds::save(const string file_name)
{
	ofstream f(file_name);

	if (!f.is_open())
		return false;

	for (int i = 0; i < 3; i++) {
		f << this->Point[i].getX() << " ";
		f << this->Point[i].getY() << endl;
	}
	f << this->getType() << endl;
	f << this->getPerimeter() << endl;
	f << this->getArea();

	f.close();
	return true;
}

bool c3Point2Ds::isTriangle()
{
	// Vector
	float x1 = this->Point[0].getX() - this->Point[1].getX();
	float y1 = this->Point[0].getY() - this->Point[1].getY();
	float x2 = this->Point[1].getX() - this->Point[2].getX();
	float y2 = this->Point[1].getY() - this->Point[2].getY();
	float x3 = this->Point[2].getX() - this->Point[0].getX();
	float y3 = this->Point[2].getY() - this->Point[0].getY();

	if (x1 == y1 && x1 == 0 || x2 == y2 && x2 == 0 || x3 == y3 && x3 == 0)	// Overlap
		return false;

	if (x1 * y2 == x2 * y1)	// In line
		return false;

	return true;
}

string c3Point2Ds::getType() const
{
	float AB = this->Point[0].getDistance(this->Point[1]);
	float BC = this->Point[1].getDistance(this->Point[2]);
	float AC = this->Point[2].getDistance(this->Point[0]);

	float cos1 = (AB * AB + BC * BC - AC * AC) / (2 * AB * BC);
	float cos2 = (AB * AB + AC * AC - BC * BC) / (2 * AB * AC);
	float cos3 = (BC * BC + AC * AC - AB * AB) / (2 * BC * AC);

	if (fabs(cos1 - cos2) < EPSILON && fabs(cos2 - cos3) < EPSILON)
		return "Equilateral";

	if (fabs(cos1 - cos2) < EPSILON || fabs(cos1 - cos3) < EPSILON || fabs(cos2 - cos3) < EPSILON) {
		if (fabs(cos1) < EPSILON || fabs(cos2) < EPSILON || fabs(cos3) < EPSILON)
			return "Isosceles and Right";
		
		if (cos1 < 0 || cos2 < 0 || cos3 < 0)
			return "Isosceles and Obtuse";

		return "Isosceles and Acute";
	}

	if (fabs(cos1) < EPSILON || fabs(cos2) < EPSILON || fabs(cos3) < EPSILON)
		return "Right";

	if (cos1 < 0 || cos2 < 0 || cos3 < 0)
		return "Obtuse";

	return "Acute";
}

float c3Point2Ds::getPerimeter() const
{
	return this->Point[0].getDistance(this->Point[1]) + this->Point[1].getDistance(this->Point[2]) + this->Point[2].getDistance(this->Point[0]);
}

float c3Point2Ds::getArea() const
{
	return fabs((this->Point[1].getX() - this->Point[0].getX())*(this->Point[2].getY() - this->Point[0].getY()) - (this->Point[2].getX() - this->Point[0].getX())*(this->Point[1].getY() - this->Point[0].getY())) / 2;
}