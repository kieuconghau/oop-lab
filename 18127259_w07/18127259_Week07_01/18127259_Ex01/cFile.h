#pragma once

#include "cItem.h"

class cFile : public cItem
{
public:
	cFile();
	cFile(string name, long size);

private:
	long ReadOnlyByte;
	long HiddenByte;
};

