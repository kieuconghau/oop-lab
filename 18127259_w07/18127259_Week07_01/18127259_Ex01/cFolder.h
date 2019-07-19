#pragma once

#include "cItem.h"

class cFolder : public cItem
{
public:
	cFolder();
	cFolder(string name);
	~cFolder();

	void add(cItem* item);
	void print(bool type);	// Sub-files: 1, Folders: 0
	cItem* removeByName(string itemName);
	cItem* findByName(string itemName);
	void setHidden(bool, bool);

private:
	vector<cItem*> Items;
};

