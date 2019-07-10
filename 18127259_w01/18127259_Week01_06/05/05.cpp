#include <iostream>
#include "cStudentList.h"
using namespace std;

#define DEST "output.xml"

int main() {
	cStudentList list;

	list.input();

	Comparison res = list.getList()[0].compareAchivement(list.getList()[1]);
	bool state = false;
	switch (res)
	{
	case Comparison::LESS:
		state = list.getList()[1].saveToXML(string(DEST));
		break;
	case Comparison::EQUAL:
		state = list.saveToXML(string(DEST));
		break;
	case Comparison::GREATER:
		state = list.getList()[0].saveToXML(string(DEST));
		break;
	default:
		break;
	}

	if (state)
		cout << "Save succesfully." << endl;
	else
		cout << "\aSave failed." << endl;

	return 0;
}