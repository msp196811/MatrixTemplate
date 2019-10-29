#include "Matrix.h"

Matrix::Matrix(int rowNum, int colNum) {
	matrix = new double* [rowNum];
	for (int i = 0; i < rowNum; ++i) {
		matrix[i] = new double[colNum];

	}
	row = rowNum;
	col = colNum;
}
Matrix::~Matrix()
{
	for (int i = 0; i < row; ++i)
		delete[] matrix[i];
	delete[] matrix;
}
Matrix::Matrix(const Matrix &temp) {
	row = temp.row;
	col = temp.col;

	matrix = new double* [row];

	for (int i = 0; i < row; ++i) {
		matrix[i] = new double[col];

	}

	for (int i = 0; i < row; ++i) {

		for (int j = 0; j < col; ++j) {
			matrix[i][j] = temp.matrix[i][j];
		}

	}


}

void Matrix::resize(int newRow, int newCol) {  //for now, resizing does not require copying values

	double** temp;
	temp = new double* [newRow];
	for (int i = 0; i < newRow; ++i) {
		temp[i] = new double [newCol] ;
	}

	for (int i = 0; i < getRow(); ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;

	matrix = temp;

	row = newRow;
	col = newCol;

}
Matrix& Matrix:: operator = (const Matrix& b) {
	if (getRow() != b.row || getCol() != b.col) {
		this->resize(b.row, b.col);

	}
	**matrix = **b.matrix;
	return (*this);

}
int Matrix::getRow() {
	return this->row;
}
int Matrix::getCol() {
	return this->col;
}
double Matrix::getElem(int i, int j) {
	if (i >= row || j >= col) { exit(0); }
	return matrix[i][j];
}
int Matrix::setElem(int i_Row, int i_Col, double value) {
	if (i_Row >= row || i_Col >= col) { exit(0); }
	matrix[i_Row][i_Col] = value;
	return 0;
}
Matrix operator+(const Matrix &a, const Matrix &b) {
	if (a.col != b.col || a.row != a.row) {
		cout << "Матрицы разного размера" << endl;
		exit(1);
	}
	Matrix temp(a.row,a.col);
	for (int i = 0; i < a.row; i++) {
		for (int j = 0; j < a.col; j++) {
			temp.setElem(i,j,(a.matrix[i][j] + b.matrix[i][j]));
		}
	}
	return temp;
}
Matrix operator-(const Matrix& a, const Matrix& b) {
	if (a.col != b.col || a.row != b.row) {
		cout << "Матрицы разного размера" << endl;
		exit(1);
	}
	Matrix temp(a.row,a.col);
	for (int i = 0; i < a.row; i++) {
		for (int j = 0; j < a.col; j++) {
			temp.setElem(i, j, (a.matrix[i][j] - b.matrix[i][j]));
		}
	}
	return temp;
}
Matrix operator*(const Matrix& a, const Matrix& b) {
	if (a.col != b.row) {
		cout << "Умножение невозможно" << endl;
		exit(1);
	}
	Matrix temp(a.row, b.col);
	for (int i = 0; i < a.row; i++) {
		for (int j = 0; j < b.col; j++) {
			temp.matrix[i][j] = 0;
			for (int k = 0; k < a.col; k++)
				temp.matrix[i][j] += a.matrix[i][k] + b.matrix[k][j];
		}
	}
	return temp;
}
Matrix operator*(const Matrix &a, double b) {
	Matrix temp(a.row, a.col);
	for (int i = 0; i < a.row; i++) {
		for (int j = 0; j < a.col; j++) {
			temp.matrix[i][j] = a.matrix[i][j] * b;
		}
	}
   return temp;
}
Matrix operator*(double b, const Matrix& a) {
	return a * b;
}
Matrix operator/(const Matrix& a, double b) {
	return a * (1 / b);
}
istream& operator >> (istream &in, Matrix &ob)
{
	int i, j;
	for (i = 0; i < ob.row; ++i)
		for (j = 0; j < ob.col; ++j)
		{
			cout << "[" << i << "][" << j << "] ";
			in >> ob.matrix[i][j];
		}
	return in;
}

ostream &operator << (ostream &out, Matrix &ob) 
{
	int i, j;

	for (i = 0; i < ob.row; ++i)
		for (j = 0; j < ob.col; ++j)
		{
			if (j % ob.col == 0)
				out << endl;
			cout << "     " << ob.matrix[i][j];
		}
	out << endl;
	return out;
}