/*
	ID Description: 		Implementation of class walker
							Written by Pushpreet on 17/03/2014
	
	Version:				- 1.0.0

	Features:				- stores the position, direction and step size of the walker
	
	Modification Historty:  --/--/----
								- --:--

	Dependencies:			Depends On: cartesian.h
							Used In: 	Project: markov_chains - Main.cpp

*/

#pragma once

#include"cartesian.h"

#define NORTH	0
#define SOUTH	1
#define EAST	2
#define WEST	3

class walker
{
protected:
	cartesian position;				// structure to store current position of the walker
	short unsigned int stepSize;	// size of step to take at once
	char heading;					// direction in which the walker is heading / looking

public:
	// constructors and destructors
	walker ( void );
	walker ( cartesian _position, short unsigned int _stepSize = 1, char _heading = NORTH );
	~walker ( void );

	cartesian step ( unsigned int _noOfSteps = 1 );
	cartesian step ( unsigned int _noOfSteps, char _direction );

	cartesian getPosition ( );
};

/*
	Changelog:
	
	--/--/----
		- --:-- 
	
*/