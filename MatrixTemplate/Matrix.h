#include <iostream>

using namespace std;
template< typename T>
class Matrix
{
private:
	int row;
	int col;
	T** matrix;
public:
	Matrix(int rowNum, int colNum) {
		matrix = new T * [rowNum];
		for (int i = 0; i < rowNum; ++i) {
			matrix[i] = new T[colNum];

		}
		row = rowNum;
		col = colNum;
	}
	~Matrix()
	{
		for (int i = 0; i < row; ++i)
			delete[] matrix[i];
		delete[] matrix;
	}
	Matrix(const Matrix& temp) {
		row = temp.row;
		col = temp.col;

		matrix = new T * [row];

		for (int i = 0; i < row; ++i) {
			matrix[i] = new T[col];

		}

		for (int i = 0; i < row; ++i) {

			for (int j = 0; j < col; ++j) {
				matrix[i][j] = temp.matrix[i][j];
			}

		}


	}
	void resize(int newRow, int newCol) {

		T** temp;
		temp = new T * [newRow];
		for (int i = 0; i < newRow; ++i) {
			temp[i] = new T[newCol];
		}

		for (int i = 0; i < getRow(); ++i) {
			delete[] matrix[i];
		}
		delete[] matrix;

		matrix = temp;

		row = newRow;
		col = newCol;

	}
	template<typename T>
	Matrix<T>& operator = (const Matrix<T>& b) {
		if (getRow() != b.row || getCol() != b.col) {
			this->resize(b.row, b.col);

		}
		**matrix = **b.matrix;
		return (*this);

	}
	int getRow() {
		return this->row;
	}
	int getCol() {
		return this->col;
	}
	template<typename T>
	friend Matrix<T> operator+(const Matrix<T>& a, const Matrix<T>& b) {
		if (a.col != b.col || a.row != a.row) {
			cout << "Матрицы разного размера" << endl;
			exit(1);
		}
		Matrix temp(a.row, a.col);
		for (int i = 0; i < a.row; i++) {
			for (int j = 0; j < a.col; j++) {
				temp.setElem(i, j, (a.matrix[i][j] + b.matrix[i][j]));
			}
		}
		return temp;
	}
	template<typename T>
	friend Matrix<T> operator-(const Matrix<T>& a, const Matrix<T>& b) {
		if (a.col != b.col || a.row != b.row) {
			cout << "Матрицы разного размера" << endl;
			exit(1);
		}
		Matrix temp(a.row, a.col);
		for (int i = 0; i < a.row; i++) {
			for (int j = 0; j < a.col; j++) {
				temp.setElem(i, j, (a.matrix[i][j] - b.matrix[i][j]));
			}
		}
		return temp;
	}
	template<typename T>
	friend Matrix<T> operator*(const Matrix<T>& a, const Matrix<T>& b) {
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
	template<typename T>
	friend Matrix<T> operator*(const Matrix<T>& a, double b) {
		Matrix temp(a.row, a.col);
		for (int i = 0; i < a.row; i++) {
			for (int j = 0; j < a.col; j++) {
				temp.matrix[i][j] = a.matrix[i][j] * b;
			}
		}
		return temp;
	}
	template<typename T>
	friend Matrix<T> operator*(double b, const Matrix<T>& a) {
		return a * b;
	}
	template<typename T>
	friend Matrix<T> operator/(const Matrix<T>& a, double b) {
		return a * (1 / b);
	}
	template<typename T>
	friend istream& operator >> (istream& in, Matrix<T>& ob)
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
	template<typename T>
	friend ostream& operator << (ostream& out, Matrix<T>& ob)
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


	};


