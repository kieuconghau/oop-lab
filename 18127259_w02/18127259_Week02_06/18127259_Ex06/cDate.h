#ifndef cdate_h_ex06
#define cdate_h_ex06

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