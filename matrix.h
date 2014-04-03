/*
	ID Description: 		Implementation of class matrix
							Written by Pushpreet on 23/03/2014
	
	Version:				- 1.0.0

	Features:				- 
	
	Modification Historty:  --/--/----
								- --:--

	Dependencies:			Depends On: class vector
							Used In: 	Project: markov_chains - Main.cpp

*/

#pragma once

#include <vector>

using namespace std;

template <class T>				// template class to store matrices of different types
class matrix
{
private:
	vector<vector<T> > mat;						// pointer to store the address of the 2D array
public:
	// constructors
	matrix(void);
	matrix(vector<T> _mat);
	matrix(vector<vector<T> > _mat);
	
	// destructors
	~matrix(void);

	// access functions
	matrix<T> operator( ) ( unsigned int _row );
	T operator( ) ( unsigned int _row, unsigned int _col );
	
	vector<T> getRowVector( unsigned int _row );
	vector<T> getColVector( unsigned int _col );

	matrix<T> getRow( unsigned int _row );
	matrix<T> getCol( unsigned int _col );
};

/*
	Changelog:
	
	03/04/2014
		- 01:26 changed storage of matrix from 2D array to 2D vector
	
*/