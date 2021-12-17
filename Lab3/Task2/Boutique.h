#pragma once
#include "Shop.h"

class Boutique : public Shop
{
public:
	Boutique(string name, string location, int createYear, int phoneNumber);
	void payTax()override;
	double GetTax();
};

