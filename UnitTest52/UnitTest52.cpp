#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 7.2 rec/lab 7.2 rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest52
{
	TEST_CLASS(UnitTest52)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            int rows = 3, cols = 3;
            int** matrix = new int* [rows];
            for (int i = 0; i < rows; ++i) {
                matrix[i] = new int[cols];
            }

            Create(matrix, rows, 7, 65);

            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    Assert::IsTrue(matrix[i][j] >= 7 && matrix[i][j] <= 65);
                }
            }

            for (int i = 0; i < rows; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;
		}
	};
}
