#ifndef ctime_h
#define ctime_h

#include <iostream>
#include <string>
using namespace std;

class cTime
{
private:
	int Hour;
	int Min;
	int Sec;

public:
	bool isValid();
	void input();
	void change(const int);
	string getFormat() const;
};

#endif