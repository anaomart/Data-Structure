#include <iostream>
using namespace std;
static int top = -1;
struct Stack
{
    int arr[100];

    // First function push
    void push(int val)
    {
        if (top == 99)
            return;
        top++;
        arr[top] = val;
    }
    void pop()
    {
        if (isEmpty())
            return;
        // delete arr[top];
        top--;
    }
    int GetTop()
    {
        if (isEmpty())
            return -1;
        return arr[top];
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    void display()
    {
        int pointer = top;
        while (pointer != -1)
            cout << arr[pointer--] << endl;
    };
};

int main()
{

    Stack stk;
    stk.push(4);
    stk.push(432);
    stk.push(5);
    stk.push(522);
    stk.display();
}