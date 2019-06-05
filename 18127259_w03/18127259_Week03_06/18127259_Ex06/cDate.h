#ifndef cdate_h_ex06
#define cdate_h_ex06

#include <iostream>
#include <string>
using namespace std;

#define MIN_YEAR 1700
#define MAX_YEAR 9998

class cDate
{
private:
	string Day;
	string Month;
	string Year;
	string Format;

public:
	cDate();
	cDate(const cDate&);
	cDate(string, string, string);
	~cDate();

	void setDate(const string date);
	void init();
	string getFormat() const;
	bool isValid();
};

#endif