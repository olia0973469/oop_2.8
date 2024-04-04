//////////////////////////////////////////////////////////////////////////////
// Source.cpp
// головний файл проекту – функція main

#include "Goods.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Goods z;
	string c;
	int d, n1 = 1, n2 = 5;
	cout << " Name = "; cin >> c;
	z.SetName(c);
	cout << " Price = "; cin >> d;
	z.SetPrice(d);
	cout << " Quantity = "; cin >> d;
	z.SetQuantity(d);
	cout << " N = "; cin >> d;
	z.SetNo(d);
	cout << " Date = "; cin >> d;
	z.SetDate(d);
	cout << "g: "; cin >> z;
	cout << z << endl;

	cout << " CangePrice = " << endl;
	z.ChangePrice(n1, n2);
	cout << z << endl;
	cout << " Cost = " << endl;
	z.Cost();
	cout << z << endl;

	cout << "Goods : " << Goods::getCounter() << endl;
	cout << "Goods::Money : " << Goods::Money::getCounter() << endl;

	return 0;
}