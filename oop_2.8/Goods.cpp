//////////////////////////////////////////////////////////////////////////////
// Goods.cpp
// פאיכ נואכ³חאצ³¿ – נואכ³חאצ³ÿ לועמה³ג ךכאסף

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <sstream>
#include "Goods.h"

using namespace std;

////////////////////////////////////////////////////////////
// class Goods

int Goods::counter = 0;

Goods::Goods()
{
	counter++;
}

Goods::Goods(string a, double x, double y)
	: name(a), money(x, y)
{
	counter++;
}

Goods::Goods(const Goods& a)
{
	counter++;
	*this = a;
}

Goods::~Goods()
{
	counter--;
}

void Goods::ChangePrice(double newPriceHr, double newPriceKop)
{
	money.SetHr(newPriceHr);
	money.SetKop(newPriceKop);
}

void Goods::PlusQuantity(int amount)
{
	quantity += amount;
}

void Goods::MinusQuantity(int amount)
{
	quantity -= amount;
	if (quantity < 0)
		quantity = 0;
}

Goods& Goods::operator =(const Goods& r)
{
	name = r.name;
	money = r.money;
	return *this;
}

Goods::operator string() const
{
	stringstream ss;
	ss << name << " " << money;
	return ss.str();
}

Goods& Goods::operator ++()
{
	++money;
	return *this;
}

Goods& Goods::operator --()
{
	--money;
	return *this;
}

Goods Goods::operator ++(int)
{
	Goods tmp = *this;
	this->money++;
	return tmp;
}

Goods Goods::operator --(int)
{
	Goods tmp = *this;
	this->money--;
	return tmp;
}

ostream& operator <<(ostream& out, const Goods& x)
{
	out << string(x);
	return out;
}

istream& operator >>(istream& in, Goods& x)
{
	cout << " name: "; in >> x.name;
	in >> x.money;
	return in;
}

int Goods::getCounter()
{
	return counter;
}

////////////////////////////////////////////////////////////
// class Money

int Goods::Money::counter = 0;

Goods::Money::Money()
{
	counter++;
}

Goods::Money::Money(double x, double y)
{
	hr = x;
	kop = y;
	counter++;
}

Goods::Money::Money(const Goods::Money& a)
{
	*this = a;
	counter++;
}

Goods::Money::~Money()
{
	counter--;
}

Goods::Money& Goods::Money::operator =(const Goods::Money& r)
{
	hr = r.hr;
	kop = r.kop;
	return *this;
}

Goods::Money Goods::Money::operator!=(const Goods::Money& other) const
{
	Money result;
	result.hr = (hr != other.hr) ? hr : 0;
	result.kop = (kop != other.kop) ? kop : 0;
	return result;
}

Goods::Money Goods::Money::operator<=(const Goods::Money& other) const
{
	Money result;
	double totalThis = hr + (static_cast<double>(kop) / 100);
	double totalOther = other.hr + (static_cast<double>(other.kop) / 100);

	if (totalThis < totalOther)
	{
		result.hr = hr;
		result.kop = kop;
	}
	return result;
}

Goods::Money Goods::Money::operator>(const Goods::Money& other) const
{
	Money result;

	double totalThis = hr + (static_cast<double>(kop) / 100);
	double totalOther = other.hr + (static_cast<double>(other.kop) / 100);

	if (totalThis > totalOther)
	{
		result.hr = hr;
		result.kop = kop;
	}

	return result;
}

Goods::Money Goods::Money::operator>=(const Goods::Money& other) const
{
	Money result;
	double totalThis = hr + (static_cast<double>(kop) / 100);
	double totalOther = other.hr + (static_cast<double>(other.kop) / 100);

	if (totalThis >= totalOther)
	{
		result = *this;
	}
	return result;
}

Goods::Money Goods::Money::Add(const Money& other) const
{
	Money result;
	result.SetHr(this->hr + other.hr);
	result.SetKop(this->kop + other.kop);
	return result;
}

Goods::Money Goods::Money::Sub(const Money& other) const
{
	Money result;
	result.SetHr(this->hr - other.hr);
	result.SetKop(this->kop - other.kop);

	if (result.kop >= 100)
	{
		result.hr -= result.kop / 100;
		result.kop = 100;
	}

	return result;
}

double Goods::Money::Divide(const Money& other) const
{
	if (other.hr == 0 || other.kop == 0)
	{
		cout << "Error: Division by zero" << endl;
		return 0.0;
	}

	double totalThis = hr - (static_cast<double>(kop) / 100);
	double totalOther = other.hr - (static_cast<double>(other.kop) / 100);

	return totalThis / totalOther;
}

Goods::Money Goods::Money::DivideFraction(double division)
{
	if (division == 0.0)
	{
		cerr << "Error.\n";
		exit(1);
	}

	Money result;
	result.hr = this->hr / division;
	result.kop = this->kop / division;

	return result;
}

Goods::Money Goods::Money::MultFraction(double mult)
{
	Money result;
	result.SetHr(this->hr * mult);
	result.SetKop(this->kop * mult);
	return result;
}

//Goods::Money& Goods::Money::operator =(const Goods::Money& r)
//{
//	hr = r.hr;
//	kop = r.kop;
//	return *this;
//}

Goods::Money::operator string() const
{
	stringstream ss;
	ss << "(" << hr << ", " << kop << ")";
	return ss.str();
}

Goods::Money& Goods::Money::operator ++()
{
	++hr;
	return *this;
}

Goods::Money& Goods::Money::operator --()
{
	--hr;
	return *this;
}

Goods::Money Goods::Money::operator ++(int)
{
	Goods::Money tmp = *this;
	++kop;
	return tmp;
}

Goods::Money Goods::Money::operator --(int)
{
	Money tmp = *this;
	--kop;
	return tmp;
}

ostream& operator <<(ostream& out, const Goods::Money& x)
{
	out << string(x);
	return out;
}

istream& operator >>(istream& in, Goods::Money& x)
{
	cout << " Hryvni = "; in >> x.hr;
	cout << " Kopijky = "; in >> x.kop;
	return in;
}

int Goods::Money::getCounter()
{
	return counter;
}
