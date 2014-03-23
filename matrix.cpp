#include "matrix.h"

template <class type>
matrix<type>::matrix(void)
{
	**mat = NULL;
	rows = 0;
	cols = 0;
}

template <class type>
matrix<type>::matrix(type _mat[][SIZE], int _rows, int _cols )
{
	rows = _rows;
	cols = _cols;
	
	mat = new int *[_rows];

	for (int i = 0; i < _cols; i++)
	{
		mat[i] = new int[_cols];
	}

	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _cols; j++)
		{
			mat[i][j] = _mat[i][j];
		}
	}
}

template <class type>
matrix<type>::~matrix(void)
{
	for( int i = 0 ; i < rows ; i++ )
	{
		delete [] mat[i];   
	}
	delete [] mat;
}

template <class type>
type matrix<type> :: operator( ) ( unsigned int _row, unsigned int _col )
{
	return mat[_row][_col];
}