#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP 4.5/Pair.h"
#include "../OOP 4.5/FuzzyNumber.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UTOOP45
{
	TEST_CLASS(UTOOP45)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Pair* A = new FuzzyNumber(4, 1, 7);
			Pair* B = new FuzzyNumber(6, 3, 9);
			Pair* C = new FuzzyNumber();
			C = *A + B;
			Assert::AreEqual(((FuzzyNumber*)C)->get_x(), 10.0);
		}
	};
}
