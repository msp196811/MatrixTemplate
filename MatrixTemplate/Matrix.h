#include <iostream>
using namespace std;

class Matrix
{
private:
	int row;
	int col;
	double** matrix;
public:
	Matrix(int newRow = 1, int newCol = 1); // конструктор с параметрами
	Matrix(const Matrix &); // конструктор копии
	~Matrix(); // деструктор 
	Matrix& operator = (const Matrix& b);
	
	int getRow();
	int getCol();
	double getElem(int i, int j);
	int setElem(int, int, double);
	
	void resize(int newRow, int newCol);
	friend Matrix operator + (const Matrix&,const Matrix&);
	friend Matrix operator - (const Matrix&, const Matrix&);
	friend Matrix operator * (const Matrix&, const Matrix&);
	friend Matrix operator * (const Matrix&, double);
	friend Matrix operator * (double, Matrix&);
	friend Matrix operator / (const Matrix&, double);

	friend std::ostream& operator << (std::ostream&, Matrix&);
	friend std::istream& operator >> (std::istream&, Matrix&);
	};





