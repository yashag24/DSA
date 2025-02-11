#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i)
{
    if (i > n)
        return;

    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left])
        largest = left;
    if (right <= n && arr[largest < arr[right]])
        largest = right;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
void heapsort(int arr[], int n)
{for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    cout << "print array:-";
    for (int i = 1; i <= n; i++)
    {
        cout << " " << arr[i];
    }
    int s = n;
    while (1 < s)
    {
        swap(arr[s], arr[1]);
        s--;
        heapify(arr, s, 1);
    }
}
int main()
{

    int size = 6;
    int arr[size] = {-1, 55, 52, 440, 65, 2};
    int n = size - 1;
    

    heapsort(arr, n);

    cout << "\nprint array:-";
    for (int i = 1; i <=n; i++)
    {
        cout << " " << arr[i];
    }
}