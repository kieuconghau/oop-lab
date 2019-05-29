#include "cStudent.h"

void cStudent::load_txt(ifstream& stream)
{
	string temp;
	getline(stream, this->ID, ';');
	
	getline(stream, temp, ';');
	this->Name.setFullName(temp);
	this->Name.init();
	
	getline(stream, this->Address, ';');
	
	getline(stream, temp, ';');
	this->DoB.setDate(temp);
	this->DoB.init();

	stream >> this->Mark;
	stream.seekg(2, ios::cur);
}

void cStudent::save_xml(ofstream& stream)
{
	stream << "<Student" << to_string(this->No) << ">" << endl;
	stream << "<ID>" << this->ID << "</ID>" << endl;
	stream << "<Name>" << endl;
	stream << "<FullName>" << this->Name.getFullName() << "</FullName>" << endl;
	stream << "<FirstName>" << this->Name.getFirstName() << "</FirstName>" << endl;
	stream << "<LastName>" << this->Name.getLastName() << "</LastName>" << endl;
	stream << "</Name>" << endl;
	stream << "<Address>" << this->Address << "</Address>" << endl;
	stream << "<DoB>" << this->DoB.getFormat() << "</DoB>" << endl;
	stream << "<Mark>" << this->Mark << "</Mark>" << endl;
	stream << "</Student" << to_string(this->No) << ">" << endl;
}

void cStudent::setNo(int number)
{
	this->No = number;
}

int cStudent::compare(const cStudent& student)
{
	if (this->Name.getLastName().compare(student.Name.getLastName()) == 0)
		return this->Name.getFirstName().compare(student.Name.getFirstName());

	return this->Name.getLastName().compare(student.Name.getLastName());
}

void cStudent::swap(cStudent& student)
{
	cStudent temp = *this;
	*this = student;
	student = temp;
}

