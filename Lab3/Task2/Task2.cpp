/*Класс МАГАЗИН + классы АПТЕКА, БУТИК.
Реализовать схему наследования классов и корректно распределить по классам данные :
название, адрес, год основания, номер, суммарная прибыль, доход, время работы,
количество клиентов со скидкой, тип(круглосуточно или нет).
Интерфейс налогоплательщика ITaxPayment с методом void payTax().Для бутика
налог рассчитывается с учетом земельного налога, для аптеки – без(коэффициенты
    задайте произвольно).Сумма налогов должна быть вычтена из суммарной прибыли.В
    main() создать 2 аптеки и 1 бутик, продемонстрировать полиморфизм payTax().*/

#include <iostream>
#include "Pharmacy.h"
#include "Boutique.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    Pharmacy apteka1("Наша аптека", "st. Yniver", 2001, 7132525251);
    Pharmacy apteka2("Арника", "st. Donetsk", 2010, 7156415251);
    Boutique boutique1("Донетский Бутик", "st. Artema", 2005, 7154541663);

    boutique1.payTax();
    apteka1.payTax();
    apteka2.payTax();

    std::cout << "Налог бутика 1: " << boutique1.GetTax()<< " При доходе: "<< boutique1.GetProfit() << endl;
    std::cout << "Налог аптеки 1: " << apteka1.GetTax() << " При доходе: " << apteka1.GetProfit() << endl;
    std::cout << "Налог аптеки 2: " << apteka2.GetTax() << " При доходе: " << apteka2.GetProfit() << endl;
}
