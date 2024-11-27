#include "pch.h"
#include "CppUnitTest.h"
#include "../pr12.1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::IsTrue(isLatinLetter('A'), L"'A' має бути латинською літерою.");
			Assert::IsTrue(isLatinLetter('z'), L"'z' має бути латинською літерою.");
			Assert::IsTrue(isLatinLetter('M'), L"'M' має бути латинською літерою.");
		}
	};
}
