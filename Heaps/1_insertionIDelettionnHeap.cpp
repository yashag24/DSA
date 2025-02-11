#include <iostream>>
using namespace std;
class Heap
{
public:
    int arr[100];
    int size;
    Heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insertion(int d) /// O(logn)
    {
        size++;
        int index = size;
        arr[index] = d;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {

        for (int i = 1; i < size; i++)
            cout << arr[i] << " ";
    }

    // only root node is deleted in heap;
    void deletion()
    {
        if (size == 0)
        {
            cout << "No node to delete." << endl;
            return;
        }
        swap(arr[1], arr[size]);
        size--;

        int i = 1;
        while (i < size)
        {
            int leftchild = 2 * i;
            int rightchild = 2 * i + 1;
            if (leftchild < size && arr[leftchild] > arr[i])
            {
                swap(arr[i], arr[leftchild]);
                i = leftchild;
            }
            else if (rightchild < size && arr[rightchild] > arr[i])
            {
                swap(arr[i], arr[rightchild]);
                i = rightchild;
            }
            else
            {
                return;
            }
        }
    }
};