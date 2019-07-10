#ifndef _achievement_h_
#define _achievement_h_

#include <iostream>
using namespace std;

class cAchievement
{
private:
	float Mark;
	string GPA;

public:
	cAchievement();
	~cAchievement();

	float& getMark();
	string& getGPA();
};

#endif