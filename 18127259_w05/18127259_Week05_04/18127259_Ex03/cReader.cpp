#include "cReader.h"

cReader::cReader()
{
	this->ID = "N/A";
	this->FullName = "N/A";
	this->Sex = ecSex::NONE;
}

cReader::cReader(const cReader& reader)
{
	*this = reader;
}

cReader::cReader(string id, string fullName, int day, int month, int year, ecSex sex)
	: ExpirationDate(day, month, year)
{
	this->ID = id;
	this->FullName = fullName;
	this->Sex = sex;
}

cReader::cReader(string id, string fullName, int day, int month, int year)
	: ExpirationDate(day, month, year)
{
	this->ID = id;
	this->FullName = fullName;
	this->Sex = ecSex::NONE;
}

cReader::cReader(string id, string fullName)
{
	this->ID = id;
	this->FullName = fullName;
	this->Sex = ecSex::NONE;
}

void cReader::input_info()
{
	cout << "Input basic info:" << endl;
	cout << "  * ID: ";
	getline(cin, this->ID);
	cout << "  * Full Name: ";
	getline(cin, this->FullName);
	cout << "  * Expiration date: ";
	this->ExpirationDate.input();
	cout << "  * Sex (1. Male, 2.Female, 3. None): ";
	int opt;
	cin >> opt;
	switch (opt)
	{
	case 1:
		this->Sex = ecSex::MALE;
		break;
	case 2:
		this->Sex = ecSex::FEMALE;
		break;
	default:
		this->Sex = ecSex::NONE;
		break;
	}
}

void cReader::show_info()
{
	cout << "Basic info:" << endl;
	cout << "  * ID: " << this->ID << endl;
	cout << "  * Full Name: " << this->FullName << endl;
	cout << "  * Expiration Date: " << this->ExpirationDate.getFormat() << endl;
	cout << "  * Sex: ";
	switch (this->Sex)
	{
	case ecSex::MALE:
		cout << "Male" << endl;
		break;
	case ecSex::FEMALE:
		cout << "Female" << endl;
		break;
	case ecSex::NONE:
		cout << "None" << endl;
		break;
	default:
		break;
	}
}
