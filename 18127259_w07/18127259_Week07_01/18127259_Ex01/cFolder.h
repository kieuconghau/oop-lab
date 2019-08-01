#pragma once
#include "CFile.h"

class CFolder : public CItem
{
public:
	CFolder(string const name);
	//~CFolder();

	void add(CItem* const item);

	CItem* removeByName(string const name) override;
	CItem* findByName(string const name) const override;
	void print(bool const show_hidden) const override;
	unsigned getSize() const override;
	void setHidden(bool const hidden, bool const all) override;

private:
	vector<CItem*> Items;
};
