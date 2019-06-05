#include "cName.h"

cName::cName()
{
	this->FirstName = "No";
	this->LastName = "Name";
	this->FullName = "No Name";
}

cName::cName(const cName& name)
{
	this->FirstName = name.FirstName;
	this->LastName = name.LastName;
	this->FullName = name.FullName;
}

cName::cName(string full_name)
{
	this->FullName = full_name;
	this->initFirstName();
	this->initLastName();
}

cName::~cName()
{
}

void cName::setFullName(const string full_name)
{
	this->FullName = full_name;
}

void cName::initFirstName()
{
	char* full_name = strdup(this->FullName.c_str());
	strrev(full_name);
	char* p = strtok(full_name, " ");
	strrev(p);
	this->FirstName = p;
}

void cName::initLastName()
{
	char* full_name = strdup(this->FullName.c_str());
	char* p = strtok(full_name, " ");
	this->LastName = p;
}

void cName::init()
{
	this->initFirstName();
	this->initLastName();
}

string cName::getFirstName() const
{
	return this->FirstName;
}

string cName::getLastName() const
{
	return this->LastName;
}

string cName::getFullName() const
{
	return this->FullName;
}
