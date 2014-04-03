#include "matrix.h"

//using namespace std;

template <class T>
matrix<T>::matrix(void)
{

	mat = NULL;
}

template <class T>
matrix<T>::matrix(vector<T> _mat)
{
	mat.push_back( vector<T>() );

	mat[0] = _mat;
}

template <class T>
matrix<T>::matrix(vector<vector<T> > _mat)
{
	mat = _mat;
}

template <class T>
matrix<T>::~matrix(void)
{
}

template <class T>
T matrix<T> :: operator( ) ( unsigned int _row, unsigned int _col )
{
	return mat[_row][_col];
}

template <class T>
matrix<T> matrix<T> :: operator( ) ( unsigned int _row )
{
	matrix<T> rowMatrix( mat[_row] );
	
	return rowMatrix;
}

template <class T>
vector<T> matrix<T> :: getRowVector( unsigned int _row )
{
	return mat[_row];
}

template <class T>
vector<T> matrix<T> :: getColVector( unsigned int _col )
{
	vector<vector<T> > colVector( mat.size() );

	for (int i = 0; i < mat.size(); i++)
	{
		colVector[i] = mat[i][_col];
	}


}
