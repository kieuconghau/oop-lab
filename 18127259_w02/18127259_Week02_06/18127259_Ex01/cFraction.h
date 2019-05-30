#ifndef cfraction_h_ex01
#define cfraction_h_ex01

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum class cSign {
	NEGATIVE,
	NON_NEGATIVE
};

enum class cComparison {
	LESS,
	EQUAL,
	GREATER
};

class cFraction
{
private:
	int Nu;
	int De;
	cSign Sign;

public:
	cFraction() = default;
	~cFraction();

	void load(ifstream& stream);
	void reduce();
	void standardize();
	cFraction add(const cFraction& f);

	cComparison getComparison(const cFraction& f) const;
	cSign getSign() const;
	string getFormat() const;

	void setNu(const int& Numerator);
	void setDe(const int& Denominator);
};

#endif