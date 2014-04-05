/*
	ID Description: 		Implementation of class randomWalker
							Written by Pushpreet on 17/03/2014
	
	Version:				- 1.0.0

	Features:				- randomly chooses a direction and walks in that direction
	
	Modification Historty:  --/--/----
								- --:--

	Dependencies:			Depends On: cartesian.h
										walker.h
										matrix.h
							Used In: 	Project: markov_chains - Main.cpp

*/

#pragma once

#include <stdlib.h>
#include <iostream>
#include "walker.h"
#include "matrix.h"
#include "grid.h"

class grid;

class randomWalker :
	public walker
{
private:
	static grid space;
	static unsigned int noOfWalkers;
	const int identifier;
	matrix<float> transitionMatrix;
		
public:
	// constructors and destructors
	randomWalker ( void );
	randomWalker ( randomWalker &_randomWalker );
	randomWalker ( cartesian _position, short unsigned int _stepSize, char _heading );
	randomWalker ( cartesian _position, short unsigned int _stepSize, char _heading, matrix<float> _transitionMatrix );
	~randomWalker ( void );

	int getIdentifier( );

	cartesian step ( unsigned int _noOfSteps = 1 );
	cartesian predictStep ( randomWalker &_randomWalker, unsigned int _noOfSteps = 1 );
};

/*
	Changelog:
	
	--/--/----
		- --:-- 
	
*/