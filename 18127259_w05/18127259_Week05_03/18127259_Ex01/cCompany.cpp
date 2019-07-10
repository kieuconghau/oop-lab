#include "cCompany.h"

cCompany::cCompany()
{
	this->N_DW = 0;
	this->N_PE = 0;
	this->PEs = nullptr;
	this->DWs = nullptr;
}

cCompany::~cCompany()
{
	delete[] this->PEs;
	delete[] this->DWs;
}


