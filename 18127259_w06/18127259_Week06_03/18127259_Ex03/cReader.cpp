#include "cReader.h"

cReader::cReader(cReader::ecType type)
{
	this->ID = "N/A";
	this->FullName = "N/A";
	this->Sex = ecSex::NONE;
	this->Type = type;
}

cReader::cReader(const cReader& reader)
{
	*this = reader;
}

cReader::cReader(string id, string fullName, int day, int month, int year, ecSex sex, cReader::ecType type)
	: ExpirationDate(day, month, year)
{
	this->ID = id;
	this->FullName = fullName;
	this->Sex = sex;
	this->Type = type;
}

cReader::cReader(string id, string fullName, int day, int month, int year, cReader::ecType type)
	: ExpirationDate(day, month, year)
{
	this->ID = id;
	this->FullName = fullName;
	this->Sex = ecSex::NONE;
	this->Type = type;
}

cReader::cReader(string id, string fullName, cReader::ecType type)
{
	this->ID = id;
	this->FullName = fullName;
	this->Sex = ecSex::NONE;
	this->Type = type;
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

bool cReader::has_id(string id)
{
	return this->ID == id;
}

bool cReader::has_full_name(string fullName)
{
	return this->FullName == fullName;
}

bool cReader::has_type(cReader::ecType type)
{
	return this->Type == type;
}

bool cReader::has_expiration_date_in_year(int year)
{
	return this->ExpirationDate.is_in_year(year);
}
