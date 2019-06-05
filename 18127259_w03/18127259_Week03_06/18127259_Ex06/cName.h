#ifndef cname_h_ex06
#define cname_h_ex06

#pragma warning(disable : 4996)

#include <iostream>
#include <string>
using namespace std;

class cName
{
private:
	string FirstName;
	string LastName;
	string FullName;

public:
	cName();
	cName(const cName&);
	cName(string);
	~cName();

	void setFullName(const string);
	void initFirstName();
	void initLastName();
	void init();

	string getFirstName() const;
	string getLastName() const;
	string getFullName() const;
};

#endif