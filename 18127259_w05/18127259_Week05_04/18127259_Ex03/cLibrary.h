#pragma once

#include "cNormalReader.h"
#include "cVipReader.h"

class cLibrary
{
public:
	cLibrary();
	~cLibrary();

private:
	int N_NR, N_VR;
	cNormalReader* NRs;
	cVipReader* VRs;
};

