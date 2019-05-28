#include "cFraction.h"

cFraction::~cFraction()
{
}

void cFraction::load(ifstream& stream)
{
	stream >> this->Nu >> this->De;
}

void cFraction::reduce()
{
	int a = fabs(this->Nu), b = fabs(this->De);
	int GCD = 1;
	
	if (a != 0) {
		while (a != b) {
			if (a > b)
				a -= b;
			else
				b -= a;
		}
		GCD = a;
	}

	this->Nu /= GCD;
	this->De /= GCD;
}

void cFraction::standardize()
{
	reduce();

	if (this->Nu != 0)
		this->Nu = fabs(this->Nu) * ((this->Nu*this->De) / fabs(this->Nu*this->De));
	
	this->De = fabs(this->De);
}

cFraction cFraction::add(const cFraction& f)
{
	cFraction res;
	
	res.Nu = this->Nu * f.De + f.Nu * this->De;
	res.De = this->De * f.De;

	return res;
}

cComparison cFraction::getComparison(const cFraction& f) const
{
	cSign sign1 = this->getSign();
	cSign sign2 = f.getSign();

	if (sign1 != sign2)
		return sign1 == cSign::NEGATIVE ? cComparison::LESS : cComparison::GREATER;
	else {
		int delta = abs(this->Nu * f.De * 1.0) - abs(f.Nu * this->De * 1.0);

		if (sign1 == cSign::NON_NEGATIVE)
			return delta == 0 ? cComparison::EQUAL : delta < 0 ? cComparison::LESS : cComparison::GREATER;
		else
			return delta == 0 ? cComparison::EQUAL : delta < 0 ? cComparison::GREATER : cComparison::LESS;
	}
}

cSign cFraction::getSign() const {
	cSign res;
	if (this->Nu * this->De < 0)
		res = cSign::NEGATIVE;
	else
		res = cSign::NON_NEGATIVE;

	return res;
}

string cFraction::getFormat() const {
	return to_string(this->Nu) + "/" + to_string(this->De);
}

void cFraction::setNu(const int& Numerator) {
	this->Nu = Numerator;
}

void cFraction::setDe(const int& Denominator) {
	this->De = Denominator;
}