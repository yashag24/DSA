#include <iostream>
#include <vector>

using namespace std;

// Bubble Sort
void bubbleSort(vector<int> &array)
{
    int size = array.size();
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

// Selection Sort
void selectionSort(vector<int> &array)
{
    const int size = array.size();
    for (int i = 0; i < size - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }
        swap(array[i], array[minIndex]);
    }
}

// Insertion Sort
void insertionSort(vector<int> &array)
{
    int size = array.size();
    for (int i = 1; i < size; ++i)
    {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

// Radix Sort
int getMax(vector<int> &array)
{
    int maxVal = array[0];
    for (int i = 1; i < array.size(); ++i)
    {
        if (array[i] > maxVal)
        {
            maxVal = array[i];
        }
    }
    return maxVal;
}

void countSort(vector<int> &array, int exp)
{
    int size = array.size();
    vector<int> output(size);
    int k = 10;
    vector<int> count(k, 0);

    for (int i = 0; i < size; ++i)
    {
        count[(array[i] / exp) % k]++;
    }

    for (int i = 1; i < k; ++i)
    {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; --i)
    {
        output[count[(array[i] / exp) % k] - 1] = array[i];
        count[(array[i] / exp) % k]--;
    }

    for (int i = 0; i < size; ++i)
    {
        array[i] = output[i];
    }
}

void radixSort(vector<int> &array)
{
    int maxElement = getMax(array);
    for (int exp = 1; maxElement / exp > 0; exp *= 10)
    {
        countSort(array, exp);
    }
}