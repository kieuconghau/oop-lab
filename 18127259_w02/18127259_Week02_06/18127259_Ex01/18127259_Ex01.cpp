#include <iostream>
#include <string>
#include "cFractionArray.h"
using namespace std;

#define SOURCE "input.txt"

int main()
{
	cFractionArray set;
	
	if (set.load(SOURCE))
	{
		set.show();
		cout << endl;

		set.standardize();
		set.show();
		cout << endl;

		cFraction sum = set.getSum();
		cout << "Sum of all above fractions: " << sum.getFormat() << endl << endl;

		cFraction* max_fraction = set.getMax();
		cFraction* min_fraction = set.getMin();
		cout << "Maximum fraction: " << max_fraction->getFormat() << endl;
		cout << "Minimum fraction: " << min_fraction->getFormat() << endl << endl;

		set.sortAscending();
		set.show();
		cout << endl;
	}
	else
		cout << "\aLOAD FAILED!" << endl;

	return 0;
}