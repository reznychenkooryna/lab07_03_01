#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestMethod1)
        {
            int rowCount = 3;
            int colCount = 3;

            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount];

            a[0][0] = 1;  a[0][1] = 0;  a[0][2] = 3;
            a[1][0] = 4;  a[1][1] = 5;  a[1][2] = 6;
            a[2][0] = 0;  a[2][1] = 8;  a[2][2] = 0;

            int count = 0;

            bool hasZero = Part1_CountRowsWithZero(a, rowCount, colCount, count);

            Assert::IsTrue(hasZero);
            Assert::AreEqual(2, count);

            for (int i = 0; i < rowCount; i++)
                delete[] a[i];
            delete[] a;
        }

	};
}
