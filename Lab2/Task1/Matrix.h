#pragma once
class Matrix
{
private:
	int rows_;
	int cols_;
	double** matrix;

public:
	Matrix(const int rows, const int cols);
	~Matrix();

	void operator++();
	void operator++(int);
	void operator--();
	void operator--(int);

	void FillArray();
	void PrintArr2D();

	double** GetMatrix();
	void  SetMatrix(double** arr);
	void SetElem(int i, int j, double val);

};

