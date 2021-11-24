#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int* Get_array(int max, int size)
{
    if (max > 0 && size > 0)
    {
        int* arr = new int[size]; //creat new array
        int i;
        srand(time(0));

        //generate an entire random array of SIZE items 1 to MAX
        arr[0] = max / 3 + rand() % max;
        for (i = 1; i < size; i++)
            arr[i] = 1 + rand() % max;
        return arr;
    }
}
void Print_array(int* array, int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << array[i] << " "; // print array
    cout << endl;
}
int Get_max()
{
    srand(time(0));
    int max = rand();
    return max;
}

int BinarySearch(int* arr, int left, int right, int search_item)
{
    if (arr != nullptr && left > 0 && right > 0)
    {
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == search_item) {
                return mid;
            }
            else if (arr[mid] < search_item) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return -1; //if search item doesn't exsist
    }
    else
    {
        cout << "Wrong input" << endl;
    }
}
void QuickSort(int* array, int first, int last)
{
    if (array != nullptr)
    {
        int pivot, left, temp, right;

        if (first < last) {
            pivot = first;
            right = first;
            left = last;

            while (right < left)
            {
                while (array[right] <= array[pivot] && right < last)
                    right++;
                while (array[left] > array[pivot])
                    left--;
                if (right < left)
                {
                    temp = array[right];
                    array[right] = array[left];
                    array[left] = temp;
                }
            }

            temp = array[pivot];
            array[pivot] = array[left];
            array[left] = temp;
            QuickSort(array, first, left - 1);
            QuickSort(array, left + 1, last);
        }

    }
    else
    {
        cout << "Empty array" << endl;
    };
}
void InsertSort(int* array, int size)
{
    if (array != nullptr && size > 0)
    {
        for (int i = 0; i < size; i++)
        {
            for (int i = 1; i < size; i++) {
                for (int j = i; j > 0 && array[j - 1] > array[j]; j--) {//until j>0 and item  j-1 > j. swap j and j-1
                    int tmp = array[j - 1];
                    array[j - 1] = array[j];
                    array[j] = tmp;
                }
            }
        }
    }
    else {
        cout << "Wrong input" << endl;
    }
}
int correct(int* arr, int size)
{
    while (size-- > 0)
        if (arr[size - 1] > arr[size])
            return 0;
    return 1;
}
void BogoSort(int* arr, int size) {
    while (correct(arr, size) != 1)
        for (int i = 0; i < size; ++i) // swap arr[i] to rand items until sort it
        {
            int save = arr[i];
            int rand_i = rand() % size;
            arr[i] = arr[rand_i];
            arr[rand_i] = save;
        }
}
int MaxChar(char* string, int size)
{
    if (string && size > 0)
    {
        int max = string[0];
        //finds the maximum number in a character array
        for (int i = 1; i < size; i++)
        {
            if (max < string[i])
                max = (int)string[i];
        }
        return max;
    }
}
void CountingSort(char* string, int size) {
    if (string && size > 0)
    {
        int max;
        max = MaxChar(string, size);
        char* new_arr = new char[max + 1];
        // fills the array with 0
        memset(new_arr, 0, sizeof(*string) * (max + 1));
        for (int i = 0; i < size; ++i)
        {
            ++new_arr[string[i]];
        }
        int index = 0;
        //if j < new_arr then swap string[index] with i and increase index
        for (int i = 0; i < max + 1; ++i) {
            for (int j = 0; j < new_arr[i]; ++j)
            {
                string[index++] = i;
            }
        }
        delete[] new_arr;
        new_arr = nullptr;
    }
}
