#include "pch.h"
#include "CppUnitTest.h"
#include"../lab2/Sort_Search_func.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(lab2)
	{
	public:
		
		TEST_METHOD(QuickSort_test)
		{
			int* arr = nullptr;
			arr = new int[4];
			for (int i = 0; i < 4; i++)
			{
				arr[i] = 4 - i;
			}
			QuickSort(arr, 0, 3);
			int* arr_true = nullptr;
			arr_true = new int[4];
			arr_true[0] = 1;
			arr_true[1] = 2;
			arr_true[2] = 3;
			arr_true[3] = 4;
			Assert::IsTrue(arr[0] == arr_true[0]);
			Assert::IsTrue(arr[3] == arr_true[3]);
			Assert::IsTrue(arr[2] == arr_true[2]);
			Assert::IsTrue(arr[1] == arr_true[1]);
			delete[] arr;
			delete[] arr_true;
		}
		TEST_METHOD(BinarySearch_test)
		{
			int* arr = nullptr;
			arr = new int[4];
			for (int i = 0; i < 4; i++)
			{
				arr[i] = 4 - i;
			}
			int number=0;
			number = BinarySearch(arr, 0, 4, 1);
			Assert::IsFalse(number == 0);
			Assert::IsFalse(number == 1);
			Assert::IsFalse(number == 2);
			delete[] arr;
		}
		TEST_METHOD(InsertSort_test)
		{
			int* arr = nullptr;
			arr = new int[4];
			for (int i = 0; i < 4; i++)
			{
				arr[i] = 4 - i;
			}
			InsertSort(arr,4);
			int* arr_true = nullptr;
			arr_true = new int[4];
			arr_true[0] = 1;
			arr_true[1] = 2;
			arr_true[2] = 3;
			arr_true[3] = 4;
			Assert::IsTrue(arr[0] == arr_true[0]);
			Assert::IsTrue(arr[3] == arr_true[3]);
			Assert::IsTrue(arr[2] == arr_true[2]);
			Assert::IsTrue(arr[1] == arr_true[1]);
			delete[] arr;
			delete[] arr_true;
		}
		TEST_METHOD(CountingSort_test)
		{
			char* string = nullptr;

			string = new char[5];
			string[0] = 'b';
			string[1] = 'd';
			string[2] = 'c';
			string[3] = 'a';
			string[4] = '\0';
			CountingSort(string, 4);
			Assert::AreEqual("abcd", string);
			delete[] string;
		}
		TEST_METHOD(BogoSort_test)
		{
			int* arr = nullptr;
			arr = Get_array(32, 10);
			BogoSort(arr, 10);
			Assert::IsTrue(correct(arr, 10));
			delete[] arr;
		}
	};

}
