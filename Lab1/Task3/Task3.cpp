/*�������� �������� ������ ��������� 2� ���� ������ ���2 ������� 3
������� strcat.
������ char* strcat(char* dest, const char* src).
������� ����������� ������ src � ������ dest*/

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
	char s2[100] = "�������� ������1";
	char s1[] = "�������� ������2";
	char s3[100] = "�������� ������3";
	char s4[] = "�������� ������4";

	strcat(s2, s1);
	printf("%s ", s2);
	Mystrcat(s3, s4);
	printf("%s ", s3);
}