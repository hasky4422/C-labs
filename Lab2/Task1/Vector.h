#pragma once
class Vector
{
private:
	int size_;
	double* vector;

public:
	Vector(const int size);
	~Vector();
	void PrintArr1D();
	double* GetVector();
	void  SetVector(double arr[]);
	void SetElem(int i, double val);
};

