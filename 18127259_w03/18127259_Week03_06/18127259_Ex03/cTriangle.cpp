#include "cTriangle.h"

cTriangle::cTriangle()
{
	this->A = { 0, 0 };
	this->B = { 0, 0 };
	this->C = { 0, 0 };
	this->Type = cTypeOfTriangle::INVALID;
}

cTriangle::cTriangle(cPoint2D a, cPoint2D b, cPoint2D c)
{
	this->A = a;
	this->B = b;
	this->C = c;
	this->identifyType();
}

cTriangle::cTriangle(const cTriangle& tri)
{
	this->A = tri.A;
	this->B = tri.B;
	this->C = tri.C;
	this->Type = tri.Type;
}

cTriangle::~cTriangle()
{
}

void cTriangle::load(ifstream& stream)
{
	this->A.load(stream);
	this->B.load(stream);
	this->C.load(stream);
}

void cTriangle::identifyType()
{
	float AB = this->A.getDistance(this->B);
	float BC = this->B.getDistance(this->C);
	float AC = this->A.getDistance(this->C);

	float cos1 = (AB * AB + BC * BC - AC * AC) / (2 * AB * BC);
	float cos2 = (AB * AB + AC * AC - BC * BC) / (2 * AB * AC);
	float cos3 = (BC * BC + AC * AC - AB * AB) / (2 * BC * AC);

	if (fabsf(fabsf(cos1) - 1) < EPSILON || fabsf(fabsf(cos2) - 1) < EPSILON || fabsf(fabsf(cos3) - 1) < EPSILON)
		this->Type = cTypeOfTriangle::INVALID;

	else if (fabs(cos1 - cos2) < EPSILON && fabs(cos2 - cos3) < EPSILON)
		this->Type = cTypeOfTriangle::EQUILATERAL;

	else if (fabs(cos1 - cos2) < EPSILON || fabs(cos1 - cos3) < EPSILON || fabs(cos2 - cos3) < EPSILON) {
		if (fabs(cos1) < EPSILON || fabs(cos2) < EPSILON || fabs(cos3) < EPSILON)
			this->Type = cTypeOfTriangle::RIGHT_ISOSCELES;

		else if (cos1 < 0 || cos2 < 0 || cos3 < 0)
			this->Type = cTypeOfTriangle::OBTUSE_ISOSCELES;

		else this->Type = cTypeOfTriangle::ACUTE_ISOSCELES;
	}

	else if (fabs(cos1) < EPSILON || fabs(cos2) < EPSILON || fabs(cos3) < EPSILON)
		this->Type = cTypeOfTriangle::RIGHT;

	else if (cos1 < 0 || cos2 < 0 || cos3 < 0)
		this->Type = cTypeOfTriangle::OBTUSE;

	else this->Type = cTypeOfTriangle::ACUTE;
}

void cTriangle::showInfo()
{
	cout << "(" << this->A.getFormat() << ", " << this->B.getFormat() << ", " << this->C.getFormat() << "): " << this->getType_str() << endl;
}

cTypeOfTriangle cTriangle::getType() const
{
	return this->Type;
}

string cTriangle::getType_str() const
{
	switch (this->Type)
	{
	case cTypeOfTriangle::INVALID:
		return "Invalid Triangle";
		break;
	case cTypeOfTriangle::EQUILATERAL:
		return "Equilateral Triangle";
		break;
	case cTypeOfTriangle::RIGHT_ISOSCELES:
		return "Right Isosceles Triangle";
		break;
	case cTypeOfTriangle::OBTUSE_ISOSCELES:
		return "Obtuse Isosceles Triangle";
		break;
	case cTypeOfTriangle::ACUTE_ISOSCELES:
		return "Acute Isosceles Triangle";
		break;
	case cTypeOfTriangle::RIGHT:
		return "Right Triangle";
		break;
	case cTypeOfTriangle::OBTUSE:
		return "Obtuse Triangle";
		break;
	case cTypeOfTriangle::ACUTE:
		return "Acute Triangle";
		break;
	default:
		break;
	}
}