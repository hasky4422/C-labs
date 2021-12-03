#include "Vector.h"
#include <iostream>
#include <iomanip>
using namespace std;
Vector::Vector(const int size)
{
    size_ = size;
    vector = new double [size];
}

Vector::~Vector()
{
    delete[] vector;
}
double* Vector::GetVector()
{
    return vector;
}

void  Vector::SetVector(double arr[])
{
    vector = arr;
}
void Vector::SetElem(int i, double val)
{
    vector[i] = val;
}

void Vector::PrintArr1D()
{
    for (int i = 0; i < size_; i++)
    {
        cout << setw(3) << setprecision(3) << vector[i] << "   ";
    }
}