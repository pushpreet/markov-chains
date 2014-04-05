#include <iostream>
#include "randomWalker.h"
#include <time.h>
#include <stdlib.h>
#include "matrix.h"
#include "grid.h"

using namespace std;

int main( )
{
	cartesian walkerPos, walker2Pos;
	walkerPos.x = 50;
	walkerPos.y = 50;

	walker2Pos.x = 60;
	walker2Pos.y = 60;


	matrix<float> transitionMatrix;

	srand( time(NULL) );
	
	float values[81] = {0.33, 0.33,    0, 0.33,    0,    0,    0,    0,    0,
						0.25, 0.25, 0.25,    0, 0.25,    0,    0,    0,    0,
						   0, 0.33, 0.33,    0,    0, 0.33,    0,    0,    0,
						0.25,    0,    0, 0.25, 0.25,    0, 0.25,    0,    0,
						   0, 0.2,     0,  0.2,  0.2,  0.2,    0,  0.2,    0,
						   0,    0, 0.25,    0,	0.25, 0.25,    0,    0, 0.25,
						   0,    0,    0, 0.33,    0,    0, 0.33, 0.33,    0,
						   0,    0,    0,    0, 0.25,    0, 0.25, 0.25, 0.25,
						   0,    0,    0,    0,    0, 0.33,    0, 0.33, 0.33};

	transitionMatrix.assign( 9, 9, values );

	randomWalker test( walkerPos, 1, NORTH, transitionMatrix ), test2(walker2Pos, 1, NORTH, transitionMatrix);

	for (int i = 0; i < 10; i++)
	{
		walkerPos = test.predictStep( test2 );

		cout<<walkerPos.x<<" "<<walkerPos.y<<endl;
	}
	
	getchar( );
	return 0;
}