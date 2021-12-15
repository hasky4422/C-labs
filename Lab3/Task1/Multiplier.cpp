#include "Multiplier.h"
#include <iostream>

using namespace std;

Multiplier::Multiplier(int n) : ExpressionEvaluator(n) { }

double Multiplier::calculate()
{
	double mult = operands[0];
	for (int i = 1; i < size; i++)
		mult *= operands[i];
	return mult;
}

void Multiplier::logToScreen()
{
	cout << "<Multiplier>" << endl;
	cout << "Operands :" << size << endl;

	operands[0] >= 0 ? cout << operands[0] : cout << '(' << operands[0] << ')';

	for (int i = 1; i < size; ++i)
		operands[i] >= 0 ? cout << " * " << operands[i] : cout << " * (" << operands[i] << ") ";

	cout << "\nResult: " << calculate() << endl << endl;
}

void Multiplier::logToFile(const std::string& filename)
{
	ofstream stream;
	stream.open(filename, ios_base::app);

	stream << "<Multiplier>" << endl;
	stream << "Operands :" << size << endl;
	operands[0] >= 0 ? stream << operands[0] : stream << '(' << operands[0] << ')';

	for (int i = 1; i < size; ++i)
		operands[i] >= 0 ? stream << " * " << operands[i] : stream << " * (" << operands[i] << ")";

	stream << "\nResult: " << calculate() << endl << endl;

	stream.close();
}


Multiplier::~Multiplier()
{
	//delete[] operands;
}