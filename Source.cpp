#include <iostream>
#include "randomWalker.h"
#include <time.h>
#include <stdlib.h>
#include "matrix.h"

using namespace std;

int main( )
{
	int data[3][3];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			data[i][j] = i;
		}
	}

	return 1;
}