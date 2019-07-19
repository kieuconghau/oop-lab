#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class cItem
{
public:
	cItem();
	cItem(string name);
	cItem(string name, long size);

	virtual void setHidden(bool, bool);
	virtual void print(bool type);

private:

protected:
	string Name;
	long Size;
	bool Hidden;
};

