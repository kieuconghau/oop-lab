#include "Fraction.h"


Fraction::Fraction()
{
	nu = 1;
	de = 1;
}

Fraction::~Fraction()
{
}

void Fraction::input()
{
	cout << "Input info of a fraction: " << endl;
	cout << "  * Numerator: ";
	cin >> nu;
	while (true) {
		cout << "  * Denominator: ";
		cin >> de;
		if (de != 0)
			break;
		else {
			cout << "\aDENOMINATOR MUST NOT EQUAL 0." << endl;
		}
	}
	cout << endl;
}

void Fraction::reduce()
{
	int a = abs(nu), b = abs(de);
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

	nu /= GCD;
	de /= GCD;
}

void Fraction::standardize()
{
	reduce();
	if (nu != 0)
		nu = abs(nu) * ((nu*de)/abs(nu*de));
	de = abs(de);
}

Fraction Fraction::add(const Fraction& f)
{
	Fraction res;
	res.nu = nu * f.de + f.nu * de;
	res.de = de * f.de;
	
	return res;
}

string Fraction::getFormat()
{
	standardize();

	if (nu % de == 0)
		return to_string(nu / de);

	return to_string(nu) + "/" + to_string(de);
}