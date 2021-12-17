/*Вид выражения CustomExpression: result = x1 + x2/2 + x3/3 + x4/4 + ...
Порядок создания и инициализации объектов подклассов:
CustomExpressionEvaluator: 6 операндов, присвоить группой 5, 16, -3, 10, 12, 2.
Subtractor: 4 операнда, присвоить группой 5.6,-2.1, 3.2, 1.5.
Multiplier: 3 операнда, присвоить поэлементно 1.5, -8, 2.5.
Метод shuffle() – поменять местами первый и последний операнды и изменить их
знак. Метод shuffle(size_t i, size_t j) – поменять местами i-ый и j-ый операнды и
изменить их знак.
Формат вывода:
Operands: 4
5.6-(-2.1)-3*/


#include <iostream>
#include <string>
#include "ILoggable.h"
#include "IShuffle.h"
#include "Summator.h"
#include "Multiplier.h"
#include "CustomExpressionEvaluator.h"

int main()
{
	ExpressionEvaluator* ex[3];
	
	ex[0] = new Summator(4);
	double* ops_sum = new double[4]{ 5.6, -2.1, 3.2, 1.5 };
	ex[0]->setOperands(ops_sum, 4);

	ex[1] = new Multiplier(3);
	double* ops_mult = new double[3]{ -1.5, -8, 2.5 };
	ex[1]->setOperands(ops_mult, 3);
	//Subtractor: 4 операнда, присвоить группой 5.6,-2.1, 3.2, 1.5.
    //Multiplier: 3 операнда, присвоить поэлементно 1.5, -8, 2.5
	ex[2] = new CustomExpressionEvaluator(6);
	double* ops_custom = new double[6]{ 5, 16, -3, 10, 12, 2 };
	for(int i = 0; i < 6; ++i)
		ex[2]->setOperand(i, ops_custom[i]);

	for(int i = 0; i < 3; ++i)
	{
		ex[i]->logToScreen();
		ex[i]->logToFile("LogEx.txt");
	}

	IShuffle* is = dynamic_cast<IShuffle*>(ex[2]);
	if (is) 
	{
		is->shuffle();
		ex[2]->logToScreen();
	}

	
	for (int i = 0; i < 3; i++)	
		delete ex[i];


	return 0;
}
