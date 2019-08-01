#include "CFile.h"

CFile::CFile(string const name, unsigned const size) : CItem(name)
{
	this->Size = size;
}

void CFile::print(bool const show_hidden) const
{
	if (show_hidden == true && this->Hidden == true)
	{
	}
	else
	{
		CItem::print(show_hidden);
		cout << "Size: " << this->getSize() << endl;
	}
}

unsigned CFile::getSize() const
{
	return this->Size;
}

CItem* CFile::removeByName(string const name)
{
	return nullptr;
}

CItem* CFile::findByName(string const name) const
{
	return nullptr;
}

void CFile::setHidden(bool const hidden, bool const all)
{
	CItem::setHidden(hidden, all);
}
