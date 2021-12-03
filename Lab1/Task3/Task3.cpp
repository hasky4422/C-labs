/*Выполнил Дегтярев Никита Андреевич 2й курс группа ИВТ2 вариант 3
Функция strcat.
Формат char* strcat(char* dest, const char* src).
Функция приписывает строку src к строке dest*/

#include <stdio.h>
#include <string.h>
#include <iostream>
#pragma warning(disable : 4996)
void Mystrcat(char* dest, const char* src)
{
	size_t i, j;
	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];
	dest[i + j] = '\0';
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char s2[100] = "Тестовая строка1";
	char s1[] = "Тестовая строка2";
	char s3[100] = "Тестовая строка3";
	char s4[] = "Тестовая строка4";

	strcat(s2, s1);
	printf("%s ", s2);
	Mystrcat(s3, s4);
	printf("%s ", s3);
}