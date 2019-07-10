#ifndef _fraction_h_
#define	_fraction_h_

#include <iostream>
#include <string>
using namespace std;

class Fraction
{
private:
	int nu;
	int de;

public:
	Fraction();
	~Fraction();

	void input();
	void reduce();
	void standardize();

	Fraction add(const Fraction& f);
	
	string getFormat();
};

#endif