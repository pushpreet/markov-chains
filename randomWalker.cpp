#include "randomWalker.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

randomWalker::randomWalker(void)
{
	position.x = 0;
	position.y = 0;
	position.z = 0;
	stepSize = 1;
	heading = NORTH;
}

randomWalker::randomWalker( cartesian _position, short unsigned int _stepSize = 1, char _heading = NORTH )
{
	position = _position;
	stepSize = _stepSize;
	heading = _heading;
}


randomWalker::~randomWalker(void)
{
}

cartesian randomWalker::step( unsigned int _noOfSteps )
{
	int direction;
	
	for (unsigned int i = 0; i < _noOfSteps; i++)
	{
		if( THREEDIMENSIONAL )
			direction = rand() % 6;
		else
			direction = rand() % 4;
	}

	return walker::step( _noOfSteps, direction );
}

cartesian randomWalker::predictStep( randomWalker &_randomWalker, unsigned int _noOfSteps )
{
	randomWalker temp(_randomWalker);
	return temp.step( _noOfSteps );
}