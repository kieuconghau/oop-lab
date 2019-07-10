#ifndef _fraction_h
#define _fraction_h

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum class Sign {
	NEGATIVE,
	NON_NEGATIVE,
	NOT_AVAILABLE
};

enum class Comparison {
	LESS,
	EQUAL,
	GREATER
};

class Fraction
{
private:
	int nu;
	int de;
	Sign sign;

public:
	Fraction();
	~Fraction();

	Comparison getComparison(const Fraction& f) const;
	Sign getSign() const;
	string getFormat() const;

	void setNu(const int Numerator);
	void setDe(const int Denominator);
};

#endif