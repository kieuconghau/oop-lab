#include "cAchievement.h"

cAchievement::cAchievement()
{
	this->Mark = 0;
	this->GPA = "N/A";
}

cAchievement::~cAchievement()
{
}

float& cAchievement::getMark() {
	return this->Mark;
}

string& cAchievement::getGPA() {
	if (this->Mark >= 9)
		this->GPA = "A+";
	else if (this->Mark >= 8)
		this->GPA = "A";
	else if (this->Mark >= 7)
		this->GPA = "A-";
	else if (this->Mark >= 6)
		this->GPA = "B+";
	else if (this->Mark >= 5)
		this->GPA = "B";
	else if (this->Mark >= 4)
		this->GPA = "C+";
	else if (this->Mark >= 3)
		this->GPA = "C";
	else if (this->Mark >= 2)
		this->GPA = "D";
	else if (this->Mark >= 1)
		this->GPA = "E";
	else
		this->GPA = "F";

	return this->GPA;
}