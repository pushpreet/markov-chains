#include"cartesian.h"

#pragma once
class walker
{
private:
	cartesian position;
	short unsigned int stepSize;
	char direction;

public:
	walker(void);
	~walker(void);

};