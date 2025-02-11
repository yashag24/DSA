#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i)
{
    if (i > n)
        return;

    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;

    if (left < n && arr[largest] < arr[left])
        largest = left;
    if (right < n && arr[largest] < arr[right])
        largest = right;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
// leaf nodes are from (n/2+1) to n;        
int main()
{
    int size = 6;
    int n = size - 1;
    // n=no of elements
    int arr[size] = {-1, 52, 4, 440, 50, 2};
    for (int i = n / 2; i > 0; i--)
    {
// places ith eleent at right position
        heapify(arr, n , i);
    }
     cout << "\nprint array:-";
    for (int i = 1; i <=n; i++)
    {
        cout << " " << arr[i];
    }
}