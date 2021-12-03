/*1. Написать классы Vector и Matrix для хранения и обработки одномерных и
двумерных массивов, соответственно.Реализовать задание 2 лабораторной работы №1
с помощью созданных классов.Все функции оформить в виде методов классов.
В коде отразить следующее :
 Выделение и освобождение динамической памяти производить в конструкторах и
деструкторах классов, соответственно.
 В классе Vector перегрузить оператор индексации[].В классе Matrix добавить
методы T at(int i, int j) const и setAt(int i, int j, T val), которые
позволяют получить и установить значение элемента массива с индексом[i][j], T –
это тип элементов массива по варианту(int или double).
 Перегрузить операторы инкремента и декремента(как префиксного, так и
    постфиксного).Смысл инкремента / декремента всего массива заключается в
    инкременте / декременте каждого элемента массива.*/
//Выполнил Дегтярев Никита ИВТ2


#include "Matrix.h"
#include <iostream>
#include <iomanip>
#include "Vector.h"
using namespace std;

void changeArray(double* arr[], size_t rows, size_t cols, double arr2[])
{
    int count = 0;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = cols; j > 0; j--)
        {
            cout << setw(3) << setprecision(3) << *(*(arr + i) + j - 1) << "   ";
            *(arr2 + count) = *(*(arr + i) + j - 1);
            count++;
        }
        cout << endl;
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int x = 4;
    int y = 4;
    int size = x * y;
    Matrix arry2D(x, y);
    Vector arry1D(size);
    arry2D.PrintArr2D();
    cout << arry2D.GetMatrix() << endl;
    changeArray(arry2D.GetMatrix(), x, y, arry1D.GetVector());
    cout << endl;
    arry1D.PrintArr1D();
}