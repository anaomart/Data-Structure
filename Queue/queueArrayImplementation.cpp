#include <iostream>
using namespace std; //

#define SIZE 5 // list size

int queue[SIZE];           //  list ( queue)
int front = -1, rear = -1; // front , rear

void enqueue(int value); // enqueue ->> adding new element to queue

void dequeue(); // dequeue ->> removing element from queue

int peek(); // peek ->> returning the top element

void display(); // display ->> display all the elements ;

int main()
{
    enqueue(5);
    enqueue(35);
    enqueue(55);
    enqueue(544);
    display();
    cout << "-----------";
    dequeue();
    display();
    cout << "-----------";

    cout << peek();
    cout << "-----------";

    return 0;
}

void enqueue(int value) // adding new element to queue
{
    if (rear != SIZE - 1)
    { // if it's not full
        if (front == -1 && rear == -1)
        { // if it's the first element
            front++;
            queue[++rear] = value;
        }
        else // if it's in the middle  '
        {
            queue[++rear] = value;
        }
    }
    else
    {
        cout << "Queue is Full";
    }
}

void dequeue() // remove element from queue
{
    if (front != -1 && rear != -1 && front <= rear)
    {
        front++;
    }
    else
    {
        cout << "Queue is Empty";
    }
}

int peek() // return element on the top

{
    if (front != -1 && rear != -1 && front <= rear)
    {
        return queue[front];
    }
    else
    {
        cout << "Queue is Empty";
    }
}

void display() // display all the elements
{
    if (front != -1 && rear != -1 && front <= rear)
    {
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << endl;
        }
    }
    else
    {
        cout << "Queue is Empty";
    }
}