//                  Stack
// main functions  (push -pop - display -peek)

// push: insert a new element
// three cases:
// 1- the stack is empty
// 2- the stack contains element
// 3- the stack is full
// in 1,2 you can push new elements to the  stack , in 3 you can't how we know if the stack is empty
// by making variable called top is equal to -1 when we add a new element it's increese by one
// so when the stack is empty top will be -1 and when it's full it's will be (size -1 )
//
// pop : delete the last element from the stack How ? by deleting what top variable point to becuse top
// always points to the last element then decrease the top variable by -1
// until the top is equal -1 that means the stack is empty;
//
// peek : just display what value top points at (just display the last element)
//
// display: print how the stack will appear by first in last out
// ex : you push 1, then 4 , then 6
// display will show us like this  6,4,1

#include <iostream>
using namespace std;
// array implementation
#define size 5

int stack[size], top = -1;

void push(int value);

int pop();

int peek();

void display();

int main()
{

    push(4);
    push(40);
    push(400);
    display();
    return 0;
}

void push(int value)
{
    if (top == size - 1)
    {
        cout << "The stack is full" << endl;
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

int pop()
{
    if (top == -1)
    {
        cout << "The stack is empty";
    }
    else
    {
        return stack[top--]; // return the last element then decrease top by one
    }
}

int peek()
{
    if (top == -1)
    {
        cout << "The stack is empty";
    }
    else
    {
        return stack[top]; // just return the last element and don't change any thing
    }
}
void display()
{
    if (top == -1)
    {
        cout << "The stack is empty";
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i]<<endl;
        }
    }
}
