#include "Boutique.h"
#include <string>
#include <iostream>

Boutique::Boutique(string name, string location, int createYear, int phoneNumber) :Shop(name, location, createYear, phoneNumber) {}

void Boutique::payTax()
{ 
	tax_ = profit_ * (15.0 / 100);
}

double Boutique::GetTax()
{
	return tax_;
}