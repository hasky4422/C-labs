#include "CustomExpressionEvaluator.h"
#include <iostream>

using namespace std;

CustomExpressionEvaluator::CustomExpressionEvaluator(int n) : ExpressionEvaluator(n) {}

double CustomExpressionEvaluator::calculate()
{
	double res = operands[0];
	for (int i = 1; i < size; i++)
		res += (operands[i])/i;
	return res;
}

void CustomExpressionEvaluator::logToScreen()
{
	cout << "<CustomExpressionEvaluator>" << endl;
	cout << "Operands :" << size << endl;
	cout << operands[0];
	for (int i = 1; i < size; ++i)
		cout << " + " << "(" << operands[i] << ")/" << i << ' ';

	cout << "\nResult: " << calculate() << endl << endl;
}

void CustomExpressionEvaluator::logToFile(const std::string& filename)
{
	ofstream stream;
	stream.open(filename, ios_base::app);

	stream << "<CustomExpressionEvaluator>" << endl;
	stream << "Operands :" << size << endl;
	for (int i = 1; i < size; ++i)
		stream << " + " << "(" << operands[i] << ")/" << i << ' ';
	stream << "\nResult: " << calculate() << endl << endl;

	stream.close();
}

void CustomExpressionEvaluator::shuffle()
{
	double tmp;
	tmp = operands[0];
	operands[0] = -operands[size - 1];
	operands[size - 1] = -tmp;
}

void CustomExpressionEvaluator::shuffle(size_t left, size_t right)
{
	double tmp;
	for (int i = left; i < right - 1; i++)
	{
		int max = i;
		for (int j = i + 1; j < right; j++)
		{
			if (operands[j] > operands[max])
				max = j;
		}
		tmp = operands[max];
		operands[max] = operands[i];
		operands[i] = tmp;
	}
}

CustomExpressionEvaluator::~CustomExpressionEvaluator()
{
	//delete[] operands;
}
