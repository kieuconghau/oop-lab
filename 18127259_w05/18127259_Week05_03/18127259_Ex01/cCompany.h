#pragma once

#include "cDailyWorker.h"
#include "cProductionEmployee.h"

class cCompany
{
public:
	cCompany();
	~cCompany();

private:
	int N_PE, N_DW;
	cProductionEmployee* PEs;
	cDailyWorker* DWs;
};

