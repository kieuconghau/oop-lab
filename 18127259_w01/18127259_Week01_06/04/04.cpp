#include <iostream>
#include "c3Point2Ds.h"
#include "cPoint2D.h"
using namespace std;

#define SOURCE "input.txt"
#define DEST "output.txt"

int main()
{
	c3Point2Ds set;
	if (set.load(string(SOURCE)))
	{
		if (set.isTriangle())
		{
			cout << "These vertices can make a triangle." << endl;
			if (set.save(string(DEST)))
				cout << "Check " << DEST << " for more details." << endl;
			else
				cout << "\aCANNOT SAVE THE INFO OF THIS 3 POINTS." << endl;
		}
		else
		{
			cout << "These vertices can not make a triangle." << endl; 
		}
	}
	else
		cout << "\aCANNOT LOAD THIS FILE!" << endl;

	return 0;
}