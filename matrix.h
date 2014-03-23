/*
	ID Description: 		Implementation of class matrix
							Written by Pushpreet on 23/03/2014
	
	Version:				- 1.0.0

	Features:				- 
	
	Modification Historty:  --/--/----
								- --:--

	Dependencies:			Depends On: 
							Used In: 	Project: markov_chains - Main.cpp

*/

#pragma once

#define SIZE 3

template <class type>				// template class to store matrices of different types
class matrix
{
private:
	type **mat;						// pointer to store the address of the 2D array
	unsigned int rows, cols;
public:
	// constructors
	matrix(void);
	matrix(type _mat[][SIZE], int _rows, int _cols = 0 );
	
	// destructors
	~matrix(void);

	type operator() ( unsigned int _row, unsigned int _col = 0 );

};

/*
	Changelog:
	
	--/--/----
		- --:-- 
	
*/