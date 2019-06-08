#pragma once
#pragma warning(disable:4996)

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

#define MIN_YEAR 1

class Date
{
public:
	Date();
	Date(const Date&);
	Date(int, int, int);
	Date(int, int);
	Date(int);

	bool isValid();

	Date Tomorrow();
	Date Yesterday();
	int getDayLimit_Month() const;
	int getDaysOfThisYear() const;

	bool operator==(const Date&);
	bool operator!=(const Date&);
	bool operator>=(const Date&);
	bool operator<=(const Date&);
	bool operator>(const Date&);
	bool operator<(const Date&);

	friend istream& operator>>(istream&, Date&);
	friend ostream& operator<<(ostream&, const Date&);

	operator int() const;
	operator long() const;
	int getDistance(const Date& date) const;

	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);

	Date operator+(const int);
	Date operator-(const int);

	Date& operator+=(const int);
	Date& operator-=(const int);
	Date& operator=(const Date&);

private:
	int Day;
	int Month;
	int Year;
};

