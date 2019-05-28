#include <iostream>
#include "cTime.h"
using namespace std;

int main()
{
	cTime time;

	cout << "Input a time: " << endl;
	time.input();
	cout << time.getFormat() << endl;

	int sec_change[] = { 1, -1, 2, 5, 86399, -25, 51 };
	for (int i = 0; i < sizeof(sec_change) / sizeof(sec_change[0]); i++)
	{
		time.change(sec_change[i]);
		cout << (sec_change[i] >= 0 ? "Increase " : "Decrease ") << to_string(abs(sec_change[i])) << " seconds: " << time.getFormat() << endl;
	}

	return 0;
}