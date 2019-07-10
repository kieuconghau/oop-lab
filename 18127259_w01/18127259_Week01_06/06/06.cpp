#include <iostream>
#include "cDate.h"
using namespace std;

int main() {
	cDate another_date, current_date;

	another_date.input();
	current_date.getCurrentDate();

	cout << "The distance between " << current_date.getFormat() << " (now)"<< " and " << another_date.getFormat() << " is " << current_date.getDistnace(another_date) << " days." << endl;
	
	return 0;
}