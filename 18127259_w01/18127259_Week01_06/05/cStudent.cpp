#include "cStudent.h"

cStudent::cStudent()
{
	this->ID = "N/A";
	this->Class = "N/A";
	this->Gender = "N/A";
	this->Address = "N/A";
}

cStudent::~cStudent()
{
}

void cStudent::input()
{
	cout << "  * ID: ";
	getline(cin, this->ID);
	cout << "  * Full name: ";
	getline(cin, this->Name.getFullName());
	cout << "  * Gender: ";
	getline(cin, this->Gender);
	cout << "  * Address: ";
	getline(cin, this->Address);
	cout << "  * Mark (on scale of 10.0): ";
	cin >> this->Achievement.getMark();
	cin.ignore();
	cout << endl;
}

bool cStudent::saveToXML(const string file_name)
{
	ofstream f(file_name);

	if (!f.is_open())
		return false;
	
	f << "<Student>" << endl;
	this->printInfo(f);
	f << "</Student>" << endl;

	f.close();
	return true;
}

void cStudent::printInfo(ofstream& f)
{
	f << "<ID>" << this->getID() << "</ID>" << endl;
	f << "<Name>" << endl;
	f << "<FirstName>" << this->Name.getFirstName() << "</FirstName>" << endl;
	f << "<LastName>" << this->Name.getLastName() << "</LastName>" << endl;
	f << "</Name>" << endl;
	f << "<Class>" << this->getClass() << "</Class>" << endl;
	f << "<Address>" << this->getAddress() << "</Address>" << endl;
	f << "<Achievement>" << endl;
	f << "<Mark>" << this->Achievement.getMark() << "</Mark>" << endl;
	f << "<GPA>" << this->Achievement.getGPA() << "</GPA>" << endl;
	f << "</Achievement>" << endl;
}


Comparison cStudent::compareAchivement(cStudent& st)
{
	Comparison res;

	if (this->Achievement.getMark() == st.Achievement.getMark())
		return Comparison::EQUAL;

	else if (this->Achievement.getMark() > st.Achievement.getMark())
		return Comparison::GREATER;

	return Comparison::LESS;
}

string& cStudent::getID()
{
	return this->ID;
}

cName& cStudent::getName()
{
	return this->Name;
}

string& cStudent::getClass()
{
	this->Class = this->ID.substr(0, 2);

	return this->Class;
}

string& cStudent::getGender()
{
	return this->Gender;
}

string& cStudent::getAddress()
{
	return this->Address;
}

cAchievement& cStudent::getAchievement()
{
	return this->Achievement;
}

