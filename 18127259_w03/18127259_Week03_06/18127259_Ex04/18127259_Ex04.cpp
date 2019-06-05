#include <iostream>
#include "cDate.h"
using namespace std;

int main()
{
	cDate today,
		yesterday,
		tomorrow;

	cout << "Input a date:" << endl;
	today.input();

	yesterday = today.getYesterday();
	tomorrow = today.getTomorrow();

	cout << "  * Today: " << today.getFormat() << endl;
	cout << "  * Yesterday: " << yesterday.getFormat() << endl;
	cout << "  * Tomorrow: " << tomorrow.getFormat() << endl;

	return 0;
}