#include <iostream>
#include "Point2D.h"

int main() {
	Point2D p1, p2;

	p1.input();
	p2.input();

	cout << "Distance from p1" << p1.getFormat() << " to p2" << p2.getFormat() << " is " << p1.calcDistance(p2) << endl;

	return 0;
}