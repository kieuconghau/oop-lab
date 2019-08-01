#pragma once
#include "CItem.h"

class CFile : public CItem
{
public:
	CFile(string const name, unsigned const size);
	void print(bool const show_hidden) const override;
	unsigned getSize() const override;
	CItem* removeByName(string const name) override;
	CItem* findByName(string const name) const override;
	void setHidden(bool const hidden, bool const all) override;

private:
	unsigned Size;
};


