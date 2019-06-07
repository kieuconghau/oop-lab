#pragma once

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class cFraction
{
private:
	int Nu;
	int De;

public:
	cFraction();
	cFraction(int);
	cFraction(int, int);
	cFraction(const cFraction&);

	cFraction& operator=(const cFraction&);
	cFraction operator+(const cFraction&);
	cFraction operator-(const cFraction&);
	cFraction operator*(const cFraction&);
	cFraction operator/(const cFraction&);

	cFraction operator+(int);
	cFraction operator-(int);
	cFraction operator*(int);
	cFraction operator/(int);

	friend cFraction operator+(int, const cFraction&);
	friend cFraction operator-(int, const cFraction&);
	friend cFraction operator/(int, const cFraction&);
	friend cFraction operator*(int, const cFraction&);

	cFraction& operator--();
	cFraction& operator++();
	cFraction operator--(int);
	cFraction operator++(int);

	bool operator==(const cFraction&);
	bool operator!=(const cFraction&);
	bool operator>=(const cFraction&);
	bool operator>(const cFraction&);
	bool operator<=(const cFraction&);
	bool operator<(const cFraction&);

	cFraction& operator+=(const cFraction&);
	cFraction& operator-=(const cFraction&);
	cFraction& operator*=(const cFraction&);
	cFraction& operator/=(const cFraction&);

	friend ostream& operator<<(ostream&, const cFraction&);
	
	operator float() const;

	void reduce();
	void standardize();
};