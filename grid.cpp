#include "grid.h"


grid::grid ( void )
{
}

grid :: grid ( unsigned int _size, int _boundary )
{
	for (unsigned int i = 0; i < _size; i++)
	{
		mat.push_back( vector<int>( ) );

		for (unsigned int j = 0; j < _size; j++)
		{
			if ( ( i == 0 ) || ( j == 0 ) || ( i == _size-1 ) || ( j == _size-1 ) ) 
				mat[i].push_back( _boundary );
			else
				mat[i].push_back( 0 );
		}
	}
}


grid::~grid ( void )
{
}


bool grid :: move( randomWalker &_randomWalker, cartesian _position )
{
	cartesian position = _randomWalker.getPosition( );

	if( ( mat[position.x][position.y] == _randomWalker.getIdentifier( ) )
		&& ( ( mat[_position.x][_position.y] == 0 ) || ( mat[_position.x][_position.y] == _randomWalker.getIdentifier( ) ) ) )
	{
		mat[position.x][position.y] = 0;
		mat[_position.x][_position.y] = _randomWalker.getIdentifier( );
		return true;
	}

	
	cerr<< "Cannot put walker here";
	return false;
}

bool grid :: putWalker( randomWalker &_randomWalker, cartesian _position )
{
	if( mat[_position.x][_position.y] == 0 )
	{
		mat[_position.x][_position.y] = _randomWalker.getIdentifier( );
		return true;
	}
	
	cerr<< "Cannot put walker here";
	return false;
}

matrix<float> grid :: getPositionVector( randomWalker &_randomWalker )
{
	cartesian position = _randomWalker.getPosition( );
	matrix<float> positionVector( 1, 9 );

	unsigned int immediateObstacles = 0;

	for (unsigned int i = (position.x - 1); i < 3; i++)
	{
		for (unsigned int j = (position.y - 1); j < 3; j++)
		{
			if( ( mat[i][j] != 0 ) && ( i != j ) && ( i+j != 2 ) )
				immediateObstacles++;
		}
	}

	switch( immediateObstacles )
	{
	case 0:
		positionVector(0, 4) = 1;
		break;

	case 1:
		if( mat[position.x-1][position.y] != 0 )
			positionVector(0, 3) = 1;
		
		else if( mat[position.x][position.y-1] != 0 )
			positionVector(0, 1) = 1;
		
		else if( mat[position.x+1][position.y] != 0 )
			positionVector(0, 5) = 1;
		
		else if( mat[position.x][position.y+1] != 0 )
			positionVector(0, 7) = 1;

		break;

	case 2:
	case 3:
		if( ( mat[position.x-1][position.y] != 0 ) && ( mat[position.x][position.y-1] != 0 ) )
			positionVector(0, 0) = 1;
		
		else if( ( mat[position.x+1][position.y] != 0 ) && ( mat[position.x][position.y-1] != 0 ) )
			positionVector(0, 2) = 1;
		
		else if( ( mat[position.x+1][position.y] != 0 ) && ( mat[position.x][position.y+1] != 0 ) )
			positionVector(0, 8) = 1;
		
		else if( ( mat[position.x-1][position.y] != 0 ) && ( mat[position.x][position.y+1] != 0 ) )
			positionVector(0, 6) = 1;

		break;
	}

	return positionVector;
}
