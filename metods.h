template <typename T>
Matrix<T>::Matrix(size_t row1, size_t column1)
{
	row = row1;
	column = column1;

	matrix = new T*[row];
	for (size_t i = 0;  i < row; i++)
		matrix[i] = new T[column];
}

template <typename T>
Matrix<T>::~Matrix()
{
	 for (size_t i = 0; i < row; i++)
        delete [] matrix[i];
}

template <typename T>
Matrix<T>::Matrix (const Matrix & b)
{
	row = b.row;
	column = b.column;
	
	matrix = new T*[row];
	for (size_t i = 0; i < row; i++)
		matrix[i] = new T[column];
	
	for(size_t i = 0; i < row; i++)
		for(size_t j = 0; j < column; j++)
			matrix[i][j] = b.matrix[i][j];
}

template <typename T>
void Matrix<T>::set(size_t row1, size_t column1, T value)
{
	if((row1 >= row)||(column1 >= column))
		throw "\nThink! In c++ numbering starts with the 0th element.\nPut the value < row or < column\n";
	matrix[row1][column1] = value;	
}

template <typename T>
T Matrix<T>::get(size_t row1, size_t column1)
{	
	if((row1 >= row)||(column1 >= column))
		throw "\nThink! In c++ numbering starts with the 0th element.\nTake the value < row or < column\n";
	return matrix[row1][column1];
}

template <typename T>
Matrix<T> & Matrix<T>::operator = (const Matrix & b)
{
	if (this != &b) 
    {
		row = b.row;
		column = b.column;

        for (size_t i = 0; i < row; i++)
			delete [] matrix[i];

        matrix = new T*[row];
		for (size_t i = 0;  i < row; i++)
			matrix[i] = new T[column];

		for (size_t i = 0; i < row; i++)
			for (size_t j = 0; j < column; j++)
				matrix[i][j] = b.matrix[i][j];
    }
	return (*this); 
}

template <typename T>
Matrix<T> Matrix<T>::sum(const Matrix &b)
{
	Matrix <T>result(row,column);
	if ((row != b.row)||(column != b.column))
			throw "\nYou can sum only the same size matrix\n";

	for (size_t i = 0; i < row; i++)
		for(size_t j = 0; j < column; j++)
			result.matrix[i][j] = matrix[i][j] + b.matrix[i][j];
	*this = result;
	return *this;
}

template <typename T>
void Matrix<T>::set_line(T value, size_t number)
{
	if (number >= row)
		throw "\nYou don't have string = number\n";
	for(int i = 0; i < column; i++)
		matrix[number][i] = value;
}

template <typename T>
void Matrix<T>::print()
{	
	for (size_t i = 0; i < row; i++)
	{
        for (size_t j = 0; j < column; j++)
            cout << matrix[i][j]<< " ";
		cout << endl;
	}
}