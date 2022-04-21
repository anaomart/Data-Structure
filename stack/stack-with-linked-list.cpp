#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *top = NULL;

void push(int value);

int pop();

int peek();

void display();
int main()
{

    push(4);
    push(44);
    push(80);
    display();

    return 0;
}

void push(int value)
{
    node *newNode = new node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop()
{
    if (top == NULL)
    {
        cout << "the stack is empty" << endl;
        return -1;
    }
    else
    {
        node *newNode = top;
        top = newNode->next;
        int value = newNode->data;
        delete newNode;
        return value;
    }
}

int peek()
{
    if (top == NULL)
    {
        cout << "the stack is empty" << endl;
        return -1;
    }
    else
    {
        return top->data;
    }
}
void display()
{
    node *current = top;
    while (current != NULL)
    {
        cout << current->data << endl;
        current = current->next;
    }
}
