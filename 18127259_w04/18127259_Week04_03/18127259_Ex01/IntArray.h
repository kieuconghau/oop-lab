#ifndef intarray_h
#define intarray_h

#include <iostream>
#include <fstream>
using namespace std;

class IntArray
{
private:
	int* Arr;
	int N;

public:
	IntArray();
	IntArray(int);
	IntArray(int*, int);
	IntArray(const IntArray&);
	~IntArray();

	IntArray& operator=(const IntArray&);

	friend istream& operator>>(istream&, IntArray&);
	friend ostream& operator<<(ostream&, const IntArray&);

	int& operator[](int);

	operator int() const;
};

#endif