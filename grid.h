#pragma once
#include "matrix.h"
#include "matrix.cpp"
#include "randomWalker.h"
#include "cartesian.h"

class randomWalker;

class grid :
	public matrix<int>
{
public:
	// constructors
	grid ( void );
	grid ( unsigned int _size, int _boundary = -1 );
	~grid ( void );

	// modifiers
	bool putWalker( randomWalker &_randomWalker, cartesian _position );
	bool move( randomWalker &_randomWalker, cartesian _position );

	// access
	matrix<float> getPositionVector( randomWalker &_randomWalker );
};