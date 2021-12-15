/*Написать собственный класс, в соответствии с вариантом.Продемонстрировать в коде
инкапсуляцию данных, применение конструкторов без параметров и с параметрами
для инициализации данных.Класс должен содержать метод serialize() для
сохранения данных класса в файл и метод deserialize() для чтения данных класса
из файла по умолчанию в текущей директории, а также перегруженные методы
serialize(const std::string& filename) и deserialize(const std::string&
    filename) для работы с файлом с указанным в параметре именем.*/
//Выполнил Дегтярев Никита ИВТ2


#include <iostream>
#include "Shop.h"
using namespace std;

void addSort(int arry[], string arry2[])
{
    int temp = 0;
    string temp2 = "";
    for (int i = 0; i <  2; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (arry[i] > arry[j])
            {
                temp = arry[i];
                temp2 = arry2[i];
                arry[i] = arry[j];
                arry2[i] = arry2[j];
                arry[j] = temp;
                arry2[j] = temp2;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    Shop* marketPlace = new Shop();
    marketPlace->SetName("Bazar");
    marketPlace->SetLocation("Donetsk, st Artema");
    marketPlace->SetCreateYear(2000);
    (*marketPlace).SetPhoneNumber(7134928765);

    Shop* basicShop = new Shop();
    basicShop->SetName("Technomarket");
    basicShop->SetLocation("Donetsk, st BogdanaHmel");
    basicShop->SetCreateYear(2010);
    (*basicShop).SetPhoneNumber(71326525855);

    Shop psStore("Igrozona", "Donetsk, st Yniversitetska", 20010, 714627618);

    int* profitSort = new int[3];
    profitSort[0] = marketPlace->GetProfit();
    profitSort[1] = basicShop->GetProfit();
    profitSort[2] = psStore.GetProfit();

    string* markets = new string[3];
    markets[0] = "marketPlace";
    markets[1] = "basicShop";
    markets[2] = "psStore";

    addSort(profitSort, markets);
    
    cout << "Рейтинг магазинов по доходам за 3 месяца(сортировка по убыванию)" << endl;
    for (int i = 0; i<3 ; i++)
    {
        cout << i+1<<") "<<markets[i]<<", доход: "<<profitSort[i]<< endl;
    }
    cout << ""<< endl;

    profitSort[0] = marketPlace->GetGrowth();
    profitSort[1] = basicShop->GetGrowth();
    profitSort[2] = psStore.GetGrowth();

    markets[0] = "marketPlace";
    markets[1] = "basicShop";
    markets[2] = "psStore";

    addSort(profitSort, markets);

    cout << "Рейтинг магазинов по среднему приросту прибыли за 3 месяца(сортировка по убыванию)" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << ") " << markets[i] << ", средний прирост прибыли: " << profitSort[i] << endl;
    }
    cout << "" << endl;
    psStore.LogToFile();
}
