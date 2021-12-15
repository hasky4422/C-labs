#include "Shop.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
using namespace std;

Shop::Shop(string name, string location, int createYear, int phoneNumber) 
{
	name_ = name;
	location_ = location;
	createYear_ = createYear;
	phoneNumber_ = phoneNumber;
	profitPerMonth1_ = 0 + rand() % 1000;
	profitPerMonth3_ = 0 + rand() % 1000;
	profitPerMonth2_ = 0 + rand() % 1000;
	profit_ = profitPerMonth1_ + profitPerMonth2_ + profitPerMonth3_;
	growth1_ = 0 + rand() % 1000;
	growth2_ = profitPerMonth2_ - profitPerMonth1_;
	growth3_ = profitPerMonth3_ - profitPerMonth2_;
	growth_ = (growth1_ + growth2_ + growth3_) / 3;
}

Shop::Shop()
{
	name_ = "";
	location_ = "";
	createYear_ = 0;
	phoneNumber_ = 0;
	profitPerMonth1_ = 0 + rand() % 1000;
	profitPerMonth3_ = 0 + rand() % 1000;
	profitPerMonth2_ = 0 + rand() % 1000;
	profit_ = profitPerMonth1_ + profitPerMonth2_ + profitPerMonth3_;
	growth1_ = 0 + rand() % 1000;
	growth2_ = profitPerMonth2_ - profitPerMonth1_;
	growth3_ = profitPerMonth3_ - profitPerMonth2_;
	growth_ = (growth1_ + growth2_ + growth3_) / 3;
}

Shop::~Shop() 
{
}


void Shop::SetLocation(string location)
{
	location_ = location;
}

void Shop::SetCreateYear(int year)
{
	createYear_ = year;
}

void Shop::SetPhoneNumber(int number)
{
	phoneNumber_ = number;
}

void Shop::SetName(string name)
{
	name_ = name;
}

int  Shop::GetProfit()
{
	return profit_;
}

int  Shop::GetGrowth()
{
	return growth_;
}

void Shop::LogToFile()
{
	std::ofstream out;          // поток для записи
	out.open("D:\\log.txt"); 
	if (out.is_open())
	{
		out << 
		"Название магазина: "<<name_<< endl <<
		"Адресс:"<<location_<< endl <<
		"Год создания: "<<createYear_<< endl<<
		"Номер телефона: "<<phoneNumber_
	    << std::endl;
	}
	out.close();
}
