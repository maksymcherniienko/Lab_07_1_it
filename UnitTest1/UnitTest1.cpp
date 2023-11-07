#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07_1-a-it/Lab.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const int rowCount = 2;
            const int colCount = 3;
            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++) {
                a[i] = new int[colCount];
            }
            a[0][0] = 1;
            a[0][1] = 10;
            a[0][2] = 20;
            a[1][0] = 5;
            a[1][1] = 7;
            a[1][2] = 30;

            int Sum = 1 + 7;
            int S = 0;
            CalcSum(a, rowCount, colCount, S);
            Assert::AreEqual(Sum, S);
			
		}
	};
}
