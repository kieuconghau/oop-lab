#include "cUniversity.h"

cUniversity::cUniversity()
{
	this->N_FT = 0;
	this->N_T = 0;
	this->FTs = nullptr;
	this->Ts = nullptr;
}

cUniversity::~cUniversity()
{
	delete[] this->FTs;
	delete[] this->Ts;
}


