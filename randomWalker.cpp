#include "randomWalker.h"

using namespace std;

unsigned int randomWalker :: noOfWalkers = 0;
grid randomWalker :: space( 100 );

randomWalker::randomWalker(void) : identifier( noOfWalkers + 1 )
{
	position.x = 0;
	position.y = 0;
	stepSize = 1;
	heading = NORTH;
	noOfWalkers ++;

	space.putWalker( *this, position );
}

randomWalker :: randomWalker( randomWalker &_randomWalker ) : identifier( _randomWalker.getIdentifier( ) )
{
	position = _randomWalker.position;
	stepSize = _randomWalker.stepSize;
	heading = _randomWalker.heading;
}


randomWalker::randomWalker( cartesian _position, short unsigned int _stepSize = 1, char _heading = NORTH ) : identifier( noOfWalkers + 1 )
{
	position = _position;
	stepSize = _stepSize;
	heading = _heading;
	noOfWalkers ++;

	space.putWalker( *this, position);
}

randomWalker :: randomWalker( cartesian _position, short unsigned int _stepSize, char _heading, matrix<float> _transitionMatrix ) : identifier( noOfWalkers + 1 )
{
	position = _position;
	stepSize = _stepSize;
	heading = _heading;
	noOfWalkers ++;

	space.putWalker( *this, position);

	transitionMatrix = _transitionMatrix;
}



randomWalker::~randomWalker(void)
{
}

cartesian randomWalker::step( unsigned int _noOfSteps )
{
	cartesian newPosition = position;
	
	matrix<float> positionVector = space.getPositionVector( *this );
	
	matrix<float> probableStep = positionVector * transitionMatrix;
	
	unsigned int randomStep = rand( ) % 100 + 1;
	float probabilitySet = 0;
	unsigned int i;

	for (i = 0; i < 9; i++)
	{
		probabilitySet += probableStep(0, i) * 100;

		if( randomStep < probabilitySet )
			break;
	}

	switch( i )
	{
	case 0:
		newPosition.x -= 1;
		newPosition.y -= 1;
		break;

	case 1:
		newPosition.y -= 1;
		break;

	case 2:
		newPosition.x += 1;
		newPosition.y += 1;
		break;

	case 3:
		newPosition.x -= 1;
		break;

	case 4:
		break;

	case 5:
		newPosition.x += 1;
		break;

	case 6:
		newPosition.x -= 1;
		newPosition.y += 1;
		break;

	case 7:
		newPosition.y += 1;
		break;

	case 8:
		newPosition.x += 1;
		newPosition.y += 1;
		break;
	}

	space.move( *this, newPosition );

	position = newPosition;

	return position;
}

cartesian randomWalker::predictStep( randomWalker &_randomWalker, unsigned int _noOfSteps )
{
	randomWalker temp(_randomWalker);
	return temp.step( _noOfSteps );
}

int randomWalker :: getIdentifier( )
{
	return identifier;
}
