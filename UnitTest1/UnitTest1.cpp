#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Misha\source\repos\5.1 b oop\5.1 b oop\Money.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Money m(0, 0), p(0, 0);
			m.setGrn(15);
			p.setGrn(14);
			double a = m.getGrn();
			double b = p.getGrn();
			double res = a - b;

			Assert::AreEqual(res, 1.);
		}
	};
}
