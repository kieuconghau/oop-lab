#include <iostream>
#include "cStudentArray.h"
using namespace std;

#define SOURCE "input.txt"
#define DEST "output.xml"

int main()
{
	cStudentArray set;
	
	if (set.load_txt(SOURCE))
	{
		set.sort();

		if (set.save_xml(DEST))
			cout << "Save successfully! Please check file " << DEST << "." << endl;
	}
	else
		cout << "\aLOAD FAILED!" << endl;

	return 0;
}