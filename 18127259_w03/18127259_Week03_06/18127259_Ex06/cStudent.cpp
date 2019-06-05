#include "cStudent.h"

cStudent::cStudent()
{
	this->No = 0;
	this->ID = "N/A";
	this->Name.setFullName("N/A");
	this->Address = "N/A";
	this->DoB.setDate("01/01/1700");
	this->Mark = 0;
}

cStudent::cStudent(const cStudent& st)
{
	this->No = st.No;
	this->ID = st.ID;
	this->Name = st.Name;
	this->Address = st.Address;
	this->DoB = st.DoB;
	this->Mark = st.Mark;
}

cStudent::cStudent(int no, string id, string full_name, string address, string dob, float mark)
{
	this->No = no;
	this->ID = id;
	this->Name.setFullName(full_name);
	this->Name.initFirstName();
	this->Name.initLastName();
	this->Address = address;
	this->DoB.setDate(dob);
	this->DoB.init();
	this->Mark = mark;
}

cStudent::~cStudent()
{
}

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

