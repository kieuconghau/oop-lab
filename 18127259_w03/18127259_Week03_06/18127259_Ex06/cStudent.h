#ifndef cstudent_h_ex06
#define cstudent_h_ex06

#include <iostream>
#include <string>
#include <fstream>
#include "cName.h"
#include "cDate.h"
using namespace std;

class cStudent
{
private:
	int No;
	string ID;
	cName Name;
	string Address;
	cDate DoB;
	float Mark;

public:
	cStudent();
	cStudent(const cStudent&);
	cStudent(int, string, string, string, string, float);
	~cStudent();

	void load_txt(ifstream&);
	void save_xml(ofstream&);
	void setNo(int);
	int compare(const cStudent&);
	void swap(cStudent&);
};

#endif