#include "Fraction.h"

Fraction::Fraction()
{
	this->nu = 1;
	this->de = 1;
	this->sign = Sign::NOT_AVAILABLE;
}

Fraction::~Fraction()
{
}

Comparison Fraction::getComparison(const Fraction& f) const
{
	Sign sign1 = this->getSign();
	Sign sign2 = f.getSign();

	if (sign1 != sign2)
		return sign1 == Sign::NEGATIVE ? Comparison::LESS : Comparison::GREATER;
	else {
		int delta = abs(this->nu * f.de) - abs(f.nu * this->de);

		if (sign1 == Sign::NON_NEGATIVE)
			return delta == 0 ? Comparison::EQUAL : delta < 0 ? Comparison::LESS : Comparison::GREATER;
		else
			return delta == 0 ? Comparison::EQUAL : delta < 0 ? Comparison::GREATER : Comparison::LESS;
	}
}

Sign Fraction::getSign() const {
	Sign res;
	if (this->nu * this->de < 0)
		res = Sign::NEGATIVE;
	else
		res = Sign::NON_NEGATIVE;

	return res;
}

string Fraction::getFormat() const {
	return to_string(this->nu) + "/" + to_string(this->de);
}

void Fraction::setNu(const int Numerator) {
	this->nu = Numerator;
}

void Fraction::setDe(const int Denominator) {
	this->de = Denominator;
}