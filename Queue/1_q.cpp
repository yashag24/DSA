#include <iostream>
using namespace std;
class queue
{

    int front, rear, *arr, size;

public:
    queue(int s)
    {
        size = s;
        arr = new int[size];

        front = rear = -1;
    }
    void enqueue(int n);
    void dequeue();
    void frontele();
    bool isempty();
};

void queue::enqueue(int n)
{
    if (rear == -1)
    {
        front++;
    }
    if (rear == size - 1)
    {
        cout << "\nQueue is full.";
        return;
    }

    rear++;
    arr[rear] = n;
}
void queue::dequeue()
{
    if (isempty())
    {
        cout << "\nQueue is empty.";
        return;
    }

    // if (front == -1)
    // {
    //     front += 2;
    //     cout << "\nElement deleted :-" << arr[0];
    // }
    // else
    // {
    cout << "\nElement deleted :-" << arr[front];
    front++;

    if (front == rear)
    {
        front = rear = -1;
    }
}
bool queue::isempty()
{
    if (front == -1 && rear == -1)
        return true;
    return false;
}
void queue::frontele()
{
    if (isempty())
    {
        cout << "\nQueue is empty.";
        return;
    }

    cout << "\nFront element is:-" << arr[front];
}
int main()
{
    queue q(5);
    q.enqueue(10);
    q.enqueue(1);
    q.enqueue(0);
    q.frontele();
    q.dequeue();
     q.frontele();
    q.enqueue(190);
}