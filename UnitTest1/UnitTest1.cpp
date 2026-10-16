#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 5.4/lab 5.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int N = 8;
			const double expected = 234.4992314557069;
			const double eps = 1e-8;

			Assert::AreEqual(expected, P0(N), eps);
			Assert::AreEqual(expected, P1(N, 10, 1.0), eps);
			Assert::AreEqual(expected, P2(N, N, 1.0), eps);
			Assert::AreEqual(expected, P3(N, 10), eps);
			Assert::AreEqual(expected, P4(N, N), eps);

		}
	};
}
