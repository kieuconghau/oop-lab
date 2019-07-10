#include "cLibrary.h"

cLibrary::cLibrary()
{
	this->N_NR = 0;
	this->N_VR = 0;
	this->NRs = nullptr;
	this->VRs = nullptr;
}

cLibrary::~cLibrary()
{
	delete[] this->NRs;
	delete[] this->VRs;
}


