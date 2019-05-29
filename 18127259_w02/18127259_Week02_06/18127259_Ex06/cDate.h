#ifndef cdate_h
#define cdate_h

#include <iostream>
#include <string>
using namespace std;

class cDate
{
private:
	string Day;
	string Month;
	string Year;
	string Format;

public:
	void setDate(const string date);
	void init();
	string getFormat() const;
};

#endif