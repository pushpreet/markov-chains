/*
	ID Description: 		Implementation of class randomWalker
							Written by Pushpreet on 17/03/2014
	
	Version:				- 1.0.0

	Features:				- randomly chooses a direction and walks in that direction
	
	Modification Historty:  --/--/----
								- --:--

	Dependencies:			Depends On: cartesian.h
										walker.h
							Used In: 	Project: markov_chains - Main.cpp

*/

#pragma once

#include "walker.h"

#define THREEDIMENSIONAL 0

class randomWalker :
	public walker
{
public:
	// constructors and destructors
	randomWalker(void);
	randomWalker::randomWalker( cartesian _position, short unsigned int _stepSize, char _heading );
	~randomWalker(void);

	cartesian step( unsigned int _noOfSteps = 1 );
	cartesian predictStep( randomWalker &_ramdomWalker, unsigned int _noOfSteps = 1 );
};

/*
	Changelog:
	
	--/--/----
		- --:-- 
	
*/