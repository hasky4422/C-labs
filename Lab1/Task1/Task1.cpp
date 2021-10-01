/* Выполнил Дегтярев Никита Андреевич 2й курс группа ИВТ2 вариант 3
Объявить массив из n = 10 целых чисел, проинициализировать нулями.Функция
processArray() должна заполнить массив членами геометрической прогрессии с
начальным элементом b1 и шагом q(ввести с клавиатуры), подсчитать и вернуть cnt –
количество всех трехзначных элементов массива, а также сформировать выходной
массив, который содержит все элементы исходного, кроме тех, которые делятся на 3 с
остатком 1. Вывести на экран массивы*/

#include <iostream>
#include <cstdio>
#pragma warning(disable : 4996)

int processArray(int arr[], int arr2[], size_t n, int s)
{
	int cnt = 0;
	int j = 0;
	for (size_t i = 1; i < n; ++i)
	{
		arr[i] = arr[i - 1] * s;
		if ((int)(log10(arr[i]) + 1) == 3)
		{
			cnt++;
		}
		if (arr[i] % 3 != 1)
		{
			arr2[j] = arr[i];
			j++;
		}
	}
	return cnt;
}
void prindArr(int arr[], size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		if (arr[i] != 0) 
		{
		printf("%d ", arr[i]);
		}
	}
	printf("\n");
}
int main()
{
	const size_t N = 10;
	int arr[N] = { 0 };
	int arr2[N] = { 0 };
	int initial;
	int step;
	setlocale(LC_ALL, "Russian");
	puts("Введите начальный элемент геометричесокй прогрессии: ");
	scanf("%d", &initial);
	puts("Введите шаг прогрессии: ");
	scanf("%d", &step);
	arr[0] = initial;
	int result = processArray(arr, arr2, N, step);
	printf("Количество всех трехзначных элементов массива: %d\n\n", result);
	puts("Изначальный массив");
	prindArr(arr, N);
	puts("Сформированый массив");
	prindArr(arr2, N);
	return 0;
}