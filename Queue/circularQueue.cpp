#include <iostream>
using namespace std;

#define SIZE 9 // size of

int queue[SIZE];

int front = -1, rear = -1;

bool isEmpty();
bool isFull();
void enqueue(int value);
void dequeue();
int peek();
void display();
int main()
{
    enqueue(111111);

    enqueue(423);
    enqueue(43);
    display();

    return 0;
}
bool isEmpty() // Empty if front and rear are = -1
{
    if (front == -1 && rear == -1)
    {
        return true;
    }
    return false;
}

bool isFull() // if  front =0 (first ele) and rear = size -1 (last ele) or front is bigger than rarer
{
    if ((front == 0 && rear == SIZE - 1))
    {
        return true;
    }
    else if ((front - 1 == rear))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(int value) // add value to queue
{

    // 0-make sure it't not full
    // 1-if it's is empty then just add one for front and rear then assign the new value
    // 2-if rear is at last element (size -1) then make start from the begging by make rear =0 then assign the new value ;
    // 3-if neither of this just add one to rear and assign the new value ;
    if (isFull())
    {
        cout << "Queue is full" << endl;
    }
    else
    {
        if (isEmpty())
        {
            front = rear = 0;
            queue[rear] = value;
        }
        else if (rear == SIZE - 1)
        {
            rear = 0;
            queue[rear] = value;
        }
        else
        {
            queue[++rear] = value;
        }
    }
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == SIZE - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
}

int peek()
{
    if (isEmpty())
    {
        cout << "Queue isEmpty" << endl;
        return -1;
    }
    else
    {
        return queue[front];
    }
}

void display()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << queue[i] << endl;
            }
            cout << endl;
        }
        else
        {
            for (int i = front; i < SIZE; i++)
            {
                cout << queue[i] << endl;
            }
            for (int i = 0; i <= rear; i++)
            {
                cout << queue[i] << endl;
            }
            cout << endl;
        }
    }
}
