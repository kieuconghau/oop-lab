#include <iostream>
#include "cFraction.h"
using namespace std;

int main()
{
	cFraction f1, f2;					// 0/1
	cFraction f3(1, -7);				// -1/7
	cFraction f4(f3);					// Copy constructor
	cFraction f5 = f2;					// Copy constructor
	cFraction f6, f7, f8;				// Default constructor
	f6 = f3;							// Operator =

	f7 = f1 + f5;
	f8 = f2 - f4;
	f3 = f1 * f7;
	f5 = f6 / (++f2);

	if (f2 == f3)
		cout << "f2==f3" << endl;
	if (f3 != f1)
		cout << "f3!=f1" << endl;
	if (f2 >= f5)
		cout << "f2>=f5" << endl;
	if (f2 > f5)
		cout << "f2>f5" << endl;
	if (f5 <= f3)
		cout << "f5<=f3" << endl;
	if (f5 < f3)
		cout << "f5<f3" << endl;


	f1 = f2 + 3;
	f3 = -7 + f1;
	f5 = 7 * f3;
	f6 = f4 - 6;

	cout << f3 << endl;
	cout << f6 << endl;

	f1 += f5;
	f6 -= f7;
	f8 *= f1;
	f8 /= f2 + f3;

	cout << f8++ << endl;
	cout << ++f7 << endl;

	cout << f8-- << endl;
	cout << --f7 << endl;

	float f = (float)f3;				// 3/2 => 1.5
	cout << f << endl;
	cout << f3 << endl;

	return 0;
}