#include "Matrix.h"
#include <iostream>
#include <iomanip>
using namespace std;
Matrix::Matrix(const int rows, const int cols)
{
	rows_ = rows;
	cols_ = cols;
    matrix = new double* [rows];
    for (int count = 0; count < 4; count++)
    {
        matrix[count] = new double[cols];
    }
    FillArray();
}

Matrix::~Matrix()
{
    for (int i = 0; i < 4; i++)
    {
        delete* (matrix + i);
    }
    delete[] matrix;
}

void Matrix::operator++()
{
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            matrix[i][j]++;
        }
    }
}

void Matrix::operator++(int)
{
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            ++matrix[i][j];
        }
    }
}

void Matrix::operator--()
{
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            matrix[i][j]--;
        }
    }
}

void Matrix::operator--(int)
{
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            --matrix[i][j];
        }
    }
}

double**  Matrix::GetMatrix()
{
    return matrix;
}

void  Matrix :: SetMatrix(double** arr)
{
    matrix = arr;
}
void Matrix:: SetElem(int i, int j, double val)
{
    matrix[i][j] = val;
}

void Matrix :: FillArray()
{
    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; j++)
        {
            matrix[i][j] = (double)(sqrt(i + j + 1));
        }
    }
}
void Matrix :: PrintArr2D()
{
    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; j++)
        {
            cout << setw(3) << setprecision(3) << matrix[i][j] << "   ";
        }
        cout << endl;
    }
}