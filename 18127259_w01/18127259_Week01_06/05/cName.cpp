#include "cName.h"

cName::cName()
{
	this->FirstName = "N/A";
	this->LastName = "N/A";
	this->FullName = "N/A";
}

cName::~cName()
{
}

string& cName::getFirstName() {
	char* full_name = strdup(this->FullName.c_str());
	strrev(full_name);
	char* p = strtok(full_name, " ");
	strrev(p);
	this->FirstName = p;

	return this->FirstName;
}

string& cName::getLastName() {
	char* full_name = strdup(this->FullName.c_str());
	char* p = strtok(full_name, " ");
	this->LastName = p;

	return this->LastName;
}

string& cName::getFullName() {
	return this->FullName;
}