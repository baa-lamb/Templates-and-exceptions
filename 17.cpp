template <typename T>
Matrix<T>::Matrix(int row1, int column1)
{
	row = row1;
	column = column1;

	matrix = new T*[row];
	for (int i = 0;  i < row; i++)
		matrix[i] = new T[column];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			matrix[i][j] = 0;
}

template <typename T>
Matrix<T>::~Matrix()
{
	 for (int i = 0; i < row; i++)
        delete [] matrix[i];
}

template <typename T>
Matrix<T>::Matrix (const Matrix & b)
{
	row = b.row;
	column = b.column;
	
	matrix = new T*[row];
	for (int i = 0; i < row; i++)
		matrix[i] = new T[column];
	
	for(int i = 0; i < row; i++)
		for(int j = 0; j < column; j++)
			matrix[i][j] = b.matrix[i][j];
}

template <typename T>
void Matrix<T>::set(int row, int column)
{
	for(int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			cin >> matrix[i][j];			
}

template <typename T>
int Matrix<T>::get_row()
{
	return row;
}

template <typename T>
int Matrix<T>::get_column()
{
	return column;
}

template <typename T>
Matrix<T> & Matrix<T>::operator = (const Matrix & b)
{
	if (this != &b) 
    {
		row = b.row;
		column = b.column;

        for (int i = 0; i < row; i++)
			delete [] matrix[i];

        matrix = new T*[row];
		for (int i = 0;  i < row; i++)
			matrix[i] = new T[column];

		for (int i = 0; i < row; i++)
			for (int j = 0; j < column; j++)
				matrix[i][j] = b.matrix[i][j];
    }
	return (*this); 
}

template <typename T>
Matrix<T> Matrix<T>::sum(const Matrix &b)
{
	if ((column != b.column)&&(row != b.row))
		return 0;

	Matrix <T>result(row,column);

	for (int i = 0; i < row; i++)
		for(int j = 0; j < column; j++)
			result.matrix[i][j] = matrix[i][j] + b.matrix[i][j];

	return result;
}

template <typename T>
void Matrix<T>::print()
{	
	for (int i = 0; i < row; i++)
	{
        for (int j = 0; j < column; j++)
            cout << matrix[i][j]<< " ";
		cout << endl;
	}
}