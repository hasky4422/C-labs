// Выполнил Дегтярев Никита Андреевич 2й курс группа ИВТ2

#include <iostream>
#include <cstdio>
#pragma warning(disable : 4996)

int main()
{
	const size_t N = 10;
	int arr[N] = { 0 };
	int initial;
	int step;
	setlocale(LC_ALL, "Russian");
	puts("Введите начальный элемент геометричесокй прогрессии: ");
	scanf("%d", &initial);
	puts("Введите шаг прогрессии: ");
	scanf("%d", &step);
	arr[0] = initial;
	// подсчет среднего значения в массиве а, изменение массива b
	//double result = processArray(arr, N, step);
	// вывод массивов на экран
	//printArray(a, N);
	// ...и среднего значения элементов массива а
	//printf("Average: %g\n\n", result);
	//return 0;
}
/*double processArray(int arr[], size_t n, int s)
{
	for (size_t i = 1; i < n; ++i)
	{
		arr[i] = arr[i - 1] * s;
		if ((log10(arr[i]) + 1) == 3)
		{

		}
	}
	double average = 0.0;
	for (size_t i = 0; i < n; ++i) // подсчет среднего значения элементов
	{
		average += arr[i];
	}
	average /= n;
}*/

