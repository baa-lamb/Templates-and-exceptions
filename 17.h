#include <cstdio>
#include <iostream>
//#include "classPOINT.h"

using namespace std;

template <typename T>
class Matrix
{
private:
	size_t row;
	size_t column;
	T **matrix;

public: 
	Matrix (size_t row1, size_t column1);           
	Matrix (const Matrix & b); 
	~Matrix ();

	void set(size_t row, size_t column, T value);
	T get(size_t row, size_t column);

	Matrix & operator = (const Matrix & b);
	
	Matrix sum(const Matrix &b);
	void set_line(T value, size_t number);

	void print();
};

#include "metods.h"
