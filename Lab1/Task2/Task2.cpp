/* Выполнил Дегтярев Никита Андреевич 2й курс группа ИВТ2 вариант 3
Преобразование: 2D → 1D.Двумерный массив 4х4 вещественных чисел необходимо
выложить в один ряд по элементам справа налево и сверху вниз.
Инициализация : заполнить массив числами x[i][j] = √(i + j + 1).
Вывод на экран : каждый элемент одномерного массива вывести с точностью 4 знака
после запятой; каждый элемент двумерного массива – с точностью 2 знака.*/

#include <iostream>
#include <iomanip>
using namespace std;
void fillArray(double* arr[], size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            *(*(arr + i) + j) = (double)(sqrt(i + j + 1));
        }
    }
}
void PrintArr2D(double** arr, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cout << setw(3) << setprecision(3) << *(*(arr + i) + j) << "   ";
        }
        cout << endl;
    }
}
void changeArray(double* arr[], size_t rows, size_t cols, double arr2[])
{
    int count = 0;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = cols; j > 0; j--)
        {
            cout << setw(3) << setprecision(3) << *(*(arr + i) + j-1) << "   ";
            *(arr2+count) = *(*(arr + i) + j-1);
            count++;
        }
        cout << endl;
    }
}
void prind1Darr(double arr2[])
{
    for (int i = 0; i < 16; i ++)
    {
        cout << setw(3) << setprecision(5) << *(arr2 + i) << "   ";
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");   
    size_t x = 4;
    size_t y = 4;
    double** ptrarray = new double* [x];
    for (int count = 0; count < 4; count++)
    {
        ptrarray[count] = new double[y];
    }
    fillArray(ptrarray, x, y);
    PrintArr2D(ptrarray, x, y);
    cout << endl;
    double* changetarr = new double [x * y];
    changeArray(ptrarray, x, y, changetarr);
    cout << endl;
    prind1Darr(changetarr);
    cout << endl;
    for (size_t i = 0; i < 4; i++)
    {
        delete* (ptrarray + i);
    }
    delete[] ptrarray;
    delete[] changetarr;
}