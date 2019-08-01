#include "CFolder.h"

CFolder::CFolder(string const name) : CItem(name) {}

//CFolder::~CFolder()
//{
//	for (int i = 0; i < this->Items.size(); ++i)
//		delete this->Items[i];
//}

void CFolder::add(CItem* const item)
{
	if (item)
		this->Items.push_back(item);
}

CItem* CFolder::removeByName(string const name)
{
	CItem* item = nullptr;
	for (size_t i = 0; i < this->Items.size(); ++i)
	{
		if (this->Items[i]->hasName(name) && this->ReadOnly == false)
		{	
			/*delete this->Items[i];
			this->Items[i] = nullptr;*/
			item = *this->Items.erase(this->Items.begin() + i);
			break;
		}
	}

	if (item == nullptr)
	{
		for (size_t i = 0; i < this->Items.size(); ++i)
		{
			item = this->Items[i]->removeByName(name);
			if (item != nullptr)
				break;
		}
	}

	return item;
}

CItem* CFolder::findByName(string const name) const
{
	CItem* item = nullptr;
	for (size_t i = 0; i < this->Items.size(); ++i)
	{
		if (this->Items[i]->hasName(name))
		{
			item = this->Items[i];
			break;
		}
	}

	if (item == nullptr)
	{
		for (size_t i = 0; i < this->Items.size(); ++i)
		{
			item = this->Items[i]->findByName(name);
			if (item != nullptr)
				break;
		}
	}

	return item;
}

void CFolder::print(bool const show_hidden) const
{
	if (show_hidden == true && this->Hidden == true)
	{
	}
	else
	{
		CItem::print(show_hidden);
		cout << "Size: " << this->getSize() << endl;
		for (size_t i = 0; i < this->Items.size(); ++i)
		{
			this->Items[i]->print(show_hidden);
		}
	}
}

unsigned CFolder::getSize() const
{
	unsigned res = 0;
	for (int i = 0; i < this->Items.size(); ++i)
	{
		res += this->Items[i]->getSize();
	}

	return res;
}

void CFolder::setHidden(bool const hidden, bool const all)
{
	if (all == true)
	{
		for (size_t i = 0; i < this->Items.size(); ++i)
		{
			this->Items[i]->setHidden(hidden, all);
		}

		CItem::setHidden(hidden, all);
	}
	else
		CItem::setHidden(hidden, all);
}
