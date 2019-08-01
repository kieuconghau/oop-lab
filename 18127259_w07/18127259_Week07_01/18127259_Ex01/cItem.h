#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CItem
{
public:
	CItem(string const name);
	virtual ~CItem();
	virtual void print(bool const show_hidden) const;
	virtual unsigned getSize() const = 0;
	virtual CItem* removeByName(string const name) = 0;
	virtual CItem* findByName(string const name) const = 0;
	virtual void setHidden(bool const hidden, bool const all);

	bool hasName(string const name) const;

protected:
	string Name;
	bool Hidden;
	bool ReadOnly;
};
