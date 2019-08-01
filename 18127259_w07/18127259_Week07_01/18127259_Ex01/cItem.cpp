#include "CItem.h"

CItem::CItem(string const name)
{
	this->Name = name;
	this->Hidden = false;
	this->ReadOnly = false;
}

CItem::~CItem() {}

void CItem::print(bool const show_hidden) const
{
	cout << "Name: " << this->Name << endl;
	cout << "Hidden: " << this->Hidden << endl;
	cout << "Read Only: " << this->ReadOnly << endl;
}

void CItem::setHidden(bool const hidden, bool const all)
{
	this->Hidden = hidden;
}

bool CItem::hasName(string const name) const
{
	return this->Name == name;
}

