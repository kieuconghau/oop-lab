#ifndef _name_h_
#define _name_h_

#pragma warning(disable:4996)

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
	~cName();

	string& getFirstName();
	string& getLastName();
	string& getFullName();
};

#endif