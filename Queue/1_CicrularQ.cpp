#include <iostream>
using namespace std;
class CircularQ
{
    int front;
    int rear, *arr, size;

public:
    CircularQ(int s)
    {
        size = s;
        arr = new int[s];
        front = -1;
        rear = -1;
    }
    void enqueue(int d);
    int dequeue();
};
void CircularQ::enqueue(int d)
{
    if ((rear == (front - 1) % (size - 1)) || (rear == size - 1 && front == 0))
    {
        cout << "\nQueue is full.";
    }
    else if (front = -1)
    {
        front = rear = 0;
        arr[rear] = d;
    }
    else if (rear == size - 1 && front != 0)
    {
        rear = 0;
        arr[rear] = d;
    }
    else
    {
        rear++;
        arr[rear] = d;
    }
}
int CircularQ::dequeue()
{
    if (front == -1 && rear == -1)
    {
        return -1;
    }
    int ans = arr[front];
    arr[front] = -1;
    if (front == rear)
    {

        front = rear = -1;
    }
    else if (front == size - 1)
    {
        front = 0;
    }
    else
    {

        front++;
    }
    return ans;
}