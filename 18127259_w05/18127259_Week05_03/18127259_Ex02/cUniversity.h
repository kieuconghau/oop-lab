#pragma once

#include "cFormTeacher.h"

class cUniversity
{
public:
	cUniversity();
	~cUniversity();

private:
	int N_FT, N_T;
	cFormTeacher* FTs;
	cTeacher* Ts;
};


