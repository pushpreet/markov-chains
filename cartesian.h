/*
	ID Description: 		Definition of structure cartesian
							Written by Pushpreet on 05/10/2013
	
	Version:				- 1.1.0

	Features:				- stores the position as co-ordinates of a point in a 3D plane
								
	Modification Historty:  - stores the position in a 3D plane
	
	Dependencies:			Depends On: NULL
							Used In: 	Project: - walker.h

*/

#ifndef _cartesian_h
#define _cartesian_h

struct cartesian		// structure to hold position as cartesian co-ordinates
{
	int x;		// x-co-ordinate
    int y;		// y-co-ordinate
};

#endif

/*
	Changelog:
	
	18/09/2013
		- 09:56 added z co-ordinate
*/