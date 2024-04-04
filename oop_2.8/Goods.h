//////////////////////////////////////////////////////////////////////////////
// Goods.h
// заголовний файл Ц визначенн€ класу

#pragma once
#include <iostream>
#include <string>

using namespace std;

class Goods
{
	string name;
	int price, quantity, no, date;
	static int counter;
public:
	class Money
	{
		double hr;
		double kop;
		static int counter;
	public:
		double GetHr() const { return hr; }
		double GetKop() const { return kop; }
		void SetHr(double value) { this->hr = value; }
		void SetKop(double value) { this->kop = value; }

		Money();
		Money(double, double);
		Money(const Money&);

		Money Add(const Money& other) const;
		Money Sub(const Money& other) const;
		double Divide(const Money& other) const;
		Money DivideFraction(double division);
		Money MultFraction(double mult);

		Money& operator =(const Money&);
		Money operator!=(const Money& other) const;
		Money operator<=(const Money& other) const;
		Money operator>(const Money& other) const;
		Money operator>=(const Money& other) const;
		operator string() const;
		Money& operator ++();
		Money& operator --();
		Money operator ++(int);
		Money operator --(int);
		friend ostream& operator <<(ostream&, const Money&);
		friend istream& operator >>(istream&, Money&);
		static int getCounter();
		~Money();
	};
	~Goods();
	string GetName() const { return name; };
	int GetDate() const { return date; };
	int GetPrice() const { return price; };
	int GetQuantity() const { return quantity; };
	int GetNo() const { return no; };
	void SetName(string value) { name = value; };
	void SetDate(int value) { date = value; };
	void SetPrice(int value) { price = value; };
	void SetQuantity(int value) { quantity = value; };
	void SetNo(int value) { no = value; }
	void SetMoney(Money value)
	{
		money.SetHr(value.GetHr());
		money.SetKop(value.GetKop());
	}
	Goods();
	Goods(string, double, double);
	Goods(const Goods&);
	Money Add();
	Money Sub();
	double Divide(int, int);
	Money DivideFraction();
	operator string() const;
	void ChangePrice(double newPriceHr, double newPriceKop);
	void PlusQuantity(int amount);
	void MinusQuantity(int amount);
	Money Cost() const;
	Goods& operator ++();
	Goods& operator --();
	Goods operator ++(int);
	Goods operator --(int);
	friend ostream& operator <<(ostream& out, const Goods& x);
	friend istream& operator >>(istream& in, Goods& x);
	static int getCounter();
	Goods& operator =(const Goods& r);
private:
	Money money;
};
