#include "cFraction.h"

cFraction::cFraction()
{
	this->Nu = 0;
	this->De = 1;
}

cFraction::cFraction(int numerator)
{
	this->Nu = numerator;
	this->De = 1;
}

cFraction::cFraction(int numerator, int denominator)
{
	this->Nu = numerator;
	if (denominator == 0)
		throw;
	this->De = denominator;
	this->standardize();
}

cFraction::cFraction(const cFraction& f)
{
	this->Nu = f.Nu;
	this->De = f.De;
}

cFraction& cFraction::operator=(const cFraction& f)
{
	if (this == &f)
		return *this;

	this->Nu = f.Nu;
	this->De = f.De;

	return *this;
}

cFraction cFraction::operator+(const cFraction& f)
{
	cFraction res;
	res.Nu = this->Nu * f.De + f.Nu * this->De;
	res.De = this->De * f.De;

	res.standardize();
	return res;
}

cFraction cFraction::operator-(const cFraction& f)
{
	cFraction res;
	res.Nu = this->Nu * f.De - f.Nu * this->De;
	res.De = this->De * f.De;

	res.standardize();
	return res;
}

cFraction cFraction::operator*(const cFraction& f)
{
	cFraction res;
	res.Nu = this->Nu * f.Nu;
	res.De = this->De * f.De;

	res.standardize();
	return res;
}

cFraction cFraction::operator/(const cFraction& f)
{
	cFraction res;
	res.Nu = this->Nu * f.De;
	res.De = this->De * f.Nu;

	if (res.De == 0)
		throw;

	res.standardize();
	return res;
}

cFraction cFraction::operator+(int i)
{
	cFraction f(i);
	cFraction res = *this + f;
	res.standardize();

	return res;
}

cFraction cFraction::operator-(int i)
{
	cFraction f(i);
	cFraction res = *this - f;
	res.standardize();

	return res;
}

cFraction cFraction::operator*(int i)
{
	cFraction f(i);
	cFraction res = *this * f;

	return res;
}

cFraction cFraction::operator/(int i)
{
	cFraction f(i);
	cFraction res = *this / f;

	return res;
}

cFraction& cFraction::operator--()
{
	*this = *this - 1;

	return *this;
}

cFraction& cFraction::operator++()
{
	*this = *this + 1;

	return *this;
}

cFraction cFraction::operator--(int)
{
	cFraction res = *this;
	*this = *this - 1;

	return res;
}

cFraction cFraction::operator++(int)
{
	cFraction res = *this;
	*this = *this + 1;

	return res;
}

bool cFraction::operator==(const cFraction& f)
{
	return (*this - f).Nu == 0;
}

bool cFraction::operator!=(const cFraction& f)
{
	return (*this - f).Nu != 0;
}

bool cFraction::operator>=(const cFraction& f)
{
	cFraction res = *this - f;

	return (res.Nu == 0 || res.Nu * res.De > 0);
}

bool cFraction::operator>(const cFraction& f)
{
	cFraction res = *this - f;

	return res.Nu * res.De > 0;
}

bool cFraction::operator<=(const cFraction& f)
{
	cFraction res = *this - f;

	return (res.Nu == 0 || res.Nu * res.De < 0);
}

bool cFraction::operator<(const cFraction& f)
{
	cFraction res = *this - f;

	return res.Nu * res.De < 0;
}

cFraction& cFraction::operator+=(const cFraction& f)
{
	*this = *this + f;

	return *this;
}

cFraction& cFraction::operator-=(const cFraction& f)
{
	*this = *this - f;

	return *this;
}

cFraction& cFraction::operator*=(const cFraction& f)
{
	*this = *this * f;

	return *this;
}

cFraction& cFraction::operator/=(const cFraction& f)
{
	*this = *this / f;

	return *this;
}

cFraction operator+(int i, const cFraction& f)
{
	cFraction f1(i);
	
	return f1 + f;
}

cFraction operator-(int i, const cFraction& f)
{
	cFraction f1(i);

	return f1 - f;
}

cFraction operator/(int i, const cFraction& f)
{
	cFraction f1(i);

	return f1 / f;
}

cFraction operator*(int i, const cFraction& f)
{
	cFraction f1(i);

	return f1 * f;
}

ostream& operator<<(ostream& os, const cFraction& f)
{
	os << to_string(f.Nu) + "/" + to_string(f.De);
	
	return os;
}

cFraction::operator float() const
{
	return float(this->Nu) / float(this->De);
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
		this->Nu = fabs(this->Nu) * ((this->Nu * this->De) / fabs(this->Nu * this->De));

	this->De = fabs(this->De);
}