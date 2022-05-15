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
bool Pair(char open, char close)
{
    if (open == '(' && close == ')')
        return true;
    else if (open == '[' && close == ']')
        return true;
    else if (open == '{' && close == '}')
        return true;
    return false;
}
bool Balanced(string exp)
{
    Stack openBrackets;
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            openBrackets.push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (openBrackets.isEmpty())
                return false;
            else if (Pair(openBrackets.GetTop(), exp[i]) == false)
                return false;
            openBrackets.pop();
        }
    }
    if (openBrackets.isEmpty())
        return true;
    else
        return false;
}

int main()
{
    string s;
    cout << "Enter The expresion : ";
    cin >> s;
    if (Balanced(s))
        cout << "Balanced";
    else
        cout << "not Balanced";

    return 0;
}
