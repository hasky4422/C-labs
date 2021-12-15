#pragma once
#include "Shop.h"
class Pharmacy : public Shop
{
public:
	Pharmacy(string name, string location, int createYear, int phoneNumber);
	void PayTax();
	double GetTax();
};