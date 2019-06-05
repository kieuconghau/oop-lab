#include <iostream>
#include "cPoint2DArray.h"
using namespace std;

#define SOURCE "input.txt"

int main()
{
	cPoint2DArray set;

	if (set.load(string(SOURCE)))
	{
		cout << "LOAD FILE SUCCESSFULLY." << endl << endl;
		set.showArr();
		
		cPoint2D P;
		cout << endl << "Input point2d P info:" << endl;
		P.input();

		cPoint2D* res = set.findTheFarthestPoint(P);
		cout << endl << "The element in this array that the distance from it to P is longest is: " << res->getFormat() << endl;
	}
	else
		cout << "/aLOAD FILE FAILED." << endl;

	return 0;
}