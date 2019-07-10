#ifndef _student_h_
#define _student_h_

#include <iostream>
#include <fstream>
#include <string>
#include "cAchievement.h"
#include "cName.h"
using namespace std;

enum class Comparison
{
	LESS,
	EQUAL,
	GREATER
};

class cStudent
{
private:
	string ID;
	cName Name;
	string Class;
	string Gender;
	string Address;
	cAchievement Achievement;

public:
	cStudent();
	~cStudent();

	void input();
	bool saveToXML(const string file_name);
	void printInfo(ofstream& f);
	Comparison compareAchivement(cStudent& st);

	string& getID();
	cName& getName();
	string& getClass();
	string& getGender();
	string& getAddress();
	cAchievement& getAchievement();
};

#endif