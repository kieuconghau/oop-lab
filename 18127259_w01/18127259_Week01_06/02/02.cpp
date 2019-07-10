#include <iostream>
#include "Fraction.h"
#include "FractionList.h"

using namespace std;

#define SOURCE "input.txt"

int main() {
	FractionList FL;

	if (FL.load(string(SOURCE))) {
		Comparison res = FL.getList()[0].getComparison(FL.getList()[1]);
		switch (res)
		{
		case Comparison::LESS:
			cout << FL.getList()[0].getFormat() << " < " << FL.getList()[1].getFormat();
			break;
		case Comparison::EQUAL:
			cout << FL.getList()[0].getFormat() << " = " << FL.getList()[1].getFormat();
			break;
		case Comparison::GREATER:
			cout << FL.getList()[0].getFormat() << " > " << FL.getList()[1].getFormat();
			break;
		default:
			break;
		}
	}
	else
		cout << "\aCANNOT LOAD FILE " << string(SOURCE) << "." << endl <<
				"Please check this file again!" << endl;

	return 0;
}