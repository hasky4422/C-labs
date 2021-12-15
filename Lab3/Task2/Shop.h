#pragma once
#include "ITaxPayment.h"
#include <iostream>
using namespace std;
class Shop : public ITaxPayment
{
private:
	string name_;
	string location_;
	int createYear_;
	int phoneNumber_;


public:
	int profit_;
	int profitPerMonth1_;
	int profitPerMonth2_;
	int profitPerMonth3_;
	int growth1_;
	int growth2_;
	int growth3_;
	int growth_;
	double tax_;
	Shop(string name, string location, int createYear, int phoneNumber);
	Shop();
	~Shop();
	void SetLocation(string location);
	void SetCreateYear(int year);
	void SetPhoneNumber(int number);
	void SetName(string name);
	int GetProfit();
	int GetGrowth();
	void LogToFile();
};
