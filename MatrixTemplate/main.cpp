#include "Matrix.h"


int main()
{
	setlocale(LC_ALL,"rus");
	Matrix m(2,2);
	cin >> m;
	Matrix m_2(m);
	cout << m;
	cout << m_2;
	Matrix m_3 = m * m_2;
	cout << m_3;
	Matrix m_4 = m_3 / 2;
	cout << m_4;
}