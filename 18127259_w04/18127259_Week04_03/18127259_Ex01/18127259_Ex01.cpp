#include <iostream>
#include "IntArray.h"
using namespace std;

int main()
{
	IntArray m1;
	IntArray m2(7);
	int a[100];
	int n = 7;
	for (int i = 0; i < n; i++)
	{
		a[i] = i * 2 / 7;
	}
	IntArray m3(a, n);
	IntArray m4(m2);
	IntArray m5;
	m5 = m2;

	cin >> m2;
	cout << m2 << endl;

	cout << m3[6] << endl;
	m3[6] = 1;

	cout << (int)m4 << endl;

	return 0;
}