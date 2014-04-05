#include "walker.h"

walker::walker(void)
{
	position.x = 0;
	position.y = 0;
	stepSize = 1;
	heading = NORTH;
}

walker::walker( cartesian _position, short unsigned int _stepSize, char _heading )
{
	position = _position;
	stepSize = _stepSize;
	heading = _heading;
}

walker::~walker(void)
{
}

cartesian walker::step( unsigned int _noOfSteps )
{
	switch( heading )
	{
		case NORTH:
			position.x += stepSize * _noOfSteps;
			break;
		case SOUTH:
			position.x -= stepSize * _noOfSteps;
			break;
		case EAST:
			position.y += stepSize * _noOfSteps;
			break;
		case WEST:
			position.y -= stepSize * _noOfSteps;
			break;

		default:
			//TODO:Exception Handling
			;
	}

	return position;
}

cartesian walker::step( unsigned int _noOfSteps, char _direction )
{
	heading = _direction;
	switch( heading )
	{
		case NORTH:
			position.x += stepSize * _noOfSteps;
			break;
		case SOUTH:
			position.x -= stepSize * _noOfSteps;
			break;
		case EAST:
			position.y += stepSize * _noOfSteps;
			break;
		case WEST:
			position.y -= stepSize * _noOfSteps;
			break;

		default:
			//TODO:Exception Handling
			;
	}

	return position;
}

cartesian walker::getPosition( )
{
	return position;
}