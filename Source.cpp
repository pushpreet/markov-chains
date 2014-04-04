#include <iostream>
#include "randomWalker.h"
#include <time.h>
#include <stdlib.h>
#include "matrix.h"
#include "matrix.cpp"
#include "markovMatrix.h"
#include "markovMatrix.cpp"

using namespace std;

int main( )
{
	matrix<int> test( 1, 3),test1( 1, 3),add( 3, 3);

	cout<<endl;

	for (int i = 0; i < test.numRows( ); i++)
	{
		for (int j = 0; j < test.numCols( ); j++)
		{
			test(i,j) = i*j;
			test1(i,j) = i+j;
		}

		cout<<endl;
	}

	add = test + test1;

	add.addRow( );
	add.addRow( );
	add.addCol( );
	
	
	for (int i = 0; i < add.numRows( ); i++)
	{
		for (int j = 0; j < add.numCols( ); j++)
		{
			cout<< add(i,j)<<" ";
		}

		cout<<endl;
	}

	getchar( );
	return 0;
}