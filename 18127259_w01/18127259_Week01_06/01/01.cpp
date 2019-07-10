#include <iostream>
#include "Fraction.h"

int main() {
	Fraction f1, f2, sum;
	
	f1.input();
	f2.input();

	sum = f1.add(f2);

	cout << f1.getFormat() << " + " << f2.getFormat() << " = " << sum.getFormat() << endl;

	return 0;
}