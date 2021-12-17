#include "Pharmacy.h"
#include <string>
#include <iostream>

Pharmacy::Pharmacy(string name, string location, int createYear, int phoneNumber):Shop(name, location, createYear, phoneNumber) {}

void Pharmacy::payTax() {
	tax_ = profit_* (10.0 / 100);
}

double Pharmacy::GetTax()
{
	return tax_;
}