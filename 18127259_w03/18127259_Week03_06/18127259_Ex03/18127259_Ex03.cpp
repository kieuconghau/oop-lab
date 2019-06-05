#include <iostream>
#include "cTriangleArray.h"
using namespace std;

#define SOURCE "input.txt"

int main()
{
	cTriangleArray set;

	if (set.load(SOURCE))
	{
		cout << "Load successfully!" << endl;
		set.classify();
		set.showInfo();
		cout << endl;

		cout << "Removed all invalid triangles" << endl;
		set.removeAllInvalidTriangles();
		set.showInfo();
		cout << endl;
	}
	else
		cout << "\aLOAD FAILED!" << endl;


	return 0;
}