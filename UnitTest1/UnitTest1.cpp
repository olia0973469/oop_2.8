#include "pch.h"
#include "CppUnitTest.h"
#include "../oop_2.8/Goods.h"
#include "../oop_2.8/Goods.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Goods::Money money1(10, 50);
			Goods::Money money2(5, 25);
			Goods::Money sum = money1.Add(money2);
			Assert::AreEqual(15.0, sum.GetHr());
			Assert::AreEqual(75.0, sum.GetKop());
		}
	};
}
